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
    control/main.cpp \
    view/mainwindow.cpp \
    view/layouts/borderlayout.cpp \
    view/layouts/flowlayout.cpp \
    model/iconclassification.cpp \
    model/icon.cpp \
    model/iconset.cpp \
    scannerstrategies/abstractscannerstrategy.cpp \
    model/access/classificationtreemodel.cpp \
    model/iconcomponent.cpp \
    model/icongroup.cpp \
    model/access/iconlistmodel.cpp \
    scannerstrategies/freedesktopscannerstrategy.cpp \
    control/coordinator.cpp \
    control/iconsetoperator.cpp \
    model/access/iconsetobserver.cpp \
    control/commands/iconsetcommand.cpp \
    control/commands/deleteiconcommand.cpp \
    model/access/iconfilterproxymodel.cpp

HEADERS  += \
    view/iconsetbrowser.h \
    view/mainwindow.h \
    view/layouts/borderlayout.h \
    view/layouts/flowlayout.h \
    model/iconclassification.h \
    model/icon.h \
    model/iconset.h \
    scannerstrategies/abstractscannerstrategy.h \
    model/access/classificationtreemodel.h \
    model/iconcomponent.h \
    model/icongroup.h \
    model/access/iconlistmodel.h \
    scannerstrategies/freedesktopscannerstrategy.h \
    control/coordinator.h \
    control/iconsetoperator.h \
    model/access/iconsetobserver.h \
    control/commands/iconsetcommand.h \
    control/commands/deleteiconcommand.h \
    model/access/iconfilterproxymodel.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11

# Mac flags
macx{
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.7 -stdlib=libc++
    LIBS += -mmacosx-version-min=10.7 -stdlib=libc++
}
