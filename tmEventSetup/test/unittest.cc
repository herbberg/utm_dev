#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tmEventSetup

#include "tmEventSetup/tmEventSetup.hh"

#include "tmEventSetup/esAlgorithmHandle.hh"
#include "tmEventSetup/esAlgorithm.hh"

#include "tmUtil/tmUtil.hh"

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

BOOST_AUTO_TEST_CASE(esAlgorithmHandle_init)
{
  tmtable::Row row;
  row["name"] = "L1_Unnamed";
  row["index"] = "42";
  row["module_id"] = "0";
  row["module_index"] = "1";
  row["expression"] = "mass{MU4,MU2}[MASS_Z] OR TAU42";

  tmeventsetup::esAlgorithmHandle handle;
  handle.init(row);

  tmeventsetup::esAlgorithm* algorithm = dynamic_cast<tmeventsetup::esAlgorithm*>(&handle);

  BOOST_CHECK_EQUAL("L1_Unnamed", algorithm->getName());
  BOOST_CHECK_EQUAL(42, algorithm->getIndex());
  BOOST_CHECK_EQUAL(0, algorithm->getModuleId());
  BOOST_CHECK_EQUAL(1, algorithm->getModuleIndex());
  BOOST_CHECK_EQUAL("mass{MU4,MU2}[MASS_Z] OR TAU42", algorithm->getExpression());
  BOOST_CHECK_EQUAL("", algorithm->getExpressionInCondition());
}

BOOST_AUTO_TEST_CASE(esAlgorithmHandle_setRpnVector)
{
  tmtable::Row row;
  row["name"] = "L1_setRpnVector";
  row["index"] = "42";
  row["module_id"] = "0";
  row["module_index"] = "1";
  row["expression"] = "MU7 AND TAU3";

  std::map<std::string, std::string> conditionMap;
  conditionMap["MU7"] = "SingleMu_4";
  conditionMap["TAU3"] = "SingleTau_5";

  tmeventsetup::esAlgorithmHandle handle;
  handle.init(row);
  handle.setExpressionInCondition(conditionMap);

  tmeventsetup::esAlgorithm* algorithm = dynamic_cast<tmeventsetup::esAlgorithm*>(&handle);

  BOOST_CHECK_EQUAL("L1_setRpnVector", algorithm->getName());
  BOOST_CHECK_EQUAL(42, algorithm->getIndex());
  BOOST_CHECK_EQUAL(0, algorithm->getModuleId());
  BOOST_CHECK_EQUAL(1, algorithm->getModuleIndex());
  BOOST_CHECK_EQUAL("MU7 AND TAU3", algorithm->getExpression());
  BOOST_CHECK_EQUAL("SingleMu_4 AND SingleTau_5", algorithm->getExpressionInCondition());
}

BOOST_AUTO_TEST_CASE(esAlgorithmHandle_setExpressionInCondition)
{
  tmtable::Row row;
  row["name"] = "L1_setExpressionInCondition";
  row["index"] = "42";
  row["module_id"] = "0";
  row["module_index"] = "1";
  row["expression"] = "mass{MU4,MU2}[MASS_Z] OR TAU42 AND EXT_SIG_0";

  std::map<std::string, std::string> conditionMap;
  conditionMap["mass{MU4,MU2}[MASS_Z]"] = "mass_123";
  conditionMap["TAU42"] = "single_tau_124";
  conditionMap["EXT_SIG_0"] = "ext_signal_125";

  tmeventsetup::esAlgorithmHandle handle;
  handle.init(row);
  handle.setExpressionInCondition(conditionMap);

  // Isn't this all a quite a big rubish?!
  tmeventsetup::esTriggerMenuHandle triggerMenuHandle;
  handle.setRpnVector(triggerMenuHandle.parse(handle.getExpressionInCondition()));

  tmeventsetup::esAlgorithm* algorithm = dynamic_cast<tmeventsetup::esAlgorithm*>(&handle);

  BOOST_CHECK_EQUAL("L1_setExpressionInCondition", algorithm->getName());
  BOOST_CHECK_EQUAL(42, algorithm->getIndex());
  BOOST_CHECK_EQUAL(0, algorithm->getModuleId());
  BOOST_CHECK_EQUAL(1, algorithm->getModuleIndex());
  BOOST_CHECK_EQUAL("mass{MU4,MU2}[MASS_Z] OR TAU42 AND EXT_SIG_0", algorithm->getExpression());
  BOOST_CHECK_EQUAL("mass_123 OR single_tau_124 AND ext_signal_125", algorithm->getExpressionInCondition());

  std::vector<std::string> rpn_vector_ref;
  rpn_vector_ref.push_back("mass_123");
  rpn_vector_ref.push_back("single_tau_124");
  rpn_vector_ref.push_back("OR");
  rpn_vector_ref.push_back("ext_signal_125");
  rpn_vector_ref.push_back("AND");
  std::vector<std::string> rpn_vector = algorithm->getRpnVector();

  BOOST_CHECK_EQUAL_COLLECTIONS(rpn_vector.begin(), rpn_vector.end(),
                                rpn_vector_ref.begin(), rpn_vector_ref.end());
}

BOOST_AUTO_TEST_SUITE_END()

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
