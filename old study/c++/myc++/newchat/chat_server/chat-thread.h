#ifndef CHATTHREAD_H
#define CHATTHREAD_H
#include <QThread>
#include <QDebug>
#include "connect.h"
#define MAX_BUFFERSIZE 1024
class serverThread:public QThread
{
    Q_OBJECT
public:
    serverThread(quint32 threadfd,int sockfd,QObject *parent = NULL);
    ~serverThread();
    quint32 getThrdfd () const;
signals:
    void exiting (quint32 thrdfd);
protected:
    void run();
private slots:
    void sockDisconnected();
private:
    bool m_disconnected;
    quint32 thrdfd;
    int socketDescriptor;
    ConnectSocket *sock;
};


#endif // CHATTHREAD_H
