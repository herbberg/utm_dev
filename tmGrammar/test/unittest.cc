#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tmGrammar

#include "tmGrammar/Algorithm.hh"
#include "tmGrammar/Function.hh"
#include "tmGrammar/Object.hh"
#include "tmGrammar/Cut.hh"

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <string>
#include <vector>

BOOST_AUTO_TEST_SUITE(Algorithm)

BOOST_AUTO_TEST_CASE(Algorithm_isGate)
{
  BOOST_CHECK_EQUAL(Algorithm::isGate(Algorithm::AND), true);
  BOOST_CHECK_EQUAL(Algorithm::isGate(Algorithm::OR), true);
  BOOST_CHECK_EQUAL(Algorithm::isGate(Algorithm::NOT), true);
  BOOST_CHECK_EQUAL(Algorithm::isGate(Algorithm::XOR), true);

  BOOST_CHECK_EQUAL(Algorithm::isGate(" AND "), false);
  BOOST_CHECK_EQUAL(Algorithm::isGate("MU10"), false);
  BOOST_CHECK_EQUAL(Algorithm::isGate("comb{MU0,MU0}"), false);
  BOOST_CHECK_EQUAL(Algorithm::isGate("foobar"), false);
  BOOST_CHECK_EQUAL(Algorithm::isGate("ANDOR"), false);
  BOOST_CHECK_EQUAL(Algorithm::isGate("XORNOT"), false);
}

