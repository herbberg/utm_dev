..

Installation
============

Build locally with python bindings
----------------------------------

  .. code-block:: bash

    git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
    cd utm
    git checkout utm_0.7.0
    make all python
    . setup.sh

Build for CMSSW
---------------

See :doc:`cmssw`

Build for XDAQ 14
-----------------

  .. code-block:: bash

    git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git cactusprojects/utm
    cd cactusprojects/utm
    git checkout utm_0.7.0
    make -f Makefile.xdaq _all
    make -f Makefile.xdaq rpm

Make sure to clone the repository into `cactusprojects/utm`

Build on MacOS
--------------

Future support.

  .. code-block:: bash

    make -f Makefile.macos all python
    . setup.sh
