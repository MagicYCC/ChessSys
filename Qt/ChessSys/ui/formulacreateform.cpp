#include "formulacreateform.h"
#include "formulacalcuaverform.h"
#include "formulacalcu2slotsform.h"
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

    delete ui->twoSlotPage;
    ui->twoSlotPage = new FormulaCalcu2SlotsForm;
    ui->twoSlotPage->setObjectName(QStringLiteral("twoSlotPage"));
    ui->stackedWidget->addWidget(ui->twoSlotPage);

    ui->stackedWidget->setCurrentWidget(ui->averPage);
}

FormulaCreateForm::~FormulaCreateForm()
{
    delete ui;
}

// 获取计费公式
QString FormulaCreateForm::getFormula() {
    FormulaTempType index = (FormulaTempType)ui->formulaComboBox->currentIndex();
    switch(index)
    {
    case Average:
        return ((FormulaCalcuAverForm *)ui->averPage)->getFormula();
    case TwoSlots:
        return ((FormulaCalcu2SlotsForm *)ui->twoSlotPage)->getFormula();
    default:
        return ((FormulaCalcuAverForm *)ui->averPage)->getFormula();
    }
}

void FormulaCreateForm::on_formulaComboBox_currentIndexChanged(int index)
{
    switch((FormulaTempType)index)
    {
    case Average:
        ui->stackedWidget->setCurrentWidget(ui->averPage);
        break;
    case TwoSlots:
        ui->stackedWidget->setCurrentWidget(ui->twoSlotPage);
        break;
    default:
        ui->stackedWidget->setCurrentWidget(ui->averPage);
        break;
    }
}
