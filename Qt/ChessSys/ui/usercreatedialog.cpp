#include "usercreatedialog.h"
#include "ui_usercreatedialog.h"
#include <QMessageBox>
#include <QSqlQuery>

UserCreateDialog::UserCreateDialog(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::UserCreateDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("创建用户");

    // 设置密码模式
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPwdEdit->setEchoMode(QLineEdit::Password);

    // 更新用户界别信息
    updateLevelInfo();
}

UserCreateDialog::~UserCreateDialog()
{
    delete ui;
}

// 更新用户界别信息
void UserCreateDialog::updateLevelInfo(){

    ui->levelCombo->setCurrentIndex(0);

    // 获取用户级别信息
    QString sql;
    sql = "select name from userlevel;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return;
    }
    while(query->next()){
        QString name = query->value("name").toString();
        ui->levelCombo->addItem(name);
    }

}

void UserCreateDialog::on_sureButton_clicked()
{
    QString name = ui->nameEdit->text();
    if(name == ""){
        QMessageBox::warning(this, "警告", "用户名不可为空！");
        return;
    }

    QString newPwd = ui->pwdEdit->text();
    QString confirmPwd = ui->confirmPwdEdit->text();
    if(newPwd != confirmPwd){
        QMessageBox::warning(this, "警告", "两次输入的新密码不一致！");
        return;
    }

    QString levelName = ui->levelCombo->currentText();

    // 获取用户级别信息
    QString sql;
    QString sqlLevelName = levelName==""?"NULL":("'"+levelName+"'");
    sql = "select level from userlevel where name = " +
            sqlLevelName + ";";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return;
    }
    if(!query->next()){
        QMessageBox::warning(this, "警告", "级别不存在！");
        return;
    }
    int level = query->value("level").toInt();

    int ret = _user->createUser(name, newPwd, (ChessSysUserLevel) level);
    if(ret == -101){
        // 用户已经存在
        QMessageBox::warning(this, "警告", "用户已经存在！");
        return;
    } else if(ret == -104){
        QMessageBox::warning(this, "警告", "不可创建游客级别用户！");
        return;
    }
    if(ret <= -102){
        QMessageBox::warning(this, "警告", "当前用户无权新建用户！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库异常！");
        return;
    }
    QMessageBox::information(this, "通知", levelName +
                             " " + name + " 创建成功！");
    close();
}
