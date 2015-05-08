#include "chat-thread.h"


serverThread::serverThread( quint32 thrdfd, int sockfd, QObject *parent)
    : QThread(parent),m_disconnected(true),thrdfd(thrdfd),socketDescriptor(sockfd)
{

}

serverThread::~serverThread()
{
}

void serverThread::run()
{
    sock = new ConnectSocket();
    sock->setSocketDescriptor(socketDescriptor);//返回套接字符（socket）
    m_disconnected = false;
    connect(sock,SIGNAL(disconnected()),sock, SLOT(deleteLater()));
    connect(sock,SIGNAL(disconnected()),this, SLOT(sockDisconnected()));
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
    qDebug()<<"Thread thread start running "<< thrdfd <<endl;
    exec();
}
void serverThread::sockDisconnected()
{
    qDebug() << "Thread connect socket disconnected !\n" << thrdfd << socketDescriptor <<endl;
    emit exiting(thrdfd);
    exit();
}
quint32 serverThread::getThrdfd () const{
    return thrdfd;
}
