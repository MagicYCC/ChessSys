#include "formulacalcu2slotsform.h"
#include "ui_formulacalcu2slotsform.h"

FormulaCalcu2SlotsForm::FormulaCalcu2SlotsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormulaCalcu2SlotsForm)
{
    ui->setupUi(this);
    updateFormula();
}

FormulaCalcu2SlotsForm::~FormulaCalcu2SlotsForm()
{
    delete ui;
}

void FormulaCalcu2SlotsForm::on_pushButton_clicked()
{
    updateFormula();
}

// 更新计费公式
void FormulaCalcu2SlotsForm::updateFormula()
{
    FormulaInfo info;
    getFormulaInfo(info);

    QString sp1 = QString::number(info._startPrice1, 'f', 2);   // 起步价1 sp1
    QString sp2 = QString::number(info._startPrice2, 'f', 2);   // 起步价2 sp2
    QString st1 = QString::number((long)info._startTime1);      // 起步时长1（分钟）st1
    QString st2 = QString::number((long)info._startTime2);      // 起步时长2（分钟）st2
    QString jt  = QString::number((long)info._jumpTime);        // 后续跳费时长（分钟）jt
    QString jp1 = QString::number(info._jumpPrice1, 'f', 2);    // 跳费价格1 jp1
    QString jp2 = QString::number(info._jumpPrice2, 'f', 2);    // 跳费价格2 jp2
    QString sjt = QString::number((long)info._slotStartTime);   // 跳费价格2当日起始时间（分钟） sjt > 0(当日0点)
    QString ejt = QString::number((long)info._slotEndTime);     // 跳费价格2当日结束时间（分钟） ejt <= 1440(24点)

    QString formula = "IF(HOUR(entry_time)*60 + MINUTE(entry_time) >= " + sjt + " AND HOUR(entry_time)*60 + MINUTE(entry_time) < " + ejt + ", " + sp2 + " + IF(time < " + st2 + ", 0, FLOOR((time - " + st2 + ")/1440)*(1440/" + jt + "*" + jp1 + "+(" + ejt + "-" + sjt + ")/" + jt + "*(" + jp2 + "-" + jp1 + ")) + (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), closing_time)/" + jt + ") + 1)*(" + jp1 + ")+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))>=" + sjt + " AND HOUR(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))<" + ejt + ", (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), LEAST(DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), closing_time))/" + jt + ") + 1 + IF(DATE_SUB(closing_time, INTERVAL 1 DAY) < DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), 0, FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), closing_time)/" + jt + ") - FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440)+1 DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + sjt + " MINUTE))/" + jt + "))), FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), closing_time)/" + jt + ") + 1 - (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), LEAST(DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + sjt + " MINUTE), closing_time))/" + jt + ") + 1 + IF(closing_time < DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), 0, FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), closing_time)/" + jt + ") - FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440) DAY), INTERVAL " + st2 + " MINUTE), DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st2 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st2 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st2 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE))/" + jt + "))))*(" + jp2 + "-" + jp1 + ")), " + sp1 + " + IF(time < " + st1 + ", 0, FLOOR((time - " + st1 + ")/1440)*(1440/" + jt + "*" + jp1 + "+(" + ejt + "-" + sjt + ")/" + jt + "*(" + jp2 + "-" + jp1 + ")) + (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), closing_time)/" + jt + ") + 1)*(" + jp1 + ")+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))>=" + sjt + " AND HOUR(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))<" + ejt + ", (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), LEAST(DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), closing_time))/" + jt + ") + 1 + IF(DATE_SUB(closing_time, INTERVAL 1 DAY) < DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), 0, FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), closing_time)/" + jt + ") - FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440)+1 DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + sjt + " MINUTE))/" + jt + "))), FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), closing_time)/" + jt + ") + 1 - (FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), LEAST(DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + sjt + " MINUTE), closing_time))/" + jt + ") + 1 + IF(closing_time < DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE), 0, FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), closing_time)/" + jt + ") - FLOOR(TIMESTAMPDIFF(MINUTE, DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440) DAY), INTERVAL " + st1 + " MINUTE), DATE_ADD(CAST(DATE_ADD(DATE_ADD(entry_time, INTERVAL FLOOR((time - " + st1 + ")/1440)+IF(HOUR(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))*60 + MINUTE(DATE_ADD(entry_time, INTERVAL " + st1 + " MINUTE))<" + sjt + ", 0, 1) DAY), INTERVAL " + st1 + " MINUTE) AS DATE), INTERVAL " + ejt + " MINUTE))/" + jt + "))))*(" + jp2 + "-" + jp1 + ")))";

    ui->formulaEdit->setText(formula);
}

