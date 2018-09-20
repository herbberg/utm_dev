#
# Author: Takashi Matsushita
#

# XDAQ stuff
-include $(XDAQ_ROOT)/config/mfAutoconf.rules
-include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)
# XDAQ stuff


VERSION = 0.7.1
LIBRARY = libtmeventsetup.so
PROGRAMS =

# install prefix
PREFIX ?= ..

#
# files
#
SRCS = tmEventSetup.cc \
			 esTriggerMenuHandle.cc esAlgorithmHandle.cc \
			 esConditionHandle.cc esObjectHandle.cc esCutHandle.cc \
			 esScaleHandle.cc esBinHandle.cc
HDRS = tmEventSetup.hh \
			 esTriggerMenuHandle.hh esAlgorithmHandle.hh \
			 esTriggerMenu.hh esAlgorithm.hh \
			 esConditionHandle.hh esObjectHandle.hh esCutHandle.hh \
			 esCondition.hh esObject.hh esCut.hh \
			 esScaleHandle.hh esBinHandle.hh \
			 esScale.hh esBin.hh esCutValue.hh esTypes.hh

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
INCDIR = -I. -I.. -I$(BOOST_ROOT)/include
LIBDIR = -L../tmUtil -L../tmTable -L../tmGrammar -L$(BOOST_ROOT)/lib
LIBS = -ltmutil -ltmtable -ltmgrammar

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
	mkdir -p $(PREFIX)/include/tmEventSetup
	cp -p $(HDRS) $(PREFIX)/include/tmEventSetup

python: $(HDRS) $(SRCS) tmEventSetup.i
	echo '//     creating python interface'
	swig -c++ -python -I.. tmEventSetup.i
	python setup.py build_ext --inplace

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmEventSetup.so

dist-clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmEventSetup.so tmEventSetup.py tmEventSetup_wrap.cxx
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
Package = utm/tmEventSetup
PackageName = tmEventSetup
Summary = tmEventSetup
Link = https://twiki.cern.ch/twiki/bin/viewauth/CMS/GlobalTrigger

IncludeDirs = $(BUILD_HOME)/$(Project)/utm \
              $(BUILD_HOME)/$(Project)/$(Package)
Sources = $(SRCS)
UserCCFlags = $(CXXFLAGS) $(CPPFLAGS)
DependentLibraryDirs = \
		$(BUILD_HOME)/$(Project)/utm/tmUtil/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM) \
		$(BUILD_HOME)/$(Project)/utm/tmTable/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM) \
		$(BUILD_HOME)/$(Project)/utm/tmGrammar/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM)

DependentLibraries = tmutil tmtable tmgrammar
DynamicLibrary = tmeventsetup

-include $(XDAQ_ROOT)/config/Makefile.rules
-include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
