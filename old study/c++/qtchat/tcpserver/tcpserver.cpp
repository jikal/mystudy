#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);

}

TcpServer::~TcpServer()
{
    delete ui;
}
//服务器端显示消息
void TcpServer::updateServer(QString msg, int length){
    ui->messagTextEdit->append(msg.left(length));
}
//开启服务器
void TcpServer::on_pushButton_clicked()
{
    port = ui->portLineEdit->text().toShort();
    server=new Server(this,port);
    QObject::connect(server,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    ui->pushButton->setEnabled(false);
}
