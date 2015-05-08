#-------------------------------------------------
#
# Project created by QtCreator 2015-02-12T10:27:55
#
#-------------------------------------------------

QT       += core gui network

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp \
    server.cpp \
    tcpocket.cpp

HEADERS  += tcpserver.h \
    server.h \
    tcpsocket.h \
    server_common.h

FORMS    += tcpserver.ui
