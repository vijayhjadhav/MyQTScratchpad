QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testcsvfile.cpp \
    colorhistogram.cpp

LIBS += -L..\opencv-build\install\x64\vc16\lib -lopencv_core451d -lopencv_imgproc451d -lopencv_highgui451d -lopencv_imgcodecs451d -lopencv_videoio451d -lopencv_video451d -lopencv_calib3d451d -lopencv_photo451d -lopencv_features2d451d

INCLUDEPATH += ..\opencv-build\install\include
DEPENDPATH += ..\opencv-build\install\include

HEADERS += \
    colorhistogram.h
