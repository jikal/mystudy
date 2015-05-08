#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include "server.h"
#include <QDebug>
namespace Ui {
class TcpServer;
}

class TcpServer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();
public slots:
    void updateServer(QString,int);
private slots:
    void on_pushButton_clicked();
private:
    Ui::TcpServer *ui;
    Server *server;
    int port;
};

#endif // TCPSERVER_H
