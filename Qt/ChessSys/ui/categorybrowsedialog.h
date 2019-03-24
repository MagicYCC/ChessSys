#ifndef CATEGORYBROWSEDIALOG_H
#define CATEGORYBROWSEDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "chess_sys_user.h"

namespace Ui {
class CategoryBrowseDialog;
}

class CategoryBrowseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryBrowseDialog(ChessSysUser *user, QDateTime startTime,
                                QDateTime endTime, QString category,
                                QWidget *parent = 0);
    ~CategoryBrowseDialog();

    // 初始化分类浏览表
    void initCategoryTable();
    // 查询分类信息
    void queryCategory();

public:
    static const QString CategoryFieldAlias[];

private slots:
    void on_outputButton_clicked();

private:
    Ui::CategoryBrowseDialog *ui;
    ChessSysUser *_user;
    QDateTime _startTime;
    QDateTime _endTime;
    QString _category;

};

#endif // CATEGORYBROWSEDIALOG_H
