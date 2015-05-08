#include "widget.h"
#include "ui_widget.h"
#include "chatwidgit.h"
#include "mainform.h"
#include "filesender.h"
#include "filereceiver.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(300, 550);
    this->move(1000, 50);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格为整行选中的方式//设置选择模式
    //ui->tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);//使行完全填充并平分
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//使列完全填充并平分

    Sender = new FileSender(this);
    udpSocket = new QUdpSocket(this);
    port = 45454;
    isGame = 0;
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);//绑定UDP
    //ShareAddress模式：允许其他服务绑定到相同的地址和端口//ReuseAddressHint模式：重新连接服务器
    //readyRead()信号是每当有新的数据来临时就被触发
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));//进行监听是否有数据报文需要读取
    connect(Sender, SIGNAL(sendFileName(QString, QString)), this, SLOT(sendFileName(QString, QString)));


}

//登录成功后调用，设置昵称，并广播新用户加入
void Widget::SetName(QString name)
{
    Name = name;
    sendMessage(NewParticipant);//广播有新用户加入
}

//接收UDP信息信号的处理函数//接收数据，并根据type分类 槽函数
void Widget::processPendingDatagrams()//接收数据处理过程
{
    while(udpSocket->hasPendingDatagrams())//是否有数据报等待阅读//hasPendingDatagrams返回true时表示至少有一个数据报在等待被读取
    {
        QByteArray datagram;//缓存字节数组
        //pendingDatagramSize为返回第一个在等待读取报文的size，resize函数是把datagram的size归一化到参数size的大小一样
        datagram.resize(udpSocket->pendingDatagramSize());//获取缓存大小
        //将读取到的不大于datagram.size()大小数据输入到datagram.data()中，datagram.data()返回的是一个字节数组中存储数据位置的指针
        udpSocket->readDatagram(datagram.data(), datagram.size());//读取数据
        QDataStream in(&datagram, QIODevice::ReadOnly);//Qt的I/O设备接口类 从&datagram中读取串行化的数据 只读 序列化的二进制数据
        int messageType;//此处的int为qint32，在Qt中，qint8为char，qint16为uint
        in >> messageType;//读取1个32位长度的整型数据到messageTyep中//提取出messageType
        QString localHostName, ipAddress, message, secretAddress;//消息发送方昵称名，IP地址，消息内容和消息接受方IP地址
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间//将当前的时间转化到括号中的形式
        switch(messageType)
        {
            case RefuseChat://拒绝聊天
                //in>>后面如果为Qstring，则表示读取一个直到出现'\0'的字符串
                in  >> localHostName >> ipAddress >> secretAddress;//提取出消息发送方昵称名，IP和消息接收方IP
                if(secretAddress == getIP())//是发给自己的
                {
                    QMessageBox::information(this, tr("拒绝"), tr("来自（%1）的%2  拒绝你的聊天").arg(ipAddress).arg(localHostName));
                }
                break;

            case StartChat://开始聊天
                in  >> localHostName >> ipAddress >> secretAddress;
                if(secretAddress == getIP())
                {
                    ChatWidgit *chatView = new ChatWidgit();
                    list.insert(ipAddress, chatView);//插入聊天窗口列表

                    connect(chatView, SIGNAL(closeChat(QString)), this, SLOT(closeFromChat(QString)));
                    connect(this, SIGNAL(sendMessagesZ(QString, QString, QString)), chatView, SLOT(setMessage(QString, QString, QString)));
                    connect(chatView, SIGNAL(sendMessagesFromChat(QString, QString)), this, SLOT(sendMessagesToMain(QString, QString)));
                    connect(chatView, SIGNAL(sendFile(QString, QString)), this, SLOT(hasFileToSend(QString, QString)));

                    chatView->setSecAddr(ipAddress, Name);//设置具体聊天窗口（chatView）
                    chatView->show();
                }
                break;

            case AskStartChat://申请聊天
                in  >> localHostName >> ipAddress >> secretAddress;
                if(secretAddress == getIP())
                {
                    int btn = QMessageBox::information(this, tr("同意聊天"), tr("来自%1(%2)的聊天,是否接收？")\
                                                           .arg(ipAddress).arg(localHostName), QMessageBox::Yes, QMessageBox::No);
                    if(btn == QMessageBox::Yes)
                    {
                        ChatWidgit *chatView = new ChatWidgit();
                        list.insert(ipAddress, chatView);

                        connect(chatView, SIGNAL(closeChat(QString)), this, SLOT(closeFromChat(QString)));
                        connect(this, SIGNAL(sendMessagesZ(QString, QString, QString)), chatView, SLOT(setMessage(QString, QString, QString)));
                        connect(chatView, SIGNAL(sendMessagesFromChat(QString, QString)), this, SLOT(sendMessagesToMain(QString, QString)));
                        connect(chatView, SIGNAL(sendFile(QString, QString)), this, SLOT(hasFileToSend(QString, QString)));

                        chatView->setSecAddr(ipAddress, Name);
                        chatView->show();
                        sendMessage(StartChat, ipAddress);
                    }
                    else if(btn == QMessageBox::No)
                    {
                        sendMessage(RefuseChat, ipAddress);
                    }
                }
                break;

            case Message://聊天消息
                in  >> localHostName >> ipAddress >> secretAddress >> message;
                //QMessageBox::information(this, tr("0"), tr("%1sec\n%2").arg(secretAddress).arg(ipAddress));
                if(secretAddress == getIP() )//发给自己的私有聊天
                {
                    //QMessageBox::information(this, tr("0"), tr("%1sec").arg(secretAddress));
                    if(list.contains(ipAddress))
                    {
                        list[ipAddress]->show();
                        emit sendMessagesZ(ipAddress, tr("[ %1 ] %2").arg(localHostName).arg(time), message);//主窗口向具体聊天窗口发送聊天消息的信号
                    }
                    else
                    {
                        ChatWidgit *chatView = new ChatWidgit();
                        list.insert(ipAddress, chatView);

                        connect(chatView, SIGNAL(closeChat(QString)), this, SLOT(closeFromChat(QString)));
                        connect(this, SIGNAL(sendMessagesZ(QString, QString, QString)), chatView, SLOT(setMessage(QString, QString, QString)));
                        connect(chatView, SIGNAL(sendMessagesFromChat(QString, QString)), this, SLOT(sendMessagesToMain(QString, QString)));
                        connect(chatView, SIGNAL(sendFile(QString, QString)), this, SLOT(hasFileToSend(QString, QString)));

                        chatView->setSecAddr(ipAddress, Name);
                        chatView->show();
                        emit sendMessagesZ(ipAddress, tr("[ %1 ] %2").arg(localHostName).arg(time), message);
                    }
                }
                else if(secretAddress == "NULL")//群消息
                {
                    if(list.contains("NULL"))
                    {
                        list["NULL"]->show();
                        emit sendMessagesZ(secretAddress, tr("[ %1 ] %2").arg(localHostName).arg(time), message);
                    }
                    else
                    {
                        ChatWidgit *chatView = new ChatWidgit();
                        list.insert(secretAddress, chatView);

                        connect(chatView, SIGNAL(closeChat(QString)), this, SLOT(closeFromChat(QString)));
                        connect(this, SIGNAL(sendMessagesZ(QString, QString, QString)), chatView, SLOT(setMessage(QString, QString, QString)));
                        connect(chatView, SIGNAL(sendMessagesFromChat(QString, QString)), this, SLOT(sendMessagesToMain(QString, QString)));
                        connect(chatView, SIGNAL(sendFile(QString, QString)), this, SLOT(hasFileToSend(QString, QString)));

                        chatView->setSecAddr(secretAddress, Name);
                        chatView->show();
                        emit sendMessagesZ(secretAddress, tr("[ %1 ] %2").arg(localHostName).arg(time), message);
                    }
                }
                break;

            case NewParticipant://新用户加入
                in >> localHostName >> ipAddress;
                newParticipant(localHostName, ipAddress);//主窗口登记新用户
                break;

            case ParticipantLeft://用户离开
                in >> localHostName;
                //participantLeft(localHostName, time);
                participantLeft(localHostName);//主窗口处理用户离开
                break;

            case FileName://发送文件
                {
                    in >> localHostName >> ipAddress;
                    QString clientAddress, fileName;//
                    in >> clientAddress >> fileName;
                    QMessageBox::information(this, tr(""), tr("%1ipaddr\n%2sev\n%3file").arg(ipAddress).arg(clientAddress).arg(message));//
                    hasPendingFile(localHostName, ipAddress, clientAddress, fileName);//有文件需要接收
                    break;
                }
            case Refuse://拒绝接收文件
                in >> localHostName;
                QString serverAddress;//
                in >> ipAddress >> serverAddress;

                if(serverAddress == getIP())
                {
                    this->Sender->refused();
                }
                break;
        }
    }
}

