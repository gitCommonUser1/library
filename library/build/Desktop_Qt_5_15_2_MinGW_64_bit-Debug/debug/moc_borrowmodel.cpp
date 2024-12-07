/****************************************************************************
** Meta object code from reading C++ file 'borrowmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../borrowmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'borrowmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BorrowItem_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BorrowItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BorrowItem_t qt_meta_stringdata_BorrowItem = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BorrowItem"
QT_MOC_LITERAL(1, 11, 6), // "userId"
QT_MOC_LITERAL(2, 18, 6), // "bookId"
QT_MOC_LITERAL(3, 25, 10), // "borrowDate"
QT_MOC_LITERAL(4, 36, 10), // "returnDate"
QT_MOC_LITERAL(5, 47, 12) // "borrowStatus"

    },
    "BorrowItem\0userId\0bookId\0borrowDate\0"
    "returnDate\0borrowStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BorrowItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::QString, 0x00095103,
       5, QMetaType::QString, 0x00095103,

       0        // eod
};

void BorrowItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<BorrowItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->userId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->bookId(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->borrowDate(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->returnDate(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->borrowStatus(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<BorrowItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUserId(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setBookId(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setBorrowDate(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setReturnDate(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setBorrowStatus(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BorrowItem::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_BorrowItem.data,
    qt_meta_data_BorrowItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };

struct qt_meta_stringdata_BorrowModel_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BorrowModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BorrowModel_t qt_meta_stringdata_BorrowModel = {
    {
QT_MOC_LITERAL(0, 0, 11) // "BorrowModel"

    },
    "BorrowModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BorrowModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void BorrowModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BorrowModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BorrowModel.data,
    qt_meta_data_BorrowModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BorrowModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BorrowModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BorrowModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BorrowModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
