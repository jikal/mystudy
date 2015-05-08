/****************************************************************************
** Meta object code from reading C++ file 'imagewindow.h'
**
** Created: Thu Mar 19 09:57:31 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imagewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      25,   12,   20,   12, 0x08,
      32,   12,   20,   12, 0x08,
      41,   12,   12,   12, 0x08,
      60,   12,   12,   12, 0x08,
      77,   12,   12,   12, 0x08,
      91,   12,   12,   12, 0x08,
     108,   12,   12,   12, 0x08,
     124,   12,   12,   12, 0x08,
     140,   12,   12,   12, 0x08,
     148,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageWindow[] = {
    "ImageWindow\0\0open()\0bool\0save()\0"
    "saveAs()\0flipHorizontally()\0"
    "flipVertically()\0resizeImage()\0"
    "convertTo32Bit()\0convertTo8Bit()\0"
    "convertTo1Bit()\0about()\0allTransactionsDone()\0"
};

void ImageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImageWindow *_t = static_cast<ImageWindow *>(_o);
        switch (_id) {
        case 0: _t->open(); break;
        case 1: { bool _r = _t->save();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->saveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->flipHorizontally(); break;
        case 4: _t->flipVertically(); break;
        case 5: _t->resizeImage(); break;
        case 6: _t->convertTo32Bit(); break;
        case 7: _t->convertTo8Bit(); break;
        case 8: _t->convertTo1Bit(); break;
        case 9: _t->about(); break;
        case 10: _t->allTransactionsDone(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImageWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImageWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageWindow,
      qt_meta_data_ImageWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWindow))
        return static_cast<void*>(const_cast< ImageWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