//有文件需要接收//收到发送文件的请求信息，对应的处理函数
void Widget::hasPendingFile(QString localHostName, QString serverAddress, QString clientAddress, QString fileName)
{
    if(clientAddress == getIP())
    {
        int btn = QMessageBox::information(this, tr("接受文件"), tr("来自%1(%2)的文件：%3,是否接收？")\
                           .arg(localHostName).arg(serverAddress).arg(fileName), QMessageBox::Yes, QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            QString name = QFileDialog::getSaveFileName(0, tr("保存文件"), fileName);//提供对话框,允许用户选择文件或目录的类 静态函数
            if(!name.isEmpty())
            {
                fileReceiver *receiver = new fileReceiver(this);
                receiver->setFileName(name);
                receiver->setHostAddress(QHostAddress(serverAddress));
                receiver->move(500, 200);
                receiver->show();
            }
        }
        else
        {
            sendMessage(Refuse, serverAddress);
        }
    }
}

//双击用户,弹出私聊窗口
void Widget::on_tableWidget_doubleClicked(QModelIndex index)
{
    QString secretAddress = ui->tableWidget->item(index.row(), 1)->text();//对方ip
    if(secretAddress == getIP())
    {
        QMessageBox::information(this, tr("警告"), tr("你在尝试和自己聊天"));
        return ;
    }
    if(list.contains(secretAddress))
    {
        list[secretAddress]->raise();
        list[secretAddress]->activateWindow();//激活窗口
        list[secretAddress]->show();
        return ;
    }
    sendMessage(AskStartChat, secretAddress);
}

