/****************************************************************************
** Meta object code from reading C++ file 'Gobang.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gobang.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gobang.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gobang_t {
    QByteArrayData data[13];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gobang_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gobang_t qt_meta_stringdata_Gobang = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Gobang"
QT_MOC_LITERAL(1, 7, 7), // "back_to"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "boardMsg"
QT_MOC_LITERAL(4, 25, 9), // "drawChess"
QT_MOC_LITERAL(5, 35, 4), // "undo"
QT_MOC_LITERAL(6, 40, 7), // "restart"
QT_MOC_LITERAL(7, 48, 10), // "backToMenu"
QT_MOC_LITERAL(8, 59, 4), // "save"
QT_MOC_LITERAL(9, 64, 13), // "sendChessInfo"
QT_MOC_LITERAL(10, 78, 13), // "readChessInfo"
QT_MOC_LITERAL(11, 92, 8), // "setLevel"
QT_MOC_LITERAL(12, 101, 9) // "initBoard"

    },
    "Gobang\0back_to\0\0boardMsg\0drawChess\0"
    "undo\0restart\0backToMenu\0save\0sendChessInfo\0"
    "readChessInfo\0setLevel\0initBoard"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gobang[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   73,    2, 0x0a /* Public */,
       5,    0,   74,    2, 0x0a /* Public */,
       6,    0,   75,    2, 0x0a /* Public */,
       7,    0,   76,    2, 0x0a /* Public */,
       8,    0,   77,    2, 0x0a /* Public */,
       9,    0,   78,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x0a /* Public */,
      12,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void Gobang::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gobang *_t = static_cast<Gobang *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back_to(); break;
        case 1: _t->boardMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->drawChess(); break;
        case 3: _t->undo(); break;
        case 4: _t->restart(); break;
        case 5: _t->backToMenu(); break;
        case 6: _t->save(); break;
        case 7: _t->sendChessInfo(); break;
        case 8: _t->readChessInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->initBoard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Gobang::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gobang::back_to)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Gobang::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gobang::boardMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Gobang::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Gobang.data,
      qt_meta_data_Gobang,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Gobang::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gobang::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gobang.stringdata0))
        return static_cast<void*>(const_cast< Gobang*>(this));
    return QWidget::qt_metacast(_clname);
}

int Gobang::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Gobang::back_to()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Gobang::boardMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
