Contents
========

* [Overview](#overview)
* [Build](#build)
* [Build for XDAQ](#build-for-xdaq)
* [Build for CMSSW](#build-for-cmssw)

Overview
========

Core components of the utm libraries are:

* tmUtil:          common utility library
* tmXsd:           XSD binding for the CMS L1 Menu XML
* tmTable:         C++ classes for the CMS L1 Menu data
* tmGrammar:       parser for the CMS L1 Menu Grammar
* tmEventSetup:    CondFormat compatible data classes for the CMS L1 Menu

Check the README.md in the subdirectories for further information.

Build
=====

## Prerequisites

* CodeSynthesis XSD (http://www.codesynthesis.com/products/xsd/)
* BOOST (https://www.boost.org/)
* SWIG if python binding is needed (http://www.swig.org/)
* Xerces library (http://xerces.apache.org/xerces-c/)

Check the corresponding Web pages for the installation of the packages
as well as the following twiki page;
https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUpgradeL1T-uTme#uGT_Trigger_Menu_library_utm

### Dependencies

Redhat/CC7:

    $ sudo yum install make gcc-c++ python-devel boost-system boost-filesystem boost-devel \
      xsd swig xerces-c-devel

Debian/Ubuntu:

    $ sudo apt-get install build-essential python-dev libboost-dev libboost-system-dev \
      libboost-filesystem-dev xsdcxx swig libxerces-c-dev

### Generate XML bindings

Pre-generated XML bindings and XSDC++ headers (`xsd/cxx/`) are bundled with the projects source code.

The bindings can be manually generated use the following commands (eg. for c++11 compatibility or when using XSDC++ >= 4.0.0)

    $ make dist-clean
    $ make genxsd

## Compilation

Building C++ libraries

    $ make all

Building python bindings (if required)

    $ make all python

## Install

Install libraries, headers and XSD files, use `PREFIX` to assign a custom location.

    $ make install PREFIX=/home/user/local

Build for XDAQ
==============

To use the library in the XDAQ environment (note the underline in front of \_all):

    $ git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git cactusprojects/utm
    $ cd cactusprojects/utm
    $ git checkout <tag/branch>

## Compile

    $ make -f Makefile.xdaq _all  # note the underscore

## Build RPMs

    $ make -f Makefile.xdaq rpm

## Install RPMs

    $ sudo yum install $(find tm* -name '*.x86_64.rpm')


Build for CMSSW
===============

Example of a manual installation as an external library of CMSSW and test of the installation.

## Compilation

```{r, engine='bash', count_lines}
cmsrel CMSSW_10_3_0_pre4
cd CMSSW_10_3_0_pre4/src
cmsenv
export $(scram tool info xerces-c | grep XERCES_C_BASE=)
echo "XERCES_C_BASE=$XERCES_C_BASE"
export $(scram tool info boost | grep BOOST_BASE=)
echo "BOOST_BASE=$BOOST_BASE"
cd ..
git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
cd utm
git checkout <tag/branch>
make all
make install PREFIX=<install/path>
```

## Testing

```{r, engine='bash', count_lines}
# Note: edit tmEventSetup/test/cmssw/utm.xml
# change UTM_BASE according to your local setup
cp tmEventSetup/test/cmssw/utm.xml ../config/toolbox/${SCRAM_ARCH}/tools/selected/
scram setup utm
# compile and run the sample code for using utm: tmEventSetup/test/cmssw/test.cc
scram b -j4
../test/${SCRAM_ARCH}/test -f L1Menu_sample.xml  # does not work anymore?
```

API documentation
=================

To generate API documentation for tmEventSetup, run

    doxygen doxygen.config
