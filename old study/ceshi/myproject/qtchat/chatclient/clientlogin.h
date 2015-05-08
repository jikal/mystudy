#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QWidget>

#include <QTcpSocket>
#include <QMessageBox>
#include "regusr.h"
#include "chat.h"
namespace Ui {
class clientlogin;
}

class clientlogin : public QWidget
{
    Q_OBJECT

public:
    explicit clientlogin(QTcpSocket *p,QWidget *parent = 0);
    ~clientlogin();

private slots:
    void on_regPushButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::clientlogin *ui;
    QTcpSocket *tcpsocket;
};

#endif // CLIENTLOGIN_H
