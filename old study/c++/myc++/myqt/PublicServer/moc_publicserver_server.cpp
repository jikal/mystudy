/****************************************************************************
** Meta object code from reading C++ file 'publicserver_server.h'
**
** Created: Tue Mar 24 14:20:59 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "publicserver_server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'publicserver_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_publicserver_server[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   21,   20,   20, 0x05,
      49,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   21,   20,   20, 0x0a,
     106,   20,   20,   20, 0x0a,
     128,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_publicserver_server[] = {
    "publicserver_server\0\0,\0updateServer(QString,int)\0"
    "tellpublicserver_sig(QString)\0"
    "updateClients(QString,int)\0"
    "slotDisconnected(int)\0tellpublicserver(QString)\0"
};

void publicserver_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        publicserver_server *_t = static_cast<publicserver_server *>(_o);
        switch (_id) {
        case 0: _t->updateServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->tellpublicserver_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateClients((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->slotDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->tellpublicserver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData publicserver_server::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject publicserver_server::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_publicserver_server,
      qt_meta_data_publicserver_server, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &publicserver_server::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *publicserver_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *publicserver_server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_publicserver_server))
        return static_cast<void*>(const_cast< publicserver_server*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int publicserver_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void publicserver_server::updateServer(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void publicserver_server::tellpublicserver_sig(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
