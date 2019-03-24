#ifndef COMMODITYSALEDIALOG_H
#define COMMODITYSALEDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class CommoditySaleDialog;
}

class CommoditySaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommoditySaleDialog(ChessSysUser* user, int transactionId, QWidget *parent = 0);
    virtual ~CommoditySaleDialog();

    virtual void updateCommodityTable();
    virtual void initCommodityTable();
    virtual void updateBudget();
    virtual void sureTransaction();



private slots:
    void on_updateCommodityButton_clicked();

    void on_updateBudgetButton_clicked();

    void on_sureButton_clicked();

public:
    static const QString CommodityFieldAlias[];

private:

protected:
    Ui::CommoditySaleDialog *ui;
    ChessSysUser* _user;
    int _transactionId;
};

#endif // COMMODITYSALEDIALOG_H
