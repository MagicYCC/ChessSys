#include "chessroomform.h"
#include "ui_chessroomform.h"
#include "chessroomicon.h"
#include "chessroomadddialog.h"
#include "commoditysaledialog.h"
#include "scheduleroomdialog.h"
#include "scheduletransactiondialog.h"
#include "chessroomformulachangedialog.h"
#include "chessroomopendialog.h"
#include <QPushButton>
#include <QSqlQuery>
#include <QVariant>
#include <QDateTime>
#include <QMessageBox>
#include <QLabel>

const QString ChessRoomForm::StatusStrings[] = {
    "空闲", "预定中", "计费中", "挂起"
};

const QString ChessRoomForm::ImageFileDir = "../skin/";
const QString ChessRoomForm::ImageFileName[] = {
    "Free.png", "Schedule.png", "Busy.png", "Suspend.png"
};

ChessRoomForm::ChessRoomForm(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::ChessRoomForm)
{
    ui->setupUi(this);

    ui->chessRoomList->setMovement(QListView::Static);
    ui->chessRoomList->setIconSize(QSize(80, 100));

    int ret = 0;
    ret = updateRoomInfo();
    if(ret<0){
        QMessageBox::warning(this, "警告", "房间信息更新失败！");
        return;
    }

    enableRoomButtons((ChessRoomState)0);

}

// 开房
void ChessRoomForm::openRoom(){
//    int ret = QMessageBox::question(
//                this,
//                "", "确实要开房吗?",
//                QMessageBox::Ok|
//                QMessageBox::Cancel
//                );
//    switch(ret){
//    case QMessageBox::Ok:
////        qDebug() << "i am ok";
//        break;
//    case QMessageBox::Cancel:
////        qDebug() << "i am bad";
//        return;
//        break;
//    default:
//        break;
//    }

//    QListWidgetItem *item = ui->chessRoomList->currentItem();
//    QString name = item->text();
//    int id = _user->queryChessRoomId(name);
//    if(id <= 0){
//        QMessageBox::warning(this, "警告", "房间信息有误！");
//        return;
//    }
//    _user->openChessRoom(id);

//    ret = updateRoomInfo();
//    if(ret<0){
//        QMessageBox::warning(this, "警告", "房间信息更新失败！");
//        return;
//    }

    int ret = 0;
    QListWidgetItem *item = ui->chessRoomList->currentItem();
    QString name = item->text();
    // 打开
    ChessRoomOpenDialog crod(_user, name, this);
    ret = crod.exec();

    if(ret == ChessRoomOpenDialog::RoomOpened){
        ret = updateRoomInfo();
        if(ret<0){
            QMessageBox::warning(this, "警告", "房间信息更新失败！");
            return;
        }
    }

}

void ChessRoomForm::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)) != 0){
        //删除widget
        if(item->widget()){
            delete item->widget();
            //item->widget()->deleteLater();
        }
        //删除子布局
        QLayout *childLayout = item->layout();
        if(childLayout){
            clearLayout(childLayout);
        }
        delete item;
    }
}

int ChessRoomForm::updateRoomInfo(){


    int count = 0;

//    int num = ui->chessRoomList->count();  //获取列表项的总数目
//    ui->chessRoomList->setFocus(); //将光标设置到列表框上，若注释该语句，则删除时，要手动将焦点设置到列表框，即点击列表项
//    for(int i=0;i<num;i++){
//        //逐个获取列表项的指针，并删除
//       QListWidgetItem *item = ui->chessRoomList->takeItem(ui->chessRoomList->currentRow());
//       delete item;
//    }

    int counter =ui->chessRoomList->count();
    for(int index=0;index<counter;index++) {
        QListWidgetItem *item = ui->chessRoomList->takeItem(0);
        delete item;
    }

    QSqlQuery* query = _user->queryChessRoomInfo();
    if(query == NULL){
        return -1;
    }

    while(query->next()){
        QString name = query->value("name").toString();
        QDateTime dateTime = query->value("scheduled_time").toDateTime();
        int status = query->value("status").toInt();
        QString remark = query->value("remark").toString();
//        QPushButton * button = new QPushButton(name + " " + StatusStrings[status-1] + "\n" +
//                                               dateTime.time().toString() + "\n" +
//                                               remark);
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(name);                     //设置列表项的文本

//        item->setIcon(QIcon("../skin/Busy.png"));
        item->setIcon(QIcon(ImageFileDir + ImageFileName[status - 1]));
        ui->chessRoomList->addItem(item);          //加载列表项到列表框

    }
    ui->chessRoomList->setCurrentRow(0);
    return 0;
}

