/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[20];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 12), // "signInSignal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "result"
QT_MOC_LITERAL(4, 28, 14), // "newBookMessage"
QT_MOC_LITERAL(5, 43, 8), // "MenuItem"
QT_MOC_LITERAL(6, 52, 4), // "item"
QT_MOC_LITERAL(7, 57, 16), // "connectedChanged"
QT_MOC_LITERAL(8, 74, 9), // "connected"
QT_MOC_LITERAL(9, 84, 12), // "setConnected"
QT_MOC_LITERAL(10, 97, 18), // "connectByIpAddress"
QT_MOC_LITERAL(11, 116, 9), // "ipAddress"
QT_MOC_LITERAL(12, 126, 6), // "signIn"
QT_MOC_LITERAL(13, 133, 8), // "username"
QT_MOC_LITERAL(14, 142, 8), // "password"
QT_MOC_LITERAL(15, 151, 8), // "getBooks"
QT_MOC_LITERAL(16, 160, 10), // "removeBook"
QT_MOC_LITERAL(17, 171, 6), // "bookId"
QT_MOC_LITERAL(18, 178, 9), // "sendImage"
QT_MOC_LITERAL(19, 188, 8) // "fileName"

    },
    "Client\0signInSignal\0\0result\0newBookMessage\0"
    "MenuItem\0item\0connectedChanged\0connected\0"
    "setConnected\0connectByIpAddress\0"
    "ipAddress\0signIn\0username\0password\0"
    "getBooks\0removeBook\0bookId\0sendImage\0"
    "fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   68,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    1,   71,    2, 0x02 /* Public */,
      12,    2,   74,    2, 0x02 /* Public */,
      15,    0,   79,    2, 0x02 /* Public */,
      16,    1,   80,    2, 0x02 /* Public */,
      18,    1,   83,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    8,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
       8, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       2,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signInSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->newBookMessage((*reinterpret_cast< const MenuItem(*)>(_a[1]))); break;
        case 2: _t->connectedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->connectByIpAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { bool _r = _t->signIn((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->getBooks(); break;
        case 7: _t->removeBook((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MenuItem >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::signInSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(const MenuItem & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::newBookMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::connectedChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->connected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setConnected(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Client.data,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Client::signInSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::newBookMessage(const MenuItem & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::connectedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
