#-------------------------------------------------
#
# Project created by QtCreator 2013-04-16T10:13:42
#
#-------------------------------------------------

QT       += core gui

CONFIG   += qxt
QXT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hamster
TEMPLATE = app


SOURCES += main.cpp\
        prompt.cpp \
    iniparser.cpp \
    imgbutton.cpp

HEADERS  += prompt.h \
    iniparser.h \
    imgbutton.h

FORMS    +=

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    config.ini
