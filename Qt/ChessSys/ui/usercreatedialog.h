#ifndef USERCREATEDIALOG_H
#define USERCREATEDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class UserCreateDialog;
}

class UserCreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserCreateDialog(ChessSysUser* user, QWidget *parent = 0);
    ~UserCreateDialog();

    // 更新用户界别信息
    void updateLevelInfo();

private slots:
    void on_sureButton_clicked();

private:
    Ui::UserCreateDialog *ui;
    ChessSysUser* _user;
};

#endif // USERCREATEDIALOG_H
