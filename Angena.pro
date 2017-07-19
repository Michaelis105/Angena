#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T19:43:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Angena
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
    src/dialogs/dialog.cpp \
    src/dialogs/dialogabout.cpp \
    src/dialogs/dialognewfamily.cpp \
    src/dialogs/dialogsaveconfirmation.cpp \
    src/model/familytree.cpp \
    src/model/fileio.cpp \
    src/model/model.cpp \
    src/model/person.cpp \
    src/model/personnode.cpp \
    src/angena.cpp \
    src/main.cpp \
    src/model/personname.cpp \
    src/model/personaddress.cpp \
    src/model/date.cpp

HEADERS += \
    src/dialogs/dialog.h \
    src/dialogs/dialogabout.h \
    src/dialogs/dialognewfamily.h \
    src/dialogs/dialogsaveconfirmation.h \
    src/model/familytree.h \
    src/model/fileio.h \
    src/model/model.h \
    src/model/person.h \
    src/model/personnode.h \
    src/angena.h \
    src/model/personname.h \
    src/model/personaddress.h \
    src/model/date.h

FORMS += \
    src/dialogs/dialogabout.ui \
    src/dialogs/dialognewfamily.ui \
    src/dialogs/dialogsaveconfirmation.ui \
    src/angena.ui

SUBDIRS += \
    Angena.pro

DISTFILES += \
    LICENSE.md \
    README.md
