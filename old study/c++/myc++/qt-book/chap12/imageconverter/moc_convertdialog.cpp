/****************************************************************************
** Meta object code from reading C++ file 'convertdialog.h'
**
** Created: Thu Mar 19 09:57:07 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "convertdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convertdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConvertDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      41,   14,   14,   14, 0x08,
      56,   14,   14,   14, 0x08,
      99,   79,   14,   14, 0x08,
     147,  141,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConvertDialog[] = {
    "ConvertDialog\0\0on_browseButton_clicked()\0"
    "convertImage()\0updateOutputTextEdit()\0"
    "exitCode,exitStatus\0"
    "processFinished(int,QProcess::ExitStatus)\0"
    "error\0processError(QProcess::ProcessError)\0"
};

void ConvertDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConvertDialog *_t = static_cast<ConvertDialog *>(_o);
        switch (_id) {
        case 0: _t->on_browseButton_clicked(); break;
        case 1: _t->convertImage(); break;
        case 2: _t->updateOutputTextEdit(); break;
        case 3: _t->processFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 4: _t->processError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConvertDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConvertDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConvertDialog,
      qt_meta_data_ConvertDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConvertDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConvertDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConvertDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConvertDialog))
        return static_cast<void*>(const_cast< ConvertDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConvertDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
