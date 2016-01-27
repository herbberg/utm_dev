/*
 * File: Algorithm.i
 * interface file fow SWIG
 *
 * Author       Takashi Matsushita
 * Created:     07 Jul 2014
 */

/* todo */

%module Algorithm
%{
#define SWIG_FILE_WITH_INIT
#include "Algorithm.hh"
%}

%rename(Algorithm_Logic) Algorithm::Logic;
%rename(Algorithm_parser) Algorithm::parser;

%include "Algorithm.hh"
/* eof */
