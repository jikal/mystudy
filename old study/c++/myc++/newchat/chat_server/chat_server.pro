#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T23:58:29
#
#-------------------------------------------------

QT       += core gui

TARGET = chat_server
TEMPLATE = app


SOURCES += main.cpp\
        chat_server.cpp \
    chat_thread.cpp \
    connect.cpp \
    serverSocket.cpp

HEADERS  += chat_server.h \
    chat-thread.h \
    connect.h \
    serverSocket.h

FORMS    += chat_server.ui

QT  += network
