/*
 * File: Object.i
 * interface file fow SWIG
 *
 * Author       Takashi Matsushita
 * Created:     07 Jul 2014
 */

/* todo */

%module Object
%{
#define SWIG_FILE_WITH_INIT
#include "Object.hh"
%}


%rename(Object_Item)  Object::Item;
%rename(Object_Unknown)  Object::Unknown;
%rename(Object_parser)  Object::parser;


%include "Object.hh"
/* eof */
