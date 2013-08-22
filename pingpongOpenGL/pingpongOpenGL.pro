QMAKE_CXXFLAGS += -std=c++11

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pingpongOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../pingpong/ball.cpp \
    ../pingpong/racket.cpp \
    ../pingpong/gamescene.cpp \
    ../pingpong/gamecontroller.cpp

HEADERS  += mainwindow.h \
    ../pingpong/racket.h \
    ../pingpong/gamescene.h \
    ../pingpong/gamecontroller.h \
    ../pingpong/ball.h
