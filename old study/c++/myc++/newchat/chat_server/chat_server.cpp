#include "chat_server.h"
#include "ui_chat_server.h"
chat_Server::chat_Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat_Server)
{
    ui->setupUi(this);
    serversocket = new ServerSocket(this);
    QObject::connect(ui->serverCreateButton,SIGNAL(clicked()),this,SLOT(startServer()),Qt::DirectConnection);//启动服务器
}

chat_Server::~chat_Server()
{
    delete ui;
}
void chat_Server::startServer()
{
    qDebug() << "listening..." << endl;
    QString port = ui->serverPort_line->text();
    if(!serversocket->listen(QHostAddress::Any, port.toShort())){
            qDebug()<<serversocket->errorString();
            close();
            return;
    }
}


