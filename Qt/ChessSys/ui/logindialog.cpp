#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    ui->passwordEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    _user->setName(ui->userEdit->text());
    _user->setPassword(ui->passwordEdit->text());

    if(_user->login() < 0){
        QMessageBox::warning(this, "警告", "用户名或密码不正确！");
        return;
    }

//    QMessageBox::information(this, "通知", "登录成功！");
    close();
}
