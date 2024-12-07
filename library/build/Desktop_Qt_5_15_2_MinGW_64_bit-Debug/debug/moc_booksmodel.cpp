/****************************************************************************
** Meta object code from reading C++ file 'booksmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../booksmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'booksmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MenuItem_t {
    QByteArrayData data[8];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MenuItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MenuItem_t qt_meta_stringdata_MenuItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MenuItem"
QT_MOC_LITERAL(1, 9, 4), // "name"
QT_MOC_LITERAL(2, 14, 6), // "author"
QT_MOC_LITERAL(3, 21, 6), // "bookId"
QT_MOC_LITERAL(4, 28, 5), // "pages"
QT_MOC_LITERAL(5, 34, 5), // "price"
QT_MOC_LITERAL(6, 40, 4), // "type"
QT_MOC_LITERAL(7, 45, 8) // "language"

    },
    "MenuItem\0name\0author\0bookId\0pages\0"
    "price\0type\0language"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MenuItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       2, QMetaType::QString, 0x00095103,
       3, QMetaType::QString, 0x00095103,
       4, QMetaType::Int, 0x00095103,
       5, QMetaType::Double, 0x00095103,
       6, QMetaType::QString, 0x00095103,
       7, QMetaType::QString, 0x00095103,

       0        // eod
};

void MenuItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<MenuItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->author(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->bookId(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->pages(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->price(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->type(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->language(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<MenuItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setAuthor(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setBookId(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPages(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setPrice(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setType(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setLanguage(*reinterpret_cast< QString*>(_v)); break;
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

QT_INIT_METAOBJECT const QMetaObject MenuItem::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_MenuItem.data,
    qt_meta_data_MenuItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };

struct qt_meta_stringdata_BooksModel_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BooksModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BooksModel_t qt_meta_stringdata_BooksModel = {
    {
QT_MOC_LITERAL(0, 0, 10) // "BooksModel"

    },
    "BooksModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BooksModel[] = {

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

void BooksModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BooksModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_BooksModel.data,
    qt_meta_data_BooksModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BooksModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BooksModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BooksModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int BooksModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
