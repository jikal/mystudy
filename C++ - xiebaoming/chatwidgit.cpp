#include "chatwidgit.h"
#include "ui_chatwidgit.h"

//此函数是网上的  将html格式的qstring 转换//？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
QString simplifyRichText( QString f_richText )
{
    QRegExp rxBody("<body[^>]*>(.*)</body>");
    if(rxBody.indexIn(f_richText))
    {
        f_richText = rxBody.cap(1); // throw away anything not in the body, and the body tags as well
        f_richText.replace(QRegExp("^\\s+"),""); // throw away any leading whitespace (be it new lines or spaces)
    }
    QRegExp rxBody1("<span[^>]*>(.*)</span>");
    if(f_richText.indexOf(rxBody1) != -1){
        if(rxBody1.indexIn(f_richText))
        {
            f_richText = rxBody1.cap(1); // throw away anything not in the body, and the body tags as well
            f_richText.replace(QRegExp("^\\s+"),""); // throw away any leading whitespace (be it new lines or spaces)
        }
    }
    f_richText.replace(QRegExp("<p style=\"[^\"]*\">"),"<p>"); // throw away paragraph styles


    if(f_richText == "<p></p>") // thats what we get for an empty QTextEdit
        return QString();
    f_richText.replace("<p>","");
    f_richText.replace("</p>","");

    return f_richText;
}

ChatWidgit::ChatWidgit(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ChatWidgit)
{
    ui->setupUi(this);
    ui->tbHistory->hide();
    //ui->teEdit->setFocusPolicy(Qt::StrongFocus);//键盘事件，设置获得焦点的方式：通过Tab键获得焦点和被单击获得焦点//
    ui->teEdit->setFocus();//设置焦点
    //ui->teEdit->installEventFilter(this);//注册成监视对象，使this可监视其（子控件）的键盘事件//

    this->resize(500, 400);
    //字符格式化信息发生改变，发送信号，改变相应的控件
    connect(ui->teEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)), this, SLOT(currentFormatChanged(const QTextCharFormat)));
}

ChatWidgit::~ChatWidgit()
{
    delete ui;
}

//收到主窗体发来的聊天消息信号，相应的槽函数
void ChatWidgit::setMessage(QString address, QString first, QString second)//IP地址  用户名和时间  聊天内容
{
    if(address == secretAddress ){
        ui->tbShow->setTextColor(Qt::blue);//设置文本颜色
        ui->tbShow->setCurrentFont(QFont("Times New Roman", 12));//设置字体大小
        ui->tbShow->append(first);//输出用户名和时间
        //ui->tbShow->setTextColor(Qt::blue);//
        //ui->tbShow->setCurrentFont(QFont("Times New Roman", 12));//
        ui->tbShow->append(second);//输出聊天内容

        if(!saveFile.open(QFile::WriteOnly | QFile::Text | QFile::Append))
        {
            QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件 :\n %1").arg(saveFile.errorString()));
            return ;
        }

        QTextStream out(&saveFile);//读写文本的接口类
        out << first << endl << simplifyRichText(second) << endl;//聊天记录写入记录文本中//
        //out << first.trimmed() << endl << second.trimmed() << endl;//
        saveFile.close();
    }
}

//获取本机ip//没用到？？？
QString ChatWidgit::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address, list)
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
        {
            if(address.toString() != "127.0.0.1")
            {
                return address.toString();
            }
        }
    }
    return 0;
}

//获取此聊天框对应的聊天人ip//没用到？？？
QString ChatWidgit::getSecAddr()
{
    return this->secretAddress;
}

//设置聊天窗口，并创建聊天记录文件
void ChatWidgit::setSecAddr(QString addr, QString niname)
{
    this->secretAddress = addr;
    if(secretAddress == "NULL")//群聊
    {
        ui->lbConn->setText(tr("对方ip: All"));
        ui->textSave->hide();//群聊时隐藏发送文件按钮
    }
    else
    {
        ui->lbConn->setText(tr("对方ip：%1").arg(secretAddress));
    }
    QDir dir;//访问目录结构及其内容的类
    dir.mkpath("history");//创建目录文件夹

    saveFile.setFileName(tr("history\\%1%2.chat").arg(addr).arg(niname));//保存聊天记录
    this->setWindowTitle(tr("聊天--%1").arg(niname));
}

