#ifndef FORM1_H
#define FORM1_H

#include <QWidget>

namespace Ui {
class form1;
}

class form1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit form1(QWidget *parent = 0);
    ~form1();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::form1 *ui;
    QList<QString> stu;
};

#endif // FORM1_H
