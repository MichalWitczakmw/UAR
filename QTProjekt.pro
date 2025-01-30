QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Generator_Sygnalow.cpp \
    Model_ARX.cpp \
    Regulator_PID.cpp \
    Robie_Wykres.cpp \
    Sprzerzenie_Zwrotne.cpp \
    Zapisze_Do_Pliku.cpp \
    Generator_Sygnalow.cpp \
    Model_ARX.cpp \
    Regulator_PID.cpp \
    Robie_Wykres.cpp \
    Sprzerzenie_Zwrotne.cpp \
    Zapisze_Do_Pliku.cpp \
    main.cpp \
    main_Okno_Zapisu.cpp \
    mainwindow.cpp

HEADERS += \
    Generator_Sygnalow.h \
    Model_ARX.h \
    Regulator_PID.h \
    Robie_Wykres.h \
    Sprzerzenie_Zwrotne.h \
    Zapisze_Do_Pliku.h \
    Generator_Sygnalow.h \
    Model_ARX.h \
    Regulator_PID.h \
    Robie_Wykres.h \
    Sprzerzenie_Zwrotne.h \
    Zapisze_Do_Pliku.h \
    main_Okno_Zapisu.h \
    mainwindow.h

FORMS += \
    main_Okno_Zapisu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
