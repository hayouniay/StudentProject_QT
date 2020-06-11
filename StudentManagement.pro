#-------------------------------------------------
#
# Project created by QtCreator 2020-06-05T17:21:45
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentManagement
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    cancel.cpp \
    add.cpp \
    list.cpp \
    dbase.cpp \
    modify.cpp \
    delete.cpp \
    info.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    cancel.h \
    add.h \
    log.h \
    list.h \
    dbase.h \
    modify.h \
    delete.h \
    info.h

FORMS += \
        mainwindow.ui \
    menu.ui \
    cancel.ui \
    add.ui \
    list.ui \
    modify.ui \
    delete.ui \
    info.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    exit.png \
    list.png \
    modify.png
