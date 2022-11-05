TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp

SOURCES += \
        circle.cpp \
        ellipse.cpp \
        helix.cpp \
        main.cpp \
        point3d.cpp

HEADERS += \
    circle.h \
    ellipse.h \
    helix.h \
    point3d.h \

