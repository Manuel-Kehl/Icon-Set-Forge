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
    view/layouts/flowlayout.cpp \
    control/abstracticonscannerstrategy.cpp \
    model/iconclassification.cpp

HEADERS  += \
    view/iconsetbrowser.h \
    view/iconsetview.h \
    view/mainwindow.h \
    view/layouts/borderlayout.h \
    view/layouts/flowlayout.h \
    control/abstracticonscannerstrategy.h \
    model/iconclassification.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
