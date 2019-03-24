#ifndef BENEFITANALYSISFORM_H
#define BENEFITANALYSISFORM_H

#include <QWidget>
#include "chess_sys_user.h"

namespace Ui {
class BenefitAnalysisForm;
}

class BenefitAnalysisForm : public QWidget
{
    Q_OBJECT

public:
    explicit BenefitAnalysisForm(ChessSysUser *user, QWidget *parent = 0);
    ~BenefitAnalysisForm();

private:
    Ui::BenefitAnalysisForm *ui;
    ChessSysUser *_user;
};

#endif // BENEFITANALYSISFORM_H
