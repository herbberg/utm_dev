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
