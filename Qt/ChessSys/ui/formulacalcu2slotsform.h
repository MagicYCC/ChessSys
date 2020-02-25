#ifndef FORMULACALCU2SLOTSFORM_H
#define FORMULACALCU2SLOTSFORM_H

#include <QWidget>

namespace Ui {
class FormulaCalcu2SlotsForm;
}

class FormulaCalcu2SlotsForm : public QWidget
{
    Q_OBJECT

public:
    explicit FormulaCalcu2SlotsForm(QWidget *parent = 0);
    ~FormulaCalcu2SlotsForm();

    // 更新计费公式
    void updateFormula();

    // 获取计费公式
    QString getFormula();

protected:
    struct FormulaInfo;
    struct SlotInfo;

    void getFormulaInfo(FormulaInfo &info);

private slots:
    void on_pushButton_clicked();

    void on_slot2StartTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_slot2EndTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_slot1StartTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_slot1EndTimeEdit_dateTimeChanged(const QDateTime &dateTime);

protected:
    struct FormulaInfo
    {
        // 0 < _slotStartTime <= _slotEndTime <= 1440
        double _slotStartTime;// 时间段二起始时间
        double _slotEndTime;// 时间段二结束时间
        double _startPrice1;
        double _startTime1;
        double _jumpPrice1;
        double _startPrice2;
        double _startTime2;
        double _jumpPrice2;
        double _jumpTime;
    };

    struct SlotInfo
    {
        double _slotStartTime;
        double _slotEndTime;
        double _startPrice;
        double _startTime;
        double _jumpPrice;
    };

private:
    Ui::FormulaCalcu2SlotsForm *ui;

};

#endif // FORMULACALCU2SLOTSFORM_H
