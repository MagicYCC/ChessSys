#ifndef STOCKMANAGEFORM_H
#define STOCKMANAGEFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class StockManageForm;
}

class StockManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit StockManageForm(ChessSysUser* user, QWidget *parent = 0);
    ~StockManageForm();

    void initStockTable();
    void updateStockInfo();

    void initRecordTable();
    void updateStockRecord();
    void setCommodityStatus(QString name, CommodityState status);
public:
    static const QString CommodityFieldName[];
    static const QString CommodityFieldAlias[];

    static const QString RecordFieldName[];
    static const QString RecordFieldAlias[];
private slots:
    void on_addStockButton_clicked();

    void on_addCommodityButton_clicked();

    void on_updateButton_clicked();

    void on_updateRecordButton_clicked();

    void on_cancelRecordButton_clicked();

    void on_activeButton_clicked();

    void on_forSaleButton_clicked();

    void on_changePriceButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::StockManageForm *ui;

    ChessSysUser* _user;
};

#endif // STOCKMANAGEFORM_H
