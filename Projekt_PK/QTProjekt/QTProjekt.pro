QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Projekt_PK/Generator_Sygnalow.cpp \
    ../Projekt_PK/Model_ARX.cpp \
    ../Projekt_PK/Regulator_PID.cpp \
    ../Projekt_PK/Robie_Wykres.cpp \
    ../Projekt_PK/Sprzerzenie_Zwrotne.cpp \
    ../Projekt_PK/Zapisze_Do_Pliku.cpp \
    main.cpp \
    main_Okno_Zapisu.cpp \
    mainwindow.cpp

HEADERS += \
    ../Projekt_PK/Generator_Sygnalow.h \
    ../Projekt_PK/Model_ARX.h \
    ../Projekt_PK/Regulator_PID.h \
    ../Projekt_PK/Robie_Wykres.h \
    ../Projekt_PK/Sprzerzenie_Zwrotne.h \
    ../Projekt_PK/Zapisze_Do_Pliku.h \
    main_Okno_Zapisu.h \
    mainwindow.h

FORMS += \
    main_Okno_Zapisu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
