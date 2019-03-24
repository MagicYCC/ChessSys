#include "categorybrowsedialog.h"
#include "ui_categorybrowsedialog.h"
#include "odbcexcel.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

const QString CategoryBrowseDialog::CategoryFieldAlias[] = {
    "商品", "数量", "金额"
};

CategoryBrowseDialog::CategoryBrowseDialog(ChessSysUser *user, QDateTime startTime,
                                QDateTime endTime, QString category,
                                QWidget *parent) :
    _user(user),
    _startTime(startTime),
    _endTime(endTime),
    _category(category),
    QDialog(parent),
    ui(new Ui::CategoryBrowseDialog)
{
    ui->setupUi(this);

    setWindowTitle(_category + " - 浏览");

    ui->startTimeLabel->setText("起始时间：" + _startTime.toString("yyyy.MM.dd hh:mm"));
    ui->endTimeLabel->setText("终止时间：" + _endTime.toString("yyyy.MM.dd hh:mm"));

    initCategoryTable();

    queryCategory();
}

CategoryBrowseDialog::~CategoryBrowseDialog()
{
    delete ui;
}

// 初始化分类浏览表
void CategoryBrowseDialog::initCategoryTable(){
    ui->categoryTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->categoryTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->categoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->categoryTable->clear();
    ui->categoryTable->clearContents();
    ui->categoryTable->setRowCount(0);
    QStringList header;
    int size = sizeof(CategoryFieldAlias)/sizeof(CategoryFieldAlias[0]);
    ui->categoryTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<CategoryFieldAlias[i];
    }
    ui->categoryTable->setHorizontalHeaderLabels(header);
}

// 查询分类信息
void CategoryBrowseDialog::queryCategory(){

    // 生成时间语句
    QString timeStr = "where transactionlist.closing_user_id is not null";

    if(_startTime.isValid() || _endTime.isValid()){
        if(_startTime.isValid()){
            timeStr += " and transactionlist.entry_time > '" + _startTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
        if(_endTime.isValid()){
            timeStr += " and transactionlist.entry_time < '" + _endTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
    }

    QString sql;
    int row = 0;
    QSqlQuery* query;
    ui->categoryTable->clearContents();
    ui->categoryTable->setRowCount(0);

    // 查询分类商品详情
    sql = "select commodity.name as commodity, sum(accountsales.number) as number, "
          "sum(accountsales.amout) as amout "
          "from accountsales "
          "left outer join commodity on accountsales.commodity_id = commodity.id "
          "left outer join commoditycategory on commodity.category = commoditycategory.id "
          "where accountsales.transaction_id in ("
          "select transactionlist.id from transactionlist " +
            timeStr +
          ") and commoditycategory.name = '" +
            _category +
          "' group by commodity;";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }
    // 添加内容
    while(query->next()){
        QString commodity = query->value("commodity").toString();
        int number = query->value("number").toInt();
        double amout = query->value("amout").toDouble();

        ui->categoryTable->insertRow(row);
        ui->categoryTable->setItem(row, 0, new QTableWidgetItem(commodity));
        ui->categoryTable->setItem(row, 1, new QTableWidgetItem(QString::number(number, 10)));
        ui->categoryTable->setItem(row, 2, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;

//        QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->generralAnalyTree,QStringList(QString("图像1")));
    }
}

void CategoryBrowseDialog::on_outputButton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, "",
                                 "商品- " + _category + ".xls",
                                 tr("Excel (*.xls)"));
    qDebug() << fileName;
    if(OdbcExcel::saveFromTable(fileName, ui->categoryTable,"")) {
        QMessageBox::information(this,tr("提示"),tr("保存成功"));
    }
    else{
        QString msg="保存失败！\n\r"+OdbcExcel::getError();
        QMessageBox::critical(this,tr("错误"),tr(msg.toUtf8()));
    }
}
