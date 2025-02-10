/****************************************************************************
** Meta object code from reading C++ file 'Robie_Wykres.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../Robie_Wykres.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Robie_Wykres.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRobieWykresENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSRobieWykresENDCLASS = QtMocHelpers::stringData(
    "RobieWykres",
    "daneWczytane",
    "",
    "KP",
    "TI",
    "TD",
    "WZ",
    "ZK",
    "I",
    "std::deque<double>",
    "a",
    "b",
    "aktualizacjawykresu"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRobieWykresENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[12];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[3];
    char stringdata5[3];
    char stringdata6[3];
    char stringdata7[3];
    char stringdata8[2];
    char stringdata9[19];
    char stringdata10[2];
    char stringdata11[2];
    char stringdata12[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRobieWykresENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRobieWykresENDCLASS_t qt_meta_stringdata_CLASSRobieWykresENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "RobieWykres"
        QT_MOC_LITERAL(12, 12),  // "daneWczytane"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 2),  // "KP"
        QT_MOC_LITERAL(29, 2),  // "TI"
        QT_MOC_LITERAL(32, 2),  // "TD"
        QT_MOC_LITERAL(35, 2),  // "WZ"
        QT_MOC_LITERAL(38, 2),  // "ZK"
        QT_MOC_LITERAL(41, 1),  // "I"
        QT_MOC_LITERAL(43, 18),  // "std::deque<double>"
        QT_MOC_LITERAL(62, 1),  // "a"
        QT_MOC_LITERAL(64, 1),  // "b"
        QT_MOC_LITERAL(66, 19)   // "aktualizacjawykresu"
    },
    "RobieWykres",
    "daneWczytane",
    "",
    "KP",
    "TI",
    "TD",
    "WZ",
    "ZK",
    "I",
    "std::deque<double>",
    "a",
    "b",
    "aktualizacjawykresu"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRobieWykresENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    8,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   43,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 9,    3,    4,    5,    6,    7,    8,   10,   11,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject RobieWykres::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSRobieWykresENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRobieWykresENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRobieWykresENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RobieWykres, std::true_type>,
        // method 'daneWczytane'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::deque<double>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::deque<double>, std::false_type>,
        // method 'aktualizacjawykresu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void RobieWykres::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobieWykres *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->daneWczytane((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<std::deque<double>>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<std::deque<double>>>(_a[8]))); break;
        case 1: _t->aktualizacjawykresu(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RobieWykres::*)(double , double , double , double , double , int , std::deque<double> , std::deque<double> );
            if (_t _q_method = &RobieWykres::daneWczytane; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *RobieWykres::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobieWykres::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRobieWykresENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RobieWykres::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RobieWykres::daneWczytane(double _t1, double _t2, double _t3, double _t4, double _t5, int _t6, std::deque<double> _t7, std::deque<double> _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
