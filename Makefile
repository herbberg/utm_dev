#
# Author: Takashi Matsushita
#

SUBDIRS = tmUtil tmXsd tmTable tmGrammar tmEventSetup

AR = c++ -shared -fPIC

export XDAQ_ROOT=
export XERCES_ROOT=${XERCES_C_BASE}
export BOOST_ROOT=${BOOST_BASE}


#
# files
#
CSRCS =
CHDRS =
COBJS = $(CSRCS:.c=.o)
GARBAGE = core* *.o *.ln *.bak *~ $(DEPFILE)

#
# special built-in target
#
default: all
.SILENT:
.SUFFIXES: .o
.PHONY: all clean python dist-clean message doxygen


#
# local target
#
doxygen:
	doxygen doxygen.config


#
# common target
#
all:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		cd $$project; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	echo '// '
	echo '// done ('`date`')'
	echo '// '

test:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		cd $$project/test; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ../..; \
	done
	echo '// '
	echo '// done ('`date`')'
	echo '// '


clean:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		cd $$project;  echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	$(RM) $(GARBAGE)
	echo '// '
	echo '// done ('`date`')'
	echo '// '

install:
	mkdir -p lib
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		mkdir -p include/$$project; \
		cd $$project; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	cp -pr tmXsd/xsd-type xsd-type
	cp -p tmXsd/menu.xsd .
	echo '// '
	echo '// done ('`date`')'
	echo '// '

python:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		cd $$project; echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	echo '// '
	echo '// done ('`date`')'
	echo '// '

dist-clean:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	for project in $(SUBDIRS); do \
		cd $$project;  echo '//   in '`pwd`; \
		$(MAKE) $@; if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	$(RM) $(GARBAGE) $(LIBRARY)
	$(RM) -r latex html
	echo '// '
	echo '// done ('`date`')'
	echo '// '

setting:
	echo '// '
	echo '// Target: $(SUBDIRS) ('`date`')'
	echo '// '

# eof