#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T14:55:40
#
#-------------------------------------------------

QT       += core gui sql
QT       += network
TARGET = tcpserver
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp \
    server.cpp \
    tcpsocket.cpp

HEADERS  += tcpserver.h \
    server.h \
    tcpsocket.h

FORMS    += tcpserver.ui
