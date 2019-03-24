#ifndef SCHEDULETRANSACTIONDIALOG_H
#define SCHEDULETRANSACTIONDIALOG_H

#include <QDialog>
#include "chess_sys_user.h"

#define SURE_TRANSACTION 101
#define CANCEL_TRANSACTION 102

namespace Ui {
class ScheduleTransactionDialog;
}

class ScheduleTransactionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleTransactionDialog(ChessSysUser* user, int transactionId, QWidget *parent = 0);
    ~ScheduleTransactionDialog();

    void updateTransactionInfo();

    // 获取商品交易信息字符串
    double accountSalesToString(int transactionId, QString& detail);
    // 获取房间信息字符串
    double chessRoomRecordToString(int transactionId, QString& detail);

private slots:
    void on_updateButton_clicked();

    void on_sureButton_clicked();

    void on_cancelTransactionButton_clicked();

    void on_detailButton_clicked();


    void on_amoutEdit_textEdited(const QString &arg1);

    void on_bonusEdit_textEdited(const QString &arg1);

public:

private:
    Ui::ScheduleTransactionDialog *ui;
    ChessSysUser* _user;
    int _transactionId;
    double _amout;
};

#endif // SCHEDULETRANSACTIONDIALOG_H
