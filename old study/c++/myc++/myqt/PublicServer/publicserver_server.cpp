#include "publicserver_server.h"
publicserver_server::publicserver_server(QWidget *parent,int port)
    :QTcpServer(parent)
{
    listen(QHostAddress::Any,port);//只要建立server实例，就会实施监听
}

void publicserver_server::incomingConnection(int socketDescriptor)
{
    publicserver_client *tcpClientSocket=new publicserver_client(this);
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(tellpublicserver_server(QString)),this,SLOT(tellpublicserver(QString)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));

    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpClientSocketList.append(tcpClientSocket);
}

void publicserver_server::updateClients(QString msg,int length)
{
    emit updateServer(msg,length);
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }
}

void publicserver_server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
void publicserver_server::tellpublicserver(QString ServerReciveFrom)
{
    emit tellpublicserver_sig(ServerReciveFrom);
    return;
}

