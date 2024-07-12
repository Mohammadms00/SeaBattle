QT       += core gui sql widgets

TEMPLATE = app
TARGET = testLogIn
INCLUDEPATH += .

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airdefenseweapon.cpp \
    atomicbombweapon.cpp \
<<<<<<< HEAD
    buyweaponwidget.cpp \
    clickablegameboard.cpp \
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
    database.cpp \
    draggableship.cpp \
    forgetpasswordwindow.cpp \
    gameboard.cpp \
    gamemenuwindow.cpp \
    linearbombweapon.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mineweapon.cpp \
    observationweapon.cpp \
<<<<<<< HEAD
    ondeviceplay.cpp \
    placeshipswidget.cpp \
    playwidget.cpp \
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
    signupwindow.cpp \
    user.cpp \
    weapon.cpp

HEADERS += \
    airdefenseweapon.h \
    atomicbombweapon.h \
<<<<<<< HEAD
    buyweaponwidget.h \
    clickablegameboard.h \
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
    database.h \
    draggableship.h \
    forgetpasswordwindow.h \
    gameboard.h \
    gamemenuwindow.h \
    linearbombweapon.h \
    loginwindow.h \
    mainwindow.h \
    mineweapon.h \
    observationweapon.h \
<<<<<<< HEAD
    ondeviceplay.h \
    placeshipswidget.h \
    playwidget.h \
=======
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
    signupwindow.h \
    user.h \
    weapon.h

FORMS += \
    buyweaponwidget.ui \
    forgetpasswordwindow.ui \
    gamemenuwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    ondeviceplay.ui \
    placeshipswidget.ui \
    playwidget.ui \
    signupwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

SUBDIRS += \
    weapon.pro
