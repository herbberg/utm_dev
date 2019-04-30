#
# Author: Takashi Matsushita
#

VERSION = 0.1
LIBRARY =
PROGRAMS = parser test_algorithm test_object test_function test_cut parser_file
UNITTEST = unittest

#
# files
#
SRCS =
HDRS =
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
CXXFLAGS = -std=c++11 -fPIC -O2 # -g -pg -Wall -pedantic
CPPFLAGS = -DNDEBUG #-DBOOST_SPIRIT_DEBUG
INCDIR = -I. -I.. -I$(CACTUS_ROOT)/include -I$(BOOST_ROOT)/include -I../..
LIBDIR = -L. -L.. -L$(CACTUS_ROOT)/lib -L$(BOOST_ROOT)/lib -L../../tmUtil
LIBS = -ltmutil -ltmgrammar

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
$(UNITTEST): unittest.cc
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< -lboost_unit_test_framework $(LIBRARY) $(LIBDIR) $(LIBS)

parser: parser.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

parser_file: parser_file.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

test: $(UNITTEST) $(PROGRAMS) $(LIBRARY)
	./$(UNITTEST) # run unittest

test_algorithm: test_algorithm.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

test_object: test_object.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

test_function: test_function.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

test_cut: test_cut.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

python: $(HDRS) $(SRCS) AlgoParser.i
	echo '//     creating python interface'
	swig -c++ -python AlgoParser.i
	python setup.py build_ext --inplace
#
# common target
#
all: $(LIBRARY) test
	echo '//     done ('`date`')'

clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _AlgoParser.so

dist-clean:
	$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	$(RM) _AlgoParser.so AlgoParser.py AlgoParser_wrap.cxx
	$(RM) -r build

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

# eof
