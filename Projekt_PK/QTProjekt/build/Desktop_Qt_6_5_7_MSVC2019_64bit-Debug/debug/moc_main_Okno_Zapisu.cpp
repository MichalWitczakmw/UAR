/****************************************************************************
** Meta object code from reading C++ file 'main_Okno_Zapisu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../main_Okno_Zapisu.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_Okno_Zapisu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS = QtMocHelpers::stringData(
    "mainOknoZapisu",
    "on_ZamknijZapis_clicked",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[15];
    char stringdata1[24];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS_t qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "mainOknoZapisu"
        QT_MOC_LITERAL(15, 23),  // "on_ZamknijZapis_clicked"
        QT_MOC_LITERAL(39, 0)   // ""
    },
    "mainOknoZapisu",
    "on_ZamknijZapis_clicked",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSmainOknoZapisuENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject mainOknoZapisu::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSmainOknoZapisuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<mainOknoZapisu, std::true_type>,
        // method 'on_ZamknijZapis_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void mainOknoZapisu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainOknoZapisu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_ZamknijZapis_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *mainOknoZapisu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainOknoZapisu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSmainOknoZapisuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int mainOknoZapisu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
