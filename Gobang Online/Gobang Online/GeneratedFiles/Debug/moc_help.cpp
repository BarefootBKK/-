/****************************************************************************
** Meta object code from reading C++ file 'help.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../help.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'help.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_help_t {
    QByteArrayData data[8];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_help_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_help_t qt_meta_stringdata_help = {
    {
QT_MOC_LITERAL(0, 0, 4), // "help"
QT_MOC_LITERAL(1, 5, 7), // "back_to"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 8), // "boardMsg"
QT_MOC_LITERAL(4, 23, 4), // "back"
QT_MOC_LITERAL(5, 28, 8), // "step_one"
QT_MOC_LITERAL(6, 37, 8), // "step_two"
QT_MOC_LITERAL(7, 46, 10) // "step_three"

    },
    "help\0back_to\0\0boardMsg\0back\0step_one\0"
    "step_two\0step_three"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_help[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   48,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void help::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        help *_t = static_cast<help *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back_to(); break;
        case 1: _t->boardMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->back(); break;
        case 3: _t->step_one(); break;
        case 4: _t->step_two(); break;
        case 5: _t->step_three(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (help::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&help::back_to)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (help::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&help::boardMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject help::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_help.data,
      qt_meta_data_help,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *help::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *help::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_help.stringdata0))
        return static_cast<void*>(const_cast< help*>(this));
    return QWidget::qt_metacast(_clname);
}

int help::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void help::back_to()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void help::boardMsg(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
