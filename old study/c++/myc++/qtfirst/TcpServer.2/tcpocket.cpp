#include "tcpsocket.h"

TcpSocket::TcpSocket(QObject *parent)
    :QTcpSocket(parent){
    QObject::connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    QObject::connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

TcpSocket::~TcpSocket(){

}

void TcpSocket::dataReceived(){
    while(bytesAvailable()>0){
        int length=bytesAvailable();
        char buff[1024];
        read(buff,length);
        QString msg=buff;
        emit sendClients(msg,length);//发送自定义信号
    }
}

void TcpSocket::slotDisconnected(){
    emit disconnected(this->socketDescriptor());
}


