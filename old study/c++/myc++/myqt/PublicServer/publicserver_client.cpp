#include "publicserver_client.h"

publicserver_client::publicserver_client(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

void publicserver_client::dataReceived()
{
    QByteArray data;
    while(this->bytesAvailable()>0)
    {
        data = this->readAll();
    }

    QString ServerReciveFrom= QString::fromLocal8Bit(data);
    qDebug()<<"shujushi :"<<ServerReciveFrom<<endl;
    emit tellpublicserver_server(ServerReciveFrom);
}

void publicserver_client::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
