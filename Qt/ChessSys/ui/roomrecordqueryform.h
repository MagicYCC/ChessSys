#ifndef ROOMRECORDQUERYFORM_H
#define ROOMRECORDQUERYFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class RoomRecordQueryForm;
}

class RoomRecordQueryForm : public QWidget
{
    Q_OBJECT

public:
    explicit RoomRecordQueryForm(ChessSysUser* user, QWidget *parent = 0);
    ~RoomRecordQueryForm();

    void initRoomRecordTable();
    void queryRoomRecord();

private slots:
    void on_qureyButton_clicked();

    void on_outputButton_clicked();

public:
    static const QString RoomRecordFieldAlias[];
private:
    Ui::RoomRecordQueryForm *ui;
    ChessSysUser* _user;
};

#endif // ROOMRECORDQUERYFORM_H
