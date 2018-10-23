/****************************************************************************
** Meta object code from reading C++ file 'Room.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Room.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Room.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Room_t {
    QByteArrayData data[16];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Room_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Room_t qt_meta_stringdata_Room = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Room"
QT_MOC_LITERAL(1, 5, 4), // "back"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 8), // "room_msg"
QT_MOC_LITERAL(4, 20, 5), // "start"
QT_MOC_LITERAL(5, 26, 10), // "get_myname"
QT_MOC_LITERAL(6, 37, 8), // "matching"
QT_MOC_LITERAL(7, 46, 6), // "backTo"
QT_MOC_LITERAL(8, 53, 6), // "create"
QT_MOC_LITERAL(9, 60, 3), // "set"
QT_MOC_LITERAL(10, 64, 15), // "processRoomInfo"
QT_MOC_LITERAL(11, 80, 14), // "updateRoomList"
QT_MOC_LITERAL(12, 95, 8), // "joinRoom"
QT_MOC_LITERAL(13, 104, 6), // "reshow"
QT_MOC_LITERAL(14, 111, 9), // "startGame"
QT_MOC_LITERAL(15, 121, 9) // "leaveRoom"

    },
    "Room\0back\0\0room_msg\0start\0get_myname\0"
    "matching\0backTo\0create\0set\0processRoomInfo\0"
    "updateRoomList\0joinRoom\0reshow\0startGame\0"
    "leaveRoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Room[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    1,   85,    2, 0x06 /* Public */,
       4,    0,   88,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   90,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    1,   93,    2, 0x0a /* Public */,
      10,    1,   96,    2, 0x0a /* Public */,
      11,    1,   99,    2, 0x0a /* Public */,
      12,    2,  102,    2, 0x0a /* Public */,
      13,    0,  107,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Room::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Room *_t = static_cast<Room *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->room_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->get_myname(); break;
        case 4: _t->matching(); break;
        case 5: _t->backTo(); break;
        case 6: _t->create(); break;
        case 7: _t->set((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->processRoomInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->updateRoomList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 10: _t->joinRoom((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->reshow(); break;
        case 12: _t->startGame(); break;
        case 13: _t->leaveRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Room::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::back)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Room::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::room_msg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Room::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::start)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Room::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Room::get_myname)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Room::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Room.data,
      qt_meta_data_Room,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Room::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Room::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Room.stringdata0))
        return static_cast<void*>(const_cast< Room*>(this));
    return QWidget::qt_metacast(_clname);
}

int Room::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Room::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Room::room_msg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Room::start()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Room::get_myname()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
