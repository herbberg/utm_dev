#!/usr/bin/env python

##
#  @author      Takashi Matsushita
#  Created:     07 Jul 2014
#

## @file setup.py setup file for creating tmGrammar module
## @todo


from distutils.core import setup, Extension
import os

BOOST_LIB_DIR="."
BOOST_INC_DIR="."
boost_root = os.environ.get('BOOST_ROOT')
if os.environ.get('BOOST_ROOT'):
  BOOST_LIB_DIR=boost_root+'/lib'
  BOOST_INC_DIR=boost_root+'/include'

tmGrammar_module = Extension('_tmGrammar',
                             sources=['tmGrammar_wrap.cxx',
                                      'Algorithm.cc',
                                      'Cut.cc',
                                      'Object.cc',
                                      'Function.cc'],
                             include_dirs=['..', BOOST_INC_DIR,],
                             library_dirs=['../tmUtil', BOOST_LIB_DIR,],
                             libraries=['tmutil',],
                            )

setup (name = 'tmGrammar',
       version = '0.7.5',
       author = "Takashi MATSUSHITA",
       description = """parser for level-1 trigger menu grammar""",
       ext_modules = [tmGrammar_module],
       py_modules = ["tmGrammar"],
      )
# eof
