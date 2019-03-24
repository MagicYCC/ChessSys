#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "chess_sys_db/chess_sys_user.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(ChessSysUser *user, QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;

    ChessSysUser *_user;
};

#endif // LOGINDIALOG_H
