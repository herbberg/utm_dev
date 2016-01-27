#
# Authors: Takashi Matsushita
#          Bernhard Arnold <bernhard.arnold@cern.ch>
#

LIBRARY =
PROGRAMS =

#
# files
#
SRCS_TREE = \
	simple-types.cc \
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

SRCS_PARSER = \
	simple-types-pskel.cc simple-types-parser.cc \
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

SRCS = $(SRCS_TREE) $(SRCS_PARSER)
HDRS = $(SRCS_TREE:.cc=.hxx) $(SRCS_PARSER:.cc=.hh)
OBJS = $(SRCS:.cc=.o)

DISTFILES = $(SRCS) $(HDRS) Makefile
GARBAGE = core* *.o *~ *.d *.log *.pyc a.out gmon.out *-pskel.* *-pimpl.* *-driver.*

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


XSD_TREE = $(XSDCXX) cxx-tree \
	--namespace-map http://www.cern.ch/tmxsd/1.0.0=tmxsdtree \
	--cxx-suffix .cc --hxx-suffix .hxx \
	--generate-serialization --generate-doxygen

XSD_PARSER = $(XSDCXX) cxx-parser \
	--namespace-map http://www.cern.ch/tmxsd/1.0.0=tmxsd \
	--cxx-suffix .cc --hxx-suffix .hh \
	--generate-validation --generate-print-impl --force-overwrite \
	--type-map utm.map

#
# command flags
#
CXXFLAGS = -ansi -fPIC -O2 # -g -pg -Wall -pedantic
CPPFLAGS = -DNDEBUG
INCDIR = -I. -I.. -I../.. -I./gen-xsd-type -I$(XERCES_ROOT)/include
LIBDIR = -L. -L../tmUtil -L$(XERCES_ROOT)/lib #-L/usr/lib64
LIBS = -ltmutil -lxerces-c

#
# special built-in target
#
.SILENT:
.SUFFIXES: .o
.PHONY: all clean dist-clean setting objs

#
# suffix rules
#
%.o : %.cc
	echo '//     compile $< ...'
	$(CXX) -c $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP $<

#
# local target
#
srcs: $(SRCS)
objs: $(OBJS)


## test code
scale_set-parser: scale_set-parser.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

ext_signal_set-parser: ext_signal_set-parser.o $(LIBRARY)
	echo '//     creating $@'
	$(CXX) -o $@ $(INCDIR) $(CXXFLAGS) $(CPPFLAGS) $< $(LIBRARY) $(LIBDIR) $(LIBS)

#
# common target
#
all: objs
	echo '//     done ('`date`')'

clean:
	@$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)

dist-clean:
	@$(RM) $(GARBAGE) $(LIBRARY) $(PROGRAMS)
	@$(RM) $(SRCS_TREE) $(SRCS_TREE:.cc=.hxx) gen-*.hxx

xsdbind: $(SRCS_TREE) $(SRCS_PARSER)
	cp -p $(SRCS_TREE) $(SRCS_PARSER) ..

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

# eof
