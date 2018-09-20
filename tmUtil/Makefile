#
# Authors: Bernhard Arnold
#          Takashi Matsushita
#

# XDAQ stuff
-include $(XDAQ_ROOT)/config/mfAutoconf.rules
-include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)
# XDAQ stuff

VERSION = 0.7.1
LIBRARY = libtmutil.so
PROGRAMS =

# install prefix
PREFIX ?= ..

#
# files
#
SRCS = tmUtil.cc
HDRS = tmUtil.hh
OBJS = $(SRCS:.cc=.o)
DISTFILES = $(SRCS) $(HDRS) Makefile
GARBAGE = core* *.o *~ *.d *.log *.pyc a.out gmon.out


#
# commands
#
SHELL = /bin/bash

CXX = c++
CPP = c++ -E
AR = c++ -shared -fPIC
MKDEPEND = c++ -MMD -MP
RM = rm -f
TOUCH = touch

#
# command flags
#
CXXFLAGS = -ansi -fPIC -O2 # -g -pg -Wall -pedantic
CPPFLAGS = -DNDEBUG
INCDIR = -I.. -I $(BOOST_ROOT)/include
LIBDIR = -L.
LIBS =

#
# special built-in target
#
.SILENT:
.SUFFIXES: .o
.PHONY: default all clean dist-clean setting python

#
# suffix rules
#
%.o : %.cc
	echo '//     compile $< ...'
	$(CXX) -c $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP $<

#
# local target
#
$(LIBRARY): $(OBJS)
	echo '//     creating $(LIBRARY)'
	$(AR) -o $(LIBRARY) $(OBJS)

#
# common target
#
all: $(LIBRARY)
	echo '//     done ('`date`')'

install: $(LIBRARY)
	mkdir -p $(PREFIX)/lib
	cp -p $(LIBRARY) $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/tmUtil
	cp -p $(HDRS) $(PREFIX)/include/tmUtil

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM)

dist-clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) -r html latex

setting:
	echo '// '
	echo '// Target $(LIBRARY) ('`date`')'
	echo '// '
	echo '//     compiler:            $(CXX)'
	echo '//     compiler flags:      $(CXXFLAGS)'
	echo '//     cpp flags:           $(CPPFLAGS)'
	echo '//     include directories: $(INCDIR)'
	echo '//     library directories: $(LIBDIR)'
	echo '//     libraries:           $(LIBS)'
	echo '// '
	echo '//     sources:             $(SRCS)'
	echo '// '

#
# dependencies
#
-include $(SRCS:.cc=.d)

#
# XDAQ stuff
#
BUILD_HOME := $(shell pwd)/../../../
Project = cactusprojects
Package = utm/tmUtil
PackageName = tmUtil
Summary = tmUtil
Link = https://twiki.cern.ch/twiki/bin/viewauth/CMS/GlobalTrigger

IncludeDirs = ..
Sources = $(SRCS)
UserCCFlags = $(CXXFLAGS) $(CPPFLAGS)
DependentLibraryDirs =
DependentLibraries =
DynamicLibrary = tmutil

-include $(XDAQ_ROOT)/config/Makefile.rules
-include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
