#
# Author: Takashi Matsushita
#
# TODO: remove warnings when running in XDAQ environment if possible

# XDAQ stuff
-include $(XDAQ_ROOT)/config/mfAutoconf.rules
-include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)
# XDAQ stuff


VERSION = 0.6.5
LIBRARY = libtmxsd.so
PROGRAMS =

#
# files
#
SRCS = keywords.cc table2tree.cc tree2table.cc writer.cc converter.cc reader.cc
HDRS = keywords.hh table2tree.hh tree2table.hh writer.hh converter.hh reader.hh
SRCS_TREE = simple-types.cc \
						complex-bin.cc bin.cc \
						complex-scale.cc scale.cc \
						complex-scale_set.cc scale_set.cc \
						complex-ext_signal.cc ext_signal.cc \
						complex-ext_signal_set.cc ext_signal_set.cc \
						complex-object_requirement.cc object_requirement.cc \
						complex-external_requirement.cc external_requirement.cc \
						complex-cut.cc cut.cc \
						complex-algorithm.cc algorithm.cc \
						complex-menu.cc menu.cc

SRCS_PARSER = simple-types-pskel.cc simple-types-parser.cc \
			 				complex-bin-pskel.cc complex-bin-parser.cc \
			 				complex-scale-pskel.cc complex-scale-parser.cc \
			 				complex-scale_set-pskel.cc complex-scale_set-parser.cc \
			 				complex-ext_signal-pskel.cc complex-ext_signal-parser.cc \
			 				complex-ext_signal_set-pskel.cc complex-ext_signal_set-parser.cc \
							complex-object_requirement-pskel.cc complex-object_requirement-parser.cc \
							complex-external_requirement-pskel.cc complex-external_requirement-parser.cc \
			 				complex-cut-pskel.cc complex-cut-parser.cc \
			 				complex-algorithm-pskel.cc complex-algorithm-parser.cc \
			 				complex-menu-pskel.cc complex-menu-parser.cc

OBJS = $(SRCS:.cc=.o)

DISTFILES = $(SRCS) $(HDRS) Makefile
GARBAGE = core* *.o *~ *.d *.log *.pyc a.out gmon.out

SUBDIRS = gen-xsd-type


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
INCDIR = -I. -I.. -I./gen-xsd-type -I$(XERCES_ROOT)/include -I$(BOOST_BASE)/include
LIBDIR = -L. -L../tmUtil -L$(XERCES_ROOT)/lib -L$(BOOST_BASE)/lib
LIBS = -ltmutil -lxerces-c

#
# special built-in target
#
default: all
.SILENT:
.SUFFIXES: .o
.PHONY: default all clean dist-clean setting python xsdbind _all build

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
	$(AR) -o $(LIBRARY) $(OBJS) gen-xsd-type/*.o $(LIBDIR) $(LIBS)

scale_set-parser: scale_set-parser.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

ext_signal_set-parser: ext_signal_set-parser.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

roundtrip: roundtrip.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

#
# common target
#
all:
	for i in $(SUBDIRS); do \
		cd $$i; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1 ; fi; cd ..; \
	done
	make $(LIBRARY)

install: $(LIBRARY)
	cp -p $(LIBRARY) ../lib
	cp -p $(HDRS) ../include/tmXsd

clean: _cleanall dist-clean

dist-clean:
	for i in $(SUBDIRS); do \
		cd $$i; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	cd test; echo '//   in '`pwd`; \
	$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..;
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) $(SRCS_TREE) $(SRCS_TREE:.cc=.hxx) gen-*.hxx complex-*.cc simple-types-*.cc
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
	echo '//     sub directories:     $(SUBDIRS)'
	echo '// '
	echo '//     sources:             $(SRCS)'
	echo '// '

python:

#
# dependencies
#
-include $(SRCS:.cc=.d)

#
# XDAQ stuff
#
BUILD_HOME := $(shell pwd)/../../../
Project = cactusprojects
Package = utm/tmXsd
PackageName = tmXsd
Summary = tmXsd
Link = https://twiki.cern.ch/twiki/bin/viewauth/CMS/GlobalTrigger

IncludeDirs = $(BUILD_HOME)/$(Project)/utm \
              $(BUILD_HOME)/$(Project)/$(Package) \
              $(BUILD_HOME)/$(Project)/$(Package)/gen-xsd-type
Sources = $(SRCS) $(SRCS_TREE) $(SRCS_PARSER)
UserCCFlags = $(CXXFLAGS) $(CPPFLAGS)
DependentLibraryDirs = $(BUILD_HOME)/$(Project)/utm/tmUtil/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM)
DependentLibraries = tmutil xerces-c
DynamicLibrary = tmxsd

-include $(XDAQ_ROOT)/config/Makefile.rules
-include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
