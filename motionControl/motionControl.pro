#-------------------------------------------------
#
# Project created by QtCreator 2018-06-24T01:36:57
#
#-------------------------------------------------

QT       -= gui

TARGET = motionControl
TEMPLATE = lib
CONFIG  += staticlib
DESTDIR  = ../lib
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
        motioncontrol.cpp \
    motioncontrolfactory.cpp \
    axis.cpp

HEADERS += \
        motioncontrol.h \
    motioncontrolfactory.h \
    axis.h

#--------------------------------------------Motion-------------------------------------------
CONFIG(debug,debug|release) {
LIBS += $$PWD/motion/lib/Motion_Drvd.lib
}
else {
LIBS += $$PWD/motion/lib/Motion_Drv.lib
}

INCLUDEPATH += \
    $$PWD/include/ \
    $$PWD/motion/include/
#----------------------------------------------------------------------------------------------

unix {
    target.path = /usr/lib
    INSTALLS += target
}
