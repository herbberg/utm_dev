/**
 * @author      Takashi Matsushita
 * Created:     21 Aug 2014
 */

/** @todo */

#ifndef tmxsd_keywords_hh
#define tmxsd_keywords_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <map>
#include <string>


namespace tmxsd
{
/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/** element/attribute names of SCALE_SET table, <name, mandatory> */
extern const std::map<std::string, bool> scaleSetKey;

/** element/attribute names of SCALE table, <name, mandatory> */
extern const std::map<std::string, bool> scaleKey;

/** element/attribute names of BIN table, <name, mandatory> */
extern const std::map<std::string, bool> binKey;

/** element/attribute names of EXT_SIGNAL_SET table, <name, mandatory> */
extern const std::map<std::string, bool> extSignalSetKey;

/** element/attribute names of EXT_SIGNAL table, <name, mandatory> */
extern const std::map<std::string, bool> extSignalKey;

/** element/attribute names of OBJECT/REQUIREMENT tables, <name, mandatory> */
extern const std::map<std::string, bool> objectRequirementKey;

/** element/attribute names of EXTERNAL/REQUIREMENT tables, <name, mandatory> */
extern const std::map<std::string, bool> externalRequirementKey;

/** element/attribute names of CUT table, <name, mandatory> */
extern const std::map<std::string, bool> cutKey;

/** element/attribute names of ALGORITHM table, <name, mandatory> */
extern const std::map<std::string, bool> algorithmKey;

/** element/attribute names of MENU table, <name, mandatory> */
extern const std::map<std::string, bool> menuKey;


/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
/**
 *  get a value of type T associated with the given key
 *
 *  @param  map [in] a map data structure of type <std::string, T>
 *  @param  key [in] a key for the map
 *  @return value of type T
 */
template<typename T>
const T getValue(const std::map<std::string, T>& map,
                 const std::string& key);


/**
 *  get a value of type To associated with the given key
 *
 *  @param  map [in] a map data structure of type <std::string, From>
 *  @param  key [in] a key for the map
 *  @return value of type To
 */
template<typename To, typename From>
const To getValue(const std::map<std::string, From>& map,
                  const std::string& key);


/**
 *  checks if the mandatory keys are in the map and no extra keys are defined in the map
 *
 *  @param  keys [in] a map data structure of type <name, mandatory>
 *  @param  map [in] a map data structure to be tested for its keys
 *  @return true if the map contains only the allowed and mandatory keys, false otherwise
 */
bool validateKeys(const std::map<std::string, bool> keys,
                  const std::map<std::string, std::string> map);
}
#endif // tmxsd_keywords_hh
/* eof */
