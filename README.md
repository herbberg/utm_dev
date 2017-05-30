# utm - uGT Trigger Menu library
- the original codes are hosted on [cactus.web.cern.ch](https://svnweb.cern.ch/trac/cactus/browser/trunk/cactusprojects/utm)
- in this repository, XML interface codes generated by CodeSynthesis XSD XML Schema to C++ compiler
  as well as patched XSD header files are included for use in CMSSW environment

# Example of a manual installation as an external library of CMSSW and test of the installation

Building the external utm library

```{r, engine='bash', count_lines}
cmsrel CMSSW_9_0_0
cd CMSSW_9_0_0
cmsenv
git clone https://gitlab.cern.ch/cms-l1t-utm/utm.git
cd utm
git checkout <UTM tag/branch>
scram tool info xerces-c
export XERCES_C_BASE=<XERCES_C_BASE directory printed by the above command>
scram tool info boost
export BOOST_BASE=<BOOST_BASE directory printed by the above command>
make -f Makefile.standalone all
make -f Makefile.standalone install
```

Testing the built external utm library

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

* [API document](http://cern.ch/takashi/utm-api-doc/namespacetmeventsetup.html)
* [XSD document](http://cern.ch/takashi/utm-xsd-doc/index.html)
* [Available algorithms](https://twiki.cern.ch/twiki/bin/view/CMS/GlobalTriggerUTM)
