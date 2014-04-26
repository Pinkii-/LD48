TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Game.cpp \
    LD48.cpp \
    Resources.cpp \
    utils.cpp \
    Board.cpp

HEADERS += \
    Game.hpp \
    LD48.hpp \
    Resources.hpp \
    utils.hpp \
    Board.hpp

