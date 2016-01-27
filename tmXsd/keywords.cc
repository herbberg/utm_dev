/*====================================================================*
 * declarations  
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <stdexcept>

#include "tmUtil/tmUtil.hh"
#include "tmXsd/keywords.hh"

/*====================================================================*
 * implementation
 *====================================================================*/
// ---------------------------------------------------------------------
// static variables
// ---------------------------------------------------------------------
namespace tmxsd
{
/** @cond INTERNAL */
const std::pair<std::string, bool>
binKey_[] = {
  std::make_pair("number", true),
  std::make_pair("minimum", true),
  std::make_pair("maximum", true),
  std::make_pair("bin_id", false),
  std::make_pair("scale_id", false),
  };
/** @endcond */

const std::map<std::string, bool> binKey(
    binKey_,
    binKey_ + sizeof(binKey_)/sizeof(binKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
scaleKey_[] = {
  std::make_pair("object", true),
  std::make_pair("type", true),
  std::make_pair("minimum", true),
  std::make_pair("maximum", true),
  std::make_pair("step", true),
  std::make_pair("n_bits", true),
  std::make_pair("comment", false),
  std::make_pair("scale_id", false),
  std::make_pair("datetime", false),
  std::make_pair("n_bins", false),
  };
/** @endcond */

const std::map<std::string, bool> scaleKey(
    scaleKey_,
    scaleKey_ + sizeof(scaleKey_)/sizeof(scaleKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
scaleSetKey_[] = {
  std::make_pair("name", true),
  std::make_pair("comment", false),
  std::make_pair("scale_set_id", false),
  std::make_pair("datetime", false),
  std::make_pair("is_valid", false),
  };
/** @endcond */

const std::map<std::string, bool> scaleSetKey(
    scaleSetKey_,
    scaleSetKey_ + sizeof(scaleSetKey_)/sizeof(scaleSetKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
extSignalKey_[] =
{
  std::make_pair("name", true),
  std::make_pair("system", true),
  std::make_pair("cable", true),
  std::make_pair("channel", true),
  std::make_pair("description", false),
  std::make_pair("label", false),
  std::make_pair("ext_signal_id", false),
  std::make_pair("datetime", false),
};
/** @endcond */


const std::map<std::string, bool> extSignalKey(
    extSignalKey_,
    extSignalKey_ + sizeof(extSignalKey_)/sizeof(extSignalKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
extSignalSetKey_[] =
{
  std::make_pair("name", true),
  std::make_pair("comment", false),
  std::make_pair("ext_signal_set_id", false),
  std::make_pair("datetime", false),
  std::make_pair("is_valid", false),
};
/** @endcond */


const std::map<std::string, bool> extSignalSetKey(
    extSignalSetKey_,
    extSignalSetKey_ + sizeof(extSignalSetKey_)/sizeof(extSignalSetKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
objectRequirementKey_[] = {
  std::make_pair("name", true),
  std::make_pair("type", true),
  std::make_pair("comparison_operator", true),
  std::make_pair("threshold", true),
  std::make_pair("bx_offset", true),
  std::make_pair("comment", false),
  std::make_pair("requirement_id", false),
  std::make_pair("datetime", false),
  };
/** @endcond */

const std::map<std::string, bool> objectRequirementKey(
    objectRequirementKey_,
    objectRequirementKey_ + sizeof(objectRequirementKey_)/sizeof(objectRequirementKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
externalRequirementKey_[] = {
  std::make_pair("name", true),
  std::make_pair("bx_offset", true),
  std::make_pair("comment", false),
  std::make_pair("requirement_id", false),
  std::make_pair("ext_signal_id", false),
  std::make_pair("datetime", false),
  };
/** @endcond */

const std::map<std::string, bool> externalRequirementKey(
    externalRequirementKey_,
    externalRequirementKey_ + sizeof(externalRequirementKey_)/sizeof(externalRequirementKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
cutKey_[] =
{
  std::make_pair("name", true),
  std::make_pair("object", true),
  std::make_pair("type", true),
  std::make_pair("minimum", true),
  std::make_pair("maximum", true),
  std::make_pair("data", true),
  std::make_pair("comment", false),
  std::make_pair("cut_id", false),
  std::make_pair("datetime", false),
};
/** @endcond */


const std::map<std::string, bool> cutKey(
    cutKey_,
    cutKey_ + sizeof(cutKey_)/sizeof(cutKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
algorithmKey_[] =
{
  std::make_pair("name", true),
  std::make_pair("expression", true),
  std::make_pair("index", true),
  std::make_pair("module_id", true),
  std::make_pair("module_index", true),
  std::make_pair("comment", false),
  std::make_pair("algorithm_id", false),
  std::make_pair("datetime", false),
};
/** @endcond */


const std::map<std::string, bool> algorithmKey(
    algorithmKey_,
    algorithmKey_ + sizeof(algorithmKey_)/sizeof(algorithmKey_[0])
    );


/** @cond INTERNAL */
const std::pair<std::string, bool>
menuKey_[] =
{
  std::make_pair("ancestor_id", true),
  std::make_pair("name", true),
  std::make_pair("uuid_menu", true),
  std::make_pair("uuid_firmware", true),
  std::make_pair("global_tag", true),
  std::make_pair("grammar_version", true),
  std::make_pair("n_modules", true),
  std::make_pair("is_valid", true),
  std::make_pair("is_obsolete", true),
  std::make_pair("comment", false),
  std::make_pair("menu_id", false),
  std::make_pair("datetime", false),
};
/** @endcond */


const std::map<std::string, bool> menuKey(
    menuKey_,
    menuKey_ + sizeof(menuKey_)/sizeof(menuKey_[0])
    );

} // namespace tmxsd


// ---------------------------------------------------------------------
// methods
// ---------------------------------------------------------------------
template<typename T>
const T tmxsd::getValue(const std::map<std::string, T>&map,
                        const std::string& key)
{
  typename std::map<std::string, T>::const_iterator cit = map.find(key);
  if (cit == map.end())
  {
    std::string error("err> tmxsd::getValue() key '");
    error += key + "' not found";
    throw std::runtime_error(error);
  }

  return cit->second;
}


template<typename To, typename From>
const To tmxsd::getValue(const std::map<std::string, From>&map,
                         const std::string& key)
{
  typename std::map<std::string, From>::const_iterator cit = map.find(key);
  if (cit == map.end())
  {
    std::string error("err> tmxsd::getValue() key '");
    error += key + "' not found";
    throw std::runtime_error(error);
  }

  return tmutil::convert<To>(cit->second);
}


bool
tmxsd::validateKeys(const std::map<std::string, bool> keys,
                    const std::map<std::string, std::string> map)
{
  for (std::map<std::string, bool>::const_iterator cit = keys.begin();
       cit != keys.end(); cit++)
  {
    if (not cit->second) continue;

    try
    {
      std::string str = getValue(map, cit->first);
    }
    catch (std::runtime_error& e)
    {
      TM_LOG_ERR("required value is missing: " << cit->first);
      return false;
    }
  }


  for (std::map<std::string, std::string>::const_iterator cit = map.begin();
       cit != map.end(); cit++)
  {
    try
    {
      getValue(keys, cit->first);
    }
    catch (std::runtime_error& e)
    {
      TM_LOG_ERR("unknown value is given: " << cit->first);
      return false;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// template instantiation
// ---------------------------------------------------------------------
template const int
tmxsd::getValue<int, std::string>(const std::map<std::string, std::string>& map, const std::string& key);

template const unsigned int
tmxsd::getValue<unsigned int, std::string>(const std::map<std::string, std::string>& map, const std::string& key);

template const bool
tmxsd::getValue<bool, std::string>(const std::map<std::string, std::string>& map, const std::string& key);

/* eof */
