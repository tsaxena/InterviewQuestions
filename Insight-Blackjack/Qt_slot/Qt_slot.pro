#-------------------------------------------------
#
# Project created by QtCreator 2014-04-22T18:15:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt_slot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    player.cpp \
    card.cpp \
    dealer.cpp \
    deck.cpp \
    hand.cpp \
    generic-player.cpp

HEADERS  += mainwindow.h \
    game.h \
    card.h \
    dealer.h \
    deck.h \
    generic-player.h \
    hand.h \
    player.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
