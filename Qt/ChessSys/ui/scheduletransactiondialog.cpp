#include "scheduletransactiondialog.h"
#include "ui_scheduletransactiondialog.h"
#include "transactioninfodialog.h"
#include "transactioneditdialog.h"
#include <QSqlQuery>
#include <QMessageBox>

ScheduleTransactionDialog::ScheduleTransactionDialog(ChessSysUser* user, int transactionId, QWidget *parent) :
    _user(user),
    _transactionId(transactionId),
    QDialog(parent),
    ui(new Ui::ScheduleTransactionDialog)
{
    ui->setupUi(this);

    setWindowTitle("预交易信息");

    updateTransactionInfo();
}

ScheduleTransactionDialog::~ScheduleTransactionDialog()
{
    delete ui;
}

void ScheduleTransactionDialog::updateTransactionInfo(){

    QString detail = "";
    QString totalDetail = "";
    double amout = 0;

    // 获取房间信息
    amout += chessRoomRecordToString(_transactionId, detail);
    totalDetail += detail;

    // 获取商品信息
    amout += accountSalesToString(_transactionId, detail);
    totalDetail += detail;


    totalDetail += "总金额          " + QString::number(amout, 'f', 2) + "\n";

    ui->detailEdit->setText(totalDetail);

    // 总金额写入成员变量中
    _amout = amout;

    ui->amoutEdit->setText(QString::number(_amout, 'f', 2));
    ui->amoutEdit->setFocus();

    ui->bonusEdit->setText(QString::number(0, 'f', 2));

}

// 获取商品交易信息字符串并返回总金额
double ScheduleTransactionDialog::accountSalesToString(int transactionId, QString& detail) {
    QString sql;
    double totalAmout = 0.00;
    detail = "";

    sql = "select commodity.name as name, "
          "sum(accountsales.number) as number, "
          "sum(accountsales.amout) as amout from "
          "accountsales left outer join commodity "
          "on accountsales.commodity_id = commodity.id "
          "where accountsales.transaction_id = " +
          QString::number(transactionId, 10) + " group by name;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "获取商品信息失败！");
        return -1.00;
    }
    while(query->next()){
        QString name = query->value("name").toString();
        int number = query->value("number").toInt();
        double amout = query->value("amout").toDouble();

        detail += name + "    " + QString::number(number, 10) +
                "    " + QString::number(amout, 'f', 2) + "\n";
        totalAmout += amout;
    }
    return totalAmout;
}

// 获取房间信息字符串
double ScheduleTransactionDialog::chessRoomRecordToString(int transactionId, QString& detail){
    detail = "";
    // 获取交易清单房间信息
    QSqlQuery* query = _user->queryChessRoomRecordFromTransaction(transactionId);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return 0;
    }
    if(!query->next()){
        // 无房间记录
        return 0;
    }
    int roomId = query->value("room_id").toInt();
    QString sql;
    sql = "select name from ChessRoom where id = " + QString::number(roomId, 10) + ";";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return 0;
    }
    if(!query->next()){
        QMessageBox::warning(this, "警告", "房间名称获取失败！");
        return 0;
    }
    QString name = query->value("name").toString();
    // 获取房间当前计费信息
    int minutes ;
    double roomAmout;
    roomId = _user->queryChessRoomCurrentCharging(roomId, minutes, roomAmout);
    if(roomId<=0){
        QMessageBox::warning(this, "警告", "房间当前计费信息不存在！");
        return 0;
    }

    detail += name + "    " + QString::number(minutes/60, 10) + ":" +
            QString::number(minutes%60, 10) + "    " + QString::number(roomAmout, 'f', 2) + "\n";

    return roomAmout;
}

void ScheduleTransactionDialog::on_updateButton_clicked()
{
    this->updateTransactionInfo();
}

void ScheduleTransactionDialog::on_sureButton_clicked()
{
    int ret = QMessageBox::question(
                this,
                "", "确实要结账吗?",
                QMessageBox::Ok|
                QMessageBox::Cancel
                );
    switch(ret){
    case QMessageBox::Ok:
//        qDebug() << "i am ok";
        break;
    case QMessageBox::Cancel:
//        qDebug() << "i am bad";
        return;
        break;
    default:
        break;
    }

    double amout;// 实收金额
    double bonusAmout;// 红利金额
    bonusAmout = ui->bonusEdit->text().toDouble();
    amout = ui->amoutEdit->text().toDouble();
    if(ui->amoutEdit->text() != ""){
        bonusAmout = _amout - amout;
    }
    if(bonusAmout != 0){
        // 为交易单添加红利
        if(_user->shareBonus(this->_transactionId, bonusAmout) <=0 ){
            QMessageBox::warning(this, "警告", "红利添加失败！");
            return;
        }
    }

    ret = _user->closeTransaction(this->_transactionId);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "结算失败！");
        return;
    }

    // 打开交易信息显示对话框
    TransactionInfoDialog tid(_user, this->_transactionId);
    tid.exec();

    this->done(SURE_TRANSACTION);
//    setResult(SURE_TRANSACTION);

    // 关闭预结算窗口
//    close();
}

void ScheduleTransactionDialog::on_cancelTransactionButton_clicked()
{
    int ret = QMessageBox::question(
                this,
                "", "确实要取消交易吗?\n"
                    "取消的同时对应的销售、开房、红包也将同时被删除！",
                QMessageBox::Ok|
                QMessageBox::Cancel
                );
    switch(ret){
    case QMessageBox::Ok:
//        qDebug() << "i am ok";
        break;
    case QMessageBox::Cancel:
//        qDebug() << "i am bad";
        return;
        break;
    default:
        break;
    }

    ret = _user->deleteTransaction(_transactionId);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "交易取消失败！");
        return;
    }
    this->done(CANCEL_TRANSACTION);
}

void ScheduleTransactionDialog::on_detailButton_clicked()
{
    TransactionEditDialog ted(_user, _transactionId);
    ted.exec();

    // 更新交易信息
    this->updateTransactionInfo();
}


void ScheduleTransactionDialog::on_amoutEdit_textEdited(const QString &arg1)
{
    double amout;// 实收金额
    double bonusAmout;// 红利金额
//    amout = ui->amoutEdit->text().toDouble();
    amout = arg1.toDouble();
    bonusAmout = _amout - amout;

    ui->bonusEdit->setText(QString::number(bonusAmout, 'f', 2));
}

void ScheduleTransactionDialog::on_bonusEdit_textEdited(const QString &arg1)
{
    double amout;// 实收金额
    double bonusAmout;// 红利金额
//    amout = ui->amoutEdit->text().toDouble();
    bonusAmout = arg1.toDouble();
    amout = _amout - bonusAmout;

    ui->amoutEdit->setText(QString::number(amout, 'f', 2));
}
