#ifndef FORMULACREATEFORM_H
#define FORMULACREATEFORM_H

#include <QWidget>

namespace Ui {
class FormulaCreateForm;
}

class FormulaCreateForm : public QWidget
{
    Q_OBJECT

public:
    explicit FormulaCreateForm(QWidget *parent = 0);
    ~FormulaCreateForm();

    // 更新计费公式
    void updateFormula();

    // 获取计费公式
    QString getFormula();

private slots:
    void on_formulaCreateButton_clicked();

private:
    Ui::FormulaCreateForm *ui;
};

#endif // FORMULACREATEFORM_H
