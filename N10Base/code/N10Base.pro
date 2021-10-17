TEMPLATE = subdirs

CONFIG += ordered

include(common.pri)

message("aaaaaaaaaaaaaaaaaaaaaaaaaa")

#SUBDIRS += \
#    lib \
#    plugin \
#    MainFrame                           #主框架

SUBDIRS += \
    MainForm \
    lib \
    plugin

