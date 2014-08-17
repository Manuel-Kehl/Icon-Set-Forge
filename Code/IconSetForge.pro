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
    model/iconclassification.cpp \
    model/icon.cpp \
    model/iconset.cpp \
    control/scannerstrategies/abstractscannerstrategy.cpp \
    model/access/classificationtreemodel.cpp \
    model/iconcomponent.cpp \
    model/icongroup.cpp \
    model/access/iconlistmodel.cpp \
    control/scannerstrategies/freedesktopscannerstrategy.cpp

HEADERS  += \
    view/iconsetbrowser.h \
    view/iconsetview.h \
    view/mainwindow.h \
    view/layouts/borderlayout.h \
    view/layouts/flowlayout.h \
    model/iconclassification.h \
    model/icon.h \
    model/iconset.h \
    control/scannerstrategies/abstractscannerstrategy.h \
    model/access/classificationtreemodel.h \
    model/iconcomponent.h \
    model/icongroup.h \
    model/access/iconlistmodel.h \
    control/scannerstrategies/freedesktopscannerstrategy.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
