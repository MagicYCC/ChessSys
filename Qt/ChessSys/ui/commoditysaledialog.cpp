#include "commoditysaledialog.h"
#include "ui_commoditysaledialog.h"
#include <QSqlQuery>
#include <QMessageBox>

const QString CommoditySaleDialog::CommodityFieldAlias[] = {
    "编号", "商品名称", "价格", "购买数量"
};

CommoditySaleDialog::CommoditySaleDialog(ChessSysUser* user, int transactionId, QWidget *parent) :
    _user(user),
    _transactionId(transactionId),
    QDialog(parent),
    ui(new Ui::CommoditySaleDialog)
{
    ui->setupUi(this);

    setWindowTitle("商品销售");

    initCommodityTable();
    updateCommodityTable();
}

CommoditySaleDialog::~CommoditySaleDialog()
{
    delete ui;
}

// 初始化商品列表
void CommoditySaleDialog::initCommodityTable(){
    ui->commodityTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->commodityTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
//    ui->commodityTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
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
    ui->commodityTable->setColumnWidth(0, 40);
    ui->commodityTable->setColumnWidth(2, 60);
}

// 更新商品列表
void CommoditySaleDialog::updateCommodityTable(){
    QString sql;
    sql = "select commodity.id as id, commodity.name as name, commodity.price from "
          "commodity left outer join commoditystate on commodity.status = commoditystate.id "
          "where commoditystate.name = '上架'";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "商品信息查询失败！");
        return;
    }
    ui->commodityTable->clearContents();
    ui->commodityTable->setRowCount(0);

    int row = 0;
    while(query->next()){
        int id = query->value("id").toInt();
        QString name  = query->value("name").toString();
        double price = query->value("price").toDouble();
        ui->commodityTable->insertRow(row);
        ui->commodityTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->commodityTable->setItem(row, 1, new QTableWidgetItem(name));
        ui->commodityTable->setItem(row, 2, new QTableWidgetItem(QString::number(price, 'f', 2)));
        ui->commodityTable->setItem(row, 3, new QTableWidgetItem(""));
        // 设置前3列为只读
        ui->commodityTable->item(row, 0)->setFlags(Qt::NoItemFlags|Qt::ItemIsEnabled);
        ui->commodityTable->item(row, 1)->setFlags(Qt::NoItemFlags|Qt::ItemIsEnabled);
        ui->commodityTable->item(row, 2)->setFlags(Qt::NoItemFlags|Qt::ItemIsEnabled);
//        ui->commodityTable->item(row, 3)->setFlags(
//                    Qt::ItemIsEditable|
//                    Qt::ItemIsDragEnabled|
//                    Qt::ItemIsSelectable|
//                    Qt::ItemIsEnabled);

        row ++;
    }
}

void CommoditySaleDialog::updateBudget(){
    int rowCount = ui->commodityTable->rowCount();
    QString detail;
    double totalAmout = 0.00;
    detail = "消费清单:\n";
    ui->dudgetEdit->clear();
    for(int i=0;i<rowCount;i++){
        // 获取商品购买数量
        int number = ui->commodityTable->item(i, 3)->text().toInt();
        if(number <= 0){
            // 数量<=0直接跳过
            continue;
        }
        QString name;
        double price;
        double amout;
        name = ui->commodityTable->item(i, 1)->text();
        price = ui->commodityTable->item(i, 2)->text().toDouble();
        // 计算金额
        amout = price * number;
        // 添加到显示detail中
        detail += name + "    " + QString::number(number, 10) +
                "    " + QString::number(amout, 'f', 2) + "\n";
        totalAmout += amout;
    }
    // 总金额
    detail += "总金额       " + QString::number(totalAmout, 'f', 2) + "\n";
    ui->dudgetEdit->setText(detail);
}

// 确认交易
void CommoditySaleDialog::sureTransaction(){

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

    int ret = QMessageBox::question(
                this,
                "", "确实要购买这些商品吗?",
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

    rowCount = ui->commodityTable->rowCount();
    for(i=0;i<rowCount;i++){
        // 获取商品购买数量
        int number = ui->commodityTable->item(i, 3)->text().toInt();
        if(number <= 0){
            // 数量<=0直接跳过
            continue;
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

    QMessageBox::information(this, "通知", "商品添加成功！");
    close();
}

void CommoditySaleDialog::on_updateCommodityButton_clicked()
{
    updateCommodityTable();
}

void CommoditySaleDialog::on_updateBudgetButton_clicked()
{
    updateBudget();
}

void CommoditySaleDialog::on_sureButton_clicked()
{
    sureTransaction();
}