//群聊窗口
void Widget::on_btnAll_clicked()
{
    if(list.contains("NULL"))//窗口存在
    {
        list["NULL"]->raise();
        list["NULL"]->activateWindow();
        list["NULL"]->show();
    }
    else
    {
        ChatWidgit *chatView = new ChatWidgit();
        list.insert("NULL", chatView);

        connect(chatView, SIGNAL(closeChat(QString)), this, SLOT(closeFromChat(QString)));
        connect(this, SIGNAL(sendMessagesZ(QString, QString, QString)), chatView, SLOT(setMessage(QString, QString, QString)));
        connect(chatView, SIGNAL(sendMessagesFromChat(QString, QString)), this, SLOT(sendMessagesToMain(QString, QString)));

        chatView->setSecAddr("NULL", Name);
        chatView->show();
    }
}

//发送消息,和接收消息相对应,根据type区分
void Widget::sendMessage(MessageType type, QString serverAddress, QString message)
{
    if(Name == "")
        return ;

    QByteArray data;
    //QHostAddress addr;//提供一个IP地址的类//
    QDataStream out(&data,QIODevice::WriteOnly);//将序列化的二进制数据只写方式送到io设备//把数据串行化至&data
    QString localHostName = Name;
    //QString localHostName = QHostInfo::localHostName();//返回主机名，QHostInfo包含了一些关于主机的静态函数
    QString address = getIP();
    out << type << localHostName;//串行化type和localHostName//向要发送的数据流中写入
    switch(type)
    {
        case ParticipantLeft:
            break;

        case NewParticipant:
            out << address;
            break;

        case RefuseChat:
            out << serverAddress;
            break;        

        case StartChat:
            out << address << serverAddress;
            break;        

        case AskStartChat:
            out << address << serverAddress;
            break;        

        case Message :
            out << address << serverAddress << message;
            break;        

        case FileName:
            out << address << serverAddress << message;
            break;

        case Refuse:
            out << address << serverAddress;
            break;       
    }
    //data是out流中的data，QHostAddress::Broadcast是指发送数据的目的地址,这里为本机所在地址的广播组内所有机器，即局域网广播发送
    udpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, port);//进行UDP广播 发送数据报 广播地址 端口号
}

