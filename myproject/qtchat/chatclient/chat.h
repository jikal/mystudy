#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include <QTcpSocket>
#include <QString>
namespace Ui {
class chat;
}

class chat : public QWidget
{
    Q_OBJECT
    
public:
    explicit chat(QString name,QTcpSocket *p, QWidget *parent = 0);
    ~chat();
    
private slots:
    void on_sendMessageButton_clicked();
    void messageReceived();
private:
    Ui::chat *ui;
    QTcpSocket *tcpsocket;
    QString m_name;
};

#endif // CHAT_H
