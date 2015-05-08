#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <mysql/mysql.h>
//#include "server_common.h"
class TcpSocket:public QTcpSocket{
    Q_OBJECT
public:
    TcpSocket(QObject *parent=0);
    void regUsersql(QString strname,QString strpass);
    void loginUsersql(QString strname,QString strpass);
    void createUsersql();
    ~TcpSocket();
signals:
    void sendClients(QString,int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
protected:
    void requestRegusr(QString);
    void requestLoginusr(QString);
    void requestSendmessage(QString);
private:
    QList<QString>usr;
    bool ok;
    QSqlDatabase db;
};

#endif // TCPSOCKET_H
