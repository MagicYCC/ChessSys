#ifndef SALEMANAGEFORM_H
#define SALEMANAGEFORM_H

#include <QWidget>
#include <QTableWidgetItem>
#include "chess_sys_user.h"

namespace Ui {
class SaleManageForm;
}

class SaleManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit SaleManageForm(ChessSysUser* user, QWidget *parent = 0);
    ~SaleManageForm();

    // 更新交易信息
    void initTransactionsTable();
    void updateTransactionsInfo();

    // 更新销售信息
    void initSalesTable();
    void updateSalesInfo();

protected:
    static const QString TransactionFieldAlias[];
    static const QString SaleFieldAlias[];
private slots:
    void on_updateTransactionButton_clicked();

    void on_updateSalesButton_clicked();

    void on_saleButton_clicked();

    void on_deleteSaleButton_clicked();

    void on_deleteTransactionButton_clicked();

    void on_transactionTable_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::SaleManageForm *ui;

    ChessSysUser* _user;
};

#endif // SALEMANAGEFORM_H
