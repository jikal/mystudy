/****************************************************************************
** Meta object code from reading C++ file 'propertiesdialog.h'
**
** Created: Thu Mar 19 09:56:06 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "propertiesdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'propertiesdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropertiesDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      42,   17,   17,   17, 0x08,
      71,   17,   17,   17, 0x08,
     103,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PropertiesDialog[] = {
    "PropertiesDialog\0\0on_buttonBox_accepted()\0"
    "on_textColorButton_clicked()\0"
    "on_outlineColorButton_clicked()\0"
    "on_backgroundColorButton_clicked()\0"
};

void PropertiesDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertiesDialog *_t = static_cast<PropertiesDialog *>(_o);
        switch (_id) {
        case 0: _t->on_buttonBox_accepted(); break;
        case 1: _t->on_textColorButton_clicked(); break;
        case 2: _t->on_outlineColorButton_clicked(); break;
        case 3: _t->on_backgroundColorButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData PropertiesDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropertiesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PropertiesDialog,
      qt_meta_data_PropertiesDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropertiesDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropertiesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropertiesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropertiesDialog))
        return static_cast<void*>(const_cast< PropertiesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int PropertiesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
