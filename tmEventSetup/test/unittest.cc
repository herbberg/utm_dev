#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tmEventSetup

#include "tmUtil/tmUtil.hh"
#include "tmEventSetup/tmEventSetup.hh"

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <string>
#include <vector>

#include <cmath>

namespace tmeventsetup
{
  extern long long toFixedPoint(double, const size_t);
}


BOOST_AUTO_TEST_SUITE(esTriggerMenu)

BOOST_AUTO_TEST_CASE(esTriggerMenu_attributes)
{
  // References
  const std::string name = "L1Menu_Foobar";
  const std::string version = "1.42";
  const std::string comment = "NO-body expects the Spanish Inquisition!";
  const std::string datetime = "2016-12-25T18:00:00+0000";
  const std::string firmwareUuid = "f06d0803-1852-4ac8-9f79-01299371a28b";
  const std::string scaleSetName = "spam";
  const size_t nModules = 4;

  // Create menu container
  tmeventsetup::esTriggerMenu menu;

  // Populate attribuites
  menu.setName(name);
  menu.setVersion(version);
  menu.setComment(comment);
  menu.setDatetime(datetime);
  menu.setFirmwareUuid(firmwareUuid);
  menu.setScaleSetName(scaleSetName);
  menu.setNmodules(nModules);

  // Check attributes
  BOOST_CHECK_EQUAL(name, menu.getName());
  BOOST_CHECK_EQUAL(version, menu.getVersion());
  BOOST_CHECK_EQUAL(comment, menu.getComment());
  BOOST_CHECK_EQUAL(datetime, menu.getDatetime());
  BOOST_CHECK_EQUAL(firmwareUuid, menu.getFirmwareUuid());
  BOOST_CHECK_EQUAL(scaleSetName, menu.getScaleSetName());
  BOOST_CHECK_EQUAL(nModules, menu.getNmodules());
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(tmEventSetup)

BOOST_AUTO_TEST_CASE(tmEventSetup_getMmHashN)
{
  unsigned int seed = 0xdeadbabe; // fixed inside getMmHashN

  std::string phrase = "NO-body expects the Spanish Inquisition!";

  BOOST_CHECK_EQUAL(
    tmeventsetup::getMmHashN(phrase),
    tmutil::MurmurHashNeutral2(phrase.c_str(), phrase.size(), seed)
  );
}

BOOST_AUTO_TEST_CASE(tmEventSetup_toFixedPoint)
{
  BOOST_CHECK_EQUAL(0, tmeventsetup::toFixedPoint(0.123, 0));
  BOOST_CHECK_EQUAL(1, tmeventsetup::toFixedPoint(0.123, 1));
  BOOST_CHECK_EQUAL(12, tmeventsetup::toFixedPoint(0.123, 2));
  BOOST_CHECK_EQUAL(123, tmeventsetup::toFixedPoint(0.123, 3));

  BOOST_CHECK_EQUAL(123, tmeventsetup::toFixedPoint(123.456, 0));
  BOOST_CHECK_EQUAL(1235, tmeventsetup::toFixedPoint(123.456, 1));
  BOOST_CHECK_EQUAL(12346, tmeventsetup::toFixedPoint(123.456, 2));
  BOOST_CHECK_EQUAL(123456, tmeventsetup::toFixedPoint(123.456, 3));

  // Check rounding
  BOOST_CHECK_EQUAL(14, tmeventsetup::toFixedPoint(1.449, 1));
  BOOST_CHECK_EQUAL(15, tmeventsetup::toFixedPoint(1.499, 1));
  BOOST_CHECK_EQUAL(15, tmeventsetup::toFixedPoint(1.500, 1));
}

BOOST_AUTO_TEST_CASE(tmEventSetup_setLut)
{
  size_t precision = 1;

  std::vector<double> values;
  values.push_back(0.123);
  values.push_back(1.234);
  values.push_back(2.345);
  values.push_back(3.456);

  // Reference set with precision of 1
  std::vector<long long> reference;
  reference.push_back(1);
  reference.push_back(12);
  reference.push_back(23);
  reference.push_back(35);

  std::vector<long long> results;
  tmeventsetup::setLut(results, values, precision);

  BOOST_CHECK_EQUAL_COLLECTIONS(results.begin(), results.end(),
                                reference.begin(), reference.end());
}

BOOST_AUTO_TEST_CASE(tmEventSetup_applySin)
{
  std::vector<double> values;
  values.push_back(0.123);
  values.push_back(1.234);
  values.push_back(2.345);
  values.push_back(3.456);

  std::vector<double> reference(values.size());
  std::transform(values.begin(), values.end(), reference.begin(), ::sin);

  tmeventsetup::applySin(values, values.size());

  BOOST_CHECK_EQUAL_COLLECTIONS(values.begin(), values.end(),
                                reference.begin(), reference.end());
}

BOOST_AUTO_TEST_CASE(tmEventSetup_applyCos)
{
  std::vector<double> values;
  values.push_back(0.123);
  values.push_back(1.234);
  values.push_back(2.345);
  values.push_back(3.456);

  std::vector<double> reference(values.size());
  std::transform(values.begin(), values.end(), reference.begin(), ::cos);

  tmeventsetup::applyCos(values, values.size());

  BOOST_CHECK_EQUAL_COLLECTIONS(values.begin(), values.end(),
                                reference.begin(), reference.end());
}

BOOST_AUTO_TEST_CASE(tmEventSetup_applyCosh)
{
  std::vector<double> values;
  values.push_back(0.123);
  values.push_back(1.234);
  values.push_back(2.345);
  values.push_back(3.456);

  std::vector<double> reference(values.size());
  std::transform(values.begin(), values.end(), reference.begin(), ::cosh);

  tmeventsetup::applyCosh(values, values.size());

  BOOST_CHECK_EQUAL_COLLECTIONS(values.begin(), values.end(),
                                reference.begin(), reference.end());
}

BOOST_AUTO_TEST_SUITE_END()
