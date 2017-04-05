#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE tmTable

#include "tmTable/tmTable.hh"
#include "tmTable/validator.hh"

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

// Paths and filenames
static const boost::filesystem::path pwd = boost::filesystem::current_path();
static const boost::filesystem::path xmldir = pwd / ".." / ".." / "tmXsd" / "test";
static const boost::filesystem::path menu_xml = xmldir / "menu.xml";
static const boost::filesystem::path scale_set_xml = xmldir / "scale_set.xml";
static const boost::filesystem::path ext_signal_set_xml = xmldir / "ext_signal_set.xml";

// Fixture to change into XSD directory for validation
struct XSDFixture
{
  XSDFixture()
  {
    const char* utm_xsd_dir = std::getenv("UTM_XSD_DIR");
    assert(utm_xsd_dir != NULL);
    boost::filesystem::current_path(utm_xsd_dir);
  }

  ~XSDFixture()
  {
    boost::filesystem::current_path(pwd);
  }
};


// ----------------------------------------------------------------------------
//  unittests for class Scale
// ----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_SUITE(tmTable_Scale, XSDFixture)

BOOST_AUTO_TEST_CASE(isValid)
{
  tmtable::Scale scale;
  BOOST_CHECK_EQUAL(scale.isValid(), false);

  scale.isValid(true);
  BOOST_CHECK_EQUAL(scale.isValid(), true);
}

BOOST_AUTO_TEST_CASE(getKeyForBin)
{
  tmtable::Scale scale;
  std::string key;

  tmtable::Row row;
  row["object"] = "FOO";
  row["type"] = "BAR";

  key = scale.getKeyForBin(row);
  BOOST_CHECK_EQUAL(key, "FOO-BAR");
}

BOOST_AUTO_TEST_SUITE_END()

// ----------------------------------------------------------------------------
//  unittests for class ExtSignal
// ----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_SUITE(tmTable_ExtSignal, XSDFixture)

BOOST_AUTO_TEST_CASE(isValid)
{
  tmtable::ExtSignal extSignal;
  BOOST_CHECK_EQUAL(extSignal.isValid(), false);

  extSignal.isValid(true);
  BOOST_CHECK_EQUAL(extSignal.isValid(), true);
}

BOOST_AUTO_TEST_SUITE_END()

// ----------------------------------------------------------------------------
//  unittests for class Menu
// ----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_SUITE(tmTable_Menu, XSDFixture)

BOOST_AUTO_TEST_CASE(isValid)
{
  tmtable::Menu menu;
  BOOST_CHECK_EQUAL(menu.isValid(), false);

  menu.isValid(true);
  BOOST_CHECK_EQUAL(menu.isValid(), true);
}

BOOST_AUTO_TEST_SUITE_END()

// ----------------------------------------------------------------------------
//  unittests for tmTable functions
// ----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_SUITE(tmTable_functions, XSDFixture)

BOOST_AUTO_TEST_CASE(xml2scale)
{
  tmtable::Scale scale;

  std::string message;
  message = tmtable::xml2scale(scale_set_xml.string().c_str(), scale);
  BOOST_CHECK_EQUAL(message, "");
  BOOST_CHECK_EQUAL(scale.isValid(), true);
}

BOOST_AUTO_TEST_CASE(xml2extSignal)
{
  tmtable::ExtSignal extSignal;

  std::string message;
  message = tmtable::xml2extSignal(ext_signal_set_xml.string().c_str(), extSignal);

  BOOST_CHECK_EQUAL(message, "");
  BOOST_CHECK_EQUAL(extSignal.isValid(), true);
}

BOOST_AUTO_TEST_CASE(xml2menu)
{
  tmtable::Menu menu;
  tmtable::Scale scale;
  tmtable::ExtSignal extSignal;

  std::string message;
  message = tmtable::xml2menu(menu_xml.string().c_str(), menu, scale, extSignal);

  BOOST_CHECK_EQUAL(message, "");
  BOOST_CHECK_EQUAL(menu.isValid(), true);
  BOOST_CHECK_EQUAL(scale.isValid(), true);
  BOOST_CHECK_EQUAL(extSignal.isValid(), true);
}

