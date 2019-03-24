#include "salemanageform.h"
#include "ui_salemanageform.h"
#include "commoditysaleindependentdialog.h"
#include "transactioneditdialog.h"
#include <QMessageBox>
#include <QSqlQuery>

const QString SaleManageForm::TransactionFieldAlias[] = {
    "编号", "录入人", "录入时间", "终结者", "终结时间", "金额"
};

const QString SaleManageForm::SaleFieldAlias[] = {
    "编号", "交易单编号", "录入人", "录入时间", "商品", "数量", "金额"
};

SaleManageForm::SaleManageForm(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::SaleManageForm)
{
    ui->setupUi(this);

    this->setWindowTitle("销售管理");

    // 初始化并更新交易信息
    initTransactionsTable();
    updateTransactionsInfo();

    // 初始化并更新销售信息
    initSalesTable();
    updateSalesInfo();
}

SaleManageForm::~SaleManageForm()
{
    delete ui;
}

// 初始化交易信息
void SaleManageForm::initTransactionsTable(){
    ui->transactionTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->transactionTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->transactionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->transactionTable->clear();
    ui->transactionTable->clearContents();
    ui->transactionTable->setRowCount(0);
    QStringList header;
    int size = sizeof(TransactionFieldAlias)/sizeof(TransactionFieldAlias[0]);
    ui->transactionTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<TransactionFieldAlias[i];
    }
    ui->transactionTable->setHorizontalHeaderLabels(header);
    ui->transactionTable->setColumnWidth(0, 40);
}

// 更新交易信息
void SaleManageForm::updateTransactionsInfo(){
    QString sql;
    sql = "select temp.id, entrier, entry_time, user.name as closer, closing_time, amout from "
          "(select transactionlist.id as id, user.name as entrier, transactionlist.entry_time as entry_time, "
          "transactionlist.closing_user_id as closing_user_id, transactionlist.closing_time as closing_time, "
          "transactionlist.amout as amout from transactionlist left outer join user "
          "on transactionlist.entry_user_id = user.id) as temp "
          "left outer join user on temp.closing_user_id = user.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->transactionTable->clearContents();
    ui->transactionTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        QString entrier = query->value("entrier").toString();
        QDateTime entryTime = query->value("entry_time").toDateTime();
        QString closer = query->value("closer").toString();
        QDateTime closingTime = query->value("closing_time").toDateTime();
        double amout = query->value("amout").toDouble();

        ui->transactionTable->insertRow(row);
        ui->transactionTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->transactionTable->setItem(row, 1, new QTableWidgetItem(entrier));
        ui->transactionTable->setItem(row, 2, new QTableWidgetItem(entryTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->transactionTable->setItem(row, 3, new QTableWidgetItem(closer));
        ui->transactionTable->setItem(row, 4, new QTableWidgetItem(closingTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->transactionTable->setItem(row, 5, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}

// 初始化销售信息
void SaleManageForm::initSalesTable(){
    ui->salesTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->salesTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->salesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->salesTable->clear();
    ui->salesTable->clearContents();
    ui->salesTable->setRowCount(0);
    QStringList header;
    int size = sizeof(SaleFieldAlias)/sizeof(SaleFieldAlias[0]);
    ui->salesTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<SaleFieldAlias[i];
    }
    ui->salesTable->setHorizontalHeaderLabels(header);
    ui->salesTable->setColumnWidth(0, 40);
}

// 更新销售信息
void SaleManageForm::updateSalesInfo(){
    QString sql;
    sql = "select accountsales.id as id, accountsales.transaction_id as transaction, "
          "user.name as user, accountsales.entry_time as time, commodity.name as commodity, "
          "accountsales.number as number, accountsales.amout as amout "
          "from accountsales left outer join user on accountsales.entry_user_id = user.id "
          "left outer join commodity on accountsales.commodity_id = commodity.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->salesTable->clearContents();
    ui->salesTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        int transaction = query->value("transaction").toInt();
        QString user = query->value("user").toString();
        QDateTime time = query->value("time").toDateTime();
        QString commodity = query->value("commodity").toString();
        int number = query->value("number").toInt();
        double amout = query->value("amout").toDouble();

        ui->salesTable->insertRow(row);
        ui->salesTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->salesTable->setItem(row, 1, new QTableWidgetItem(QString::number(transaction, 10)));
        ui->salesTable->setItem(row, 2, new QTableWidgetItem(user));
        ui->salesTable->setItem(row, 3, new QTableWidgetItem(time.toString("yyyy.MM.dd hh:mm:ss")));
        ui->salesTable->setItem(row, 4, new QTableWidgetItem(commodity));
        ui->salesTable->setItem(row, 5, new QTableWidgetItem(QString::number(number, 10)));
        ui->salesTable->setItem(row, 6, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}

// 交易单信息
void SaleManageForm::on_updateTransactionButton_clicked()
{
    updateTransactionsInfo();
}

// 更新交易单信息
void SaleManageForm::on_updateSalesButton_clicked()
{
    updateSalesInfo();
}

void SaleManageForm::on_saleButton_clicked()
{
    // 弹出独立商品销售对话框
    CommoditySaleIndependentDialog csid(_user);
    csid.exec();

    // 更新内容
    updateTransactionsInfo();
    updateSalesInfo();
}

void SaleManageForm::on_deleteSaleButton_clicked()
{
    int row = ui->salesTable->currentRow();
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

    int id = ui->salesTable->item(row, 0)->text().toInt();
    // 非强制删除销售记录
    ret = _user->deleteSaleRecordEx(id, 0);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "销售记录删除失败！");
        return;
    }

    QMessageBox::information(this, "通知", "销售记录删除成功！");

    this->updateSalesInfo();
    this->updateTransactionsInfo();
}

void SaleManageForm::on_deleteTransactionButton_clicked()
{
    int row = ui->transactionTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中交易记录！");
        return;
    }
    int ret = QMessageBox::question(
                this,
                "", "确实要删除该交易记录吗?\n"
                    "删除的同时对应的销售、开房、红包也将同时被删除！",
                QMessageBox::Ok|
                QMessageBox::Cancel
                );

    switch(ret){
    case QMessageBox::Ok:
        break;
    case QMessageBox::Cancel:
        return;
        break;
    default:
        break;
    }

    int id = ui->transactionTable->item(row, 0)->text().toInt();
    ret = _user->deleteTransaction(id);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "交易记录删除失败！");
        return;
    }

    QMessageBox::information(this, "通知", "交易记录删除成功！");

    this->updateSalesInfo();
    this->updateTransactionsInfo();
}

void SaleManageForm::on_transactionTable_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();
    int id = ui->transactionTable->item(row, 0)->text().toInt();

    // 弹出交易编辑对话框
    TransactionEditDialog ted(_user, id);
    ted.exec();

    this->updateSalesInfo();
    this->updateTransactionsInfo();
}