//发送文件窗口的发送文件信号对应的槽函数
void Widget::sendFileName(QString fileName, QString Addr)
{
    sendMessage(FileName, Addr, fileName);
}

//窗体关闭事件//主窗口关闭引发所有子窗口关闭
void Widget::closeEvent(QCloseEvent *)
{
    QMap<QString, ChatWidgit *>::Iterator it;//迭代器
    while(list.size() > 0)
    {
        it = list.begin();
        list[it.key()]->close();
    }
    if(isGame == 1)
    {
        emit closeGame();
    }
    sendMessage(ParticipantLeft);
}

//窗体改变事件//光标位于聊天输入栏中不同格式字体处，字体格式工具栏发生相应改变
void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;

        default:
            break;
    }
}

//处理新用户加入
void Widget::newParticipant(QString localHostName, QString ipAddress)
{   //此处的findItems表示找到与内容localHostName匹配的item，其匹配完全精确匹配模式
    bool isEmpty = ui->tableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty();//判断用户是否已加入到主窗口的用户列表中
    if(isEmpty)
    {   //新建2个小的item，分别为host，ip
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
        ui->tableWidget->insertRow(0);//用户列表中添加新用户
        ui->tableWidget->setItem(0, 0, host);
        ui->tableWidget->setItem(0, 1, ip);
        ui->lbOnline->setText(tr("在线人数：%1").arg(ui->tableWidget->rowCount()));
        sendMessage(NewParticipant);//自己先加入，然后广播，其他人收到后，也广播自己//让新来的用户也能收到其它在线用户的信息，可用于更新自己的好友列表
    }
}

//处理用户离开
//void Widget::participantLeft(QString localHostName, QString time)
void Widget::participantLeft(QString localHostName)
{
    int rowNum = ui->tableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();//搜索匹配的类型 枚举
    ui->tableWidget->removeRow(rowNum);//删除用户列表中已退出的用户
    ui->lbOnline->setText(tr("在线人数：%1").arg(ui->tableWidget->rowCount()));//更新在线人数
}

//私聊窗口的发送文件的信号对应的槽函数
void Widget::hasFileToSend(QString fileName, QString SecretAddress)
{
    this->Sender->initSender();
    this->Sender->SenderStart(fileName, SecretAddress);
    this->Sender->move(500, 200);
    this->Sender->show();
}

//聊天窗口的聊天消息的信号对应的槽函数
void Widget::sendMessagesToMain(QString message, QString secretAddr)
{
    sendMessage(Message, secretAddr, message);
}

//聊天窗口关闭后，从聊天窗口列表中删除记录
void Widget::closeFromChat(QString addr)
{
    list.remove(addr);
}

void Widget::on_btnCancel_clicked()
{
    if(isGame == 1)
    {
        emit closeGame();
    }
    this->close();
}

Widget::~Widget()
{
    delete ui;
}

//获取ip地址
QString Widget::getIP()
{   //QList 容器模板类
    QList<QHostAddress> list = QNetworkInterface::allAddresses();//获取所有IP地址的列表//ipv4和ipv6的地址
    foreach (QHostAddress address, list)//按照容器list中条目的顺序进行迭代//遍历每一个IP地址
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol) //判断是否是IPv4的地址
        {
            if(address.toString() != "127.0.0.1")//去掉127.0.0.1的IP
            {
                return address.toString();
            }
        }
    }
    return 0;
}

//玩游戏
void Widget::on_btnGame_clicked()
{
    mainform *m = new mainform();
    isGame = 1;
    ui->btnGame->setEnabled(false);//设置游戏按钮不可用
    connect(this, SIGNAL(closeGame()), m, SLOT(close()));
    connect(m, SIGNAL(game_able()), this, SLOT(btnGame_able()));
    m->show();
}

void Widget::btnGame_able()
{
    ui->btnGame->setEnabled(true);//设置游戏按钮可用
}
