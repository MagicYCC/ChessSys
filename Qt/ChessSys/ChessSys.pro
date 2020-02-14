#-------------------------------------------------
#
# Project created by QtCreator 2017-08-18T05:49:02
#
#-------------------------------------------------

QT       += core gui sql axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChessSys
TEMPLATE = app

RC_ICONS = myappico.ico

SOURCES += main.cpp\
    chess_sys_db/chess_sys_user.cpp \
    ui/logindialog.cpp \
    ui/mainwindow.cpp \
    ui/chessroomform.cpp \
    ui/chessroomicon.cpp \
    ui/chessroomadddialog.cpp \
    ui/stockmanageform.cpp \
    ui/commodityadddialog.cpp \
    ui/commoditycategoryadddialog.cpp \
    ui/stockadddialog.cpp \
    ui/commoditypricechangedialog.cpp \
    ui/commoditysaledialog.cpp \
    ui/scheduleroomdialog.cpp \
    ui/scheduletransactiondialog.cpp \
    ui/transactioninfodialog.cpp \
    ui/userinfoform.cpp \
    ui/usercreatedialog.cpp \
    ui/salemanageform.cpp \
    ui/commoditysaleindependentdialog.cpp \
    ui/formulacreateform.cpp \
    ui/chessroomformulachangedialog.cpp \
    ui/transactioneditdialog.cpp \
    ui/benefitanalysisform.cpp \
    ui/commodityanalyform.cpp \
    ui/generaltransactionform.cpp \
    ui/roomrecordqueryform.cpp \
    ui/bonusrecordform.cpp \
    ui/timeslotform.cpp \
    com/odbcexcel.cpp \
    ui/categorybrowsedialog.cpp \
    ui/chessroomopendialog.cpp \
    ui/formulacalcuaverform.cpp

HEADERS  += \
    chess_sys_db/chess_sys_user.h \
    ui/logindialog.h \
    ui/mainwindow.h \
    ui/chessroomform.h \
    ui/chessroomicon.h \
    ui/chessroomadddialog.h \
    ui/stockmanageform.h \
    ui/commodityadddialog.h \
    ui/commoditycategoryadddialog.h \
    ui/stockadddialog.h \
    ui/commoditypricechangedialog.h \
    ui/commoditysaledialog.h \
    ui/scheduleroomdialog.h \
    ui/scheduletransactiondialog.h \
    ui/transactioninfodialog.h \
    ui/userinfoform.h \
    ui/usercreatedialog.h \
    ui/salemanageform.h \
    ui/commoditysaleindependentdialog.h \
    ui/formulacreateform.h \
    ui/chessroomformulachangedialog.h \
    ui/transactioneditdialog.h \
    ui/benefitanalysisform.h \
    ui/commodityanalyform.h \
    ui/generaltransactionform.h \
    ui/roomrecordqueryform.h \
    ui/bonusrecordform.h \
    ui/timeslotform.h \
    com/odbcexcel.h \
    ui/categorybrowsedialog.h \
    ui/chessroomopendialog.h \
    ui/formulacalcuaverform.h

INCLUDEPATH += \
    ui \
    chess_sys_db \
    com

FORMS    += \
    ui/logindialog.ui \
    ui/mainwindow.ui \
    ui/chessroomform.ui \
    ui/chessroomadddialog.ui \
    ui/stockmanageform.ui \
    ui/commodityadddialog.ui \
    ui/commoditycategoryadddialog.ui \
    ui/stockadddialog.ui \
    ui/commoditypricechangedialog.ui \
    ui/commoditysaledialog.ui \
    ui/scheduleroomdialog.ui \
    ui/scheduletransactiondialog.ui \
    ui/transactioninfodialog.ui \
    ui/userinfoform.ui \
    ui/usercreatedialog.ui \
    ui/salemanageform.ui \
    ui/formulacreateform.ui \
    ui/chessroomformulachangedialog.ui \
    ui/transactioneditdialog.ui \
    ui/benefitanalysisform.ui \
    ui/commodityanalyform.ui \
    ui/generaltransactionform.ui \
    ui/roomrecordqueryform.ui \
    ui/bonusrecordform.ui \
    ui/timeslotform.ui \
    ui/categorybrowsedialog.ui \
    ui/chessroomopendialog.ui \
    ui/formulacalcuaverform.ui

