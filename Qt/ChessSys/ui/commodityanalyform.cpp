#include "commodityanalyform.h"
#include "ui_commodityanalyform.h"

CommodityAnalyForm::CommodityAnalyForm(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::CommodityAnalyForm)
{
    ui->setupUi(this);

    setWindowTitle("商品出入分析");
}

CommodityAnalyForm::~CommodityAnalyForm()
{
    delete ui;
}
