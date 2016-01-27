/*
 * File: tmEventSetup.i
 * interface file for SWIG
 *
 * Author       Takashi Matsushita
 * Created:     23 Mar 2015
 */

/* todo */

%module tmEventSetup

%include "tmTable/tmTable.i"

%{
#include "tmEventSetup.hh"
#include "esTypes.hh"
#include "esTriggerMenu.hh"
#include "esAlgorithm.hh"
#include "esCondition.hh"
#include "esObject.hh"
#include "esCut.hh"
#include "esCutValue.hh"
#include "esScale.hh"
#include "esBin.hh"
using namespace tmeventsetup;
%}

%include <std_map.i>
%include <std_vector.i>
%include <std_string.i>


namespace std {
  %template(AlgoMap) map<string, tmeventsetup::esAlgorithm *>;
  %template(CondMap) map<string, tmeventsetup::esCondition *>;
  %template(ScaleMap) map<string, tmeventsetup::esScale *>;
  %template(PrecMap) map<string, unsigned int>;
  %template(ObjVec) vector<tmeventsetup::esObject>;
  %template(CutVec) vector<tmeventsetup::esCut>;
  %template(BinVec) vector<tmeventsetup::esBin>;
  %template(StrVec) vector<string>;
  %template(LlongVec) vector<long long>;
  %template(DoubleVec) vector<double>;
}


%{
  namespace swig {
    template <>  struct traits<tmeventsetup::esAlgorithm> {
      typedef pointer_category category;
     static const char* type_name() { return"tmeventsetup::esAlgorithm"; }
    };
    template <>  struct traits<tmeventsetup::esCondition> {
      typedef pointer_category category;
     static const char* type_name() { return"tmeventsetup::esCondition"; }
    };
    template <>  struct traits<tmeventsetup::esScale> {
      typedef pointer_category category;
     static const char* type_name() { return"tmeventsetup::esScale"; }
    };
  }
%} 

typedef long esCombinationType;

%include "tmEventSetup.hh"
%include "esTypes.hh"
%include "esTriggerMenu.hh"
%include "esAlgorithm.hh"
%include "esCondition.hh"
%include "esObject.hh"
%include "esCut.hh"
%include "esCutValue.hh"
%include "esScale.hh"
%include "esBin.hh"

/* eof */
