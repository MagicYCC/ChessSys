#ifndef TRANSACTIONINFODIALOG_H
#define TRANSACTIONINFODIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

namespace Ui {
class TransactionInfoDialog;
}

class TransactionInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransactionInfoDialog(ChessSysUser* user, int transactionId, QWidget *parent = 0);
    ~TransactionInfoDialog();

    // 更新交易信息
    void updateInfo();

    // 获取商品交易信息字符串
    double accountSalesToString(int transactionId, QString& detail);
    // 获取房间信息字符串
    double chessRoomRecordToString(int transactionId, QString& detail);
    // 获取红利信息字符串
    double bonusRecordToString(int transactionId, QString& detail);

private slots:
    void on_sureButton_clicked();

private:
    Ui::TransactionInfoDialog *ui;
    ChessSysUser* _user;
    int _transactionId;
};

#endif // TRANSACTIONINFODIALOG_H
