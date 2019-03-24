#ifndef BONUSRECORDFORM_H
#define BONUSRECORDFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class BonusRecordForm;
}

class BonusRecordForm : public QWidget
{
    Q_OBJECT

public:
    explicit BonusRecordForm(ChessSysUser* user, QWidget *parent = 0);
    ~BonusRecordForm();

    // 初始化红利记录表
    void initBonusTable();
    // 查询红利记录
    void queryBonusRecord();

public:
    static const QString BonusFieldAlias[];

private slots:
    void on_queryButton_clicked();

    void on_outputButton_clicked();

private:
    Ui::BonusRecordForm *ui;
    ChessSysUser* _user;
};

#endif // BONUSRECORDFORM_H
