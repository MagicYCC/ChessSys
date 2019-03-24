#include "transactioneditdialog.h"
#include "ui_transactioneditdialog.h"
#include <QMessageBox>

const QString TransactionEditDialog::RoomFieldAlias[] = {
    "开房记录编号", "交易编号", "房间名", "录入人", "录入时间", "终结者", "终结时间", "金额"
};

const QString TransactionEditDialog::CommodityFieldAlias[] = {
    "编号", "交易单编号", "录入人", "录入时间", "商品", "数量", "金额"
};

const QString TransactionEditDialog::BonusFieldAlias[] = {
    "编号", "交易单编号", "录入人", "录入时间", "金额"
};

TransactionEditDialog::TransactionEditDialog(ChessSysUser* user, int transactionId, QWidget *parent) :
    _user(user),
    _transactionId(transactionId),
    QDialog(parent),
    ui(new Ui::TransactionEditDialog)
{
    ui->setupUi(this);

    setWindowTitle("交易详情");

    // 初始化房间信息Table
    initRoomTable();

    // 初始化商品信息Table
    initCommodityTable();

    // 初始化红利信息Table
    initBonusTable();

    // 更新房间、商品、红利信息
    updateRoomInfo();
    updateCommodityInfo();
    updateBonusInfo();
}

TransactionEditDialog::~TransactionEditDialog()
{
    delete ui;
}

// 初始化房间信息Table
void TransactionEditDialog::initRoomTable(){
    ui->roomTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->roomTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->roomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->roomTable->clear();
    ui->roomTable->clearContents();
    ui->roomTable->setRowCount(0);
    QStringList header;
    int size = sizeof(RoomFieldAlias)/sizeof(RoomFieldAlias[0]);
    ui->roomTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<RoomFieldAlias[i];
    }
    ui->roomTable->setHorizontalHeaderLabels(header);
}

// 初始化商品信息Table
void TransactionEditDialog::initCommodityTable(){
    ui->commodityTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->commodityTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->commodityTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->commodityTable->clear();
    ui->commodityTable->clearContents();
    ui->commodityTable->setRowCount(0);
    QStringList header;
    int size = sizeof(CommodityFieldAlias)/sizeof(CommodityFieldAlias[0]);
    ui->commodityTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<CommodityFieldAlias[i];
    }
    ui->commodityTable->setHorizontalHeaderLabels(header);
}

// 初始化红利信息Table
void TransactionEditDialog::initBonusTable(){
    ui->bonusTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->bonusTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->bonusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->bonusTable->clear();
    ui->bonusTable->clearContents();
    ui->bonusTable->setRowCount(0);
    QStringList header;
    int size = sizeof(BonusFieldAlias)/sizeof(BonusFieldAlias[0]);
    ui->bonusTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<BonusFieldAlias[i];
    }
    ui->bonusTable->setHorizontalHeaderLabels(header);
}

