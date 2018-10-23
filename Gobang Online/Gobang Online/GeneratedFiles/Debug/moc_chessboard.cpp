/****************************************************************************
** Meta object code from reading C++ file 'chessboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chessboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chessboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChessBoard_t {
    QByteArrayData data[12];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessBoard_t qt_meta_stringdata_ChessBoard = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChessBoard"
QT_MOC_LITERAL(1, 11, 7), // "clicked"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "chessed"
QT_MOC_LITERAL(4, 28, 7), // "ai_step"
QT_MOC_LITERAL(5, 36, 7), // "ai_undo"
QT_MOC_LITERAL(6, 44, 10), // "ai_restart"
QT_MOC_LITERAL(7, 55, 11), // "ai_gameover"
QT_MOC_LITERAL(8, 67, 7), // "AI_Step"
QT_MOC_LITERAL(9, 75, 8), // "aiThread"
QT_MOC_LITERAL(10, 84, 10), // "threadStop"
QT_MOC_LITERAL(11, 95, 8) // "Gameover"

    },
    "ChessBoard\0clicked\0\0chessed\0ai_step\0"
    "ai_undo\0ai_restart\0ai_gameover\0AI_Step\0"
    "aiThread\0threadStop\0Gameover"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    2,   66,    2, 0x06 /* Public */,
       5,    0,   71,    2, 0x06 /* Public */,
       6,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   76,    2, 0x0a /* Public */,
       9,    1,   81,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChessBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChessBoard *_t = static_cast<ChessBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->chessed(); break;
        case 2: _t->ai_step((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->ai_undo(); break;
        case 4: _t->ai_restart((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->ai_gameover(); break;
        case 6: _t->AI_Step((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->aiThread((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->threadStop(); break;
        case 9: _t->Gameover(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChessBoard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::clicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::chessed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::ai_step)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::ai_undo)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::ai_restart)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ChessBoard::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChessBoard::ai_gameover)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject ChessBoard::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_ChessBoard.data,
      qt_meta_data_ChessBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChessBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessBoard.stringdata0))
        return static_cast<void*>(const_cast< ChessBoard*>(this));
    return QLabel::qt_metacast(_clname);
}

int ChessBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void ChessBoard::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChessBoard::chessed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChessBoard::ai_step(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChessBoard::ai_undo()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChessBoard::ai_restart(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChessBoard::ai_gameover()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
