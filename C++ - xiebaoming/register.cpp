#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include <QtSql>
//#include <QSqlDatabase>
#include <QSqlQuery>
#include "database.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint);
}

Register::~Register()
{
    delete ui;
}

void Register::on_btnOk_clicked()
{
    QString username, passwd, confirmPasswd, sex, address, phoneNum, NiName;

    if(!database::Open())//打开数据库
    {
        QMessageBox::about(0, tr("错误"), tr("打开数据库失败"));
        return ;
    }

    if(!ui->leUsername->text().isEmpty())//判断帐号是否为空
    {
        username = ui->leUsername->text();
    }
    else
    {
        QMessageBox::about(0, tr("提示"), tr("用户名不能为空"));
        database::Close();
        return ;
    }

    if(!ui->lePasswd->text().isEmpty())//判断密码是否为空
    {
        passwd = ui->lePasswd->text();
    }
    else
    {
        QMessageBox::about(0, tr("提示"), tr("密码不能为空"));
        database::Close();
        return ;
    }

    if(!ui->leNiName->text().isEmpty())
    {
        NiName = ui->leNiName->text();
    }
    else
    {
        QMessageBox::about(0, tr("提示"), tr("昵称不能为空"));
        database::Close();
        return ;
    }

    if(!ui->leConfimPasswd->text().isEmpty())
    {
        confirmPasswd = ui->leConfimPasswd->text();
    }
    else
    {
        QMessageBox::about(0, tr("提示"), tr("确认密码不能为空"));
        database::Close();
        return ;
    }

    if(passwd.compare(confirmPasswd) != 0)
    {
        QMessageBox::about(0, tr("提示"), tr("确认密码与密码不同"));
        database::Close();
        return ;
    }

    if(!ui->cbxSex->currentText().isEmpty())
    {
        sex = ui->cbxSex->currentText();
    }

    if(!ui->leAddress->text().isEmpty())
    {
        address = ui->leAddress->text();
    }

    if(!ui->lePhoneNum->text().isEmpty())
    {
        phoneNum = ui->lePhoneNum->text();
    }

    QSqlQuery query;

    int id;
    query.exec("select max(ID) from user");
    if(!query.next())//在结果集中检索下一个记录，如果有效，定位查询在被检索的记录上。//执行完一个查询，可以用此函数来检索第一个记录。
    {
        return ;
    }
    id = query.value(0).toInt()+1;

    QString insertstr="insert into user(ID, userName, passwd, niName, sex, phone, address) \
            values('"+QString::number(id)+"','"+username+"','"+passwd+"','"+NiName+"','"+sex+"','"+phoneNum+"','"+address+"')";
    query.exec(insertstr);//执行sql语句;
    if(!query.isActive())//如果查询当前是处于一个活动的状态返回 TRUE，否则返回 FALSE //sql语句是否成功执行
    {
        QMessageBox::about(0, tr("结果"), tr("注册失败\n%1").arg(query.lastError().text()));
        database::Close();
        return ;
    }
    QMessageBox::about(0, tr("结果"), tr("注册成功"));
    database::Close();

    emit do_true();
    this->close();
}

void Register::on_btnQuit_clicked()
{
    emit do_true();
    this->close();
}

void Register::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->globalPos();
    }
}

void Register::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->move(this->pos() + (event->globalPos() - mLastMousePosition));
        mLastMousePosition = event->globalPos();
    }
}

void Register::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}
