#
# Author: Takashi Matsushita
#

VERSION = 0.1
LIBRARY =
PROGRAMS = roundtrip scale_set-parser ext_signal_set-parser

#
# files
#
SRCS =
HDRS =
OBJS = $(SRCS:.cc=.o)
DISTFILES = $(SRCS) $(HDRS) Makefile
GARBAGE = core* *.o *~ *.d *.log *.pyc a.out gmon.out
          
SUBDIRS =

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
INCDIR = -I. -I.. -I../..
LIBDIR = -L. -L.. -L../../tmUtil -L../../tmTable
LIBS = -ltmutil -ltmxsd -lxerces-c -ltmtable

#
# special built-in target
#
default: all
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
test: $(PROGRAMS)
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
	make test

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)

dist-clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)

setting:
	echo '// '
	echo '// Target $(PROGRAMS) ('`date`')'
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

# eof
