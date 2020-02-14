#include "formulacreateform.h"
#include "formulacalcuaverform.h"
#include "ui_formulacreateform.h"

FormulaCreateForm::FormulaCreateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormulaCreateForm)
{
    ui->setupUi(this);

    // stacked页面设置
    delete ui->averPage;
    ui->averPage = new FormulaCalcuAverForm;
    ui->averPage->setObjectName(QStringLiteral("averPage"));
    ui->stackedWidget->addWidget(ui->averPage);

    ui->stackedWidget->setCurrentWidget(ui->averPage);
}

FormulaCreateForm::~FormulaCreateForm()
{
    delete ui;
}

// 获取计费公式
QString FormulaCreateForm::getFormula() {
    return ((FormulaCalcuAverForm *)ui->averPage)->getFormula();
}
