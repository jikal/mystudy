#include <QMessageBox>
#include <QHostInfo>
#include <tcpclient.h>
#include "ui_tcpclient.h"
#include <QDebug>
#include <QTextStream>

TcpClient::TcpClient(QWidget *parent)
    :QMainWindow(parent),ui(new Ui::TcpClient){
    ui->setupUi(this);
    status=0;
}

TcpClient::~TcpClient(){

}

void TcpClient::slotDisconnected(){
    this->tcpSocket->close();
    ui->entryButton->setText(tr("进入聊天室"));
}

void TcpClient::slotConnected(){
    int length=0;
    ui->sendButton->setEnabled(true);
    ui->entryButton->setText(tr("Leave"));

    QString msg=Name+tr(":Enter Chat Room");

    if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
        return;
    }
}
void TcpClient::dataReceived(){//收到数据处理
    while(tcpSocket->bytesAvailable()>0){
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        QHostAddress sender;
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ui->contentListWidget->addItem(msg.left(datagram.size()));
    }
}


void TcpClient::on_sendButton_clicked()
{
    if(ui->sendLineEdit->text()==""){
        return;
    }
    QString msg=Name+":"+ui->sendLineEdit->text();
    tcpSocket->write(msg.toLatin1(),msg.length());

    ui->sendLineEdit->clear();
}

void TcpClient::on_entryButton_clicked()
{
    if(!status){
        QString ip=ui->serverIpLineEdit->text();
        port=ui->portLineEdit->text().toInt();
        if(ui->usrLineEdit->text()==""){
            QMessageBox::information(this,tr("error"),tr("usr name error!"));
            return;
        }
        Name=ui->usrLineEdit->text();

        tcpSocket=new QTcpSocket(this);
        QObject::connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        QObject::connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        QObject::connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

        tcpSocket->abort();
        tcpSocket->connectToHost(ip,port);//发送connect信号
        status=true;

    }else{
        int length=0;
        QString msg=Name+tr(":Leave Chat Room");

        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
            return;
        }
        tcpSocket->disconnectFromHost();
        status=false;
    }

}
