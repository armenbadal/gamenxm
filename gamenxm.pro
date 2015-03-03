
QT += core gui widgets

TARGET = gamenxm
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    tile.cpp \
    board.cpp \
    window.cpp \
    gamenxm.cpp

HEADERS += \
    tile.h \
    board.h \
    window.h \
    gamenxm.h
