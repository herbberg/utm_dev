Contents
========
- tmTable.i: SWIG interface for python
- test:      test programs


Test programs
=============
in the test directory, type "make"
type ". ../../setup.sh" or equivalent in your shell

example to validate table row with python binding
  python validate.py

example to fill tmtable::Scale from scale_set.xml
  cd ../../tmXsd
  ../tmTable/test/test_scale test/scale_set.xml

# eof
