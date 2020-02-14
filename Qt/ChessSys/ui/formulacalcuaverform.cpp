#include "formulacalcuaverform.h"
#include "ui_formulacalcuaverform.h"

FormulaCalcuAverForm::FormulaCalcuAverForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormulaCalcuAverForm)
{
    ui->setupUi(this);
    updateFormula();
}

FormulaCalcuAverForm::~FormulaCalcuAverForm()
{
    delete ui;
}

void FormulaCalcuAverForm::on_formulaCreateButton_clicked()
{
   updateFormula();
}

// 生成计费公式
void FormulaCalcuAverForm::updateFormula(){
    double hp = ui->priceEdit->text().toDouble();// 小时单价
    double jt = ui->jumpTimeEdit->text().toDouble();// 跳费时长
    double gp = ui->gainEdit->text().toDouble();// 增值费用
    double mp = ui->minPriceEdit->text().toDouble();// 最低消费

    // 计算跳费金额
    double jp = hp*jt/60;
    // 生成公式
    // greatest( (floor(time/jt) + 1)*jp + gp, mp)
    QString formula = "greatest( (floor(time/" + QString::number(jt,'f', 2) +
            ") + 1)*" + QString::number(jp, 'f', 2) + " + " +
            QString::number(gp, 'f', 2) + ", " + QString::number(mp, 'f', 2) + ")";

    // 更新到控件中
    ui->formulaEdit->setText(formula);
}

// 获取计费公式
QString FormulaCalcuAverForm::getFormula(){

    return ui->formulaEdit->text();
}
