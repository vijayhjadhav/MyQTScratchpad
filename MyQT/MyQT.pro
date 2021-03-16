QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        colorhistogram.cpp \
        main.cpp

LIBS += -L..\opencv-build\install\x64\vc16\lib -lopencv_core451d -lopencv_imgproc451d -lopencv_highgui451d -lopencv_imgcodecs451d -lopencv_videoio451d -lopencv_video451d -lopencv_calib3d451d -lopencv_photo451d -lopencv_features2d451d

INCLUDEPATH += ..\opencv-build\install\include
DEPENDPATH += ..\opencv-build\install\include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    colorhistogram.h
