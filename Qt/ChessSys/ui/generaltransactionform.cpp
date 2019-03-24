#include "generaltransactionform.h"
#include "categorybrowsedialog.h"
#include "ui_generaltransactionform.h"
#include "odbcexcel.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

const QString GeneralTransactionForm::GeneralFieldAlias[] = {
    "项目", "金额"
};

GeneralTransactionForm::GeneralTransactionForm(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::GeneralTransactionForm)
{
    ui->setupUi(this);

    setWindowTitle("综合交易分析");

    // 初始化综合分析表
    initGeneralTable();

    // 获取系统时间
    QString sql;
    sql = "select current_timestamp() as time;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行失败");
        return;
    }
    if(!query->next()){
        QMessageBox::warning(this, "警告", "获取当前时间失败");
        return;
    }
    QDateTime time = query->value("time").toDateTime();

    // 设置开始结束时间
    ui->timeSlotWidget->setStartDateTime(time);
    ui->timeSlotWidget->setEndDateTime(time);
}

GeneralTransactionForm::~GeneralTransactionForm()
{
    delete ui;
}

void GeneralTransactionForm::initGeneralTable(){
    ui->generalAnalyTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->generalAnalyTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->generalAnalyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->generalAnalyTable->clear();
    ui->generalAnalyTable->clearContents();
    ui->generalAnalyTable->setRowCount(0);
    QStringList header;
    int size = sizeof(GeneralFieldAlias)/sizeof(GeneralFieldAlias[0]);
    ui->generalAnalyTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<GeneralFieldAlias[i];
    }
    ui->generalAnalyTable->setHorizontalHeaderLabels(header);
}

void GeneralTransactionForm::queryGeneralAnaly(){
    // 获取时间
    QDateTime startTime;
    QDateTime endTime;
    startTime = ui->timeSlotWidget->getStartDateTime();
    endTime = ui->timeSlotWidget->getEndDateTime();
    // 根据时间勾选生成时间语句
    QString timeStr = "where transactionlist.closing_user_id is not null";
    Qt::CheckState startState = ui->timeSlotWidget->startTimeCheck();
    Qt::CheckState endState = ui->timeSlotWidget->endTimeCheck();

    if(startState != Qt::Unchecked || endState != Qt::Unchecked){
        if(startState == Qt::Checked){
            timeStr += " and transactionlist.entry_time > '" + startTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
        if(endState == Qt::Checked){
            timeStr += " and transactionlist.entry_time < '" + endTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
    }

    QString sql;
    int row = 0;
    QSqlQuery* query;
    ui->generalAnalyTable->clearContents();
    ui->generalAnalyTable->setRowCount(0);

    // 查询商品信息
    sql = "select commoditycategory.name as category, sum(accountsales.amout) as amout "
          "from accountsales "
          "left outer join commodity on accountsales.commodity_id = commodity.id "
          "left outer join commoditycategory on commodity.category = commoditycategory.id "
          "where accountsales.transaction_id in ( "
          "select transactionlist.id from transactionlist " +
            timeStr +
//          "where transactionlist.closing_user_id is not null "
//          "and entry_time > '2017.5.5' "
//          "and entry_time < '2017.10.10' "
          " ) group by commodity.category;";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }
    // 添加内容
    while(query->next()){
        QString category = query->value("category").toString();
        double amout = query->value("amout").toDouble();

        ui->generalAnalyTable->insertRow(row);
        ui->generalAnalyTable->setItem(row, 0, new QTableWidgetItem(category));
        ui->generalAnalyTable->setItem(row, 1, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;

//        QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->generralAnalyTree,QStringList(QString("图像1")));
    }

    _categoryCount = row;

    // 查询房间总消费金额
    sql = "select sum(chessroomrecord.amout) as amout from chessroomrecord "
          "where chessroomrecord.transaction_id in ("
          "select transactionlist.id from transactionlist " +
            timeStr +
//          "where transactionlist.closing_user_id is not null "
//          "and transactionlist.entry_time > '2017.5.5' "
//          "and transactionlist.entry_time < '2017.10.10' "
          ") ;";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }
    // 添加内容
    while(query->next()){
        double amout = query->value("amout").toDouble();

        ui->generalAnalyTable->insertRow(row);
        ui->generalAnalyTable->setItem(row, 0, new QTableWidgetItem("棋牌房间"));
        ui->generalAnalyTable->setItem(row, 1, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }

    // 查询红包总金额
    sql = "select sum(bonuslist.amout) as amout from bonuslist "
          "where bonuslist.transaction_id in ("
          "select transactionlist.id from transactionlist " +
            timeStr +
//          "where transactionlist.closing_user_id is not null "
//          "and transactionlist.entry_time > '2017.5.5' "
//          "and transactionlist.entry_time < '2017.10.10' "
          ") ;";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }
    // 添加内容
    while(query->next()){
        double amout = query->value("amout").toDouble();
        amout = -amout;

        ui->generalAnalyTable->insertRow(row);
        ui->generalAnalyTable->setItem(row, 0, new QTableWidgetItem("红包"));
        ui->generalAnalyTable->setItem(row, 1, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }

    // 查询总金额
    sql = "select sum(transactionlist.amout) as amout from transactionlist " +
            timeStr +
//          "where transactionlist.closing_user_id is not null "
//          "and transactionlist.entry_time > '2017.5.5' "
//          "and transactionlist.entry_time < '2017.10.10' "
          ";";
    query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }
    // 添加内容
    while(query->next()){
        double amout = query->value("amout").toDouble();

        ui->generalAnalyTable->insertRow(row);
        ui->generalAnalyTable->setItem(row, 0, new QTableWidgetItem("总金额"));
        ui->generalAnalyTable->setItem(row, 1, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}



void GeneralTransactionForm::on_queryButton_clicked()
{
    this->queryGeneralAnaly();
}

void GeneralTransactionForm::on_outputButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "",
                                 "综合分析.xls",
                                 tr("Excel (*.xls)"));
    qDebug() << fileName;
    if(OdbcExcel::saveFromTable(fileName, ui->generalAnalyTable,"")) {
        QMessageBox::information(this,tr("提示"),tr("保存成功"));
    }
    else{
        QString msg="保存失败！\n\r"+OdbcExcel::getError();
        QMessageBox::critical(this,tr("错误"),tr(msg.toUtf8()));
    }
}

// 分类项双击事件
void GeneralTransactionForm::on_generalAnalyTable_itemDoubleClicked(QTableWidgetItem *item)
{
    int row = item->row();
    if(row >= _categoryCount){
        // 无效选项
        return;
    }
    QString category = ui->generalAnalyTable->item(row, 0)->text();

    // 获取时间
    QDateTime startTime;
    QDateTime endTime;
    Qt::CheckState startState = ui->timeSlotWidget->startTimeCheck();
    Qt::CheckState endState = ui->timeSlotWidget->endTimeCheck();
    if(startState == Qt::Checked){
        startTime = ui->timeSlotWidget->getStartDateTime();
    }
    if(endState == Qt::Checked){
        endTime = ui->timeSlotWidget->getEndDateTime();
    }

    CategoryBrowseDialog cbd(_user, startTime, endTime, category);
    cbd.exec();
}
