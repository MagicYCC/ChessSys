/****************************************************************************
** Meta object code from reading C++ file 'stockmanageform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChessSys/ui/stockmanageform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockmanageform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StockManageForm_t {
    QByteArrayData data[11];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockManageForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockManageForm_t qt_meta_stringdata_StockManageForm = {
    {
QT_MOC_LITERAL(0, 0, 15), // "StockManageForm"
QT_MOC_LITERAL(1, 16, 25), // "on_addStockButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 29), // "on_addCommodityButton_clicked"
QT_MOC_LITERAL(4, 73, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(5, 97, 29), // "on_updateRecordButton_clicked"
QT_MOC_LITERAL(6, 127, 29), // "on_cancelRecordButton_clicked"
QT_MOC_LITERAL(7, 157, 23), // "on_activeButton_clicked"
QT_MOC_LITERAL(8, 181, 24), // "on_forSaleButton_clicked"
QT_MOC_LITERAL(9, 206, 28), // "on_changePriceButton_clicked"
QT_MOC_LITERAL(10, 235, 23) // "on_deleteButton_clicked"

    },
    "StockManageForm\0on_addStockButton_clicked\0"
    "\0on_addCommodityButton_clicked\0"
    "on_updateButton_clicked\0"
    "on_updateRecordButton_clicked\0"
    "on_cancelRecordButton_clicked\0"
    "on_activeButton_clicked\0"
    "on_forSaleButton_clicked\0"
    "on_changePriceButton_clicked\0"
    "on_deleteButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockManageForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StockManageForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockManageForm *_t = static_cast<StockManageForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addStockButton_clicked(); break;
        case 1: _t->on_addCommodityButton_clicked(); break;
        case 2: _t->on_updateButton_clicked(); break;
        case 3: _t->on_updateRecordButton_clicked(); break;
        case 4: _t->on_cancelRecordButton_clicked(); break;
        case 5: _t->on_activeButton_clicked(); break;
        case 6: _t->on_forSaleButton_clicked(); break;
        case 7: _t->on_changePriceButton_clicked(); break;
        case 8: _t->on_deleteButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject StockManageForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StockManageForm.data,
      qt_meta_data_StockManageForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockManageForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockManageForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockManageForm.stringdata0))
        return static_cast<void*>(const_cast< StockManageForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int StockManageForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
