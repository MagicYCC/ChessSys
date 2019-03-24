#include "scheduleroomdialog.h"
#include "ui_scheduleroomdialog.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDateTime>

ScheduleRoomDialog::ScheduleRoomDialog(ChessSysUser* user, QString name, QWidget *parent) :
    _user(user),
    _name(name),
    QDialog(parent),
    ui(new Ui::ScheduleRoomDialog)
{
    ui->setupUi(this);

    setWindowTitle("房间预订");

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
    ui->scheduleDateEdit->setDate(time.date());
    ui->scheduleTimeEdit->setTime(time.time());

}

ScheduleRoomDialog::~ScheduleRoomDialog()
{
    delete ui;
}

void ScheduleRoomDialog::on_sureButton_clicked()
{
    int roomId = _user->queryChessRoomId(_name);
    if(roomId <= 0){
        QMessageBox::warning(this, "警告", "房间不存在或数据库异常！");
        return;
    }
    QString remark = ui->remarkEdit->toPlainText();
    QDateTime dateTime = ui->scheduleDateEdit->dateTime();
    dateTime.setTime(ui->scheduleTimeEdit->time());
    int ret = _user->scheduleChessRoom(roomId, dateTime, remark);
    if(ret < 0){
        QMessageBox::warning(this, "警告", "预订失败或数据库异常！");
        return;
    }
    QMessageBox::information(this, "通知", "预订成功！");
    close();
}
