#
# Author: Takashi Matsushita
#

SUBDIRS = tmUtil tmXsd tmTable tmGrammar tmEventSetup

AR = c++ -shared -fPIC

export XDAQ_ROOT =
export XERCES_ROOT = ${XERCES_C_BASE}
export BOOST_ROOT = ${BOOST_BASE}

#
# install prefix
#
PREFIX ?= $(shell pwd)

#
# absolute path of install prefix to pass on to sub projects
#
PREFIX_DIR := $(shell python -c "import sys,os; print(os.path.abspath(next(iter(sys.argv[1:]), os.getcwd())))" $(PREFIX))

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
.PHONY: all genxsd test clean install python dist-clean setting doxygen


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

genxsd:
	echo '// '
	echo '// $(MAKE) $@'
	echo '// '
	cd tmXsd/gen-xsd-type; echo '//   in '`pwd`; \
	$(MAKE) -f Makefile.xsdcxx; if [ $$? != 0 ]; then exit 1; fi; cd ..;
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

install: all
	mkdir -p $(PREFIX_DIR)/lib
	echo '// '
	echo '// $(MAKE) $@ PREFIX=$(PREFIX_DIR)'
	echo '// '
	for project in $(SUBDIRS); do \
		mkdir -p $(PREFIX_DIR)/include/$$project; \
		cd $$project; echo '//   in '`pwd`; \
		$(MAKE) $@ PREFIX=$(PREFIX_DIR); if [ $$? != 0 ]; then exit 1; fi; cd ..; \
	done
	$(RM) -r $(PREFIX_DIR)/xsd-type
	cp -pr tmXsd/xsd-type $(PREFIX_DIR)/xsd-type
	cp -p tmXsd/menu.xsd $(PREFIX_DIR)/.
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
