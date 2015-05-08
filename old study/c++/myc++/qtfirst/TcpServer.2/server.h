#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "tcpsocket.h"
#include <QList>
#include <QHostAddress>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0,int port=0);
    QList<TcpSocket *> tcpSocketList;
    
signals:
    void updateServer(QString,int);
public slots:
    void sendClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
