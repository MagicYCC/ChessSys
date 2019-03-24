#ifndef STOCKADDDIALOG_H
#define STOCKADDDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class StockAddDialog;
}

class StockAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StockAddDialog(ChessSysUser* user, QWidget *parent = 0);
    ~StockAddDialog();

    void updateCommodityInfo();

private slots:
    void on_sureButton_clicked();

private:
    Ui::StockAddDialog *ui;
    ChessSysUser* _user;
};

#endif // STOCKADDDIALOG_H
