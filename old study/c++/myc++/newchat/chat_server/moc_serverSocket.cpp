/****************************************************************************
** Meta object code from reading C++ file 'serverSocket.h'
**
** Created: Fri Mar 27 00:31:04 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "serverSocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerSocket[] = {

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
      21,   14,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerSocket[] = {
    "ServerSocket\0\0thrdfd\0thrdExiting(quint32)\0"
};

void ServerSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ServerSocket *_t = static_cast<ServerSocket *>(_o);
        switch (_id) {
        case 0: _t->thrdExiting((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ServerSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ServerSocket::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_ServerSocket,
      qt_meta_data_ServerSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerSocket))
        return static_cast<void*>(const_cast< ServerSocket*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int ServerSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
