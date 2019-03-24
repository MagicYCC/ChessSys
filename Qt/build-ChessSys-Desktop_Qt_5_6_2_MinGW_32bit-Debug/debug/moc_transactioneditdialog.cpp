/****************************************************************************
** Meta object code from reading C++ file 'transactioneditdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChessSys/ui/transactioneditdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transactioneditdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TransactionEditDialog_t {
    QByteArrayData data[6];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TransactionEditDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TransactionEditDialog_t qt_meta_stringdata_TransactionEditDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TransactionEditDialog"
QT_MOC_LITERAL(1, 22, 32), // "on_commodityDeleteButton_clicked"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 27), // "on_roomUpdateButton_clicked"
QT_MOC_LITERAL(4, 84, 32), // "on_commodityUpdateButton_clicked"
QT_MOC_LITERAL(5, 117, 28) // "on_bonusUpdateButton_clicked"

    },
    "TransactionEditDialog\0"
    "on_commodityDeleteButton_clicked\0\0"
    "on_roomUpdateButton_clicked\0"
    "on_commodityUpdateButton_clicked\0"
    "on_bonusUpdateButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TransactionEditDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TransactionEditDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TransactionEditDialog *_t = static_cast<TransactionEditDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_commodityDeleteButton_clicked(); break;
        case 1: _t->on_roomUpdateButton_clicked(); break;
        case 2: _t->on_commodityUpdateButton_clicked(); break;
        case 3: _t->on_bonusUpdateButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TransactionEditDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TransactionEditDialog.data,
      qt_meta_data_TransactionEditDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TransactionEditDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TransactionEditDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TransactionEditDialog.stringdata0))
        return static_cast<void*>(const_cast< TransactionEditDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TransactionEditDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
