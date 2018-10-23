/****************************************************************************
** Meta object code from reading C++ file 'Replay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Replay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Replay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Replay_t {
    QByteArrayData data[18];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Replay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Replay_t qt_meta_stringdata_Replay = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Replay"
QT_MOC_LITERAL(1, 7, 4), // "back"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 10), // "play_state"
QT_MOC_LITERAL(4, 24, 9), // "play_stop"
QT_MOC_LITERAL(5, 34, 5), // "speed"
QT_MOC_LITERAL(6, 40, 4), // "Next"
QT_MOC_LITERAL(7, 45, 4), // "Last"
QT_MOC_LITERAL(8, 50, 4), // "Play"
QT_MOC_LITERAL(9, 55, 5), // "Pause"
QT_MOC_LITERAL(10, 61, 8), // "SetSpeed"
QT_MOC_LITERAL(11, 70, 12), // "PlaybackMode"
QT_MOC_LITERAL(12, 83, 8), // "AutoPlay"
QT_MOC_LITERAL(13, 92, 10), // "ManualPlay"
QT_MOC_LITERAL(14, 103, 6), // "Return"
QT_MOC_LITERAL(15, 110, 9), // "drawChess"
QT_MOC_LITERAL(16, 120, 13), // "ReadBoardInfo"
QT_MOC_LITERAL(17, 134, 9) // "PlayState"

    },
    "Replay\0back\0\0play_state\0play_stop\0"
    "speed\0Next\0Last\0Play\0Pause\0SetSpeed\0"
    "PlaybackMode\0AutoPlay\0ManualPlay\0"
    "Return\0drawChess\0ReadBoardInfo\0PlayState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Replay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       4,    0,   98,    2, 0x06 /* Public */,
       5,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  102,    2, 0x0a /* Public */,
       7,    0,  103,    2, 0x0a /* Public */,
       8,    0,  104,    2, 0x0a /* Public */,
       9,    0,  105,    2, 0x0a /* Public */,
      10,    0,  106,    2, 0x0a /* Public */,
      11,    0,  107,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    2,  111,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Replay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Replay *_t = static_cast<Replay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->play_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->play_stop(); break;
        case 3: _t->speed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Next(); break;
        case 5: _t->Last(); break;
        case 6: _t->Play(); break;
        case 7: _t->Pause(); break;
        case 8: _t->SetSpeed(); break;
        case 9: _t->PlaybackMode(); break;
        case 10: _t->AutoPlay(); break;
        case 11: _t->ManualPlay(); break;
        case 12: _t->Return(); break;
        case 13: _t->drawChess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->ReadBoardInfo(); break;
        case 15: _t->PlayState(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Replay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replay::back)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Replay::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replay::play_state)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Replay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replay::play_stop)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Replay::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Replay::speed)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Replay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Replay.data,
      qt_meta_data_Replay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Replay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Replay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Replay.stringdata0))
        return static_cast<void*>(const_cast< Replay*>(this));
    return QWidget::qt_metacast(_clname);
}

int Replay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Replay::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Replay::play_state(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Replay::play_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Replay::speed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
