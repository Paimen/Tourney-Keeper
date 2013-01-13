#-------------------------------------------------
#
# Project created by QtCreator 2013-01-06T15:59:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tourney-Keeper
TEMPLATE = app


SOURCES += UI/main.cpp\
    UI/mainwindow.cpp \
    UI/tournamentselector.cpp \
    UI/tournamentwizard.cpp \
    UI/tournamentbasicinformationpage.cpp \
    UI/tournamentaddplayerspage.cpp \
    UI/tournamentsettingspage.cpp \
    UI/hintcombobox.cpp \
    UI/playercreationdialog.cpp \
    UI/playerrowwidget.cpp

HEADERS  += UI/mainwindow.h \
    UI/tournamentselector.h \
    UI/tournamentwizard.h \
    UI/tournamentbasicinformationpage.h \
    UI/tournamentaddplayerspage.h \
    UI/tournamentsettingspage.h \
    UI/hintcombobox.h \
    UI/playercreationdialog.h \
    UI/playerrowwidget.h

RESOURCES += \
    Assets/assets.qrc

