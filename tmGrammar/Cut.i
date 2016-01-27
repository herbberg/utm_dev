/*
 * File: Cut.i
 * interface file fow SWIG
 *
 * Author       Takashi Matsushita
 * Created:     07 Jul 2014
 */

/* todo */

%module Cut
%{
#define SWIG_FILE_WITH_INIT
#include "Cut.hh"
%}

%rename(Cut_Item)  Cut::Item;
%rename(Cut_parser)  Cut::parser;

%include "Cut.hh"
/* eof */
