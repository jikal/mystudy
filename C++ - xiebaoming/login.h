#ifndef _LOGIN_H
#define _LOGIN_H

#include <QWidget>

namespace Ui {
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btnRegister_clicked();
    void on_btnLogin_clicked();
    void is_true();

private:
    Ui::Login *ui;
};

#endif
