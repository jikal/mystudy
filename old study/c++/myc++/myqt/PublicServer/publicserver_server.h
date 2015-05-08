#ifndef PUBLICSERVER_SERVER_H
#define PUBLICSERVER_SERVER_H
#include "mainwindow.h"
#include <QWidget>
#include "publicserver_client.h"
#include <QTcpServer>
class publicserver_client;
class publicserver_server : public QTcpServer
{
    Q_OBJECT
public:
    publicserver_server(QWidget *parent=0,int port=0);
    QList<publicserver_client*> tcpClientSocketList;
signals:
    void updateServer(QString,int);
    void tellpublicserver_sig(QString);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
    void tellpublicserver(QString);
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // PUBLICSERVER_SERVER_H
