Contents
========

* Algorithm.i, Function.i, Object.i, Cut.i: SWIG python interface
* test: unit tests, test programs

Test programs
=============

Building test programs

    cd test/
    make

Make sure to setup local environment

    . ../../setup.sh

List of test programs

* test_algorithm: parser for algorithm expression
* test_cut:       parser for cut expression
* test_object:    parser for object expression
* test_function:  parser for function expression
* parser:         all in one parser
* parser.py:      python version of parser test program

CMSSW
=====

For more information of building utm as external CMSSW library, see
https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUpgradeL1T-uTme#uGT_Trigger_Menu_library_utm
