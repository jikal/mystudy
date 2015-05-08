/****************************************************************************
** Meta object code from reading C++ file 'connect.h'
**
** Created: Fri Mar 27 00:31:03 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "connect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConnectSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConnectSocket[] = {
    "ConnectSocket\0\0sockfd\0closing(int)\0"
    "readMessage()\0"
};

void ConnectSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConnectSocket *_t = static_cast<ConnectSocket *>(_o);
        switch (_id) {
        case 0: _t->closing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->readMessage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConnectSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConnectSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_ConnectSocket,
      qt_meta_data_ConnectSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConnectSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConnectSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConnectSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectSocket))
        return static_cast<void*>(const_cast< ConnectSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int ConnectSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ConnectSocket::closing(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
