#include "chessroomopendialog.h"
#include "ui_chessroomopendialog.h"
#include <QMessageBox>

const int ChessRoomOpenDialog::RoomOpened = 101;

ChessRoomOpenDialog::ChessRoomOpenDialog(ChessSysUser *user, QString name, QWidget *parent) :
    _user(user),
    _name(name),
    QDialog(parent),
    ui(new Ui::ChessRoomOpenDialog)
{
    ui->setupUi(this);

    this->setWindowTitle("棋牌房间开设");
    ui->nameLabel->setText("房间名：" + _name);

    initTime();

}

ChessRoomOpenDialog::~ChessRoomOpenDialog()
{
    delete ui;
}

void ChessRoomOpenDialog::on_sureButton_clicked()
{
    openRoom();
}

void ChessRoomOpenDialog::openRoom(){
    int id = _user->queryChessRoomId(_name);
    if(id <= 0){
        QMessageBox::warning(this, "警告", "房间信息有误！");
        return;
    }
    QDateTime time;
    time.setDate(ui->openDateEdit->date());
    time.setTime(ui->openTimeEdit->time());
    _user->openChessRoom(id, time);

    this->done(RoomOpened);
}

void ChessRoomOpenDialog::initTime(){
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

    // 设置scheduleDateEdit和scheduleTimeEdit
    ui->openDateEdit->setDate(time.date());
    ui->openTimeEdit->setTime(time.time());
}

