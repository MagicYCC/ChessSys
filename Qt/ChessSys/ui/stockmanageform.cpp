#include "stockmanageform.h"
#include "ui_stockmanageform.h"
#include "commodityadddialog.h"
#include "stockadddialog.h"
#include "commoditypricechangedialog.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

const QString StockManageForm::CommodityFieldAlias[] = {
    "编号", "名称", "状态", "类别", "价格", "库存"
};

const QString StockManageForm::CommodityFieldName[] = {
    "id", "name", "status", "category", "price", "stock"
};

const QString StockManageForm::RecordFieldAlias[] = {
    "编号", "商品名称", "录入人", "进货价格", "数量", "录入时间"
};

const QString StockManageForm::RecordFieldName[] = {
    "id", "name", "person", "price", "number", "time"
};

StockManageForm::StockManageForm(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::StockManageForm)
{
    ui->setupUi(this);

    setWindowTitle("库存管理");

    initStockTable();
    updateStockInfo();

    initRecordTable();
    updateStockRecord();

//    user->addCommodity("可乐", ForSale, "饮料", 3.00);
//    user->deleteCommodity("可乐");

//    int id = 0;
//    id = user->addCommodityCategory("茶水");
//    qDebug() << QString::number(id, 10) + "\n";

//    id = user->addCommodityCategory("茶水");
//    qDebug() << QString::number(id, 10) + "\n";

//    id = user->addCommodityCategory("玩具");
//    qDebug() << QString::number(id, 10) + "\n";

//    id = user->deleteCommodityCategory("烟酒");
//    qDebug() << QString::number(id, 10);

//    id = user->deleteCommodityCategory("123");
//    qDebug() << QString::number(id, 10);
}

StockManageForm::~StockManageForm()
{
    delete ui;
}

void StockManageForm::initStockTable(){
    ui->stockInfoTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->stockInfoTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->stockInfoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->stockInfoTable->clear();
    ui->stockInfoTable->clearContents();
    ui->stockInfoTable->setRowCount(0);
    QStringList header;
    int size = sizeof(CommodityFieldAlias)/sizeof(CommodityFieldAlias[0]);
    ui->stockInfoTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<CommodityFieldAlias[i];
    }
    ui->stockInfoTable->setHorizontalHeaderLabels(header);
}

void StockManageForm::updateStockInfo(){
    QString sql;
    sql = "select commodity.id as id, commodity.name as name, commoditystate.name as status, "
          "commoditycategory.name as category, commodity.price as price,commodity.stock as stock "
          "from commodity left outer join commoditycategory on commodity.category = commoditycategory.id "
          "left outer join commoditystate on commodity.status = commoditystate.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "库存信息获取失败");
        return;
    }

    ui->stockInfoTable->clearContents();
    ui->stockInfoTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        QString name = query->value("name").toString();
        QString status = query->value("status").toString();
        QString category = query->value("category").toString();
        double price = query->value("price").toDouble();
        int stock = query->value("stock").toInt();
        ui->stockInfoTable->insertRow(row);
        ui->stockInfoTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->stockInfoTable->setItem(row, 1, new QTableWidgetItem(name));
        ui->stockInfoTable->setItem(row, 2, new QTableWidgetItem(status));
        ui->stockInfoTable->setItem(row, 3, new QTableWidgetItem(category));
        ui->stockInfoTable->setItem(row, 4, new QTableWidgetItem(QString::number(price, 'f', 2)));
        ui->stockInfoTable->setItem(row, 5, new QTableWidgetItem(QString::number(stock, 10)));
        row ++;
    }

}

// 初始化记录列表
void StockManageForm::initRecordTable(){
    ui->stockRecordTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->stockRecordTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->stockRecordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->stockRecordTable->clear();
    ui->stockRecordTable->clearContents();
    ui->stockRecordTable->setRowCount(0);
    QStringList header;
    int size = sizeof(RecordFieldAlias)/sizeof(RecordFieldAlias[0]);
    ui->stockRecordTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<RecordFieldAlias[i];
    }
    ui->stockRecordTable->setHorizontalHeaderLabels(header);
}

