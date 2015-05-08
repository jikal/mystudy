#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QString>
#include <QTcpSocket>
#include <QMessageBox>
#include <QtNetwork>
#include <QTcpServer>
#include <QDebug>
#include <QTcpSocket>
#include <QThread>
#include "clientlogin.h"
namespace Ui {
class chatClient;
}

class chatClient : public QWidget
{
    Q_OBJECT

public:
    explicit chatClient(QWidget *parent = 0);
    ~chatClient();

private slots:
    void enterChatroomButton();
    void displayError(QAbstractSocket::SocketError);
private:
    Ui::chatClient *ui;
    QTcpSocket *tcpsocket;
};

#endif // CHATCLIENT_H
