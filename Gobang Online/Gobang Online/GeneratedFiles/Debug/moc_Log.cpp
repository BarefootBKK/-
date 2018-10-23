/****************************************************************************
** Meta object code from reading C++ file 'Log.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Log.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Log.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Log_t {
    QByteArrayData data[15];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Log_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Log_t qt_meta_stringdata_Log = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Log"
QT_MOC_LITERAL(1, 4, 4), // "back"
QT_MOC_LITERAL(2, 9, 0), // ""
QT_MOC_LITERAL(3, 10, 7), // "log_msg"
QT_MOC_LITERAL(4, 18, 6), // "log_in"
QT_MOC_LITERAL(5, 25, 11), // "AccountInfo"
QT_MOC_LITERAL(6, 37, 6), // "regist"
QT_MOC_LITERAL(7, 44, 5), // "logIn"
QT_MOC_LITERAL(8, 50, 6), // "backTo"
QT_MOC_LITERAL(9, 57, 7), // "regHide"
QT_MOC_LITERAL(10, 65, 7), // "regShow"
QT_MOC_LITERAL(11, 73, 7), // "sign_in"
QT_MOC_LITERAL(12, 81, 9), // "clearText"
QT_MOC_LITERAL(13, 91, 8), // "makeRoom"
QT_MOC_LITERAL(14, 100, 10) // "analyzeMsg"

    },
    "Log\0back\0\0log_msg\0log_in\0AccountInfo\0"
    "regist\0logIn\0backTo\0regHide\0regShow\0"
    "sign_in\0clearText\0makeRoom\0analyzeMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Log[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    1,   75,    2, 0x06 /* Public */,
       4,    1,   78,    2, 0x06 /* Public */,
       6,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   82,    2, 0x0a /* Public */,
       8,    0,   83,    2, 0x0a /* Public */,
       9,    0,   84,    2, 0x0a /* Public */,
      10,    0,   85,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void Log::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Log *_t = static_cast<Log *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->log_msg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->log_in((*reinterpret_cast< AccountInfo(*)>(_a[1]))); break;
        case 3: _t->regist(); break;
        case 4: _t->logIn(); break;
        case 5: _t->backTo(); break;
        case 6: _t->regHide(); break;
        case 7: _t->regShow(); break;
        case 8: _t->sign_in(); break;
        case 9: _t->clearText(); break;
        case 10: _t->makeRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->analyzeMsg((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Log::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::back)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Log::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::log_msg)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Log::*_t)(AccountInfo );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::log_in)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Log::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Log::regist)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Log::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Log.data,
      qt_meta_data_Log,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Log::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Log::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Log.stringdata0))
        return static_cast<void*>(const_cast< Log*>(this));
    return QWidget::qt_metacast(_clname);
}

int Log::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Log::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Log::log_msg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Log::log_in(AccountInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Log::regist()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
