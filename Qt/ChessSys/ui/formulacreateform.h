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
    enum FormulaTempType
    {
        Average = 0,
        TwoSlots,
    };

public:
    explicit FormulaCreateForm(QWidget *parent = 0);
    ~FormulaCreateForm();

    QString getFormula();
private slots:
    void on_formulaComboBox_currentIndexChanged(int index);

private:
    Ui::FormulaCreateForm *ui;
};

#endif // FORMULACREATEFORM_H
