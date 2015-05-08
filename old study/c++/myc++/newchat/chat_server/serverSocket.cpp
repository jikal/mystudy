#include "serverSocket.h"
#include <assert.h>
quint32 ServerSocket::thrdfd  = 0;

ServerSocket::ServerSocket(QObject *parent)
    : QTcpServer(parent)
{
    threads.empty();
    mutex = new QMutex();
    assert(mutex != NULL);
}

ServerSocket::~ServerSocket()
{
    mutex->lock();
    threads.clear();
    mutex->unlock();
    delete mutex;
    mutex = NULL;
}
void ServerSocket::incomingConnection(int socketDescriptor)
{
    qDebug() << "ServerSocket ---- incoming connection " << socketDescriptor << endl;
    serverThread *thrd = new serverThread(thrdfd,socketDescriptor);
    connect(thrd, SIGNAL(exiting(quint32)),this,SLOT(thrdExiting(quint32)),Qt::DirectConnection);
    mutex->lock();
    threads.push_back(thrd);
    mutex->unlock();
    thrd->start();
}
void ServerSocket::thrdExiting(quint32 thrd_fd)
{
    qDebug() << "ServerSocket----thread is exiting!" << thrd_fd;
    mutex->lock();
    int count = threads.count();
    for(int i = 0;i < count;i++) {
        if(threads.at(i)->getThrdfd()==thrd_fd){
            threads.removeAt(i);
            break;
        }
    }
    mutex->unlock();
}
