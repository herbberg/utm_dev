/*
 * File: tmGrammar.i
 * interface file fow SWIG
 *
 * Author       Takashi Matsushita
 * Created:     07 Jul 2014
 */

/* todo */

%module tmGrammar

%include <std_vector.i>
%include <std_string.i>
%include <std_map.i>

namespace std {
  %template(StringVector) vector<string>;
  %template(map_string_int) map<string, int>;
}

%include "Algorithm.i"
%include "Cut.i"
%include "Object.i"
%include "Function.i"
/* eof */