BOOST_AUTO_TEST_CASE(xml2menu_ifstream)
{
  tmtable::Menu menu;
  tmtable::Scale scale;
  tmtable::ExtSignal extSignal;

  std::ifstream ifs(menu_xml.string().c_str());
  std::string message;
  message = tmtable::xml2menu(ifs, menu, scale, extSignal);

  BOOST_CHECK_EQUAL(message, "");
  BOOST_CHECK_EQUAL(menu.isValid(), true);
  BOOST_CHECK_EQUAL(scale.isValid(), true);
  BOOST_CHECK_EQUAL(extSignal.isValid(), true);
}

BOOST_AUTO_TEST_SUITE_END()


// ----------------------------------------------------------------------------
//  unittests for validation.cc
// ----------------------------------------------------------------------------

BOOST_FIXTURE_TEST_SUITE(validation, XSDFixture)

BOOST_AUTO_TEST_CASE(isBin)
{
  tmtable::Row bin;
  BOOST_CHECK_EQUAL(tmtable::isBin(bin), false);

  bin["number"] = "0";
  bin["minimum"] = ""; // missing values
  bin["maximum"] = "";
  BOOST_CHECK_EQUAL(tmtable::isBin(bin), false);

  bin["minimum"] = "0"; // invaild foramtting
  bin["maximum"] = "1024";
  BOOST_CHECK_EQUAL(tmtable::isBin(bin), false);

  bin["minimum"] = "+0.0000000000000000E+00";
  bin["maximum"] = "+1.0240000000000000E+03";
  BOOST_CHECK_EQUAL(tmtable::isBin(bin), true);

  bin["number"] = "foobar"; // invalid type
  BOOST_CHECK_THROW(tmtable::isBin(bin), std::bad_cast);

  bin["number"] = "0";
  bin["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isBin(bin), false);
}

BOOST_AUTO_TEST_CASE(isScale)
{
  tmtable::Row scale;
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), false);

  scale["object"] = "MU";
  scale["type"] = "ET";
  scale["minimum"] = "+0.0000000000000000E+00";
  scale["maximum"] = "+1.0000000000000000E+00";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), false);

  scale["step"] = "+1.0000000000000000E+00";
  scale["n_bits"] = "12";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), true);

  scale["comment"] = "some annotation";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), true);

  scale["scale_id"] = "";
  scale["n_bins"] = "42";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), true);

  scale["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), true);

  scale["step"] = "1";
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), false);

  scale["step"] = "+1.0000000000000000E+00";
  scale["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isScale(scale), false);
}

