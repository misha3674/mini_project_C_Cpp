TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c11

QT   += opengl
LIBS += -lopengl32

SOURCES += main.c \
    snow_falling_effect.c

win32: LIBS += -L$$PWD/glfw/lib/ -lglfw3 -lgdi32
win32: LIBS += -L$$PWD/ -lglui32

HEADERS += \
    snow_falling_effect.h
