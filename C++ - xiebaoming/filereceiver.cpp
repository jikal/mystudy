#include "filereceiver.h"
#include "ui_filereceiver.h"

#include <QFileDialog>
#include <QMessageBox>

//接收方 连接信号槽  有数据读入 触发readmessage
fileReceiver::fileReceiver(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::fileReceiver)
{
    ui->setupUi(this);
    this->setFixedSize(350, 180);//设置窗口尺寸，不可改变

    TotalBytes = 0;//初始化
    bytesReceived = 0;//初始化
    fileNameSize = 0;//初始化

    FileReceiver = new QTcpSocket(this);//TCP客户端
    tcpPort = 6666;//端口号

    connect(FileReceiver, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect(FileReceiver, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
}

fileReceiver::~fileReceiver()
{
    delete ui;
}

void fileReceiver::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

//设置服务器地址并连接服务器
void fileReceiver::setHostAddress(QHostAddress address)
{
    hostAddress = address;
    newConnect();
}

//连接服务器
void fileReceiver::newConnect()
{
    blockSize = 0;
    FileReceiver->abort();
    FileReceiver->connectToHost(hostAddress, tcpPort);
    time.start();
}

//槽 读取收到的文件
void fileReceiver::readMessage()
{
    QDataStream in(FileReceiver);
    in.setVersion(QDataStream::Qt_4_6);//设置版本号

    float useTime = time.elapsed();
    if(bytesReceived <= sizeof(qint64)*2){
        if((FileReceiver->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0))
        {
            in >> TotalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if((FileReceiver->bytesAvailable() >= fileNameSize) && (fileNameSize != 0))
        {
            in >> fileName;
            bytesReceived += fileNameSize;

            if(!localFile->open(QFile::WriteOnly))//打开本地文件
            {
                QMessageBox::warning(this, tr("应用程序"), tr("无法读取文件 %1:\n%2.").arg(fileName).arg(localFile->errorString()));
                return ;
            }
        }
        else
        {
            return ;
        }
    }
    if(bytesReceived < TotalBytes)//没有接收完毕
    {
        bytesReceived += FileReceiver->bytesAvailable();//更新接收到的字节数
        inBlock = FileReceiver->readAll();//读取接收数据
        localFile->write(inBlock);//写入本地文件
        inBlock.resize(0);//清空缓存
    }
    ui->progressBar->setMaximum(TotalBytes);//设置progressBar的最大值
    ui->progressBar->setValue(bytesReceived);//更新progressBar的值
    qDebug() << bytesReceived << "received" << TotalBytes;

    double speed = bytesReceived / useTime;//接收速度
    ui->FileReceiverStatusLabel->setText(tr("已接收 %1MB (%2MB/s) \n共%3MB 已用时:%4秒\n估计剩余时间：%5秒")
                                         .arg(bytesReceived / (1024*1024))//已接收
                                         .arg(speed*1000/(1024*1024),0,'f',2)//速度
                                         .arg(TotalBytes / (1024 * 1024))//总大小
                                         .arg(useTime/1000,0,'f',0)//用时
                                         .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//剩余时间

    if(bytesReceived == TotalBytes)//接收完毕
    {
        FileReceiver->close();
        ui->FileReceiverStatusLabel->setText(tr("接收文件 %1 完毕").arg(fileName));
        localFile->close();   //接收完文件后，一定要关闭，不然可能出问题
    }
}

//错误处理
void fileReceiver::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
        case QAbstractSocket::RemoteHostClosedError : break;
        default : qDebug() << FileReceiver->errorString();
    }
}

//中途取消的操作
void fileReceiver::on_btnCancel_clicked()
{
    FileReceiver->abort();//终止连接
}

void fileReceiver::on_btnClose_clicked()
{
    FileReceiver->abort();//终止连接
    this->close();//关闭窗口
}
