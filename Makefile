BUILD_HOME:=$(shell pwd)/../../../../

-include $(BUILD_HOME)/config/Makefile.macros

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

Project = cactusprojects/utm
Packages =

SUBDIRS = tmUtil tmXsd tmTable tmGrammar tmEventSetup ts/cell

default: all
.SILENT:
.PHONY: all rpm

all:
	echo '// '
	echo '// $(MAKE) ${MAKECMDGOALS}'
	echo '// '
	if [ "${MAKECMDGOALS}" == "all" -o "${MAKECMDGOALS}" == "_all" ];then cd tmXsd/gen-xsd-type; make xsdbind; cd ../..; fi
	echo 'CWD $(CURDIR)';
	for i in $(SUBDIRS); do \
  	cd $$i; echo '//   in '`pwd`; \
    $(MAKE) ${MAKECMDGOALS}; if [ $$? != 0 ]; then exit 1; fi; cd $(CURDIR); \
  done
	echo '// '
	echo '// done ('`date`')'
	echo '// '

_all: all
_cleanall: all
_rpmall: all
clean: all
rpm: all
dist-clean: all

include $(XDAQ_ROOT)/config/Makefile.rules
include $(XDAQ_ROOT)/config/mfRPM.rules

# eof
