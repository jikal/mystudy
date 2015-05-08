#ifndef REGUSR_H
#define REGUSR_H

#include <QWidget>

#include <QTcpSocket>
#include <QString>
namespace Ui {
class regusr;
}

class regusr : public QWidget
{
    Q_OBJECT
public:
    explicit regusr (QTcpSocket *p, QWidget *parent = 0);
    ~regusr();
private slots:
    void on_regButton_clicked();
    void dataReceived();

private:
    Ui::regusr *ui;
    QTcpSocket *tcpsocket;
};


#endif // REGUSR_H
