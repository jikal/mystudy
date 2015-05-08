#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
#include <QWidget>
#include <QMutex>
#include <QList>
#include <QTcpServer>
#include <QDebug>
#include <QHostAddress>
#include <QMessageBox>
#include <QtNetwork>
#include <QTcpSocket>
#include "chat-thread.h"
class ServerSocket : public QTcpServer
{
    Q_OBJECT
public:
    ServerSocket(QObject *parent = NULL );
    ~ServerSocket();
protected:
    void incomingConnection(int socketDescriptor);
private slots:
    void thrdExiting(quint32 thrdfd);//线程退出
private:
    QMutex *mutex;
    QList<serverThread*>threads;
    static quint32 thrdfd;
};
#endif // SERVERSOCKET_H
