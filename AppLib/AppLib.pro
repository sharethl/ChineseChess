#-------------------------------------------------
#
# Project created by QtCreator 2018-04-29T12:59:44
#
#-------------------------------------------------

QT       -= gui

TARGET = AppLib
TEMPLATE = lib
CONFIG += staticlib

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
    Greeter.cpp \
    ChessPiece.cpp \
    ChessBoard.cpp \
    Bing.cpp \
    Che.cpp \
    Shuai.cpp \
    Ma.cpp \
    Shi.cpp \
    Xiang.cpp \
    pao.cpp

HEADERS += \
    Greeter.h \
    ChessPiece.h \
    ChessBoard.h \
    IBoard.h \
    Bing.h \
    IBoard.h \
    Player.h \
    Che.h \
    Shuai.h \
    Shi.h \
    Ma.h \
    Xiang.h \
    pao.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
