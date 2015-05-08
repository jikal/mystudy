#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMessageBox>
namespace Ui {
class TcpClient;
}

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();
public slots:
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
private slots:
    void on_sendButton_clicked();
    void on_entryButton_clicked();
private:
    Ui::TcpClient *ui;
    bool status;
    int port;
    QHostAddress *Ip;
    QString Name;
    QTcpSocket *tcpSocket;
};

#endif // TCPCLIENT_H
