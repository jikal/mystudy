/****************************************************************************
** Meta object code from reading C++ file 'threaddialog.h'
**
** Created: Thu Mar 19 09:57:38 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "threaddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threaddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ThreadDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ThreadDialog[] = {
    "ThreadDialog\0\0startOrStopThreadA()\0"
    "startOrStopThreadB()\0"
};

void ThreadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ThreadDialog *_t = static_cast<ThreadDialog *>(_o);
        switch (_id) {
        case 0: _t->startOrStopThreadA(); break;
        case 1: _t->startOrStopThreadB(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ThreadDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ThreadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ThreadDialog,
      qt_meta_data_ThreadDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ThreadDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ThreadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ThreadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ThreadDialog))
        return static_cast<void*>(const_cast< ThreadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ThreadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