BOOST_AUTO_TEST_CASE(Algorithm_parser)
{
  std::vector<std::string> reference;

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("FOO AND NOT BAR"), true);
  // NOTE: RPN (Reverse Polish notation)
  boost::split(reference, "FOO BAR NOT AND", boost::is_any_of(" "));
  BOOST_CHECK_EQUAL_COLLECTIONS(Algorithm::Logic::getTokens().begin(),
                                Algorithm::Logic::getTokens().end(),
                                reference.begin(), reference.end());

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("NOT FOO OR NOT BAR AND BAZ"), true);
  // NOTE: RPN (Reverse Polish notation)
  boost::split(reference, "FOO NOT BAR NOT OR BAZ AND", boost::is_any_of(" "));
  BOOST_CHECK_EQUAL_COLLECTIONS(Algorithm::Logic::getTokens().begin(),
                                Algorithm::Logic::getTokens().end(),
                                reference.begin(), reference.end());

  // functions

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("some_func{FOO42,BAR42,BAZ42}"), true);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("some_func{FOO42,BAR42}[BAZ]"), true);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("another_func{FOO42[BAR],BAR42[BAZ]}[BAZ,FOO]"), true);

  // fault injections

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("AND"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("NOT AND"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("FOO AND"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("AND FOO"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("AND OR AND"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("FOO OR NOT"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("FOO NOT OR BAR"), false);

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Algorithm::parser("NOT FOO AND XOR"), false);
}

BOOST_AUTO_TEST_CASE(Algorithm_Logic)
{
  Algorithm::Logic::clear();
  Algorithm::Logic logic;

  logic.tokens.push_back("foo");
  logic.append("bar");
  logic.append("baz");

  std::vector<std::string> reference;
  boost::split(reference, "foo bar baz", boost::is_any_of(" "));
  BOOST_CHECK_EQUAL_COLLECTIONS(logic.getTokens().begin(), logic.getTokens().end(),
                                reference.begin(), reference.end());

  Algorithm::Logic::clear();
  BOOST_CHECK_EQUAL(Logic::getTokens().size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Cut)

BOOST_AUTO_TEST_CASE(Cut_parser)
{
  Cut::Item item;
  BOOST_CHECK_EQUAL(Cut::parser("MU-ISO_FOO, MU-ETA_BAR, MU-PHI_BAZ, MU-CHG_POS", item), true);
  BOOST_CHECK_EQUAL(item.message, "");
  std::vector<std::string> reference;
  boost::split(reference, "MU-ISO_FOO MU-ETA_BAR MU-PHI_BAZ MU-CHG_POS", boost::is_any_of(" "));
  BOOST_CHECK_EQUAL_COLLECTIONS(item.name.begin(), item.name.end(),
                                reference.begin(), reference.end());

  item.name.clear();
  item.message.clear(); // so thats not convenient at all

  BOOST_CHECK_EQUAL(Cut::parser("MU-FOO_BAR", item), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Function)

BOOST_AUTO_TEST_CASE(Function_parser_valid)
{
  std::vector<std::string> expressions;
  expressions.push_back("comb{MU0,MU0}");
  expressions.push_back("dist{TAU0,EG1}[DETA_X,DR_X]");

  expressions.push_back("mass{TAU0,EG1}[MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DR_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DETA_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DPHI_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DETA_X,DPHI_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DR_X,DPHI_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DR_X,DETA_X,MASS_X]");
  expressions.push_back("mass{TAU0,EG1}[DR_X,DETA_X,DPHI_X,MASS_X]");

  expressions.push_back("comb_orm{JET0,TAU0}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET0,JET1,TAU0}[ORMDR_X]");
  expressions.push_back("comb_orm{JET3,JET2,JET1,TAU0}[ORMDR_X]");
  expressions.push_back("comb_orm{JET4,JET3,JET2,JET1,TAU0}[ORMDR_X]");

  expressions.push_back("dist_orm{TAU0,EG1}[ORMDETA_X,DR_X]");
  expressions.push_back("dist_orm{TAU0,TAU1,EG1}[ORMDETA_X,DR_X]");

  expressions.push_back("mass_inv_orm{TAU0,EG1}[ORMDETA_X,MASS_X]");
  expressions.push_back("mass_inv_orm{TAU0,TAU1,EG1}[ORMDETA_X,MASS_X]");

  expressions.push_back("mass_trv_orm{TAU0,EG1}[ORMDETA_X,MASS_X]");
  expressions.push_back("mass_trv_orm{TAU0,TAU1,EG1}[ORMDETA_X,MASS_X]");

  std::vector<std::string>::const_iterator cit;
  for (cit = expressions.begin(); cit != expressions.end(); ++cit)
  {
    Function::Item item;
    BOOST_CHECK_MESSAGE(Function::parser(*cit, item) == true, *cit);
    BOOST_CHECK_EQUAL(item.message, "");
  }
}

BOOST_AUTO_TEST_CASE(Function_parser_invalid)
{
  std::vector<std::string> expressions;
  expressions.push_back("comb_orm{JET0}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET0,JET0,JET0}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET3,JET2}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET3,JET2,JET1,JET1}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET4,JET3,JET2}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET4,JET3,JET2,JET1,JET0}[ORMDR_X]");

  expressions.push_back("dist_orm{JET0,JET1}[DR_X]"); // missing overlap removal cut
  expressions.push_back("dist_orm{JET0,TAU0}[ORMDR_X]"); // missing delta cut
  expressions.push_back("dist_orm{JET0,TAU0,TAU0}[ORMDR_X,DR_X]");
  expressions.push_back("dist_orm{JET0,JET1,JET2,TAU0}[ORMDR_X,DR_X]");
  expressions.push_back("dist_orm{JET0,JET1,TAU0,TAU1}[ORMDR_X,DR_X]");

  expressions.push_back("mass_inv_orm{JET0,JET1}[MASS_Z]"); // missing overlap removal cut
  expressions.push_back("mass_inv_orm{JET0,TAU0}[ORMDR_X]"); // missing mass cut
  expressions.push_back("mass_inv_orm{JET0,TAU0,TAU0}[ORMDR_X,MASS_Z]");
  expressions.push_back("mass_inv_orm{JET0,JET1,JET2,TAU0}[ORMDR_X,MASS_Z]");
  expressions.push_back("mass_inv_orm{JET0,JET1,TAU0,TAU1}[ORMDR_X,MASS_Z]");

  expressions.push_back("mass_trv_orm{JET0,JET1}[MASS_Z]"); // missing overlap removal cut
  expressions.push_back("mass_trv_orm{JET0,TAU0}[ORMDR_X]"); // missing mass cut
  expressions.push_back("mass_trv_orm{JET0,TAU0,TAU0}[ORMDR_X,MASS_Z]");
  expressions.push_back("mass_trv_orm{JET0,JET1,JET2,TAU0}[ORMDR_X,MASS_Z]");
  expressions.push_back("mass_trv_orm{JET0,JET1,TAU0,TAU1}[ORMDR_X,MASS_Z]");

  std::vector<std::string>::const_iterator cit;
  for (cit = expressions.begin(); cit != expressions.end(); ++cit)
  {
    Function::Item item;
    BOOST_CHECK_MESSAGE(Function::parser(*cit, item) == false, *cit);
    BOOST_CHECK_EQUAL(item.message.empty(), false);
  }
}

BOOST_AUTO_TEST_CASE(Function_isFunction)
{
  std::vector<std::string> expressions;
  expressions.push_back("comb{MU0,MU0}");
  expressions.push_back("dist{TAU0,EG1}[DETA_X,DR_X]");
  expressions.push_back("mass{TAU0,EG1}[MASS_X]");
  expressions.push_back("comb_orm{JET0,TAU0}[ORMDETA_X]");
  expressions.push_back("comb_orm{JET0,JET0,TAU0}[ORMDR_X]");
  expressions.push_back("comb_orm{JET3,JET2,JET1,TAU0}[ORMDR_X]");
  expressions.push_back("comb_orm{JET4,JET3,JET2,JET1,TAU0}[ORMDR_X]");

  std::vector<std::string>::const_iterator cit;
  for (cit = expressions.begin(); cit != expressions.end(); ++cit)
  {
    BOOST_CHECK_EQUAL(Function::isFunction(*cit), true);
  }
}

BOOST_AUTO_TEST_SUITE_END()
