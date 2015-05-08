#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T20:04:20
#
#-------------------------------------------------

QT       += core gui

TARGET = chatclient
TEMPLATE = app


SOURCES += main.cpp\
        chatclient.cpp \
    regusr.cpp \
    clientlogin.cpp \
    chat.cpp

HEADERS  += chatclient.h \
    regusr.h \
    clientlogin.h \
    chat.h

FORMS    += chatclient.ui \
    regusr.ui \
    clientlogin.ui \
    chat.ui

QT += network
