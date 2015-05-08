#ifndef _REGISTER_H
#define _REGISTER_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
    class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private:
    Ui::Register *ui;

private slots:
    void on_btnQuit_clicked();
    void on_btnOk_clicked();

signals:
    void do_true();

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    QPoint mLastMousePosition;
    bool mMoving;
};

#endif
