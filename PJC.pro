TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp\
    isize.cpp \
    imobile.cpp \
    iobject.cpp \
    obstacle.cpp \
    creature.cpp \
    board.cpp \
    player.cpp \
    gwindow.cpp

PKGCONFIG += sdl2
CONFIG += link_pkgconfig

HEADERS  += \
    isize.h \
    imobile.h \
    iobject.h \
    obstacle.h \
    creature.h \
    board.h \
    player.h \
    gwindow.h

