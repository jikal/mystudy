/****************************************************************************
** Meta object code from reading C++ file 'scripting.h'
**
** Created: Thu Mar 19 10:03:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scripting.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scripting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PumpFilterPrototype[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      26,   20, 0x0e095103,
      35,   20, 0x0e095103,
      48,   42, 0x0f095103,
      57,   42, 0x0f095103,
      72,   64, 0x0a095103,
      77,   64, 0x0a095103,
      85,   64, 0x0a095103,
      97,   90, 0x06095103,
     110,   90, 0x06095103,
     121,   64, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_PumpFilterPrototype[] = {
    "PumpFilterPrototype\0QDate\0fromDate\0"
    "toDate\0QTime\0fromTime\0toTime\0QString\0"
    "pump\0company\0user\0double\0fromQuantity\0"
    "toQuantity\0status\0"
};

void PumpFilterPrototype::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PumpFilterPrototype::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PumpFilterPrototype::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PumpFilterPrototype,
      qt_meta_data_PumpFilterPrototype, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PumpFilterPrototype::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PumpFilterPrototype::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PumpFilterPrototype::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PumpFilterPrototype))
        return static_cast<void*>(const_cast< PumpFilterPrototype*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< PumpFilterPrototype*>(this));
    return QObject::qt_metacast(_clname);
}

int PumpFilterPrototype::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDate*>(_v) = fromDate(); break;
        case 1: *reinterpret_cast< QDate*>(_v) = toDate(); break;
        case 2: *reinterpret_cast< QTime*>(_v) = fromTime(); break;
        case 3: *reinterpret_cast< QTime*>(_v) = toTime(); break;
        case 4: *reinterpret_cast< QString*>(_v) = pump(); break;
        case 5: *reinterpret_cast< QString*>(_v) = company(); break;
        case 6: *reinterpret_cast< QString*>(_v) = user(); break;
        case 7: *reinterpret_cast< double*>(_v) = fromQuantity(); break;
        case 8: *reinterpret_cast< double*>(_v) = toQuantity(); break;
        case 9: *reinterpret_cast< QString*>(_v) = status(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFromDate(*reinterpret_cast< QDate*>(_v)); break;
        case 1: setToDate(*reinterpret_cast< QDate*>(_v)); break;
        case 2: setFromTime(*reinterpret_cast< QTime*>(_v)); break;
        case 3: setToTime(*reinterpret_cast< QTime*>(_v)); break;
        case 4: setPump(*reinterpret_cast< QString*>(_v)); break;
        case 5: setCompany(*reinterpret_cast< QString*>(_v)); break;
        case 6: setUser(*reinterpret_cast< QString*>(_v)); break;
        case 7: setFromQuantity(*reinterpret_cast< double*>(_v)); break;
        case 8: setToQuantity(*reinterpret_cast< double*>(_v)); break;
        case 9: setStatus(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
