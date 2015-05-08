#ifndef _INPUT_H
#define _INPUT_H

#include <QDialog>

namespace Ui {
    class input;
}

class input : public QDialog
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = 0);
    ~input();
    int score;//玩家所得分数
    int sum;//排行榜记录条数

private:
    Ui::input *ui;

private slots:
    void on_btnQuit_clicked();//取消
    void on_btnOk_clicked();//进入排行榜
};

#endif