//
void ChessRoomForm::enableRoomButtons(ChessRoomState status){


    ui->scheduleButton->setText("预定");
    ui->suspendButton->setText("挂起");
    ui->openButton->setEnabled(false);
    ui->scheduleButton->setEnabled(false);
    ui->suspendButton->setEnabled(false);
    ui->closeRoomButton->setEnabled(false);
    ui->commoditySaleButton->setEnabled(false);

    _statusFlag = status;

    switch (status)
    {
    case Free:
        ui->openButton->setEnabled(true);
        ui->scheduleButton->setEnabled(true);
        ui->suspendButton->setEnabled(true);
        break;
    case Schedule:
        ui->openButton->setEnabled(true);
        ui->scheduleButton->setEnabled(true);
        ui->scheduleButton->setText("取消预定");
        ui->commoditySaleButton->setEnabled(true);
        ui->closeRoomButton->setEnabled(true);
        break;
    case Busy:
        ui->commoditySaleButton->setEnabled(true);
        ui->closeRoomButton->setEnabled(true);
        break;
    case Suspend:
        ui->suspendButton->setEnabled(true);
        ui->suspendButton->setText("取消挂起");
        break;
    default:
//        ui->openButton->setEnabled(false);
//        ui->scheduleButton->setEnabled(false);
//        ui->suspendButton->setEnabled(false);
//        ui->closeRoomButton->setEnabled(false);
        break;
    }

}

ChessRoomForm::~ChessRoomForm()
{
    delete ui;
}


void ChessRoomForm::on_addRoomButton_clicked()
{
    ChessRoomAddDialog dlg(_user);
    dlg.exec();
    int ret = 0;
    ret = updateRoomInfo();
    if(ret<0){
        QMessageBox::warning(this, "警告", "房间信息更新失败！");
        return;
    }
}

void ChessRoomForm::on_updateButton_clicked()
{
    int ret = 0;
    ret = updateRoomInfo();
    if(ret<0){
        QMessageBox::warning(this, "警告", "房间信息更新失败！");
        return;
    }
}

// 开房
void ChessRoomForm::on_openButton_clicked()
{
    openRoom();
}

// 结账
void ChessRoomForm::closeRoom(){

    QString name = ui->chessRoomList->currentItem()->text();
    int id = _user->queryChessRoomId(name);
//    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    int transactionId;
    id = _user->queryChessTransactionId(id, transactionId);
    if(id <= 0){
        QMessageBox::warning(this, "警告", "交易订单有误或数据库异常！");
        return;
    }

    ScheduleTransactionDialog std(_user, transactionId);
    std.exec();

    this->updateRoomInfo();
}



//void ChessRoomForm::on_chessRoomList_itemChanged(QListWidgetItem *item)
//{
//    if(item == NULL){
//         QMessageBox::warning(this, "警告", "item == NULL");
//         return;
//    }
//    QMessageBox::warning(this, "警告", item->text());
//}

