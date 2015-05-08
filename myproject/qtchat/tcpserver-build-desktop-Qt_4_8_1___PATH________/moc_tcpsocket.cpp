/****************************************************************************
** Meta object code from reading C++ file 'tcpsocket.h'
**
** Created: Fri Apr 3 09:11:55 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpserver/tcpsocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,
      38,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      56,   10,   10,   10, 0x09,
      71,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_TcpSocket[] = {
    "TcpSocket\0\0,\0sendClients(QString,int)\0"
    "disconnected(int)\0dataReceived()\0"
    "slotDisconnected()\0"
};

void TcpSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpSocket *_t = static_cast<TcpSocket *>(_o);
        switch (_id) {
        case 0: _t->sendClients((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->disconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dataReceived(); break;
        case 3: _t->slotDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpSocket,
      qt_meta_data_TcpSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocket))
        return static_cast<void*>(const_cast< TcpSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TcpSocket::sendClients(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpSocket::disconnected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
