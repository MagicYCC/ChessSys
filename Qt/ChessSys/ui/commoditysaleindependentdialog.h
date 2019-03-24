#ifndef COMMODITYSALEINDEPENDENTDIALOG_H
#define COMMODITYSALEINDEPENDENTDIALOG_H

#include "commoditysaledialog.h"

class CommoditySaleIndependentDialog : public CommoditySaleDialog
{
public:
    CommoditySaleIndependentDialog(ChessSysUser* user, int transactionId = 0, QWidget *parent = 0);
    virtual void sureTransaction();
};

#endif // COMMODITYSALEINDEPENDENTDIALOG_H
