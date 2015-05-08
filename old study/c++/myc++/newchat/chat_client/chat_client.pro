#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T22:42:27
#
#-------------------------------------------------

QT       += core gui
QT += network
TARGET = chat_client
TEMPLATE = app


SOURCES += main.cpp\
        chatclient.cpp \
    clientlogin.cpp \
    regusr.cpp

HEADERS  += chatclient.h \
    clientlogin.h \
    regusr.h \
    common.h

FORMS    += chatclient.ui \
    clientlogin.ui \
    regusr.ui


