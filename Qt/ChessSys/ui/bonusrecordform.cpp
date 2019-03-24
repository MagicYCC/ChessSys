#include "bonusrecordform.h"
#include "transactioneditdialog.h"
#include "ui_bonusrecordform.h"
#include "odbcexcel.h"
#include <QMessageBox>
#include <QFileDialog>

const QString BonusRecordForm::BonusFieldAlias[] = {
    "编号", "交易单编号", "录入人", "录入时间", "金额"
};

BonusRecordForm::BonusRecordForm(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::BonusRecordForm)
{
    ui->setupUi(this);

    setWindowTitle("红包记录查询");

    // 初始化红利记录表
    initBonusTable();

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

BonusRecordForm::~BonusRecordForm()
{
    delete ui;
}

// 初始化红利记录表
void BonusRecordForm::initBonusTable(){
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
    ui->bonusTable->setColumnWidth(0, 40);
}

// 查询红利记录
void BonusRecordForm::queryBonusRecord(){
    // 获取时间
    QDateTime startTime;
    QDateTime endTime;
    startTime = ui->timeSlotWidget->getStartDateTime();
    endTime = ui->timeSlotWidget->getEndDateTime();
    // 根据时间勾选生成时间语句
    QString timeStr = "";
    Qt::CheckState startState = ui->timeSlotWidget->startTimeCheck();
    Qt::CheckState endState = ui->timeSlotWidget->endTimeCheck();

    if(startState != Qt::Unchecked || endState != Qt::Unchecked){
        timeStr = "where";
        if(startState == Qt::Checked){
            timeStr += " bonuslist.entry_time > '" + startTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
        if(endState == Qt::Checked){
            if(startState == Qt::Checked){
                timeStr += " and";
            }
            timeStr += " bonuslist.entry_time < '" + endTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
    }

    QString sql;
    sql = "select bonuslist.id as id, bonuslist.transaction_id as transaction_id, "
          "user.name as entrier, bonuslist.entry_time as entry_time, "
          "bonuslist.amout as amout from "
          "bonuslist left outer join user on bonuslist.entry_user_id = user.id " +
            timeStr + ";";
//          "where entry_time < '2017.09.11 00:00';";
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

void BonusRecordForm::on_queryButton_clicked()
{
    this->queryBonusRecord();
}

void BonusRecordForm::on_outputButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "",
                                 "红利记录.xls",
                                 tr("Excel (*.xls)"));
    if(OdbcExcel::saveFromTable(fileName, ui->bonusTable,"")) {
        QMessageBox::information(this,tr("提示"),tr("保存成功"));
    }
    else{
        QString msg="保存失败！\n\r"+OdbcExcel::getError();
        QMessageBox::critical(this,tr("错误"),tr(msg.toUtf8()));
    }
}
