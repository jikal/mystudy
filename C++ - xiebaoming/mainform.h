#ifndef _MAINFORM_H
#define _MAINFORM_H

#include <QWidget>
#include "gamearea.h"
//#include <time.h>
#include <QTime>

namespace Ui {
    class mainform;
}

class mainform : public QWidget
{
    Q_OBJECT

public:
    explicit mainform(QWidget *parent = 0);
    ~mainform();
    int score;//界面显示分数

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::mainform *ui;
    gamearea *gameArea;//游戏界面
    QTimer *timer;//定时器
    int num;//游戏所得分数

private slots:
    void on_btnSpeedUp_clicked();
    void on_btnSlowDown_clicked();
    void on_btnList_clicked();
    void on_btnStart_clicked();
    void timer_upDate();//方块下移，并作相应判断
    void on_btnClose_clicked();

signals:
    void game_able();
};

#endif
