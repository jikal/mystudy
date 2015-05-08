/****************************************************************************
** Meta object code from reading C++ file 'bronzedialog.h'
**
** Created: Thu Mar 19 09:58:35 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "bronzedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bronzedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BronzeDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BronzeDialog[] = {
    "BronzeDialog\0\0editable\0"
    "editableStateChanged(bool)\0"
};

void BronzeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BronzeDialog *_t = static_cast<BronzeDialog *>(_o);
        switch (_id) {
        case 0: _t->editableStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BronzeDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BronzeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BronzeDialog,
      qt_meta_data_BronzeDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BronzeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BronzeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BronzeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BronzeDialog))
        return static_cast<void*>(const_cast< BronzeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BronzeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
