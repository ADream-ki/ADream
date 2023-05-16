/****************************************************************************
** Meta object code from reading C++ file 'ADBorderContainer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Controls/Mouse/ADBorderContainer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ADBorderContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
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
struct qt_meta_stringdata_CLASSADBorderContainerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSADBorderContainerENDCLASS = QtMocHelpers::stringData(
    "ADBorderContainer",
    "windowStateChange",
    "",
    "max",
    "setPadding",
    "padding",
    "setMoveEnable",
    "moveEnable",
    "setResizeEnable",
    "resizeEnable"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSADBorderContainerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[18];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[11];
    char stringdata5[8];
    char stringdata6[14];
    char stringdata7[11];
    char stringdata8[16];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSADBorderContainerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSADBorderContainerENDCLASS_t qt_meta_stringdata_CLASSADBorderContainerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "ADBorderContainer"
        QT_MOC_LITERAL(18, 17),  // "windowStateChange"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 3),  // "max"
        QT_MOC_LITERAL(41, 10),  // "setPadding"
        QT_MOC_LITERAL(52, 7),  // "padding"
        QT_MOC_LITERAL(60, 13),  // "setMoveEnable"
        QT_MOC_LITERAL(74, 10),  // "moveEnable"
        QT_MOC_LITERAL(85, 15),  // "setResizeEnable"
        QT_MOC_LITERAL(101, 12)   // "resizeEnable"
    },
    "ADBorderContainer",
    "windowStateChange",
    "",
    "max",
    "setPadding",
    "padding",
    "setMoveEnable",
    "moveEnable",
    "setResizeEnable",
    "resizeEnable"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSADBorderContainerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   41,    2, 0x0a,    3 /* Public */,
       6,    1,   44,    2, 0x0a,    5 /* Public */,
       8,    1,   47,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject ADBorderContainer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSADBorderContainerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSADBorderContainerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSADBorderContainerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ADBorderContainer, std::true_type>,
        // method 'windowStateChange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setPadding'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMoveEnable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setResizeEnable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void ADBorderContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ADBorderContainer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowStateChange((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->setPadding((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->setMoveEnable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->setResizeEnable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ADBorderContainer::*)(bool );
            if (_t _q_method = &ADBorderContainer::windowStateChange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ADBorderContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ADBorderContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSADBorderContainerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ADBorderContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ADBorderContainer::windowStateChange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
