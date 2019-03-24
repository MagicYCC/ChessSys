#ifndef GENERALTRANSACTIONFORM_H
#define GENERALTRANSACTIONFORM_H

#include <QTableWidgetItem>
#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class GeneralTransactionForm;
}

class GeneralTransactionForm : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTransactionForm(ChessSysUser *user, QWidget *parent = 0);
    ~GeneralTransactionForm();

    void initGeneralTable();
    void queryGeneralAnaly();

public:
    static const QString GeneralFieldAlias[];

private slots:
    void on_queryButton_clicked();

    void on_outputButton_clicked();

    void on_generalAnalyTable_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::GeneralTransactionForm *ui;
    ChessSysUser *_user;

    int _categoryCount;
};

#endif // GENERALTRANSACTIONFORM_H
