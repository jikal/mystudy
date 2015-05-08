#ifndef PUBLICSERVER_H
#define PUBLICSERVER_H

#include <QWidget>
#include "mainwindow.h"
#include "publicserver_server.h"
#include <QTcpServer>
class MainWindow;
class publicserver_server;
class publicserver : public QWidget
{
    Q_OBJECT
public:
    publicserver(MainWindow *Pmainwin);
    MainWindow *_Pmainwin;
    int port;
    QString strPort;
    publicserver_server *server;
    void creatServer();
signals:

public slots:
    void updateServer(QString,int);
    void reviceTell(QString);
};
#endif // PUBLICSERVER_H
