/**
 * @author      Takashi Matsushita
 * Created:     13 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_tmEventSetup_hh
#define tmEventSetup_tmEventSetup_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <map>
#include <sstream>

#include "tmEventSetup/esTriggerMenuHandle.hh"

/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{
  class esTriggerMenu;

  /** retrieve trigger menu information from an xml file
    *
    * @param path [in] path to a menu xml file
    * @return pointer to esTriggerMenu class
    */
  const esTriggerMenu* getTriggerMenu(const std::string& path);

  /** retrieve trigger menu information from an xml file
    *
    * @param path [in] std::istringstream for the menu xml file
    * @return pointer to esTriggerMenu class
    */
  const esTriggerMenu* getTriggerMenu(std::istringstream& iss);

  /** retrieve value from map with given key
    *
    * @param map [in] string map
    * @param key [in] string key
    * @return value
    */
  std::string getValue(const std::map<std::string, std::string> map,
                       const std::string& key);

  /** get hash value of the given text
    *
    * @param s [in] text
    */
  long getHash(const std::string& s);


  /** get hash value of the given text in unsigned long
    *
    * @param s [in] text
    */
  unsigned long getHashUlong(const std::string& s);


  /** endian- and alignment-neutral MurmurHash2 by Austin Appleby
   *  https://github.com/aappleby/smhasher/
   *
   *  @param s [in] text
   */
  unsigned long getMmHashN(const std::string& s);


  /** get external signal name
    *
    * @param name [in] external condition name
    * @return external signal name
    */
  std::string getExternalName(const std::string& conditionName);


  /** get type of object combination
    *
    * @param type1 [in] type of the first object
    * @param type2 [in] type of the second object
    * @return esCombinationType
    */
  esCombinationType getObjectCombination(esObjectType type1,
                                         esObjectType type2);
  esCombinationType getObjectCombination(int type1, int type2);


  /** get key, value pair for precisions
   *
    * @param precisions [in/out] map of <string, unsigned int>
    * @param scaleMap [in] scales
   */
  void getPrecisions(std::map<std::string, unsigned int>& precisions,
                     const std::map<std::string, tmeventsetup::esScale>& scaleMap);
#if defined(SWIG)
  void getPrecisionsPy(std::map<std::string, unsigned int>& precisions,
                       const std::map<std::string, tmeventsetup::esScale*>& scaleMap);
#endif


  /** get LUT from double vector
   *
   * @param lut [in/out] look-up table
   * @param array [in] array of double to be converted to lut
   * @param precision [in] number of valid digits after decimal point
   */
  void setLut(std::vector<long long>& lut,
              const std::vector<double>& array,
              const unsigned int precision);

  /** get LUT from scale
   *
   * @param lut [in/out] look-up table
   * @param scale [in] esScale to be converted to lut
   * @param precision [in] number of valid digits after decimal point
   * @return number of valid items in lut
   */
  size_t getLut(std::vector<long long>& lut,
                const tmeventsetup::esScale* scale,
                const unsigned int precision);

  /** get eta scale conversion LUT from scales
   *
   * @param lut [in/out] look-up table
   * @param scale1 [in] calo eta scale
   * @param scale2 [in] muon eta scale
   * @return number of valid items in lut
   */
  size_t getCaloMuonEtaConversionLut(std::vector<long long>& lut,
                                     const tmeventsetup::esScale* scale1,
                                     const tmeventsetup::esScale* scale2);

  /** get phi scale conversion LUT from scales
   *
   * @param lut [in/out] look-up table
   * @param scale1 [in] calo phi scale
   * @param scale2 [in] muon phi scale
   * @return number of valid items in lut
   */
  size_t getCaloMuonPhiConversionLut(std::vector<long long>& lut,
                                     const tmeventsetup::esScale* scale1,
                                     const tmeventsetup::esScale* scale2);

  /** get differences from bin-difference
   *
   * @param array [in/out] differences
   * @param scale1 [in] scale
   * @param scale2 [in] scale
   * @return number of valid items in array
   */
  size_t getDeltaVector(std::vector<double>& array,
                        const tmeventsetup::esScale* scale1,
                        const tmeventsetup::esScale* scale2);

  /** apply sin() to each element of array
   *
   * @param array [in/out] differences
   * @param n [in] number of valid items in array
   */
  void applySin(std::vector<double>& array, const size_t n);

  /** apply cos() to each element of array
   *
   * @param array [in/out] differences
   * @param n [in] number of valid items in array
   */
  void applyCos(std::vector<double>& array, const size_t n);

  /** apply cosh() to each element of array
   *
   * @param array [in/out] differences
   * @param n [in] number of valid items in array
   */
  void applyCosh(std::vector<double>& array, const size_t n);

} // namespace tmeventsetup
#endif // tmEventSetup_tmEventSetup_hh
/* eof */
