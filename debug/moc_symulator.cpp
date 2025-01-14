/****************************************************************************
** Meta object code from reading C++ file 'symulator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../symulator.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSSymulatorENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSymulatorENDCLASS = QtMocHelpers::stringData(
    "Symulator",
    "nextStep",
    "",
    "on_spinbox_A_valueChanged",
    "value",
    "on_spinbox_B_valueChanged",
    "on_list_WartoscZadana_currentRowChanged",
    "currentRow",
    "on_button_zapisz_clicked",
    "on_button_wczytaj_clicked",
    "on_button_reset_clicked",
    "on_button_start_clicked",
    "on_button_stop_clicked",
    "on_spinbox_interval_valueChanged",
    "arg1",
    "on_spinbox_maksimumY_valueChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSymulatorENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[10];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[6];
    char stringdata5[26];
    char stringdata6[40];
    char stringdata7[11];
    char stringdata8[25];
    char stringdata9[26];
    char stringdata10[24];
    char stringdata11[24];
    char stringdata12[23];
    char stringdata13[33];
    char stringdata14[5];
    char stringdata15[34];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSymulatorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSymulatorENDCLASS_t qt_meta_stringdata_CLASSSymulatorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Symulator"
        QT_MOC_LITERAL(10, 8),  // "nextStep"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 25),  // "on_spinbox_A_valueChanged"
        QT_MOC_LITERAL(46, 5),  // "value"
        QT_MOC_LITERAL(52, 25),  // "on_spinbox_B_valueChanged"
        QT_MOC_LITERAL(78, 39),  // "on_list_WartoscZadana_current..."
        QT_MOC_LITERAL(118, 10),  // "currentRow"
        QT_MOC_LITERAL(129, 24),  // "on_button_zapisz_clicked"
        QT_MOC_LITERAL(154, 25),  // "on_button_wczytaj_clicked"
        QT_MOC_LITERAL(180, 23),  // "on_button_reset_clicked"
        QT_MOC_LITERAL(204, 23),  // "on_button_start_clicked"
        QT_MOC_LITERAL(228, 22),  // "on_button_stop_clicked"
        QT_MOC_LITERAL(251, 32),  // "on_spinbox_interval_valueChanged"
        QT_MOC_LITERAL(284, 4),  // "arg1"
        QT_MOC_LITERAL(289, 33)   // "on_spinbox_maksimumY_valueCha..."
    },
    "Symulator",
    "nextStep",
    "",
    "on_spinbox_A_valueChanged",
    "value",
    "on_spinbox_B_valueChanged",
    "on_list_WartoscZadana_currentRowChanged",
    "currentRow",
    "on_button_zapisz_clicked",
    "on_button_wczytaj_clicked",
    "on_button_reset_clicked",
    "on_button_start_clicked",
    "on_button_stop_clicked",
    "on_spinbox_interval_valueChanged",
    "arg1",
    "on_spinbox_maksimumY_valueChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymulatorENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    1 /* Private */,
       3,    1,   81,    2, 0x08,    2 /* Private */,
       5,    1,   84,    2, 0x08,    4 /* Private */,
       6,    1,   87,    2, 0x08,    6 /* Private */,
       8,    0,   90,    2, 0x08,    8 /* Private */,
       9,    0,   91,    2, 0x08,    9 /* Private */,
      10,    0,   92,    2, 0x08,   10 /* Private */,
      11,    0,   93,    2, 0x08,   11 /* Private */,
      12,    0,   94,    2, 0x08,   12 /* Private */,
      13,    1,   95,    2, 0x08,   13 /* Private */,
      15,    1,   98,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject Symulator::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSymulatorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSymulatorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSymulatorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Symulator, std::true_type>,
        // method 'nextStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinbox_A_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_spinbox_B_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_list_WartoscZadana_currentRowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_button_zapisz_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_wczytaj_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_reset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_start_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_button_stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_spinbox_interval_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_spinbox_maksimumY_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>
    >,
    nullptr
} };

void Symulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Symulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nextStep(); break;
        case 1: _t->on_spinbox_A_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->on_spinbox_B_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->on_list_WartoscZadana_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_button_zapisz_clicked(); break;
        case 5: _t->on_button_wczytaj_clicked(); break;
        case 6: _t->on_button_reset_clicked(); break;
        case 7: _t->on_button_start_clicked(); break;
        case 8: _t->on_button_stop_clicked(); break;
        case 9: _t->on_spinbox_interval_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 10: _t->on_spinbox_maksimumY_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Symulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Symulator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSymulatorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Symulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
