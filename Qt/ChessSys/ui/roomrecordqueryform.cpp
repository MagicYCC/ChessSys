#include "roomrecordqueryform.h"
#include "ui_roomrecordqueryform.h"
#include "odbcexcel.h"
#include <QMessageBox>
#include <QFileDialog>

const QString RoomRecordQueryForm::RoomRecordFieldAlias[] = {
    "编号", "交易单编号", "房间名", "录入人", "录入时间", "终结者", "终结时间", "金额"
};

RoomRecordQueryForm::RoomRecordQueryForm(ChessSysUser* user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::RoomRecordQueryForm)
{
    ui->setupUi(this);

    setWindowTitle("房间记录查询");

    // 初始化房间记录表
    initRoomRecordTable();

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

RoomRecordQueryForm::~RoomRecordQueryForm()
{
    delete ui;
}

// 初始化房间记录表
void RoomRecordQueryForm::initRoomRecordTable(){
    ui->roomRecordTable->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->roomRecordTable->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui->roomRecordTable->setEditTriggers(QAbstractItemView::NoEditTriggers);// 禁止单元格编辑
    ui->roomRecordTable->clear();
    ui->roomRecordTable->clearContents();
    ui->roomRecordTable->setRowCount(0);
    QStringList header;
    int size = sizeof(RoomRecordFieldAlias)/sizeof(RoomRecordFieldAlias[0]);
    ui->roomRecordTable->setColumnCount(size);
    for(int i=0;i<size;i++){
        header<<RoomRecordFieldAlias[i];
    }
    ui->roomRecordTable->setHorizontalHeaderLabels(header);
    ui->roomRecordTable->setColumnWidth(0, 40);
}

// 查询房间记录
void RoomRecordQueryForm::queryRoomRecord(){

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
            timeStr += " chessroomrecord.entry_time > '" + startTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
        if(endState == Qt::Checked){
            if(startState == Qt::Checked){
                timeStr += " and";
            }
            timeStr += " chessroomrecord.entry_time < '" + endTime.toString("yyyy.MM.dd hh:mm") + "'";
        }
    }

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
          "left outer join user on chessroomrecord.entry_user_id = user.id " +
            timeStr + ") as temp "
//          "where chessroomrecord.entry_time < '2017.9.13 1:02') as temp "
          "left outer join user on temp.closing_user_id = user.id;";
    QSqlQuery* query = _user->queryCommand(sql);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    ui->roomRecordTable->clearContents();
    ui->roomRecordTable->setRowCount(0);
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

        ui->roomRecordTable->insertRow(row);
        ui->roomRecordTable->setItem(row, 0, new QTableWidgetItem(QString::number(id, 10)));
        ui->roomRecordTable->setItem(row, 1, new QTableWidgetItem(QString::number(transactionId, 10)));
        ui->roomRecordTable->setItem(row, 2, new QTableWidgetItem(name));
        ui->roomRecordTable->setItem(row, 3, new QTableWidgetItem(entrier));
        ui->roomRecordTable->setItem(row, 4, new QTableWidgetItem(entryTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->roomRecordTable->setItem(row, 5, new QTableWidgetItem(closer));
        ui->roomRecordTable->setItem(row, 6, new QTableWidgetItem(closingTime.toString("yyyy.MM.dd hh:mm:ss")));
        ui->roomRecordTable->setItem(row, 7, new QTableWidgetItem(QString::number(amout, 'f', 2)));
        row ++;
    }
}

void RoomRecordQueryForm::on_qureyButton_clicked()
{
    // 查询房间记录
    this->queryRoomRecord();
}

void RoomRecordQueryForm::on_outputButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "",
                                 "房间记录.xls",
                                 tr("Excel (*.xls)"));
    if(OdbcExcel::saveFromTable(fileName, ui->roomRecordTable,"")) {
        QMessageBox::information(this,tr("提示"),tr("保存成功"));
    }
    else{
        QString msg="保存失败！\n\r"+OdbcExcel::getError();
        QMessageBox::critical(this,tr("错误"),tr(msg.toUtf8()));
    }
}
