#include "chat.h"
#include "ui_chat.h"

chat::chat(QString name,QTcpSocket *p,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat)
{
    m_name = name;
    tcpsocket = p;
    ui->setupUi(this);
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(messageReceived()));
}

chat::~chat()
{
    delete ui;
}

void chat::on_sendMessageButton_clicked()
{
    QString type = "3";
    //QString name = ui->idLineEdit->text();
    QString str1 = ui->sendMessageLineEdit->text();
    QString msg = type + m_name + ":" + str1;
    int len = msg.length();
    tcpsocket->write(msg.toLatin1());
    ui->messageTextEdit->append(msg.right(len-1));
    ui->sendMessageLineEdit->clear();
    //connect(tcpsocket,SIGNAL(readyread()),this,SLOT(messageReceived()));
}

void chat::messageReceived(){
    QString str = tcpsocket->readAll();
    ui->messageTextEdit->append(str);
}
