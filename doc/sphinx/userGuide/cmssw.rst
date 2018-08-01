..

CMSSW integration
=================

The UTM library can be used as external CMSSW library. See also
https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUpgradeL1T-uTme#uGT_Trigger_Menu_library_utm

In lack of support of the CodeSynthesis XSD-C++ compiler on CMSSW/LXPLUS machines
the auto generated XML bindings can be pre-generated. This requires to pack the
XSD headers with the UTM library.

Bundle XSD
----------

**Note:** these steps are required only when upgrading to a newer XSD-C++ version or in
case the XML format is changed.

**Prerequisites:**

* Machine with SLC6/CC7 (depends on CMSSW target)

  * Xerces C library (+3.1)
  * CodeSynthesis XSD-C++ compiler (+4.0.0)

**Instructions:**

* checkout codebase:

  .. code-block:: bash

    git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
    cd utm
    git checkout <tag/branch>

* embed the XSD headers:

  .. code-block:: bash

    cp -pr /usr/include/xsd xsd
    export XSDCXX=xsd

* generate XML bindings:

  .. code-block:: bash

    cd tmXsd/gen-xsd-type/
    make -f Makefile.xsdcxx all

Build external library
----------------------

* get CMSSW environment:

  .. code-block:: bash

    cmsrel CMSSW_9_0_0
    cd CMSSW_9_0_0
    cmsenv

* fetch tag/branch from gitlab

  .. code-block:: bash

    git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
    cd utm
    git checkout utm_0_7_x_dev

* build the extgernal library (preliminary):

  .. code-block:: bash

    scram tool info xerces-c
    export XERCES_C_BASE=<XERCES_C_BASE directory printed by the above command>
    scram tool info boost
    export BOOST_BASE=<BOOST_BASE directory printed by the above command>
    make all
    make install

* testing the external library:

  .. code-block:: bash

    cd ../src
    tar xvfz /afs/cern.ch/user/t/tmatsush/public/Demo.tgz
    # Note: edit Demo/tmEventSetup/test/utm.xml
    # change UTM_BASE according to your setup
    cp Demo/tmEventSetup/test/utm.xml ../config/toolbox/${SCRAM_ARCH}/tools/selected/
    scram setup utm
    # compile and run the sample code for using utm: Demo/tmEventSetup/test/test.cc
    scram b -j4
    ../test/${SCRAM_ARCH}/test -f /afs/cern.ch/user/t/tmatsush/public/tmGui/test-menu.xml
