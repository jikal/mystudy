#include "topscore.h"
#include "ui_topscore.h"
#include <QtSql>
#include <QMessageBox>
#include "database.h"

topscore::topscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::topscore)
{
    ui->setupUi(this);
    if(!database::Open())
    {
        QMessageBox::about(this, "Message", "connect error");
        return ;
    }

    modelScore=new QSqlTableModel(this);
    modelScore->setTable("list");//设置链接的table
    modelScore->select();//查询table内容

    //设置modle的表头
    modelScore->setHeaderData(0, Qt::Horizontal, tr("ID"));
    modelScore->setHeaderData(1, Qt::Horizontal, tr("Name"));
    modelScore->setHeaderData(2, Qt::Horizontal, tr("Score"));
    ui->tvList->setModel(modelScore);//给tvList设置modle
    ui->tvList->sortByColumn(2);//设置tvList按第三列排序
    ui->tvList->horizontalHeader()->setResizeMode(QHeaderView::Stretch);//使列完全填充并平分
    database::Close();
}

topscore::~topscore()
{
    delete ui;
}
