#ifndef TIMESLOTFORM_H
#define TIMESLOTFORM_H

#include <QWidget>
#include <QDateTime>

namespace Ui {
class TimeSlotForm;
}

class TimeSlotForm : public QWidget
{
    Q_OBJECT

public:
    explicit TimeSlotForm(QWidget *parent = 0);
    ~TimeSlotForm();

    void setStartDateTime(QDateTime dateTime);
    QDateTime getStartDateTime();
    void setEndDateTime(QDateTime dateTime);
    QDateTime getEndDateTime();

    Qt::CheckState startTimeCheck();
    Qt::CheckState endTimeCheck();
private:
    Ui::TimeSlotForm *ui;
};

#endif // TIMESLOTFORM_H
