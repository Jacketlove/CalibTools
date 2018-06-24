#-------------------------------------------------
#
# Project created by QtCreator 2018-06-23T00:25:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindow
TEMPLATE = app
DESTDIR = ../bin
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
        main.cpp \
        mainwindow.cpp \
    dialogsettiongcamera.cpp

HEADERS += \
        mainwindow.h \
    dialogsettiongcamera.h

FORMS += \
        mainwindow.ui \
    dialogsettiongcamera.ui

RESOURCES += \
    icon.qrc

#--------------------------------------------Basler-------------------------------------------
INCLUDEPATH += $$PWD/../camera/pylon/include
LIBS += -L$$PWD/../camera/pylon/lib/x64 \
-lGCBase_MD_VC120_v3_0_Basler_pylon_v5_0 \
-lGenApi_MD_VC120_v3_0_Basler_pylon_v5_0 \
-lPylonBase_MD_VC120_v5_0 \
-lPylonC_MD_VC120 \
-lPylonGUI_MD_VC120_v5_0 \
-lPylonUtility_MD_VC120_v5_0 \
#--------------------------------------------Basler End---------------------------------------

#--------------------------------------------Opencv-------------------------------------------
#自定义变量用$${},环境变量用$$()
OPENCV_PATH  = D:\opencv
INCLUDEPATH += $${OPENCV_PATH}\build\include
INCLUDEPATH += $${OPENCV_PATH}\build\include\opencv2
INCLUDEPATH += $${OPENCV_PATH}\build\include\opencv
CONFIG(debug, debug|release) {
LIBS += $${OPENCV_PATH}\build\x64\vc15\lib\opencv_world341d.lib
}
else {
LIBS += $${OPENCV_PATH}\build\x64\vc15\lib\opencv_world341.lib
}
#--------------------------------------------Opencv End---------------------------------------

#--------------------------------------------Motion-------------------------------------------
CONFIG(debug,debug|release) {
LIBS += $$PWD/../motionControl/motion/lib/Motion_Drvd.lib
}
else {
LIBS += $$PWD/../motionControl/motion/lib/Motion_Drv.lib
}

INCLUDEPATH += \
    $$PWD/../motionControl/motion/include/
#----------------------------------------------------------------------------------------------

#--------------------------------------------Camera-------------------------------------------
INCLUDEPATH += $$PWD/../camera
LIBS += $$PWD\..\lib\camera.lib
#--------------------------------------------Camera End---------------------------------------

#--------------------------------------------MotionControl------------------------------------
INCLUDEPATH += $$PWD/../motionControl
LIBS += $$PWD\..\lib\motionControl.lib
#--------------------------------------------MotionControl End--------------------------------
