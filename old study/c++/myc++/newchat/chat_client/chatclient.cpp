#include "chatclient.h"
#include "ui_chatclient.h"

chatClient::chatClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatClient)
{
    ui->setupUi(this);

    QObject::connect(ui->enterChatroomButton,SIGNAL(clicked()),this,SLOT(enterChatroomButton()),Qt::DirectConnection);
}

chatClient::~chatClient()
{
    delete ui;
}

void chatClient::enterChatroomButton()
{
    tcpsocket=new QTcpSocket(this);
    QString ip = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();
    tcpsocket->abort();
    tcpsocket->connectToHost(ip,port.toShort());
    QObject::connect(tcpsocket,SIGNAL(error(QAbstractSocket::SocketError)),
             this,SLOT(displayError(QAbstractSocket::SocketError)));
    qDebug() << "connecting";
    clientlogin *login = new clientlogin(tcpsocket);
    login->show();
}

void chatClient::displayError(QAbstractSocket::SocketError){

    qDebug()<<tcpsocket->errorString();
    tcpsocket->close();
}


