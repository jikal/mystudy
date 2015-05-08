#ifndef _TOPSCORE_H
#define _TOPSCORE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
    class topscore;
}

class topscore : public QDialog
{
    Q_OBJECT

public:
    explicit topscore(QWidget *parent = 0);
    ~topscore();
    QSqlTableModel * modelScore;//声明modelScore操作数据库表的类

private:
    Ui::topscore *ui;
};

#endif
