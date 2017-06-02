#!/usr/bin/env python

##
#  @author      Takashi Matsushita
#  Created:     18 Aug 2014
#

## @file setup.py setup file for creating tmTable module
## @todo


from distutils.core import setup, Extension
import os
XERCES_LIB_DIR=os.environ.get('XERCES_LIB_DIR')
if not XERCES_LIB_DIR:
  XERCES_LIB_DIR="."

tmTable_module = Extension('_tmTable',
                         define_macros=[('SWIG', '1')],
                         sources=['tmTable_wrap.cxx'],
                         include_dirs=['..'],
                         library_dirs=['.', '../tmUtil', '../tmXsd', XERCES_LIB_DIR],
                         libraries=['xerces-c', 'tmutil', 'tmxsd', 'tmtable'],
                        )

setup (name = 'tmTable',
       version = '0.6.5',
       author = "Takashi MATSUSHITA",
       description = """xml interface""",
       ext_modules = [tmTable_module],
       py_modules = ["tmTable"],
      )
# eof
