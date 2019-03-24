#include "commoditysaleindependentdialog.h"
#include "scheduletransactiondialog.h"
#include "ui_commoditysaledialog.h"
#include <QMessageBox>

CommoditySaleIndependentDialog::CommoditySaleIndependentDialog(
        ChessSysUser* user, int transactionId, QWidget *parent):
    CommoditySaleDialog(user, transactionId, parent)
{

}

void CommoditySaleIndependentDialog::sureTransaction(){

    // 判断是否有商品购买
    int rowCount = 0;
    rowCount = ui->commodityTable->rowCount();
    int i = 0;
    for(i=0;i<rowCount;i++){
        // 获取商品购买数量
        int number = ui->commodityTable->item(i, 3)->text().toInt();
        if(number > 0){
            // 有商品购买
            break;
        }
    }
    if(i >= rowCount){
        QMessageBox::warning(this, "警告", "没有商品被选中！");
        return;
    }

//    int ret = QMessageBox::question(
//                this,
//                "", "确实要购买这些商品吗?",
//                QMessageBox::Ok|
//                QMessageBox::Cancel
//                );
//    switch(ret){
//    case QMessageBox::Ok:
////        qDebug() << "i am ok";
//        break;
//    case QMessageBox::Cancel:
////        qDebug() << "i am bad";
//        return;
//        break;
//    default:
//        break;
//    }



    rowCount = ui->commodityTable->rowCount();
    int firstEnterFlag = 1;
    for(i=0;i<rowCount;i++){
        // 获取商品购买数量
        int number = ui->commodityTable->item(i, 3)->text().toInt();
        if(number <= 0){
            // 数量<=0直接跳过
            continue;
        }
        if(firstEnterFlag == 1){
            // 创建交易单
            _transactionId = _user->createTransaction();
            if(_transactionId<=0){
                QMessageBox::warning(this, "警告", "交易单创建失败！");
                return;
            }
            firstEnterFlag = 0;
        }
        int id;
        id = ui->commodityTable->item(i, 0)->text().toInt();
//        QString name;
//        double price;
//        double amout;
//        name = ui->commodityTable->item(i, 1)->text();
//        price = ui->commodityTable->item(i, 2)->text().toDouble();
        // 计算金额
//        amout = price * number;
        // 添加到显示detail中
//        detail += name + "    " + QString::number(number, 10) +
//                "    " + QString::number(amout, 'f', 2) + "\n";
//        totalAmout += amout;
        int recordId = _user->sellCommodity(_transactionId, id, number);
        if(recordId <= 0){
            QMessageBox::warning(this, "警告", "购买失败商品！");
            return;
        }
    }

//    QMessageBox::information(this, "通知", "商品添加成功！");
    // 弹出预交易对话框
    ScheduleTransactionDialog std(_user, _transactionId);
    int ret = std.exec();

    switch (ret) {
    case SURE_TRANSACTION:
    case CANCEL_TRANSACTION:
        break;
    default:
        // 交易没有被确定或取消
        // 直接删除交易
        ret = _user->deleteTransaction(_transactionId);
        if(ret < 0){
            QMessageBox::warning(this, "警告", "交易未被删除！");
            return;
        }
        break;
    }

    close();
}

