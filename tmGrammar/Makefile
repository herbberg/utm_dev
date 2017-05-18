#
# Author: Takashi Matsushita
#

# XDAQ stuff
-include $(XDAQ_ROOT)/config/mfAutoconf.rules
-include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)
# XDAQ stuff


VERSION = 0.6.2
LIBRARY = libtmgrammar.so
PROGRAMS =

#
# files
#
SRCS = Algorithm.cc Object.cc Function.cc Cut.cc
HDRS = Algorithm.hh Object.hh Function.hh Cut.hh CutGrammar.hh ObjectGrammar.hh FunctionGrammar.hh
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
CPPFLAGS = -DNDEBUG #-DBOOST_SPIRIT_DEBUG
INCDIR = -I. -I.. -I$(CACTUS_ROOT)/include -I$(BOOST_ROOT)/include
LIBDIR = -L. -L$(CACUTS_ROOT)/lib -L$(BOOST_ROOT)/lib -L../tmUtil
LIBS = -ltmutil

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

python: $(HDRS) $(SRCS) tmGrammar.i
	echo '//     creating python interface'
	swig -c++ -python tmGrammar.i
	python setup.py build_ext --inplace
#
# common target
#
all: $(LIBRARY) test
	echo '//     done ('`date`')'

install: $(LIBRARY)
	cp -p $(LIBRARY) ../lib
	cp -p $(HDRS) ../include/tmGrammar

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmGrammar.so

dist-clean:
	cd test; echo '//   in '`pwd`; \
	$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..;
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _tmGrammar.so tmGrammar.py tmGrammar_wrap.cxx
	$(RM) -r build html latex

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
Package = utm/tmGrammar
PackageName = tmGrammar
Summary = tmGrammar
Link = https://twiki.cern.ch/twiki/bin/viewauth/CMS/GlobalTrigger

IncludeDirs = $(BUILD_HOME)/$(Project)/utm \
              $(BUILD_HOME)/$(Project)/$(Package)
Sources = $(SRCS)
UserCCFlags = $(CXXFLAGS) $(CPPFLAGS) $(INCDIR)
DependentLibraryDirs = \
		$(BUILD_HOME)/$(Project)/utm/tmUtil/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM)

DependentLibraries = tmutil
DynamicLibrary = tmgrammar

-include $(XDAQ_ROOT)/config/Makefile.rules
-include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
