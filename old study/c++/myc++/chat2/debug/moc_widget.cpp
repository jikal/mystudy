/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Mon Jul 2 12:50:14 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    8,    7,    7, 0x08,
      64,   56,    7,    7, 0x08,
      95,    7,    7,    7, 0x08,
     114,    7,    7,    7, 0x08,
     132,    7,    7,    7, 0x08,
     155,   56,    7,    7, 0x08,
     183,   56,    7,    7, 0x08,
     211,  209,    7,    7, 0x08,
     253,    7,    7,    7, 0x08,
     302,    7,    7,    7, 0x08,
     321,    7,    7,    7, 0x08,
     343,    7,    7,    7, 0x08,
     361,    7,    7,    7, 0x08,
     387,    7,    7,    7, 0x08,
     416,  409,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0index\0on_tableWidget_doubleClicked(QModelIndex)\0"
    "checked\0on_textUnderline_clicked(bool)\0"
    "on_clear_clicked()\0on_save_clicked()\0"
    "on_textcolor_clicked()\0"
    "on_textitalic_clicked(bool)\0"
    "on_textbold_clicked(bool)\0f\0"
    "on_fontComboBox_currentFontChanged(QFont)\0"
    "on_fontsizecomboBox_currentIndexChanged(QString)\0"
    "on_close_clicked()\0on_sendfile_clicked()\0"
    "on_send_clicked()\0processPendingDatagrams()\0"
    "sentFileName(QString)\0format\0"
    "currentFormatChanged(QTextCharFormat)\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->on_tableWidget_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_textUnderline_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_clear_clicked(); break;
        case 3: _t->on_save_clicked(); break;
        case 4: _t->on_textcolor_clicked(); break;
        case 5: _t->on_textitalic_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_textbold_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_fontComboBox_currentFontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 8: _t->on_fontsizecomboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_close_clicked(); break;
        case 10: _t->on_sendfile_clicked(); break;
        case 11: _t->on_send_clicked(); break;
        case 12: _t->processPendingDatagrams(); break;
        case 13: _t->sentFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->currentFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