// 获取计费公式
QString FormulaCalcu2SlotsForm::getFormula()
{
    return ui->formulaEdit->text();
}

void FormulaCalcu2SlotsForm::getFormulaInfo(FormulaInfo &info)
{
    double jumpTime = ui->jumpTimeEdit->text().toDouble();
    jumpTime = jumpTime >= 60 ? 60 : jumpTime;

    SlotInfo    slotInfo1, slotInfo2;
    QTime       slot;
    int         min;

    slot                        = ui->slot1StartTimeEdit->time();
    min                         = slot.hour()*60 + slot.minute();
    slotInfo1._slotStartTime    = min <= 0 ? 1440 : min;
    slot                        = ui->slot1EndTimeEdit->time();
    min                         = slot.hour()*60 + slot.minute();
    slotInfo1._slotEndTime      = min <= 0 ? 1440 : min;
    slotInfo1._startPrice       = ui->startPrice1Edit->text().toDouble();
    slotInfo1._startTime        = ui->startTime1Edit->text().toDouble();
    slotInfo1._jumpPrice        = ui->jumpPrice1Edit->text().toDouble()*jumpTime/60;

    slot                        = ui->slot2StartTimeEdit->time();
    min                         = slot.hour()*60 + slot.minute();
    slotInfo2._slotStartTime    = min <= 0 ? 1440 : min;
    slot                        = ui->slot2EndTimeEdit->time();
    min                         = slot.hour()*60 + slot.minute();
    slotInfo2._slotEndTime      = min <= 0 ? 1440 : min;
    slotInfo2._startPrice       = ui->startPrice2Edit->text().toDouble();
    slotInfo2._startTime        = ui->startTime2Edit->text().toDouble();
    slotInfo2._jumpPrice        = ui->jumpPrice2Edit->text().toDouble()*jumpTime/60;

    SlotInfo *pSlotInfo1    = &slotInfo1;
    SlotInfo *pSlotInfo2    = &slotInfo2;
    if(slotInfo1._slotStartTime < slotInfo1._slotEndTime)
    {
        pSlotInfo1 = &slotInfo2;
        pSlotInfo2 = &slotInfo1;
    }

    info._slotStartTime = pSlotInfo2->_slotStartTime;
    info._slotEndTime   = pSlotInfo2->_slotEndTime;
    info._startPrice1   = pSlotInfo1->_startPrice;
    info._startTime1    = pSlotInfo1->_startTime;
    info._jumpPrice1    = pSlotInfo1->_jumpPrice;
    info._startPrice2   = pSlotInfo2->_startPrice;
    info._startTime2    = pSlotInfo2->_startTime;
    info._jumpPrice2    = pSlotInfo2->_jumpPrice;
    info._jumpTime      = jumpTime;
}

void FormulaCalcu2SlotsForm::on_slot2StartTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    ui->slot1EndTimeEdit->setTime(dateTime.time());
}

void FormulaCalcu2SlotsForm::on_slot2EndTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    ui->slot1StartTimeEdit->setTime(dateTime.time());
}

void FormulaCalcu2SlotsForm::on_slot1StartTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    ui->slot2EndTimeEdit->setTime(dateTime.time());
}

void FormulaCalcu2SlotsForm::on_slot1EndTimeEdit_dateTimeChanged(const QDateTime &dateTime)
{
    ui->slot2StartTimeEdit->setTime(dateTime.time());
}
