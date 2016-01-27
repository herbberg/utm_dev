/*
 * File: Function.i
 * interface file fow SWIG
 *
 * Author       Takashi Matsushita
 * Created:     07 Jul 2014
 */

/* todo */

%module Function
%{
#include "Function.hh"
%}

%rename(Function_Item)  Function::Item;
%rename(Function_parser)  Function::parser;
%rename(Function_Unknown)  Function::Unknown;
%rename(Function_getCuts)  Function::getCuts;
%rename(Function_getObjects)  Function::getObjects;
%rename(Function_getObjectCuts)  Function::getObjectCuts;

%include "Function.hh"
/* eof */
