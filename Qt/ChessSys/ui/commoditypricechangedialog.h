#ifndef COMMODITYPRICECHANGEDIALOG_H
#define COMMODITYPRICECHANGEDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class CommodityPriceChangeDialog;
}

class CommodityPriceChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommodityPriceChangeDialog(ChessSysUser* user, QString name, QWidget *parent = 0);
    ~CommodityPriceChangeDialog();

private slots:
    void on_sureButton_clicked();

private:
    Ui::CommodityPriceChangeDialog *ui;
    ChessSysUser* _user;
    QString _name;
};

#endif // COMMODITYPRICECHANGEDIALOG_H
