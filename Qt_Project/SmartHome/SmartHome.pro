#-------------------------------------------------
#
# Project created by QtCreator 2020-04-23T20:34:31
#
#-------------------------------------------------

QT       += core gui network
QT       += multimedia
QT       += sql
QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHome
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        loginwindow.cpp \
    majorwindow.cpp \
    roomwindow.cpp \
    playmedia.cpp \
    registerwindow.cpp \
    userdatabase.cpp \
    airhttp.cpp \
    camerawindow.cpp \
    camerawidget.cpp

HEADERS += \
        loginwindow.h \
    majorwindow.h \
    roomwindow.h \
    playmedia.h \
    registerwindow.h \
    userdatabase.h \
    airhttp.h \
    camerawindow.h \
    camerawidget.h

FORMS += \
        loginwindow.ui \
    majorwindow.ui \
    roomwindow.ui \
    playmedia.ui \
    registerwindow.ui \
    camerawindow.ui

RESOURCES += \
    sources.qrc

RC_FILE = Batman.rc
