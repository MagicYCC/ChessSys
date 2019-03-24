#include "benefitanalysisform.h"
#include "generaltransactionform.h"
#include "commodityanalyform.h"
#include "bonusrecordform.h"
#include "roomrecordqueryform.h"
#include "ui_benefitanalysisform.h"

BenefitAnalysisForm::BenefitAnalysisForm(ChessSysUser *user, QWidget *parent) :
    _user(user),
    QWidget(parent),
    ui(new Ui::BenefitAnalysisForm)
{
    ui->setupUi(this);

    // 收益页面添加
    delete ui->generalTab;
    ui->generalTab = new GeneralTransactionForm(_user);
    ui->generalTab->setObjectName(QStringLiteral("generalTab"));
    ui->benefitTabWidget->addTab(ui->generalTab, "综合交易分析");

    delete ui->commodityTab;
    ui->commodityTab = new CommodityAnalyForm(_user);
    ui->commodityTab->setObjectName(QStringLiteral("commodityTab"));
    ui->benefitTabWidget->addTab(ui->commodityTab, "商品出入分析");

    // 记录页面添加
    delete ui->roomTab;
    ui->roomTab = new RoomRecordQueryForm(_user);
    ui->roomTab->setObjectName(QStringLiteral("roomTab"));
    ui->recordTabWidget->addTab(ui->roomTab, "房间记录查询");

    delete ui->bonusTab;
    ui->bonusTab = new BonusRecordForm(_user);
    ui->bonusTab->setObjectName(QStringLiteral("bonusTab"));
    ui->recordTabWidget->addTab(ui->bonusTab, "红包记录查询");

}

BenefitAnalysisForm::~BenefitAnalysisForm()
{
    delete ui;
}
