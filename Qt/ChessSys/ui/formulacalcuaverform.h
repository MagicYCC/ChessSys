#ifndef FORMULACALCUAVERFORM_H
#define FORMULACALCUAVERFORM_H

#include <QWidget>

namespace Ui {
class FormulaCalcuAverForm;
}

class FormulaCalcuAverForm : public QWidget
{
    Q_OBJECT

public:
    explicit FormulaCalcuAverForm(QWidget *parent = 0);
    ~FormulaCalcuAverForm();

    // 更新计费公式
    void updateFormula();

    // 获取计费公式
    QString getFormula();

private slots:
    void on_formulaCreateButton_clicked();

private:
    Ui::FormulaCalcuAverForm *ui;
};

#endif // FORMULACALCUAVERFORM_H
