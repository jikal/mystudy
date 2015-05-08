#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "database.h"
#include "widget.h"
#include "register.h"
#include <QString>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    if(!database::Open())//打开数据库
    {
        QMessageBox::about(this, tr("错误！"), tr("打开数据库失败\n%1"));
        return ;
    }

    QSqlQuery query;
    query.exec("select niName from user where userName='"+ui->leUsername->text()+"' AND passwd='"+ui->lePasswd->text()+"'");
    /*
    query.exec("select * from user where userName='"+ui->leUsername->text()+"' AND passwd='"+ui->lePasswd->text()+"'");
    if(!query.isActive())//sql语句是否成功执行
    {   //arg为返回后面文本的一个副本,%1表示输出的内容按照第1个.arg后面的输出
        QMessageBox::about(0, tr("结果"), tr("\n登录失败\n%1").arg(query.lastError().text()));
        return ;
    }
    */
    QString ni_name;
    if(!query.next())
    {
        return ;
    }
    else
    {
        ni_name = query.value(0).toString();
    }
    if(query.size() == 0)//没有注册过的用户
    {
        QMessageBox::about(0, tr("结果"), tr("\n登录失败\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    database::Close();

    Widget *w = new Widget;
    //w->SetName(ui->leUsername->text());//广播新用户登录
    //w->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    //w->setWindowFlags(Qt::WindowCloseButtonHint);
    w->SetName(ni_name);//广播新用户登录
    w->show();
    this->close();
}

//打开注册界面
void Login::on_btnRegister_clicked()
{
    Register *reg = new Register(this);
    reg->show();
    connect(reg, SIGNAL(do_true()), this, SLOT(is_true()));
    ui->btnLogin->setEnabled(false);//设置登录按钮不可用
    ui->btnRegister->setEnabled(false);//设置注册按钮不可用
}

void Login::is_true()
{
    ui->btnLogin->setEnabled(true);//设置登录按钮可用
    ui->btnRegister->setEnabled(true);//设置注册按钮可用
}
