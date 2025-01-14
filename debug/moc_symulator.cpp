/****************************************************************************
** Meta object code from reading C++ file 'symulator.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../symulator.h"
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
    "on_spinbox_A_valueChanged",
    "",
    "value",
    "on_spinbox_B_valueChanged",
    "on_list_WartoscZadana_currentRowChanged",
    "currentRow",
    "on_button_zapisz_clicked",
    "on_button_wczytaj_clicked",
    "on_button_reset_clicked",
    "on_button_start_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSymulatorENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[26];
    char stringdata5[40];
    char stringdata6[11];
    char stringdata7[25];
    char stringdata8[26];
    char stringdata9[24];
    char stringdata10[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSymulatorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSymulatorENDCLASS_t qt_meta_stringdata_CLASSSymulatorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Symulator"
        QT_MOC_LITERAL(10, 25),  // "on_spinbox_A_valueChanged"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 5),  // "value"
        QT_MOC_LITERAL(43, 25),  // "on_spinbox_B_valueChanged"
        QT_MOC_LITERAL(69, 39),  // "on_list_WartoscZadana_current..."
        QT_MOC_LITERAL(109, 10),  // "currentRow"
        QT_MOC_LITERAL(120, 24),  // "on_button_zapisz_clicked"
        QT_MOC_LITERAL(145, 25),  // "on_button_wczytaj_clicked"
        QT_MOC_LITERAL(171, 23),  // "on_button_reset_clicked"
        QT_MOC_LITERAL(195, 23)   // "on_button_start_clicked"
    },
    "Symulator",
    "on_spinbox_A_valueChanged",
    "",
    "value",
    "on_spinbox_B_valueChanged",
    "on_list_WartoscZadana_currentRowChanged",
    "currentRow",
    "on_button_zapisz_clicked",
    "on_button_wczytaj_clicked",
    "on_button_reset_clicked",
    "on_button_start_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymulatorENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x08,    1 /* Private */,
       4,    1,   59,    2, 0x08,    3 /* Private */,
       5,    1,   62,    2, 0x08,    5 /* Private */,
       7,    0,   65,    2, 0x08,    7 /* Private */,
       8,    0,   66,    2, 0x08,    8 /* Private */,
       9,    0,   67,    2, 0x08,    9 /* Private */,
      10,    0,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Symulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Symulator *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_spinbox_A_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->on_spinbox_B_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->on_list_WartoscZadana_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_button_zapisz_clicked(); break;
        case 4: _t->on_button_wczytaj_clicked(); break;
        case 5: _t->on_button_reset_clicked(); break;
        case 6: _t->on_button_start_clicked(); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
