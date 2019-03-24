#ifndef TRANSACTIONEDITDIALOG_H
#define TRANSACTIONEDITDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class TransactionEditDialog;
}

class TransactionEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionEditDialog(ChessSysUser* user, int transactionId, QWidget *parent = 0);
    ~TransactionEditDialog();

    // 初始化房间信息Table
    void initRoomTable();
    // 初始化商品信息Table
    void initCommodityTable();
    // 初始化红利信息Table
    void initBonusTable();
    // 更新房间信息
    void updateRoomInfo();
    // 更新商品信息
    void updateCommodityInfo();
    // 更新红利信息
    void updateBonusInfo();

public:
    static const QString RoomFieldAlias[];
    static const QString CommodityFieldAlias[];
    static const QString BonusFieldAlias[];

private slots:
    void on_commodityDeleteButton_clicked();

    void on_roomUpdateButton_clicked();

    void on_commodityUpdateButton_clicked();

    void on_bonusUpdateButton_clicked();

private:
    Ui::TransactionEditDialog *ui;
    ChessSysUser* _user;
    int _transactionId;
};

#endif // TRANSACTIONEDITDIALOG_H
