/****************************************************************************
** Meta object code from reading C++ file 'pumpwindow.h'
**
** Created: Thu Mar 19 10:03:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pumpwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pumpwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PumpWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
      93,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     123,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PumpWindow[] = {
    "PumpWindow\0\0loadData()\0appendData()\0"
    "saveData()\0sortByDateTime()\0sortByPump()\0"
    "sortByCompany()\0sortByUser()\0"
    "sortByQuantity()\0sortByStatus()\0"
    "filter()\0convertToGallons()\0"
    "convertToLiters()\0computeTotalsPerDate()\0"
    "computeTotalsPerPump()\0computeTotalsPerCompany()\0"
    "computeTotalsPerUser()\0about()\0"
};

void PumpWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PumpWindow *_t = static_cast<PumpWindow *>(_o);
        switch (_id) {
        case 0: _t->loadData(); break;
        case 1: _t->appendData(); break;
        case 2: _t->saveData(); break;
        case 3: _t->sortByDateTime(); break;
        case 4: _t->sortByPump(); break;
        case 5: _t->sortByCompany(); break;
        case 6: _t->sortByUser(); break;
        case 7: _t->sortByQuantity(); break;
        case 8: _t->sortByStatus(); break;
        case 9: _t->filter(); break;
        case 10: _t->convertToGallons(); break;
        case 11: _t->convertToLiters(); break;
        case 12: _t->computeTotalsPerDate(); break;
        case 13: _t->computeTotalsPerPump(); break;
        case 14: _t->computeTotalsPerCompany(); break;
        case 15: _t->computeTotalsPerUser(); break;
        case 16: _t->about(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PumpWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PumpWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PumpWindow,
      qt_meta_data_PumpWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PumpWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PumpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PumpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PumpWindow))
        return static_cast<void*>(const_cast< PumpWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PumpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
