QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

include(../common.pri)
INCLUDEPATH +=  \
               $$SHARE_PATH/CommonHeader \
               $$SHARE_PATH/Communication

SOURCES += \
    ComPluginManager.cpp \
    WorkSpaceWidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ComPluginManager.h \
    WorkSpaceWidget.h \
    mainwindow.h \
    $$SHARE_PATH/CommonHeader/ComPluginInterface.h \

DESTDIR  = $${DEST_BINS}

LIBS += -L$$DEST_LIBS -lCommunication
