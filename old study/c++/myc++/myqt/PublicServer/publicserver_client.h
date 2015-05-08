#ifndef PUBLICSERVER_CLIENT_H
#define PUBLICSERVER_CLIENT_H
#include <QTcpSocket>
#include <QWidget>
#include "mainwindow.h"
class publicserver_client : public QTcpSocket
{
    Q_OBJECT
public:
    publicserver_client(QObject *parent=0);
    QString getRandTicketId();

    void splitRequest(QString &,QString &);
signals:
    void updateClients(QString,int);    //
    void disconnected(int);             //
    void tellpublicserver_server(QString);
protected slots:
    void dataReceived();
    void slotDisconnected();
};

#endif // PUBLICSERVER_CLIENT_H
