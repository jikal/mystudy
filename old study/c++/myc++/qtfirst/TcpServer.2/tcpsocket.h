#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>
#include <QObject>
#include <QString>
#include "server_common.h"
class TcpSocket:public QTcpSocket{
    Q_OBJECT
public:
    TcpSocket(QObject *parent=0);
    ~TcpSocket();
signals:
    void sendClients(QString,int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();
protected:
    void requestRegusr();
    void requestLoginusr();
    void requestSendmessage();
};

#endif // TCPCLIENTSOCKET_H
