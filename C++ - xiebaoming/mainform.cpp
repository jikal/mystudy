#include "mainform.h"
#include "ui_mainform.h"
#include "topscore.h"
#include "input.h"
#include <QtGui/QApplication>
#include <QMessageBox>
#include <QtSql>
#include "database.h"

mainform::mainform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainform)
{
    ui->setupUi(this);
    this->score = 0;
    this->resize(600, 440);
    this->gameArea = new gamearea(this);
    this->timer = new QTimer(this);
    this->gameArea->setmovespeed(200);
    connect(this->timer, SIGNAL(timeout()), this, SLOT(timer_upDate()));
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
}

mainform::~mainform()
{
//    emit game_able();
    delete ui;
}

//方块下移一步，并做出相应判断//定时器溢出处理
void mainform::timer_upDate()
{
    this->gameArea->moveOneStep();//方块下坠一步//游戏地图上还未显示出来
    if(this->gameArea->isMoveEnd())//判断方块是否到底，无法再移动
    {
        if(this->gameArea->isGame_Over())//判断游戏是否结束
        {
            this->timer->stop();
            QMessageBox::warning(this, tr("warning"), tr("Game Over!"), QMessageBox::Yes);//对话框
            ui->btnStart->setEnabled(true);//设置按钮可用
            ui->btnList->setEnabled(true);
            ui->btnSlowDown->setEnabled(true);
            ui->btnSpeedUp->setEnabled(true);
            ui->btnClose->setEnabled(true);

            int minscore = 0;//排行榜最低分
            int count = 0;//排行榜记录条数
            if(!database::Open())
            {
                QMessageBox::about(this, "Message", "connect error");
                return ;
            }
            QSqlQuery query;
            query.exec("select min(Score) from list");//查找排行榜中最低分
            while(query.next())
            {
                minscore = query.value(0).toInt();
            }
            query.exec("select count(*) from list");//查找排行榜中记录条数
            while(query.next())
            {
                count = query.value(0).toInt();
            }
            database::Close();

            if(num>minscore || count<5)//进入排行榜
            {
                input onrank;
                onrank.score = num;
                onrank.sum = count;
                onrank.show();
                onrank.exec();
            }
            else//没进入排行榜
            {
                QMessageBox::warning(this, tr("warning"), tr("So sorry"), QMessageBox::Yes);
            }
            ui->lb_score->setText("0");//界面显示的分数归0
            this->gameArea->setscore(0);//游戏得分归0
            //this->gameArea->init_Game();
            //this->gameArea->gameStart();
            //this->timer->start(this->gameArea->getmovespeed());
        }
        else
        {
            this->gameArea->nextItem();//随机产生下一个方块
            num = this->gameArea->getscore();//计算游戏得分
            QString final_score = QString::number(num, 10);//由10进制int型转换成QString型
            ui->lb_score->setText(final_score);//显示游戏所得分数
            this->gameArea->gameStart();//重新开始游戏
        }
    }
    else
    {
        this->gameArea->do_MoveNext();//更新游戏界面//方块下移一格后的界面
    }
}

void mainform::on_btnStart_clicked()
{
    this->gameArea->init_Game();//游戏初始化
    this->gameArea->gameStart();//开始游戏
    this->timer->start(this->gameArea->getmovespeed());//设置游戏难度
    this->gameArea->setFocus();//设置焦点
    ui->btnStart->setEnabled(false);//设置按钮不可用
    ui->btnList->setEnabled(false);
    ui->btnSlowDown->setEnabled(false);
    ui->btnSpeedUp->setEnabled(false);
    ui->btnClose->setEnabled(false);
}

void mainform::on_btnList_clicked()
{
    topscore diag;
    diag.show();//显示排行榜
    diag.exec();
}

void mainform::on_btnSlowDown_clicked()
{
    this->gameArea->setmovespeed(500);//设置下坠物移动速度为500
}

void mainform::on_btnSpeedUp_clicked()
{
    this->gameArea->setmovespeed(100);//设置下坠物移动速度为100
}

void mainform::on_btnClose_clicked()
{
    emit game_able();
    this->close();
}

void mainform::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPainterPath path;
    path.addRoundRect(this->rect(), 17); //圆角设置
    painter.fillPath(path, QColor(92, 155, 203, 100));//半透明背景
}