void ChessRoomForm::on_chessRoomList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
//    if(current == NULL){
//         QMessageBox::warning(this, "警告", "current == NULL");
//         return;
//    }
//    if(previous == NULL){
//         QMessageBox::warning(this, "警告", "previous == NULL");
//         return;
//    }
//    QMessageBox::warning(this, "警告", "current = " + current->text());
//    QMessageBox::warning(this, "警告", "previous = " + previous->text());

    if(current == NULL){
         enableRoomButtons();// 关闭所有按键
         ui->roomInfoText->clear();
         return;
    }

    QString name = current->text();
    QSqlQuery* query = _user->queryChessRoomInfo(name);
    if(query == NULL){
        QMessageBox::warning(this, "警告", "内容查询失败");
        return;
    }

    if(!query->next()){
        QMessageBox::warning(this, "警告", "无当前房间信息");
        return;
    }

    ChessRoomState status = (ChessRoomState) query->value("status").toInt();
    int id = query->value("id").toInt();
    QString formula = query->value("charging_formula").toString();
    QDateTime scheduledTime = query->value("scheduled_time").toDateTime();
    int scheduledMemberId = query->value("scheduled_member_id").toInt();
    int currentRecordId = query->value("current_record_id").toInt();
    QString remark = query->value("remark").toString();

    // 设置按键
    enableRoomButtons(status);

    // 显示详细内容
    ui->roomInfoText->clear();
    QString detail = "";
//    detail += "id : " + QString::number(id, 10) + "\n";
    detail += "房间名 : " + name + "\n";
    detail += "房间状态 : " + StatusStrings[status - 1] + "\n";
    detail += "备注 : " + remark + "\n";
    int transactionId = 0;// 交易清单编号
    double totalAmout = 0.00;// 总金额
    switch (status){
    case Free:
        break;
    case Schedule:
    case Busy:
        // 获取交易清单编号
        id = _user->queryChessTransactionId(id, transactionId);
        if(id<=0){
            QMessageBox::warning(this, "警告", "交易清单不存在！");
            return;
        }

        // 获取交易清单房间信息
        query = _user->queryChessRoomRecordFromTransaction(transactionId);
        if(query == NULL){
            QMessageBox::warning(this, "警告", "房间记录查询失败！");
            return;
        }
        while(query->next()){
            QDateTime entryTime  = query->value("entry_time").toDateTime();
            detail += "开始时间 ：" + entryTime.time().toString("hh:mm:ss") + "\n";
        }



        // 获取房间当前计费信息
        int minutes ;
        double roomAmout;
        id = _user->queryChessRoomCurrentCharging(id, minutes, roomAmout);
        if(id<=0){
            QMessageBox::warning(this, "警告", "房间当前计费信息不存在！");
            return;
        }
        detail += "时长 ：" + QString::number(minutes/60, 10) +
                ":" + QString::number(minutes%60) +
                "  金额 ： " + QString::number(roomAmout, 'f', 2) + "\n";
        totalAmout += roomAmout;

        // 获取交易清单商品信息
        QString sql;
        sql = "select Commodity.name as name, AccountSales.number as number, AccountSales.amout as amout"
              " from AccountSales left outer join Commodity on AccountSales.commodity_id = Commodity.id "
              "where transaction_id = " + QString::number(transactionId, 10) + " ;";
        query = _user->queryCommand(sql);
        if(query == NULL){
            QMessageBox::warning(this, "警告", "商品信息获取失败");
            return;
        }
        while(query->next()){
            QString commodityName = query->value("name").toString();
            int commodityNumber = query->value("number").toInt();
            double commodityAmout = query->value("amout").toDouble();

            detail += commodityName + "   " +  QString::number(commodityNumber, 10) +
                    "    " + QString::number(commodityAmout, 'f', 2) + "\n";
            totalAmout += commodityAmout;
        }

        // 显示总金额
        detail += "总金额 ： " + QString::number(totalAmout, 'f', 2) + "\n";

        break;
//    case Suspend:
//        break;
//    default:
//        break;
    }
    ui->roomInfoText->setText(detail);
}

//void ChessRoomForm::on_chessRoomList_currentRowChanged(int currentRow)
//{
//    QMessageBox::warning(this, "警告", "currentRow = " + QString::number(currentRow, 10));
//}

//void ChessRoomForm::on_chessRoomList_itemSelectionChanged()
//{
//    QListWidgetItem * item =  ui->chessRoomList->currentItem();
//    if(item == NULL){
//        QMessageBox::warning(this, "警告", "item == NULL");
//        return;
//    }
//    QMessageBox::warning(this, "警告", item->text());
//}

