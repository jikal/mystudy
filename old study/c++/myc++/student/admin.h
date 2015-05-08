#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>

namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT
    
public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::admin *ui;
    QString name;
    QString pass;
    //QList<QString> stu;
};

#endif // ADMIN_H
