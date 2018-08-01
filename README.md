Contents
=========

Core components of the utm libraries are:

* tmUtil:          common utility library
* tmXsd:           XSD binding for the CMS L1 Menu XML
* tmTable:         C++ classes for the CMS L1 Menu data
* tmGrammar:       parser for the CMS L1 Menu Grammar
* tmEventSetup:    CondFormat compatible data classes for the CMS L1 Menu

Check the README.md in the subdirectories for further information.


Build
=====

## Prerequisits

* CodeSynthesis XSD (http://www.codesynthesis.com/products/xsd/)
* SWIG if python binding is needed (http://www.swig.org/)
* xerces library if not available (http://xerces.apache.org/xerces-c/)

Check the corresponding Web pages for the installation of the packages
as well as the following twiki page;
https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUpgradeL1T-uTme#uGT_Trigger_Menu_library_utm

CC7:

    $ sudo yum install python-devel boost-system boost-filesystem boost-devel \
      xsd swig xerces-c

Debian/Ubuntu:

    $ sudo apt-get install python-devel libboost-dev libboost-system-dev \
      libboost-filesystem-dev xsdcxx swig libxerces-c-dev


## Compilation

Building C++ libraries

    $ make all

Building python bindings (if required)

    $ make all python


Build for XDAQ
==============

To use the library in the XDAQ environment (note the underline in front of \_all):

    $ git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git cactusprojects/utm
    $ cd cactusprojects/utm
    $ git checkout <tag/branch>

## Compile

    $ make -f Makefile.xdaq _all

## Build RPMs

    $ make -f Makefile.xdaq rpm

## Install RPMs

    $ sudo yum install $(find tm* -name '*.x86_64.rpm')


Build for CMSSW
===============

Example of a manual installation as an external library of CMSSW and test of the installation.

## Compilation

```{r, engine='bash', count_lines}
cmsrel CMSSW_9_0_0
cd CMSSW_9_0_0/src
cmsenv
cd ..
git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
cd utm
git checkout <tag/branch>
scram tool info xerces-c
export XERCES_C_BASE=<XERCES_C_BASE directory printed by the above command>
scram tool info boost
export BOOST_BASE=<BOOST_BASE directory printed by the above command>
make all
make install
```

## Testing

```{r, engine='bash', count_lines}
cd ../src
tar xvfz /afs/cern.ch/user/t/tmatsush/public/Demo.tgz
# Note: edit Demo/tmEventSetup/test/utm.xml
# change UTM_BASE according to your setup
cp Demo/tmEventSetup/test/utm.xml ../config/toolbox/${SCRAM_ARCH}/tools/selected/
scram setup utm
# compile and run the sample code for using utm: Demo/tmEventSetup/test/test.cc
scram b -j4
../test/${SCRAM_ARCH}/test -f /afs/cern.ch/user/t/tmatsush/public/tmGui/test-menu.xml
```

API documentation
=================

To generate API documentation for tmEventSetup, run

    doxygen doxygen.config