// 更新房间信息
void TransactionEditDialog::updateRoomInfo(){
    QString sql;
    sql = "select temp.id as id, temp.transaction_id as transaction_id, "
          "temp.name as name, temp.entrier as entrier, temp.entry_time as entry_time, "
          "user.name as closer , temp.closing_time as "
          "closing_time, temp.amout as amout from "
          "(select chessroomrecord.id as id, chessroomrecord.transaction_id as transaction_id, "
          "chessroom.name as name, user.name as entrier, chessroomrecord.entry_time as entry_time, "
          "chessroomrecord.closing_user_id as closing_user_id , chessroomrecord.closing_time as "
          "closing_time, chessroomrecord.amout as amout from "
          "chessroomrecord left outer join chessroom on chessroomrecord.room_id = chessroom.id "
          "left outer join user on chessroomrecord.entry_user_id = user.id "
          "where chessroomrecord.transaction_id = " +
          QString::number(_transactionId, 10)  + " ) as temp "
          "left outer join user on temp.closing_user_id = user.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->roomTable->clearContents();
    ui->roomTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        int transactionId = query->value("transaction_id").toInt();
        QString name = query->value("name").toString();
        QString entrier = query->value("entrier").toString();
        QDateTime entryTime = query->value("entry_time").toDateTime();
        QString closer = query->value("closer").toString();
        QDateTime closingTime = query->value("closing_time").toDateTime();
        double amout = query->value("amout").toDouble();

        ui->roomTable->insertRow(row);
        ui->roomTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->roomTable->setItem(row, 1, new QTableWidgetItem(QString::number(transactionId, 10)));
        ui->roomTable->setItem(row, 2, new QTableWidgetItem(name));
        ui->roomTable->setItem(row, 3, new QTableWidgetItem(entrier));
        ui->roomTable->setItem(row, 4, new QTableWidgetItem(entryTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->roomTable->setItem(row, 5, new QTableWidgetItem(closer));
        ui->roomTable->setItem(row, 6, new QTableWidgetItem(closingTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->roomTable->setItem(row, 7, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}

// 更新商品信息
void TransactionEditDialog::updateCommodityInfo(){

    QString sql;
    sql = "select accountsales.id as id, accountsales.transaction_id as transaction_id, "
          "user.name as entrier, accountsales.entry_time as entry_time, "
          "commodity.name as commodity, accountsales.number as number, "
          "accountsales.amout as amout from "
          "accountsales left outer join user on accountsales.entry_user_id = user.id "
          "left outer join commodity on accountsales.commodity_id = commodity.id "
          "where transaction_id = " +
          QString::number(_transactionId, 10)  + " ;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->commodityTable->clearContents();
    ui->commodityTable->setRowCount(0);
    // 添加内容
    int row = 0;
    double totalAmout = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        int transactionId = query->value("transaction_id").toInt();
        QString entrier = query->value("entrier").toString();
        QDateTime entryTime = query->value("entry_time").toDateTime();
        QString commodity = query->value("commodity").toString();
        int number = query->value("number").toInt();
        double amout = query->value("amout").toDouble();

        ui->commodityTable->insertRow(row);
        ui->commodityTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->commodityTable->setItem(row, 1, new QTableWidgetItem(QString::number(transactionId, 10)));
        ui->commodityTable->setItem(row, 2, new QTableWidgetItem(entrier));
        ui->commodityTable->setItem(row, 3, new QTableWidgetItem(entryTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->commodityTable->setItem(row, 4, new QTableWidgetItem(commodity));
        ui->commodityTable->setItem(row, 5, new QTableWidgetItem(QString::number(number, 10)));
        ui->commodityTable->setItem(row, 6, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
        totalAmout += amout;
    }
    ui->commodityTable->insertRow(row);
    ui->commodityTable->setItem(row, 0, new QTableWidgetItem("总金额"));
    ui->commodityTable->setItem(row, 6, new QTableWidgetItem(QString::number(totalAmout, 'f', 2)));
}

// 更新红利信息
void TransactionEditDialog::updateBonusInfo(){
    QString sql;
    sql = "select bonuslist.id as id, bonuslist.transaction_id as transaction_id, "
          "user.name as entrier, bonuslist.entry_time as entry_time, "
          "bonuslist.amout as amout from "
          "bonuslist left outer join user on bonuslist.entry_user_id = user.id "
          "where transaction_id = " +
          QString::number(_transactionId, 10)  + ";";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->bonusTable->clearContents();
    ui->bonusTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        int transactionId = query->value("transaction_id").toInt();
        QString entrier = query->value("entrier").toString();
        QDateTime entryTime = query->value("entry_time").toDateTime();
        double amout = query->value("amout").toDouble();

        ui->bonusTable->insertRow(row);
        ui->bonusTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->bonusTable->setItem(row, 1, new QTableWidgetItem(QString::number(transactionId, 10)));
        ui->bonusTable->setItem(row, 2, new QTableWidgetItem(entrier));
        ui->bonusTable->setItem(row, 3, new QTableWidgetItem(entryTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->bonusTable->setItem(row, 4, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}

void TransactionEditDialog::on_commodityDeleteButton_clicked()
{

    int row = ui->commodityTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中销售记录！");
        return;
    }
    int ret = QMessageBox::question(
                this,
                "", "确实要删除该销售记录吗?",
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

    int id = ui->commodityTable->item(row, 0)->text().toInt();
    // 非强制删除销售记录
    ret = _user->deleteSaleRecordEx(id, 0);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "销售记录删除失败！");
        return;
    }

    QMessageBox::information(this, "通知", "销售记录删除成功！");

    this->updateCommodityInfo();
}

void TransactionEditDialog::on_roomUpdateButton_clicked()
{
    this->updateRoomInfo();
}

void TransactionEditDialog::on_commodityUpdateButton_clicked()
{
    this->updateCommodityInfo();
}

void TransactionEditDialog::on_bonusUpdateButton_clicked()
{
    this->updateBonusInfo();
}
