#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tmUtil

#include "tmUtil/tmUtil.hh"

#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>
#include <cmath>
#include <regex.h>

// ----------------------------------------------------------------------------
//  unittests for tmUtil functions
// ----------------------------------------------------------------------------

BOOST_AUTO_TEST_SUITE(tmUtil)

BOOST_AUTO_TEST_CASE(pow10)
{
  size_t lutsize = 309;

  // Validate lookup table
  for (size_t exponent = 0; exponent < lutsize; ++exponent)
  {
    BOOST_CHECK_EQUAL(tmutil::pow10(exponent), static_cast<double>(std::pow(10, exponent)));
  }

  // Exceeding range
  BOOST_CHECK_THROW(tmutil::pow10(9999), std::exception);
}

BOOST_AUTO_TEST_CASE(MurmurHashNeutral2)
{
  const unsigned int reference = 557387791; // "foobar" with seed 0xbeef
  BOOST_CHECK_EQUAL(tmutil::MurmurHashNeutral2("foobar", 6, 0xbeef), reference);
}

BOOST_AUTO_TEST_CASE(regex_compile)
{
  regex_t regex;

  BOOST_CHECK_EQUAL(0, tmutil::regex_compile(&regex, "(\\w+):([0-9]+)"));

  regfree(&regex);

  // faulty expression
  BOOST_CHECK_EQUAL(1, tmutil::regex_compile(&regex, "(\\w+"));

  regfree(&regex);
}

BOOST_AUTO_TEST_CASE(regex_match)
{
  std::string expr = "foobar:42";
  std::vector<std::string> reference;
  reference.push_back("foobar");
  reference.push_back("42");

  regex_t regex;
  tmutil::regex_compile(&regex, "(\\w+)\\:([0-9]+)");


  std::vector<std::string> tokens;
  tmutil::regex_match(&regex, expr, tokens);

  BOOST_CHECK_EQUAL_COLLECTIONS(tokens.begin(), tokens.end(),
                                reference.begin(), reference.end());

  regfree(&regex);
}

BOOST_AUTO_TEST_CASE(Version)
{
  using tmutil::Version;

  BOOST_CHECK_EQUAL(Version("1.2.3") < Version("1.2.4"), true);
  BOOST_CHECK_EQUAL(Version("1.2.4") < Version("1.2.3"), false);

  BOOST_CHECK_EQUAL(Version("1.2.3") < Version("1.3.3"), true);
  BOOST_CHECK_EQUAL(Version("1.3.3") < Version("1.2.3"), false);

  BOOST_CHECK_EQUAL(Version("1.2.3") < Version("2.2.3"), true);
  BOOST_CHECK_EQUAL(Version("2.2.3") < Version("1.2.3"), false);

  BOOST_CHECK_EQUAL(Version("1.2.3") > Version("1.2.4"), false);
  BOOST_CHECK_EQUAL(Version("1.2.4") > Version("1.2.3"), true);

  BOOST_CHECK_EQUAL(Version("1.2.3") > Version("1.3.3"), false);
  BOOST_CHECK_EQUAL(Version("1.3.3") > Version("1.2.3"), true);

  BOOST_CHECK_EQUAL(Version("1.2.3") > Version("2.2.3"), false);
  BOOST_CHECK_EQUAL(Version("2.2.3") > Version("1.2.3"), true);

  BOOST_CHECK_EQUAL(Version("1.2.3") == Version("1.2.3"), true);
  BOOST_CHECK_EQUAL(Version("1.2.3") != Version("1.2.4"), true);
  BOOST_CHECK_EQUAL(Version("1.2.4") != Version("1.2.3"), true);

  BOOST_CHECK_EQUAL(Version("1.2.3").str() == "1.2.3", true);
  BOOST_CHECK_EQUAL(Version("2.0.1").str() != "2.0.0", true);
}

BOOST_AUTO_TEST_SUITE_END()
