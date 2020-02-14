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

    QString getFormula();
private:
    Ui::FormulaCreateForm *ui;
};

#endif // FORMULACREATEFORM_H
