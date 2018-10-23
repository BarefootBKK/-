/****************************************************************************
** Meta object code from reading C++ file 'Onlinepvp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Onlinepvp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Onlinepvp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Onlinepvp_t {
    QByteArrayData data[15];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Onlinepvp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Onlinepvp_t qt_meta_stringdata_Onlinepvp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Onlinepvp"
QT_MOC_LITERAL(1, 10, 8), // "boardMsg"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 4), // "back"
QT_MOC_LITERAL(4, 25, 9), // "drawChess"
QT_MOC_LITERAL(5, 35, 4), // "undo"
QT_MOC_LITERAL(6, 40, 6), // "defeat"
QT_MOC_LITERAL(7, 47, 4), // "save"
QT_MOC_LITERAL(8, 52, 13), // "sendChessInfo"
QT_MOC_LITERAL(9, 66, 13), // "readChessInfo"
QT_MOC_LITERAL(10, 80, 9), // "initBoard"
QT_MOC_LITERAL(11, 90, 15), // "startTimeThread"
QT_MOC_LITERAL(12, 106, 15), // "countTimeThread"
QT_MOC_LITERAL(13, 122, 7), // "setTime"
QT_MOC_LITERAL(14, 130, 7) // "getHint"

    },
    "Onlinepvp\0boardMsg\0\0back\0drawChess\0"
    "undo\0defeat\0save\0sendChessInfo\0"
    "readChessInfo\0initBoard\0startTimeThread\0"
    "countTimeThread\0setTime\0getHint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Onlinepvp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   83,    2, 0x0a /* Public */,
       5,    0,   84,    2, 0x0a /* Public */,
       6,    0,   85,    2, 0x0a /* Public */,
       7,    0,   86,    2, 0x0a /* Public */,
       8,    0,   87,    2, 0x0a /* Public */,
       9,    1,   88,    2, 0x0a /* Public */,
      10,    2,   91,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Onlinepvp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Onlinepvp *_t = static_cast<Onlinepvp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boardMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->back(); break;
        case 2: _t->drawChess(); break;
        case 3: _t->undo(); break;
        case 4: _t->defeat(); break;
        case 5: _t->save(); break;
        case 6: _t->sendChessInfo(); break;
        case 7: _t->readChessInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->initBoard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->startTimeThread(); break;
        case 10: _t->countTimeThread(); break;
        case 11: _t->setTime(); break;
        case 12: _t->getHint(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Onlinepvp::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Onlinepvp::boardMsg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Onlinepvp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Onlinepvp::back)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Onlinepvp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Onlinepvp.data,
      qt_meta_data_Onlinepvp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Onlinepvp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Onlinepvp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Onlinepvp.stringdata0))
        return static_cast<void*>(const_cast< Onlinepvp*>(this));
    return QWidget::qt_metacast(_clname);
}

int Onlinepvp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Onlinepvp::boardMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Onlinepvp::back()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