BOOST_AUTO_TEST_CASE(isScaleSet)
{
  tmtable::Row scaleSet;
  BOOST_CHECK_EQUAL(tmtable::isScaleSet(scaleSet), false);

  scaleSet["name"] = "";
  scaleSet["comment"] = "";
  BOOST_CHECK_EQUAL(tmtable::isScaleSet(scaleSet), true);

  scaleSet["scale_set_id"] = "0";
  scaleSet["is_valid"] = "1";
  scaleSet["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isScaleSet(scaleSet), true);

  scaleSet["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isScaleSet(scaleSet), false);
}

BOOST_AUTO_TEST_CASE(isExtSignal)
{
  tmtable::Row extSignal;
  BOOST_CHECK_EQUAL(tmtable::isExtSignal(extSignal), false);

  extSignal["name"] = "foo";
  extSignal["system"] = "bar";
  extSignal["cable"] = "0";
  extSignal["channel"] = "0";
  BOOST_CHECK_EQUAL(tmtable::isExtSignal(extSignal), true);

  extSignal["description"] = "";
  extSignal["label"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExtSignal(extSignal), true);

  extSignal["ext_signal_id"] = "";
  extSignal["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExtSignal(extSignal), true);

  extSignal["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isExtSignal(extSignal), false);

}

BOOST_AUTO_TEST_CASE(isExtSignalSet)
{
  tmtable::Row extSignalSet;
  BOOST_CHECK_EQUAL(tmtable::isExtSignalSet(extSignalSet), false);

  extSignalSet["name"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExtSignalSet(extSignalSet), true);

  extSignalSet["comment"] = "some annotation";
  BOOST_CHECK_EQUAL(tmtable::isExtSignalSet(extSignalSet), true);

  extSignalSet["ext_signal_set_id"] = "";
  extSignalSet["is_valid"] = "1";
  extSignalSet["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExtSignalSet(extSignalSet), true);

  extSignalSet["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isExtSignalSet(extSignalSet), false);
}

BOOST_AUTO_TEST_CASE(isCut)
{
  tmtable::Row cut;
  BOOST_CHECK_EQUAL(tmtable::isCut(cut), false);

  cut["name"] = "MU-ET";
  cut["object"] = "MU";
  cut["type"] = "ET";
  cut["minimum"] = "+0.0000000000000000E+00";
  cut["maximum"] = "+1.0000000000000000E+00";
  cut["data"] = "";
  BOOST_CHECK_EQUAL(tmtable::isCut(cut), true);

  cut["comment"] = "some annotations";
  BOOST_CHECK_EQUAL(tmtable::isCut(cut), true);

  cut["cut_id"] = "";
  cut["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isCut(cut), true);

  cut["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isCut(cut), false);
}

BOOST_AUTO_TEST_CASE(isObjectRequirement)
{
  tmtable::Row object;
  BOOST_CHECK_EQUAL(tmtable::isObjectRequirement(object), false);

  object["name"] = "MU.ge.10p5+2";
  object["type"] = "MU";
  object["comparison_operator"] = ".ge.";
  object["threshold"] = "+1.0500000000000000E+01";
  object["bx_offset"] = "+2";
  BOOST_CHECK_EQUAL(tmtable::isObjectRequirement(object), true);

  object["comment"] = "some annotations";
  BOOST_CHECK_EQUAL(tmtable::isObjectRequirement(object), true);

  object["requirement_id"] = "";
  object["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isObjectRequirement(object), true);

  object["foobar"] = ""; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isObjectRequirement(object), false);
}

BOOST_AUTO_TEST_CASE(isExternalRequirement)
{
  tmtable::Row external;
  BOOST_CHECK_EQUAL(tmtable::isExternalRequirement(external), false);

  external["name"] = "EXT_";
  external["bx_offset"] = "+0";
  BOOST_CHECK_EQUAL(tmtable::isExternalRequirement(external), true);

  external["comment"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExternalRequirement(external), true);

  external["requirement_id"] = "";
  external["ext_signal_id"] = "";
  external["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isExternalRequirement(external), true);

  external["foobar"] = "42"; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isExternalRequirement(external), false);
}

BOOST_AUTO_TEST_CASE(isAlgorithm)
{
  tmtable::Row algorithm;
  BOOST_CHECK_EQUAL(tmtable::isAlgorithm(algorithm), false);

  algorithm["name"] = "L1";
  algorithm["index"] = "0";
  algorithm["module_id"] = "0";
  algorithm["module_index"] = "0";
  algorithm["expression"] = "MU10";
  BOOST_CHECK_EQUAL(tmtable::isAlgorithm(algorithm), true);

  algorithm["comment"] = "some annotations";
  BOOST_CHECK_EQUAL(tmtable::isAlgorithm(algorithm), true);

  algorithm["algorithm_id"] = "";
  algorithm["datetime"] = "";
  BOOST_CHECK_EQUAL(tmtable::isAlgorithm(algorithm), true);

  algorithm["foobar"] = "42"; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isAlgorithm(algorithm), false);
}

BOOST_AUTO_TEST_CASE(isMenu)
{
  tmtable::Row menu;
  BOOST_CHECK_EQUAL(tmtable::isMenu(menu), false);

  menu["ancestor_id"] = "0";
  menu["name"] = "L1Menu_";
  menu["uuid_menu"] = "00000000-0000-0000-0000-000000000000";
  menu["uuid_firmware"] = "00000000-0000-0000-0000-000000000000";
  menu["global_tag"] = "0";
  menu["grammar_version"] = "0.5";
  menu["n_modules"] = "0";
  menu["is_valid"] = "1";
  menu["is_obsolete"] = "0";
  BOOST_CHECK_EQUAL(tmtable::isMenu(menu), true);

  menu["foobar"] = "42"; // fault injection
  BOOST_CHECK_EQUAL(tmtable::isMenu(menu), false);
}

BOOST_AUTO_TEST_SUITE_END()
