/****************************************************************************
** Meta object code from reading C++ file 'datetime.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../datetime.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datetime.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateTime_t {
    QByteArrayData data[12];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateTime_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateTime_t qt_meta_stringdata_DateTime = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DateTime"
QT_MOC_LITERAL(1, 9, 8), // "dChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "mChanged"
QT_MOC_LITERAL(4, 28, 11), // "timeChanged"
QT_MOC_LITERAL(5, 40, 11), // "dateChanged"
QT_MOC_LITERAL(6, 52, 15), // "dateTimeChanged"
QT_MOC_LITERAL(7, 68, 1), // "d"
QT_MOC_LITERAL(8, 70, 1), // "m"
QT_MOC_LITERAL(9, 72, 4), // "time"
QT_MOC_LITERAL(10, 77, 4), // "date"
QT_MOC_LITERAL(11, 82, 8) // "dateTime"

    },
    "DateTime\0dChanged\0\0mChanged\0timeChanged\0"
    "dateChanged\0dateTimeChanged\0d\0m\0time\0"
    "date\0dateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateTime[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495903,
       8, QMetaType::QString, 0x00495903,
       9, QMetaType::QString, 0x00495903,
      10, QMetaType::QString, 0x00495903,
      11, QMetaType::QString, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void DateTime::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DateTime *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dChanged(); break;
        case 1: _t->mChanged(); break;
        case 2: _t->timeChanged(); break;
        case 3: _t->dateChanged(); break;
        case 4: _t->dateTimeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DateTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTime::dChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DateTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTime::mChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DateTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTime::timeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DateTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTime::dateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DateTime::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateTime::dateTimeChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DateTime *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->d(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->m(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->time(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->date(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->dateTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DateTime *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setD(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setM(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setTime(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setDate(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setDateTime(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DateTime::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DateTime.data,
    qt_meta_data_DateTime,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DateTime::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateTime::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateTime.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DateTime::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DateTime::dChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DateTime::mChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DateTime::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DateTime::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DateTime::dateTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
