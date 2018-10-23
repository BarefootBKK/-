/****************************************************************************
** Meta object code from reading C++ file 'LevelDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LevelDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LevelDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LevelDialog_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LevelDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LevelDialog_t qt_meta_stringdata_LevelDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LevelDialog"
QT_MOC_LITERAL(1, 12, 8), // "ai_level"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "setConnection"
QT_MOC_LITERAL(4, 36, 12), // "setEasyLevel"
QT_MOC_LITERAL(5, 49, 14), // "setNormalLevel"
QT_MOC_LITERAL(6, 64, 14), // "setMiddleLevel"
QT_MOC_LITERAL(7, 79, 12), // "setDiffLevel"
QT_MOC_LITERAL(8, 92, 17) // "setNightmareLevel"

    },
    "LevelDialog\0ai_level\0\0setConnection\0"
    "setEasyLevel\0setNormalLevel\0setMiddleLevel\0"
    "setDiffLevel\0setNightmareLevel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LevelDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LevelDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LevelDialog *_t = static_cast<LevelDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ai_level((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setConnection(); break;
        case 2: _t->setEasyLevel(); break;
        case 3: _t->setNormalLevel(); break;
        case 4: _t->setMiddleLevel(); break;
        case 5: _t->setDiffLevel(); break;
        case 6: _t->setNightmareLevel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LevelDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LevelDialog::ai_level)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LevelDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LevelDialog.data,
      qt_meta_data_LevelDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LevelDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LevelDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LevelDialog.stringdata0))
        return static_cast<void*>(const_cast< LevelDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LevelDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LevelDialog::ai_level(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
