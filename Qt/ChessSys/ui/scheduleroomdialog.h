#ifndef SCHEDULEROOMDIALOG_H
#define SCHEDULEROOMDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class ScheduleRoomDialog;
}

class ScheduleRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleRoomDialog(ChessSysUser* user, QString name, QWidget *parent = 0);
    ~ScheduleRoomDialog();

private slots:
    void on_sureButton_clicked();

private:
    Ui::ScheduleRoomDialog *ui;
    ChessSysUser* _user;
    QString _name;
};

#endif // SCHEDULEROOMDIALOG_H
