/****************************************************************************
** Meta object code from reading C++ file 'chatclient.h'
**
** Created: Fri Mar 27 12:52:09 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chat_client/chatclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chatClient[] = {

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
      12,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_chatClient[] = {
    "chatClient\0\0enterChatroomButton()\0"
    "displayError(QAbstractSocket::SocketError)\0"
};

void chatClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        chatClient *_t = static_cast<chatClient *>(_o);
        switch (_id) {
        case 0: _t->enterChatroomButton(); break;
        case 1: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData chatClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject chatClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_chatClient,
      qt_meta_data_chatClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &chatClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *chatClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *chatClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chatClient))
        return static_cast<void*>(const_cast< chatClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int chatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
