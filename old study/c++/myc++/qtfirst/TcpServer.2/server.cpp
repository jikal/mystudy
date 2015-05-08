#include "server.h"

Server::Server(QObject *parent,int port) :
    QTcpServer(parent){
    listen(QHostAddress::Any,port);

}

void Server::incomingConnection(int socketDescriptor){
    TcpSocket *tcpSocket=new TcpSocket(this);
    QObject::connect(tcpSocket,SIGNAL(sendClients(QString,int)),this,SLOT(sendClients(QString,int)));

    tcpSocket->setSocketDescriptor(socketDescriptor);
    tcpSocketList.append(tcpSocket);
}

void Server::sendClients(QString msg, int length){
    emit updateServer(msg,length);//发送信号更新服务器contentListWidget
    for(int i=0;i<tcpSocketList.count();i++){
        QTcpSocket *item=tcpSocketList.at(i);//群发
        if(item->write(msg.toLatin1(),length)!=length){
            continue;
        }
    }
}

void Server::slotDisconnected(int descriptor){//程序退出删除套接字
    for(int i=0;i<tcpSocketList.count();i++){
        QTcpSocket *item=tcpSocketList.at(i);
        if(item->socketDescriptor()==descriptor){
            qDebug() << "tcpSocket is exiting" << descriptor << endl;
            tcpSocketList.removeAt(i);
            return;
        }
    }
    return;
}
