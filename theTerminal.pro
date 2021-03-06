#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T19:14:06
#
#-------------------------------------------------

QT       += core gui x11extras thelib
CONFIG   += c++14
LIBS     += -lX11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = theterminal
TEMPLATE = app
LIBS += -lqtermwidget5

SOURCES += main.cpp\
        mainwindow.cpp \
    terminalwidget.cpp \
    about.cpp \
    dropdown.cpp \
    nativeeventfilter.cpp \
    settingswindow.cpp

HEADERS  += mainwindow.h \
    terminalwidget.h \
    about.h \
    dropdown.h \
    nativeeventfilter.h \
    settingswindow.h

FORMS    += mainwindow.ui \
    about.ui \
    dropdown.ui \
    settingswindow.ui

unix {
    target.path = /usr/bin

    appentry.path = /usr/share/applications
    appentry.files = theterminal.desktop theterminaldd.desktop

    INSTALLS += target appentry
}

DISTFILES += \
    theterminaldd.desktop \
    theterminal.desktop
