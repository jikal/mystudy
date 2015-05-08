#include "connect.h"

ConnectSocket::ConnectSocket( QObject *parent /* = NULL */ )
    : QTcpSocket(parent)
{
    connect( this, SIGNAL(readyRead()), this, SLOT(readMessage()));
    connect( this, SIGNAL(disconnected()), this, SLOT(deleteLater()));
}

void ConnectSocket::readMessage()
{
  if((bytesAvailable())<MESSAGE_LEN)
       return;
    MESSAGE msg = {MT_NULL,0};
    readData((char*)&msg,MESSAGE_LEN);
    switch(msg.msgtype){
        case REGUSR:
        qDebug() << "1";
            requestRegusr();
            break;
        case LOGINUSR:
            requestLoginusr();
            break;
        case SENDMESSAGE:
            requestSendmessage();
            break;
        default:
            printf( "ConnectSocket: receive something unknown !\n" );
            return;
    }
}

void ConnectSocket::sendData(const char *data, qint32 len )
{
    if( NULL == data || len <= 0 )
        return;

    qint32 len_sended = 0;
    while( len > 0 ) {
        qint32 len_send = writeData(data + len_sended,len) ;
        if( len_send <= 0 ) {
            printf( "ConnectSocket: send data failed !\n" );
            emit closing(socketDescriptor());
            close();
        }
        len_sended += len_send;
        len -= len_send;
    }

    waitForBytesWritten();
}

void ConnectSocket::requestRegusr()
{
    MESSAGE msg1 = {MT_NULL,0};
    qDebug() << "1";
    msg1.msgtype = REGUSR;
    sendData((char *)&msg1,MESSAGE_LEN);
}

void ConnectSocket::requestLoginusr()
{
}

void ConnectSocket::requestSendmessage()
{
}
