Contents
========

* tmTable.i: SWIG interface for python
* test:      unit tests, test programs


Test programs
=============

Building test programs

    cd test/
    make

Make sure to setup local environment

    . ../../setup.sh

example to validate table row with python binding
  python validate.py

example to fill tmtable::Scale from scale_set.xml
  cd ../../tmXsd
  ../tmTable/test/test_scale test/scale_set.xml
