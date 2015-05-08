#include "input.h"
#include "ui_input.h"
#include <QtSql>
#include <QMessageBox>
#include "database.h"

input::input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
}

input::~input()
{
    delete ui;
}

void input::on_btnOk_clicked()
{
    QString tempscore = QString::number(this->score, 10);//由int型转换成QString型
    QString tempname = ui->leName->text();//获取游戏玩家姓名
    QString id;

    if(!database::Open())
    {
        QMessageBox::about(this, "Message", "connect error");
        return ;
    }

    QSqlQuery query;
    query.exec("select max(ID) from list");//查找排行榜中最大ID
    if(!query.next())
    {
        return ;
    }
    else
    {
        id = QString::number(query.value(0).toInt() + 1);
    }

    if(sum < 5)//排行榜未满，直接进入排行榜
    {
        query.exec("insert into list values('"+id+"','"+tempname+"','"+tempscore+"')");
    }
    else if(sum >= 5)//排行榜已满
    {
        QString tempid;
        query.exec("select max(ID) from list group by Score having Score<=all(select min(Score) from list)");
        if(query.next())
        {
            tempid = query.value(0).toString();
        }
        query.exec("delete from list where ID="+tempid);//删除分数最低的
        query.exec("insert into list values('"+id+"','"+tempname+"','"+tempscore+"')");//插入排行榜
    }
    database::Close();
    this->close();
}

void input::on_btnQuit_clicked()
{
    this->close();
}
