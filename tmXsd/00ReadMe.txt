Contents
========
- xsd-type:     XSD definitions
- gen-xsd-type: C++ bindings for the XSD
- menu.xsd:     primary XSD for the CMS L1 Menu
- test:         test programs


Test programs
=============
in the test directory, type "make"
type "cd .."
type ". ../setup.sh" or equivalent in your shell

example to read tmxsd::ext_signal_set
  test/ext_signal_set-parser test/ext_signal_set.xml

example to read tmxsd::scale_set
  test/scale_set-parser test/scale_set.xml

example to read and write tmxsd::scale_set, tmxsd::tree2extSignal, tmxsd::menu
is in test/roundtrip.cc

# eof