void StockManageForm::updateStockRecord(){
    QString sql;
    sql = "select godownentry.id as id, commodity.name as commodity, user.name as user, "
          "godownentry.purchase_price as price, godownentry.number as number, godownentry.entry_time as time "
          "from godownentry left outer join commodity on godownentry.commodity_id = commodity.id "
          "left outer join user on godownentry.user_id = user.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "库存清单获取失败");
        return;
    }

    ui->stockRecordTable->clearContents();
    ui->stockRecordTable->setRowCount(0);
    // 添加内容
    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        QString commodity = query->value("commodity").toString();
        QString user = query->value("user").toString();
        double price = query->value("price").toDouble();
        int number = query->value("number").toInt();
        QDateTime time = query->value("time").toDateTime();
        ui->stockRecordTable->insertRow(row);
        ui->stockRecordTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->stockRecordTable->setItem(row, 1, new QTableWidgetItem(commodity));
        ui->stockRecordTable->setItem(row, 2, new QTableWidgetItem(user));
        ui->stockRecordTable->setItem(row, 3, new QTableWidgetItem(QString::number(price, 'f', 2)));
        ui->stockRecordTable->setItem(row, 4, new QTableWidgetItem(QString::number(number, 10)));
        ui->stockRecordTable->setItem(row, 5, new QTableWidgetItem(time.toString("yyyy.MM.dd hh:mm:ss")));
        row ++;
    }

}

void StockManageForm::on_addStockButton_clicked()
{
    // 库存添加对话框
    StockAddDialog sad(_user);
    sad.exec();
    updateStockInfo();
    updateStockRecord();
}

void StockManageForm::on_addCommodityButton_clicked()
{
    // 商品添加对话框
    CommodityAddDialog cad(_user);
    cad.exec();
    updateStockInfo();
    updateStockRecord();
}

void StockManageForm::on_updateButton_clicked()
{
//    initStockTable();
    updateStockInfo();
}

void StockManageForm::on_updateRecordButton_clicked()
{
    updateStockRecord();
}

void StockManageForm::on_cancelRecordButton_clicked()
{
    int ret = QMessageBox::question(
                this,
                "", "确实要删除记录吗?",
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

    int row = ui->stockRecordTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中记录！");
        return;
    }
    int id =  ui->stockRecordTable->item(row, 0)->text().toInt();
    if(id <= 0){
        QMessageBox::warning(this, "警告", "操作失败！");
        return;
    }
    ret = _user->cancelStore(id);
    if(ret == -101){
        QMessageBox::warning(this, "警告", "用户无权限！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "库存记录不存在！");
        return;
    } else if(ret == -103){
        QMessageBox::warning(this, "警告", "记录对应的商品不存在！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "数据库异常！");
        return;
    }
    QMessageBox::information(this, "通知", "记录已删除！");

    updateStockInfo();
    updateStockRecord();

}

void StockManageForm::setCommodityStatus(QString name, CommodityState status){
    int ret = 0;
    if(name == ""){
        QMessageBox::warning(this, "警告", "操作失败！");
        return;
    }
    ret = _user->setCommodityStatus(name, status);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "上架失败！");
        return;
    }

    updateStockInfo();
    updateStockRecord();
}

void StockManageForm::on_activeButton_clicked()
{
    int row = ui->stockInfoTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中商品！");
        return;
    }

    QString name =  ui->stockInfoTable->item(row, 1)->text();

    setCommodityStatus(name, Active);

}

void StockManageForm::on_forSaleButton_clicked()
{
    int row = ui->stockInfoTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中商品！");
        return;
    }

    QString name =  ui->stockInfoTable->item(row, 1)->text();

    setCommodityStatus(name, ForSale);
}

void StockManageForm::on_changePriceButton_clicked()
{
    int row = ui->stockInfoTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中商品！");
        return;
    }

    QString name = ui->stockInfoTable->item(row, 1)->text();
    CommodityPriceChangeDialog cpcd(_user, name);
    cpcd.exec();

    updateStockInfo();
    updateStockRecord();
}

void StockManageForm::on_deleteButton_clicked()
{
    int row = ui->stockInfoTable->currentRow();
    if(row < 0){
        QMessageBox::warning(this, "警告", "未选中商品！");
        return;
    }
    int ret = QMessageBox::question(
                this,
                "", "确实要删除商品吗?",
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

    int id = ui->stockInfoTable->item(row, 0)->text().toInt();
    ret = _user->deleteCommodity(id);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "商品删除失败！");
        return;
    }

    QMessageBox::information(this, "通知", "商品删除成功！");

    updateStockInfo();
    updateStockRecord();
}
