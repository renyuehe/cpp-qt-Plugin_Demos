TEMPLATE = lib
CONFIG += c++11

SOURCES += \
    dll.cpp

HEADERS += \
    dll.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
