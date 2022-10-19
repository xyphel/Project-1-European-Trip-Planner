QT       += core gui
QT += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    berlintripwindow.cpp \
    custominput.cpp \
    customwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    newberlinwindow.cpp \
    parisinput.cpp \
    pariswindow.cpp \
    plantripwindow.cpp \
    summarypage.cpp \
    travelplan.cpp

HEADERS += \
    adminpage.h \
    berlintripwindow.h \
    custominput.h \
    customwindow.h \
    loginwindow.h \
    mainwindow.h \
    newberlinwindow.h \
    parisinput.h \
    pariswindow.h \
    plantripwindow.h \
    summarypage.h \
    travelplan.h

FORMS += \
    adminpage.ui \
    berlintripwindow.ui \
    custominput.ui \
    customwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    newberlinwindow.ui \
    parisinput.ui \
    pariswindow.ui \
    plantripwindow.ui \
    summarypage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
