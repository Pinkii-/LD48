TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio

SOURCES += main.cpp \
    Game.cpp \
    LD48.cpp \
    Resources.cpp \
    utils.cpp \
    Ui.cpp \
    Board.cpp \
    Player.cpp \
    Object.cpp \
    Collectible.cpp


HEADERS += \
    Game.hpp \
    LD48.hpp \
    Resources.hpp \
    utils.hpp \
    Ui.hpp \
    Board.hpp \
    Player.hpp \
    Object.hpp \
    Collectible.hpp

OTHER_FILES += \
    shaders/tunnel.frag \
    shaders/water.frag

