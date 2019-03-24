/****************************************************************************
** Meta object code from reading C++ file 'chessroomform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ChessSys/ui/chessroomform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessroomform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChessRoomForm_t {
    QByteArrayData data[17];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessRoomForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessRoomForm_t qt_meta_stringdata_ChessRoomForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ChessRoomForm"
QT_MOC_LITERAL(1, 14, 24), // "on_addRoomButton_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(4, 64, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(5, 86, 35), // "on_chessRoomList_currentItemC..."
QT_MOC_LITERAL(6, 122, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(7, 139, 7), // "current"
QT_MOC_LITERAL(8, 147, 8), // "previous"
QT_MOC_LITERAL(9, 156, 30), // "on_commoditySaleButton_clicked"
QT_MOC_LITERAL(10, 187, 24), // "on_suspendButton_clicked"
QT_MOC_LITERAL(11, 212, 25), // "on_scheduleButton_clicked"
QT_MOC_LITERAL(12, 238, 26), // "on_closeRoomButton_clicked"
QT_MOC_LITERAL(13, 265, 30), // "on_changeFormulaButton_clicked"
QT_MOC_LITERAL(14, 296, 26), // "on_deletRoomButton_clicked"
QT_MOC_LITERAL(15, 323, 34), // "on_chessRoomList_itemDoubleCl..."
QT_MOC_LITERAL(16, 358, 4) // "item"

    },
    "ChessRoomForm\0on_addRoomButton_clicked\0"
    "\0on_updateButton_clicked\0on_openButton_clicked\0"
    "on_chessRoomList_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous\0"
    "on_commoditySaleButton_clicked\0"
    "on_suspendButton_clicked\0"
    "on_scheduleButton_clicked\0"
    "on_closeRoomButton_clicked\0"
    "on_changeFormulaButton_clicked\0"
    "on_deletRoomButton_clicked\0"
    "on_chessRoomList_itemDoubleClicked\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessRoomForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    2,   72,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    0,   81,    2, 0x08 /* Private */,
      14,    0,   82,    2, 0x08 /* Private */,
      15,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,   16,

       0        // eod
};

void ChessRoomForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChessRoomForm *_t = static_cast<ChessRoomForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addRoomButton_clicked(); break;
        case 1: _t->on_updateButton_clicked(); break;
        case 2: _t->on_openButton_clicked(); break;
        case 3: _t->on_chessRoomList_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        case 4: _t->on_commoditySaleButton_clicked(); break;
        case 5: _t->on_suspendButton_clicked(); break;
        case 6: _t->on_scheduleButton_clicked(); break;
        case 7: _t->on_closeRoomButton_clicked(); break;
        case 8: _t->on_changeFormulaButton_clicked(); break;
        case 9: _t->on_deletRoomButton_clicked(); break;
        case 10: _t->on_chessRoomList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ChessRoomForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChessRoomForm.data,
      qt_meta_data_ChessRoomForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChessRoomForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessRoomForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChessRoomForm.stringdata0))
        return static_cast<void*>(const_cast< ChessRoomForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChessRoomForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
