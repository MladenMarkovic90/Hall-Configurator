TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11


LIBS += libfreeglut -lopengl32 -lglu32 -luser32


SOURCES += main.cpp


HEADERS += glutcpp/glutcpp.h \
    glutcpp/glutMouseListener.h \
    glutcpp/glutReshapeListener.h \
    glutcpp/glutDisplay.h \
    glutcpp/glutNormalKeyListener.h \
    glutcpp/glutMotionListener.h \
    glutcpp/glutAnimationTimer.h \
    glutcpp/glutSpecialKeyListener.h \
    glutcpp/glutMouseWheelListener.h \
    glutcpp/tacka.h \
    glutcpp/vector3d.h \
    delovi2d.h \
    materijal.h \
    quad.h


HEADERS += global.h \
    animationStatus.h \
    display.h \
    specialKeyListener.h \
    normalKeyListener.h \
    reshapeListener.h \
    mouseListener.h \
    mouseWheelListener.h \
    motionListener.h \
    metalniDeo.h \
    konstrukcija.h \
    mreza.h \
    delovi.h

include(deployment.pri)

