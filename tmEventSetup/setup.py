#!/usr/bin/env python

##
#  @author      Takashi Matsushita
#  Created:     23 Mar 2015
#

## @file setup.py setup file for creating tmEventSetup module
## @todo


from distutils.core import setup, Extension

tmEventSetup_module = Extension('_tmEventSetup',
                          define_macros=[('SWIG', '1'),],
                          sources=['tmEventSetup_wrap.cxx',
                                   'tmEventSetup.cc',
                                   'esTriggerMenuHandle.cc',
                                   'esAlgorithmHandle.cc',
                                   'esConditionHandle.cc',
                                   'esObjectHandle.cc',
                                   'esCutHandle.cc',
                                   'esScaleHandle.cc',
                                   'esBinHandle.cc'],
                          include_dirs=['..', '../tmTable',],
                          library_dirs=['../tmUtil', '../tmTable', '../tmGrammar',],
                          libraries=['tmutil', 'tmtable', 'tmgrammar',],
                         )

setup (name = 'tmEventSetup',
       version = '0.8.0',
       author = "Takashi MATSUSHITA",
       description = """algorithm expression to tmEventSetup converter""",
       ext_modules = [tmEventSetup_module],
       py_modules = ["tmEventSetup"],
      )
# eof