//发送聊天消息，触发主窗口的槽函数  并显示储存消息
void ChatWidgit::on_btnSend_clicked()
{
    if(ui->teEdit->toPlainText() == "")//将输入框里的文字转化成纯文本发送
    {
        QMessageBox::warning(0, tr("警告"), tr("发送内容不能为空"), QMessageBox::Ok);//tr函数为译本函数，即译码后面的text内容
        return ;
    }
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString message = ui->teEdit->toHtml();//转化成html语言进行发送//
    if(secretAddress != "NULL"){
        ui->tbShow->setTextColor(Qt::blue);
        ui->tbShow->setCurrentFont(QFont("Times New Roman",12));
        ui->tbShow->append(tr("[ 你说 ]  %1").arg(time));
        ui->tbShow->append(message);

        if(!saveFile.open(QFile::WriteOnly | QFile::Text | QFile::Append))
        {
            QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件 :\n %1").arg(saveFile.errorString()));
            return ;
        }
        QTextStream out(&saveFile);
        out << tr("[ 你说 ]  %1").arg(time) << endl << simplifyRichText(message) << endl;//没有用？？？？？？？？？？？？？？？？？？
        //out << tr("[ 你说 ]  %1").arg(time) << endl << ui->teEdit->toPlainText() << endl;
        //out <<tr("[ 你说 ]  %1").arg(time).trimmed()<<endl << message.trimmed()<<endl;
        saveFile.close();
    }

    ui->teEdit->clear();//发送完后清空输入框
    ui->teEdit->setFocus();//重新设置光标输入焦点，即焦点保持不变

    emit sendMessagesFromChat(message, secretAddress);
}

//字体加粗
void ChatWidgit::on_textbold_clicked(bool checked)
{
    if(checked)
    {
        ui->teEdit->setFontWeight(QFont::Bold);
    }
    else
    {
        ui->teEdit->setFontWeight(QFont::Normal);
    }
    ui->teEdit->setFocus();
}

//字体倾斜
void ChatWidgit::on_textitalic_clicked(bool checked)
{
    ui->teEdit->setFontItalic(checked);
    ui->teEdit->setFocus();
}

//字体加下滑线
void ChatWidgit::on_textunderline_clicked(bool checked)
{
    ui->teEdit->setFontUnderline(checked);
    ui->teEdit->setFocus();
}

//字体颜色
void ChatWidgit::on_textcolor_clicked()
{
    QColor color = QColorDialog::getColor(color, this);
    if(color.isValid())
    {
        ui->teEdit->setTextColor(color);
        ui->teEdit->setFocus();
    }
}

//事件处理 监视代码具体实现：在输入时按下Ctrl+Enter发送聊天消息
bool ChatWidgit::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->teEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent *k = static_cast<QKeyEvent *> (event);
            //if (k->key() == Qt::Key_Return)
            if(k->key() == Qt::Key_Return && (k->modifiers() & Qt::ControlModifier))
            {
                on_btnSend_clicked();
                return true;
            }
        }
    }
    return QWidget::eventFilter(target, event);
}

//聊天窗口关闭时发送信号，让主窗口删除Qmap表项中相对应的数据
void ChatWidgit::closeEvent(QCloseEvent *)
{
    emit closeChat(secretAddress);
}

//聊天窗口关闭/隐藏
void ChatWidgit::on_btnClose_clicked()
{
    this->hide();
}

//清空聊天框内容
void ChatWidgit::on_textBin_clicked()
{
    ui->tbShow->clear();
}

//发送文件时，向主窗口发送相应信号
void ChatWidgit::on_textSave_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);//获取想要发送的文件名
    if(fileName.isEmpty())
    {
        QMessageBox::information(this, tr("警告"), tr("请选择文件"));
        return ;
    }

    emit sendFile(fileName, secretAddress);
}

//当编辑器的字体格式改变时，让部件状态也随之改变
void ChatWidgit::currentFormatChanged(const QTextCharFormat &format)//QTextCharFormat 字符格式化信息类
{
    ui->fontComboBox->setCurrentFont(format.font());//

    if(format.fontPointSize() < 9)//如果字体大小出错，因为设置的最小字体为9//
    {
        ui->fontComboBox->setCurrentIndex(3);//即显示12//设置为12//
    }
    else
    {
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(QString::number(format.fontPointSize())));
    }
    ui->textbold->setChecked(format.font().bold());
    ui->textitalic->setChecked(format.font().italic());
    ui->textunderline->setChecked(format.font().underline());
    color = format.foreground().color();
}

//字体大小
void ChatWidgit::on_comboBox_currentIndexChanged(QString size)
{
    ui->teEdit->setFontPointSize(size.toDouble());
    ui->teEdit->setFocus();
}

//显示聊天记录的按键
void ChatWidgit::on_textHistory_clicked()
{
    if(ui->tbHistory->isHidden())
    {
        if(!saveFile.open(QFile::ReadOnly))
        {
            QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件 :\n %1").arg(saveFile.errorString()));
            return ;
        }

        QTextStream out(&saveFile);

        ui->tbHistory->setText(out.readAll());
        ui->tbHistory->verticalScrollBar()->setValue(ui->tbHistory->verticalScrollBar()->maximum());//设置垂直滑动条的最大值
        saveFile.close();
        ui->tbHistory->show();
        this->resize(800, 400);
    }
    else
    {
        ui->tbHistory->hide();
        this->resize(500, 400);
    }
}
