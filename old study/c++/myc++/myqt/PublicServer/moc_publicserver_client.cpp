/****************************************************************************
** Meta object code from reading C++ file 'publicserver_client.h'
**
** Created: Tue Mar 24 14:20:59 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "publicserver_client.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'publicserver_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_publicserver_client[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   21,   20,   20, 0x05,
      50,   20,   20,   20, 0x05,
      68,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   20,   20,   20, 0x09,
     116,   20,   20,   20, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_publicserver_client[] = {
    "publicserver_client\0\0,\0"
    "updateClients(QString,int)\0disconnected(int)\0"
    "tellpublicserver_server(QString)\0"
    "dataReceived()\0slotDisconnected()\0"
};

void publicserver_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        publicserver_client *_t = static_cast<publicserver_client *>(_o);
        switch (_id) {
        case 0: _t->updateClients((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->disconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->tellpublicserver_server((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dataReceived(); break;
        case 4: _t->slotDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData publicserver_client::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject publicserver_client::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_publicserver_client,
      qt_meta_data_publicserver_client, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &publicserver_client::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *publicserver_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *publicserver_client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_publicserver_client))
        return static_cast<void*>(const_cast< publicserver_client*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int publicserver_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void publicserver_client::updateClients(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void publicserver_client::disconnected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void publicserver_client::tellpublicserver_server(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
