/****************************************************************************
** Meta object code from reading C++ file 'RoomWait.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RoomWait.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoomWait.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoomWait_t {
    QByteArrayData data[8];
    char stringdata0[74];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoomWait_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoomWait_t qt_meta_stringdata_RoomWait = {
    {
QT_MOC_LITERAL(0, 0, 8), // "RoomWait"
QT_MOC_LITERAL(1, 9, 5), // "leave"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "start_game"
QT_MOC_LITERAL(4, 27, 13), // "setRoomOwnner"
QT_MOC_LITERAL(5, 41, 12), // "isRoomOwnner"
QT_MOC_LITERAL(6, 54, 9), // "leaveRoom"
QT_MOC_LITERAL(7, 64, 9) // "startGame"

    },
    "RoomWait\0leave\0\0start_game\0setRoomOwnner\0"
    "isRoomOwnner\0leaveRoom\0startGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomWait[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x0a /* Public */,
       5,    0,   51,    2, 0x0a /* Public */,
       6,    0,   52,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoomWait::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoomWait *_t = static_cast<RoomWait *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->leave((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->start_game(); break;
        case 2: _t->setRoomOwnner((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: { bool _r = _t->isRoomOwnner();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->leaveRoom(); break;
        case 5: _t->startGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoomWait::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomWait::leave)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (RoomWait::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoomWait::start_game)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject RoomWait::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RoomWait.data,
      qt_meta_data_RoomWait,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RoomWait::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomWait::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoomWait.stringdata0))
        return static_cast<void*>(const_cast< RoomWait*>(this));
    return QDialog::qt_metacast(_clname);
}

int RoomWait::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void RoomWait::leave(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RoomWait::start_game()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
