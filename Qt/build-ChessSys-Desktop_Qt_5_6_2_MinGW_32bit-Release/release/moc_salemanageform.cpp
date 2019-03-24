/****************************************************************************
** Meta object code from reading C++ file 'salemanageform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChessSys/ui/salemanageform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'salemanageform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SaleManageForm_t {
    QByteArrayData data[10];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SaleManageForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SaleManageForm_t qt_meta_stringdata_SaleManageForm = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SaleManageForm"
QT_MOC_LITERAL(1, 15, 34), // "on_updateTransactionButton_cl..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 28), // "on_updateSalesButton_clicked"
QT_MOC_LITERAL(4, 80, 21), // "on_saleButton_clicked"
QT_MOC_LITERAL(5, 102, 27), // "on_deleteSaleButton_clicked"
QT_MOC_LITERAL(6, 130, 34), // "on_deleteTransactionButton_cl..."
QT_MOC_LITERAL(7, 165, 37), // "on_transactionTable_itemDoubl..."
QT_MOC_LITERAL(8, 203, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(9, 221, 4) // "item"

    },
    "SaleManageForm\0on_updateTransactionButton_clicked\0"
    "\0on_updateSalesButton_clicked\0"
    "on_saleButton_clicked\0on_deleteSaleButton_clicked\0"
    "on_deleteTransactionButton_clicked\0"
    "on_transactionTable_itemDoubleClicked\0"
    "QTableWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaleManageForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    1,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void SaleManageForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SaleManageForm *_t = static_cast<SaleManageForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_updateTransactionButton_clicked(); break;
        case 1: _t->on_updateSalesButton_clicked(); break;
        case 2: _t->on_saleButton_clicked(); break;
        case 3: _t->on_deleteSaleButton_clicked(); break;
        case 4: _t->on_deleteTransactionButton_clicked(); break;
        case 5: _t->on_transactionTable_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SaleManageForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SaleManageForm.data,
      qt_meta_data_SaleManageForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SaleManageForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaleManageForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SaleManageForm.stringdata0))
        return static_cast<void*>(const_cast< SaleManageForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int SaleManageForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
