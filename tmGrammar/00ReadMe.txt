================
Algorithm parser
================

Contents
========
- Algorithm.i, Function.i, Object.i, Cut.i: SWIG python interface
- test: test programs

development environment:
  - SLC6: 2.6.32-504.el6.x86_64 #1 SMP Tue Oct 14 19:40:41 CEST 2014 x86_64 x86_64 x86_64 GNU/Linux
  - gcc: gcc version 4.4.7 20120313 (Red Hat 4.4.7-4) (GCC) 
  - boost: BOOST_LIB_VERSION "1_41"
  - swig: SWIG Version 1.3.40
  - Python 2.6.6 (r266:84292, Jan 23 2014, 10:39:35) 
    [GCC 4.4.7 20120313 (Red Hat 4.4.7-4)] on linux2


test programs
-------------
in the test directory, type "make" to create the following test programs
type ". ../../setup.sh" or equivalent in your shell

  - test_algorithm: parser for algorithm expression
  - test_cut:       parser for cut expression
  - test_object:    parser for object expression
  - test_function:  parser for function expression
  - parser:         all in one parser
  - parser.py:      python version of parser test program


CMSSW
=====
Refer the following twiki page;
https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUpgradeL1T-uTme#uGT_Trigger_Menu_library_utm

# eof
