QT += core gui multimedia gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS std=c89

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/debug.c \
    src/emu.c \
    src/font.c \
    src/frontend/qt/framebuffer_widget.cpp \
    src/frontend/qt/main.cpp \
    src/frontend/qt/mainwindow.cpp \
    src/frontend/qt/registerswindow.cpp \
    src/frontend/qt/settings.cpp \
    src/hle.c \
    src/hw/2102.c \
    src/hw/3850.c \
    src/hw/3851.c \
    src/hw/fairbug_parallel.c \
    src/hw/hand_controller.c \
    src/hw/selector_control.c \
    src/hw/system.c \
    src/hw/vram.c \
    src/input.c \
    src/romc.c \
    src/screen.c \
    src/software.c \
    src/sound.c \
    src/wave.c

HEADERS += \
    src/config.h \
    src/debug.h \
    src/emu.h \
    src/font.h \
    src/frontend/qt/framebuffer_widget.h \
    src/frontend/qt/main.h \
    src/frontend/qt/mainwindow.h \
    src/frontend/qt/registerswindow.h \
    src/frontend/qt/settings.h \
    src/hle.h \
    src/hw/2102.h \
    src/hw/3850.h \
    src/hw/3851.h \
    src/hw/f8_device.h \
    src/hw/fairbug_parallel.h \
    src/hw/hand_controller.h \
    src/hw/kdbug.h \
    src/hw/selector_control.h \
    src/hw/system.h \
    src/hw/vram.h \
    src/input.h \
    src/romc.h \
    src/screen.h \
    src/software.h \
    src/sound.h \
    src/types.h \
    src/wave.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/frontend/qt/resources.qrc