void ChessRoomForm::on_commoditySaleButton_clicked()
{
    QListWidgetItem *item = ui->chessRoomList->currentItem();
    if(item == NULL){
        QMessageBox::warning(this, "警告", "未选中房间");
        return;
    }
    QString roomName = item->text();
    int roomId = _user->queryChessRoomId(roomName);
    int transactionId = 0;
    roomId = _user->queryChessTransactionId(roomId, transactionId);
    if(roomId <= 0){
        QMessageBox::warning(this, "警告", "房间未开启交易");
        return;
    }

    CommoditySaleDialog csd(_user, transactionId);
    csd.exec();

}

void ChessRoomForm::on_suspendButton_clicked()
{
    QString name = ui->chessRoomList->currentItem()->text();
    int id = _user->queryChessRoomId(name);
    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    switch (_statusFlag){
    case Free:
        ret = _user->suspendChessRoom(id);
        if (ret < 0){
            QMessageBox::warning(this, "警告", "挂起失败！");
            return;
        }
        break;
    case Suspend:
        ret = _user->cancelSuspendChessRoom(id);
        if (ret < 0){
            QMessageBox::warning(this, "警告", "取消挂起失败！");
            return;
        }
        break;
    default:
        QMessageBox::warning(this, "警告", "程序执行有错误！\n suspendButton");
        return;
    }
    updateRoomInfo();
}

void ChessRoomForm::on_scheduleButton_clicked()
{
    QString name = ui->chessRoomList->currentItem()->text();
    int id = _user->queryChessRoomId(name);
    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    switch (_statusFlag){
    case Free:{
        // 弹出挂起对话框
        ScheduleRoomDialog srd(_user, name);
        srd.exec();
        break;
    }
    case Schedule:
        // 确认取消操作
        ret = QMessageBox::question(
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
        // 取消挂起
        ret = _user->cancelScheduleChessRoom(id);
        if(ret < 0){
            QMessageBox::warning(this, "警告", "取消挂起失败或数据库异常！");
            return;
        }
        break;
    default:
        QMessageBox::warning(this, "警告", "程序执行有错误！\n suspendButton");
        return;
    }
    updateRoomInfo();
}

void ChessRoomForm::on_closeRoomButton_clicked()
{
    // 结账
    closeRoom();
}

void ChessRoomForm::on_changeFormulaButton_clicked()
{
    QString name = ui->chessRoomList->currentItem()->text();
    int id = _user->queryChessRoomId(name);
//    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    // 弹出公式修改对话框
    ChessRoomFormulaChangeDialog crfcd(_user, id);
    crfcd.exec();

    updateRoomInfo();
}

void ChessRoomForm::on_deletRoomButton_clicked()
{
    int ret = QMessageBox::question(
                this,
                "", "确实要删除该房间吗?",
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

    // 获取房间编号
    QString name = ui->chessRoomList->currentItem()->text();
    int id = _user->queryChessRoomId(name);
//    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }

    ret = _user->deleteChessRoom(id);
    if(ret == -101){
        QMessageBox::warning(this, "警告", "用户无权删除房间！");
        return;
    } else if(ret == -102){
        QMessageBox::warning(this, "警告", "房间不存在！");
        return;
    } else if(ret == -103){
        QMessageBox::warning(this, "警告", "该房间已经存在开房记录！");
        return;
    }
    if(ret < 0){
        QMessageBox::warning(this, "警告", "sql执行错误！");
        return;
    }

    QMessageBox::information(this, "通知", "房间删除成功！");

    this->updateRoomInfo();
}

void ChessRoomForm::on_chessRoomList_itemDoubleClicked(QListWidgetItem *item)
{
    QString name = item->text();
    int id = _user->queryChessRoomId(name);
//    int ret = 0;
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    ChessRoomState status = (ChessRoomState)0;
    id = _user->queryChessRoomStatus(id, status);
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间状态获取失败或数据库异常！");
        return;
    }
    switch (status){
    case Free:
        openRoom();
        break;
    case Schedule:
        openRoom();
        break;
    case Busy:
        closeRoom();
        break;
    case Suspend:
        break;
    default:
        break;
    }
}
