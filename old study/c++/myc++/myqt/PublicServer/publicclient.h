#ifndef PUBLICCLIENT_H
#define PUBLICCLIENT_H

#include <QWidget>
#include "mainwindow.h"
class MainWindow;
class QHostAddress;
class QTcpSocket;
class publicclient : public QWidget
{
    Q_OBJECT
public:
    publicclient(MainWindow *Pmainwin);
    ~publicclient();
    void clientSendto();

    QHostAddress *serverIP;
    QTcpSocket *tcpSocket;
    MainWindow *_Pmainwin;
signals:

public slots:
    void clientrecvFrom();
};

#endif // PUBLICCLIENT_H
