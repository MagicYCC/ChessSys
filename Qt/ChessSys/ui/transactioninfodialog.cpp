#include "transactioninfodialog.h"
#include "ui_transactioninfodialog.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>

TransactionInfoDialog::TransactionInfoDialog(ChessSysUser* user, int transactionId, QWidget *parent) :
    _user(user),
    _transactionId(transactionId),
    QDialog(parent),
    ui(new Ui::TransactionInfoDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("交易信息");

    updateInfo();
}

TransactionInfoDialog::~TransactionInfoDialog()
{
    delete ui;
}

// 更新交易信息
void TransactionInfoDialog::updateInfo(){

    QString detail = "";
    QString totalDetail = "";
    double amout = 0;

    // 获取房间信息
    amout += chessRoomRecordToString(_transactionId, detail);
    totalDetail += detail;

    // 获取商品信息
    amout += accountSalesToString(_transactionId, detail);
    totalDetail += detail;

    // 获取红利信息
    amout -= bonusRecordToString(_transactionId, detail);
    totalDetail += detail;

    qDebug() << "amout = " + QString::number(amout, 'f', 2);

    // 获取交易信息
    QString sql;
    sql = "select amout, closing_time from TransactionList where id = " +
            QString::number(this->_transactionId, 10) + ";";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return;
    }
    if(!query->next()){
        QMessageBox::warning(this, "警告", "找不到记录！");
        return;
    }
    double totalAmout = query->value("amout").toDouble();
    QDateTime time = query->value("closing_time").toDateTime();
    totalDetail += "\n";
    totalDetail += "总金额          " + QString::number(totalAmout, 'f', 2) + "\n";
    totalDetail += "交易时间            " + time.toString("yyyy.MM.dd hh:mm:ss") + "\n";

    ui->infoEdit->setText(totalDetail);
}

// 获取商品交易信息字符串并返回总金额
double TransactionInfoDialog::accountSalesToString(int transactionId, QString& detail) {
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
double TransactionInfoDialog::chessRoomRecordToString(int transactionId, QString& detail){
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
    int recordId = query->value("id").toInt();
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
//    roomId = _user->queryChessRoomCurrentCharging(roomId, minutes, roomAmout);
//    if(roomId<=0){
//        QMessageBox::warning(this, "警告", "房间当前计费信息不存在！");
//        return 0;
//    }
    sql = "select amout, timestampdiff(MINUTE, entry_time, closing_time) as time "
          "from ChessRoomRecord where id = " + QString::number(recordId, 10) + ";";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return 0;
    }
    if(!query->next()){
        QMessageBox::warning(this, "警告", "房间名称获取失败！");
        return 0;
    }
    minutes = query->value("time").toInt();
    roomAmout = query->value("amout").toDouble();

    detail += name + "    " + QString::number(minutes/60, 10) + ":" +
            QString::number(minutes%60, 10) + "    " + QString::number(roomAmout, 'f', 2) + "\n";

    return roomAmout;
}

// 获取红利信息字符串
double TransactionInfoDialog::bonusRecordToString(int transactionId, QString& detail){
    QString sql;
    double amout = 0.00;
    detail = "";

    sql = "select sum(bonuslist.amout) as amout, bonuslist.transaction_id as id"
          " from bonuslist where transaction_id = " +
          QString::number(transactionId, 10) + ";";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败！");
        return -1.00;
    }
    if(query->next()){
        amout = query->value("amout").toDouble();
        if(amout >= 0){
            detail += "红包        -" + QString::number(amout, 'f', 2) + "\n";
        } else {
            detail += "红包        " + QString::number(-amout, 'f', 2) + "\n";
        }
    }
    return amout;
}

void TransactionInfoDialog::on_sureButton_clicked()
{
    close();
}
