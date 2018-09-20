#
# Author: Takashi Matsushita
#

# XDAQ stuff
-include $(XDAQ_ROOT)/config/mfAutoconf.rules
-include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)
# XDAQ stuff


VERSION = 0.7.2
LIBRARY = libtmtable.so
PROGRAMS =

# install prefix
PREFIX ?= ..

#
# files
#
SRCS = tmTable.cc validator.cc
HDRS = tmTable.hh validator.hh
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
INCDIR = -I. -I.. -I$(XERCES_ROOT)/include -I$(BOOST_ROOT)/include
LIBDIR = -L../tmUtil -L../tmXsd -L$(XERCES_ROOT)/lib -L/usr/lib/x86_64-linux-gnu/ -L$(BOOST_ROOT)/lib
LIBS = -ltmutil -ltmxsd -lxerces-c -lboost_system -lboost_filesystem

#
# special built-in target
#
.SILENT:
.SUFFIXES: .o
.PHONY: all clean dist-clean setting python

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
	$(AR) -o $(LIBRARY) $(OBJS) $(LIBDIR) $(LIBS)

#
# common target
#
all: $(LIBRARY)
	echo '//     done ('`date`')'

install: $(LIBRARY)
	mkdir -p $(PREFIX)/lib
	cp -p $(LIBRARY) $(PREFIX)/lib
	mkdir -p $(PREFIX)/include/tmTable
	cp -p $(HDRS) $(PREFIX)/include/tmTable

python: $(HDRS) $(SRCS) tmTable.i
	echo '//     creating python interface'
	swig -c++ -python tmTable.i
	python setup.py build_ext --inplace

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmTable.so

dist-clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmTable.so tmTable.py tmTable_wrap.cxx
	$(RM) -r build html latex
	cd test; echo '//   in '`pwd`; \
	$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..;

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

#
# dependencies
#
-include $(SRCS:.cc=.d)

#
# XDAQ stuff
#
BUILD_HOME := $(shell pwd)/../../../
Project = cactusprojects
Package = utm/tmTable
PackageName = tmTable
Summary = tmTable
Link = https://twiki.cern.ch/twiki/bin/viewauth/CMS/GlobalTrigger

IncludeDirs = $(BUILD_HOME)/$(Project)/utm \
              $(BUILD_HOME)/$(Project)/$(Package)
Sources = $(SRCS)
UserCCFlags = $(CXXFLAGS) $(CPPFLAGS)
DependentLibraryDirs = \
		$(BUILD_HOME)/$(Project)/utm/tmUtil/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM) \
		$(BUILD_HOME)/$(Project)/utm/tmXsd/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM)

DependentLibraries = tmutil tmxsd xerces-c
DynamicLibrary = tmtable

-include $(XDAQ_ROOT)/config/Makefile.rules
-include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
