#ifndef COMMODITYADDDIALOG_H
#define COMMODITYADDDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class CommodityAddDialog;
}

class CommodityAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommodityAddDialog(ChessSysUser *user, QWidget *parent = 0);
    ~CommodityAddDialog();

    void updateCategory();
    void clearInput();

private slots:
    void on_clearButton_clicked();

    void on_categoryAddButton_clicked();

    void on_updateCategoryButton_clicked();

    void on_sureButton_clicked();

private:
    Ui::CommodityAddDialog *ui;
    ChessSysUser *_user;
};

#endif // COMMODITYADDDIALOG_H
