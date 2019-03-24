#ifndef USERINFOFORM_H
#define USERINFOFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class UserInfoForm;
}

class UserInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoForm(ChessSysUser* user, QWidget *parent = 0);
    ~UserInfoForm();

private slots:
    void on_sureButton_clicked();

    void on_createUserButton_clicked();

private:
    Ui::UserInfoForm *ui;
    ChessSysUser* _user;
};

#endif // USERINFOFORM_H
