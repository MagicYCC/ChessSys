#include "timeslotform.h"
#include "ui_timeslotform.h"

TimeSlotForm::TimeSlotForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeSlotForm)
{
    ui->setupUi(this);
}

TimeSlotForm::~TimeSlotForm()
{
    delete ui;
}


void TimeSlotForm::setStartDateTime(QDateTime dateTime){
    ui->startDateEdit->setDate(dateTime.date());
    ui->startTimeEdit->setTime(dateTime.time());
}

QDateTime TimeSlotForm::getStartDateTime(){
    QDateTime dateTime;
    dateTime.setDate(ui->startDateEdit->date());
    dateTime.setTime(ui->startTimeEdit->time());
    return dateTime;
}

void TimeSlotForm::setEndDateTime(QDateTime dateTime){
    ui->endDateEdit->setDate(dateTime.date());
    ui->endTimeEdit->setTime(dateTime.time());
}

QDateTime TimeSlotForm::getEndDateTime(){
    QDateTime dateTime;
    dateTime.setDate(ui->endDateEdit->date());
    dateTime.setTime(ui->endTimeEdit->time());
    return dateTime;
}

Qt::CheckState TimeSlotForm::startTimeCheck(){
    return ui->startCheck->checkState();
}

Qt::CheckState TimeSlotForm::endTimeCheck(){
    return ui->endCheck->checkState();
}
