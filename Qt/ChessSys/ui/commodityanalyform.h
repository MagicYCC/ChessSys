#ifndef COMMODITYANALYFORM_H
#define COMMODITYANALYFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class CommodityAnalyForm;
}

class CommodityAnalyForm : public QWidget
{
    Q_OBJECT

public:
    explicit CommodityAnalyForm(ChessSysUser *user, QWidget *parent = 0);
    ~CommodityAnalyForm();

private:
    Ui::CommodityAnalyForm *ui;
    ChessSysUser *_user;
};

#endif // COMMODITYANALYFORM_H
