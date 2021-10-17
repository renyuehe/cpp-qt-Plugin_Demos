QT += core gui sql widgets

TEMPLATE = lib
TARGET = Communication

include(../../common.pri)

INCLUDEPATH += $$SHARE_PATH/Communication
DEFINES += COMMON_LIBRARY

HEADERS += \
    $$SHARE_PATH/Communication/ComInstance.h


SOURCES += \
    ComInstance.cpp \

#生成路径
DESTDIR = $$DEST_LIBS
