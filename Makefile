#############################################################################
# Makefile for building: LD48
# Generated by qmake (2.01a) (Qt 4.8.4) on: Mon Apr 28 17:00:15 2014
# Project:  LD48.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile LD48.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -O2 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)   -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		Game.cpp \
		LD48.cpp \
		Resources.cpp \
		utils.cpp \
		Ui.cpp \
		Board.cpp \
		Player.cpp \
		Object.cpp \
		Collectible.cpp 
OBJECTS       = main.o \
		Game.o \
		LD48.o \
		Resources.o \
		utils.o \
		Ui.o \
		Board.o \
		Player.o \
		Object.o \
		Collectible.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		LD48.pro
QMAKE_TARGET  = LD48
DESTDIR       = 
TARGET        = LD48

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: LD48.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile LD48.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile LD48.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/LD481.0.0 || $(MKDIR) .tmp/LD481.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/LD481.0.0/ && (cd `dirname .tmp/LD481.0.0` && $(TAR) LD481.0.0.tar LD481.0.0 && $(COMPRESS) LD481.0.0.tar) && $(MOVE) `dirname .tmp/LD481.0.0`/LD481.0.0.tar.gz . && $(DEL_FILE) -r .tmp/LD481.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp Resources.hpp \
		utils.hpp \
		LD48.hpp \
		Game.hpp \
		Player.hpp \
		Object.hpp \
		Board.hpp \
		Ui.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Game.o: Game.cpp Game.hpp \
		utils.hpp \
		Resources.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Game.o Game.cpp

LD48.o: LD48.cpp LD48.hpp \
		Game.hpp \
		utils.hpp \
		Player.hpp \
		Object.hpp \
		Board.hpp \
		Resources.hpp \
		Ui.hpp \
		Collectible.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o LD48.o LD48.cpp

Resources.o: Resources.cpp Resources.hpp \
		utils.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Resources.o Resources.cpp

utils.o: utils.cpp utils.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utils.o utils.cpp

Ui.o: Ui.cpp Ui.hpp \
		utils.hpp \
		LD48.hpp \
		Game.hpp \
		Player.hpp \
		Object.hpp \
		Board.hpp \
		Resources.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Ui.o Ui.cpp

Board.o: Board.cpp Board.hpp \
		Resources.hpp \
		utils.hpp \
		LD48.hpp \
		Game.hpp \
		Player.hpp \
		Object.hpp \
		Ui.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Board.o Board.cpp

Player.o: Player.cpp Player.hpp \
		utils.hpp \
		Object.hpp \
		LD48.hpp \
		Game.hpp \
		Board.hpp \
		Resources.hpp \
		Ui.hpp \
		Collectible.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Player.o Player.cpp

Object.o: Object.cpp Object.hpp \
		utils.hpp \
		LD48.hpp \
		Game.hpp \
		Player.hpp \
		Board.hpp \
		Resources.hpp \
		Ui.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Object.o Object.cpp

Collectible.o: Collectible.cpp Collectible.hpp \
		Object.hpp \
		utils.hpp \
		Resources.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Collectible.o Collectible.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

