/****************************************************************************
** Meta object code from reading C++ file 'socket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Socket_t {
    QByteArrayData data[12];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Socket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Socket_t qt_meta_stringdata_Socket = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Socket"
QT_MOC_LITERAL(1, 7, 4), // "conn"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 6), // "discon"
QT_MOC_LITERAL(4, 20, 8), // "oppChess"
QT_MOC_LITERAL(5, 29, 8), // "serv_msg"
QT_MOC_LITERAL(6, 38, 10), // "conn_state"
QT_MOC_LITERAL(7, 49, 7), // "sendMsg"
QT_MOC_LITERAL(8, 57, 13), // "on_connection"
QT_MOC_LITERAL(9, 71, 16), // "on_disconnection"
QT_MOC_LITERAL(10, 88, 7), // "on_read"
QT_MOC_LITERAL(11, 96, 15) // "reconnectServer"

    },
    "Socket\0conn\0\0discon\0oppChess\0serv_msg\0"
    "conn_state\0sendMsg\0on_connection\0"
    "on_disconnection\0on_read\0reconnectServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Socket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       5,    1,   69,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   75,    2, 0x0a /* Public */,
       8,    0,   78,    2, 0x0a /* Public */,
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Socket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Socket *_t = static_cast<Socket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->conn(); break;
        case 1: _t->discon(); break;
        case 2: _t->oppChess((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->serv_msg((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->conn_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->sendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_connection(); break;
        case 7: _t->on_disconnection(); break;
        case 8: _t->on_read(); break;
        case 9: _t->reconnectServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Socket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Socket::conn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Socket::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Socket::discon)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Socket::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Socket::oppChess)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Socket::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Socket::serv_msg)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Socket::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Socket::conn_state)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Socket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_Socket.data,
      qt_meta_data_Socket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Socket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Socket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Socket.stringdata0))
        return static_cast<void*>(const_cast< Socket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int Socket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Socket::conn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Socket::discon()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Socket::oppChess(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Socket::serv_msg(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Socket::conn_state(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
