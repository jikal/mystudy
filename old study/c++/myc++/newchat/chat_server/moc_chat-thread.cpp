/****************************************************************************
** Meta object code from reading C++ file 'chat-thread.h'
**
** Created: Fri Mar 27 00:31:03 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "chat-thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat-thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_serverThread[] = {

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
      21,   14,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_serverThread[] = {
    "serverThread\0\0thrdfd\0exiting(quint32)\0"
    "sockDisconnected()\0"
};

void serverThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        serverThread *_t = static_cast<serverThread *>(_o);
        switch (_id) {
        case 0: _t->exiting((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->sockDisconnected(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData serverThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject serverThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_serverThread,
      qt_meta_data_serverThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &serverThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *serverThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *serverThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_serverThread))
        return static_cast<void*>(const_cast< serverThread*>(this));
    return QThread::qt_metacast(_clname);
}

int serverThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void serverThread::exiting(quint32 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
