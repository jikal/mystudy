/****************************************************************************
** Resource object code
**
** Created: Thu Mar 19 09:55:05 2015
**      by: The Resource Compiler for Qt version 4.8.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/iotek/c++/myc++/qt-book/chap05/iconeditorplugin/images/iconeditor.png
  0x0,0x0,0x0,0xa6,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x11,0x0,0x0,0x0,0x11,0x8,0x6,0x0,0x0,0x0,0x3b,0x6d,0x47,0xfa,
  0x0,0x0,0x0,0x6,0x62,0x4b,0x47,0x44,0x0,0xff,0x0,0xff,0x0,0xff,0xa0,0xbd,
  0xa7,0x93,0x0,0x0,0x0,0x5b,0x49,0x44,0x41,0x54,0x38,0xcb,0xcd,0xd3,0xb1,0x9,
  0xc0,0x30,0xc,0x44,0xd1,0x3f,0x66,0xc6,0xc9,0x38,0x1e,0x43,0x83,0x64,0x97,0x9f,
  0x26,0xc8,0x22,0xb8,0x8b,0x3,0x12,0xbc,0xe2,0xa,0x5d,0x21,0x10,0x80,0x1b,0xe0,
  0xb8,0x4c,0x80,0xc7,0x30,0x1,0x72,0x3a,0x3d,0x4b,0x65,0xba,0x95,0x6c,0xb9,0x89,
  0x11,0x9,0xd0,0x2,0x30,0xa,0xc0,0xb3,0x68,0x58,0xb2,0xe7,0x26,0x46,0x5a,0xe7,
  0x9,0x30,0x62,0x6a,0x58,0xf2,0xcb,0xef,0xbc,0x73,0x9d,0x55,0x6e,0x56,0xf2,0xd5,
  0xd,0x89,0x3b,0x2b,0x88,0x75,0x73,0xf,0x6f,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,
  0x44,0xae,0x42,0x60,0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // images
  0x0,0x6,
  0x7,0x3,0x7d,0xc3,
  0x0,0x69,
  0x0,0x6d,0x0,0x61,0x0,0x67,0x0,0x65,0x0,0x73,
    // iconeditor.png
  0x0,0xe,
  0xf,0xac,0x3a,0xa7,
  0x0,0x69,
  0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x65,0x0,0x64,0x0,0x69,0x0,0x74,0x0,0x6f,0x0,0x72,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/images
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/images/iconeditor.png
  0x0,0x0,0x0,0x12,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_iconeditorplugin)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_iconeditorplugin))

int QT_MANGLE_NAMESPACE(qCleanupResources_iconeditorplugin)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_iconeditorplugin))

