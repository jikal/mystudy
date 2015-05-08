/****************************************************************************
** Meta object code from reading C++ file 'pumpspreadsheet.h'
**
** Created: Thu Mar 19 10:03:16 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pumpspreadsheet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pumpspreadsheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PumpSpreadsheet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       2,   64, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      50,   34,   29,   16, 0x0a,
      78,   34,   29,   16, 0x0a,
     120,  107,   16,   16, 0x0a,
     162,  155,   16,   16, 0x2a,
     190,  183,   16,   16, 0x0a,
     221,  214,   16,   16, 0x0a,
     242,  155,   16,   16, 0x0a,
     280,  264,   16,   16, 0x0a,
     324,  313,  305,   16, 0x0a,

 // enums: name, flags, count, data
     338, 0x0,    2,   72,
     349, 0x0,    8,   76,

 // enum data: key, value
     356, uint(PumpSpreadsheet::Pump2000),
     365, uint(PumpSpreadsheet::GasPumpXml),
     376, uint(PumpSpreadsheet::Date),
     381, uint(PumpSpreadsheet::Time),
     386, uint(PumpSpreadsheet::Pump),
     391, uint(PumpSpreadsheet::Company),
     399, uint(PumpSpreadsheet::User),
     404, uint(PumpSpreadsheet::Quantity),
     413, uint(PumpSpreadsheet::Status),
     420, uint(PumpSpreadsheet::ColumnCount),

       0        // eod
};

static const char qt_meta_stringdata_PumpSpreadsheet[] = {
    "PumpSpreadsheet\0\0clearData()\0bool\0"
    "fileName,format\0addData(QString,FileFormat)\0"
    "saveData(QString,FileFormat)\0column,order\0"
    "sortByColumn(Column,Qt::SortOrder)\0"
    "column\0sortByColumn(Column)\0filter\0"
    "applyFilter(PumpFilter)\0factor\0"
    "convertUnits(double)\0computeTotals(Column)\0"
    "row,column,text\0setText(int,int,QString)\0"
    "QString\0row,column\0text(int,int)\0"
    "FileFormat\0Column\0Pump2000\0GasPumpXml\0"
    "Date\0Time\0Pump\0Company\0User\0Quantity\0"
    "Status\0ColumnCount\0"
};

void PumpSpreadsheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PumpSpreadsheet *_t = static_cast<PumpSpreadsheet *>(_o);
        switch (_id) {
        case 0: _t->clearData(); break;
        case 1: { bool _r = _t->addData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FileFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->saveData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< FileFormat(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->sortByColumn((*reinterpret_cast< Column(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 4: _t->sortByColumn((*reinterpret_cast< Column(*)>(_a[1]))); break;
        case 5: _t->applyFilter((*reinterpret_cast< const PumpFilter(*)>(_a[1]))); break;
        case 6: _t->convertUnits((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->computeTotals((*reinterpret_cast< Column(*)>(_a[1]))); break;
        case 8: _t->setText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: { QString _r = _t->text((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PumpSpreadsheet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PumpSpreadsheet::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_PumpSpreadsheet,
      qt_meta_data_PumpSpreadsheet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PumpSpreadsheet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PumpSpreadsheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PumpSpreadsheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PumpSpreadsheet))
        return static_cast<void*>(const_cast< PumpSpreadsheet*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int PumpSpreadsheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
