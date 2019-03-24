#ifndef COMMODITYCATEGORYADDDIALOG_H
#define COMMODITYCATEGORYADDDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class CommodityCategoryAddDialog;
}

class CommodityCategoryAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommodityCategoryAddDialog(ChessSysUser *user, QWidget *parent = 0);
    ~CommodityCategoryAddDialog();

private slots:
    void on_sureButton_clicked();

private:
    Ui::CommodityCategoryAddDialog *ui;
    ChessSysUser *_user;
};

#endif // COMMODITYCATEGORYADDDIALOG_H
