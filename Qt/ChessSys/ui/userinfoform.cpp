#include "userinfoform.h"
#include "ui_userinfoform.h"
#include "usercreatedialog.h"
#include <QMessageBox>

UserInfoForm::UserInfoForm(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::UserInfoForm)
{
    ui->setupUi(this);

    this->setWindowTitle("用户信息");

    // 显示用户信息
    ui->nameEdit->setText(_user->getName());
    ui->levelEdit->setText(_user->getLevelName());

    // 设置密码模式
    ui->oldPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->newPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);

}

UserInfoForm::~UserInfoForm()
{
    delete ui;
}

// 修改密码
void UserInfoForm::on_sureButton_clicked()
{
    QString newPwd = ui->newPasswordEdit->text();
    QString confirmPwd = ui->confirmPasswordEdit->text();
    if(newPwd != confirmPwd){
        QMessageBox::warning(this, "警告", "两次输入的新密码不一致！");
        return;
    }

    QString oldPwd = ui->oldPasswordEdit->text();
    int ret = _user->changePassword(newPwd, oldPwd);
    if(ret == -101){
        QMessageBox::warning(this, "警告", "旧密码错误！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "新旧密码一致！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库通信异常！");
        return;
    }
    QMessageBox::information(this, "通知", "密码修改成功！");

    // 清除密码输入
    ui->newPasswordEdit->clear();
    ui->confirmPasswordEdit->clear();
    ui->oldPasswordEdit->clear();
}

void UserInfoForm::on_createUserButton_clicked()
{
    if(_user->getLevel() != SysAdmin){
        QMessageBox::warning(this, "警告", "只有系统管理员有权创建用户！");
        return;
    }

    // 弹出创建用户对话框
    UserCreateDialog ucd(_user);
    ucd.exec();
}
