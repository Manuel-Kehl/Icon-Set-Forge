#-------------------------------------------------
#
# Project created by QtCreator 2014-07-18T12:07:51
#
#-------------------------------------------------

QT += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IconSetForge
TEMPLATE = app


SOURCES +=\
    view/iconsetbrowser.cpp \
    view/iconsetview.cpp \
    control/main.cpp \
    view/mainwindow.cpp \
    view/layouts/borderlayout.cpp \
    view/layouts/flowlayout.cpp

HEADERS  += \
    view/iconsetbrowser.h \
    view/iconsetview.h \
    view/mainwindow.h \
    view/layouts/borderlayout.h \
    view/layouts/flowlayout.h

FORMS    += mainwindow.ui
