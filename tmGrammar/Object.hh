/**
 * @author      Takashi Matsushita
 * Created:     03 Jul 2014
 */

/** @todo rewrite with regex possible */

#ifndef tmGrammar_Object_hh
#define tmGrammar_Object_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <map>
#include <vector>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Object {

// object names
const char MU[] = "MU";   /**< muon */
const char EG[] = "EG";   /**< egamma */
const char TAU[] = "TAU"; /**< tau */
const char JET[] = "JET"; /**< jet */
const char ETT[] = "ETT"; /**< total ET */
const char HTT[] = "HTT"; /**< total HT */
const char ETM[] = "ETM"; /**< missing ET */
const char HTM[] = "HTM"; /**< missing HT */
const char EXT[] = "EXT"; /**< external signal */
const char MBT0HFP[] = "MBT0HFP"; /**< Minimum Bias Threshold 0 HF+ */
const char MBT1HFP[] = "MBT1HFP"; /**< Minimum Bias Threshold 1 HF+ */
const char MBT0HFM[] = "MBT0HFM"; /**< Minimum Bias Threshold 0 HF- */
const char MBT1HFM[] = "MBT1HFM"; /**< Minimum Bias Threshold 1 HF- */
const char ETTEM[] = "ETTEM"; /**< ECAL only total ET */
const char ETMHF[] = "ETMHF"; /**< missing ET with HF */
const char TOWERCOUNT[] = "TOWERCOUNT"; /**< calo tower count */
const char ASYMET[] = "ASYMET"; /**< asymmetry ET */
const char ASYMHT[] = "ASYMHT"; /**< asymmetry HT */
const char ASYMETHF[] = "ASYMETHF"; /**< asymmetry ET with HF */
const char ASYMHTHF[] = "ASYMHTHF"; /**< asymmetry HT with HF */
const char CENT0[] = "CENT0"; /**< centrality 0 */
const char CENT1[] = "CENT1"; /**< centrality 1 */
const char CENT2[] = "CENT2"; /**< centrality 2 */
const char CENT3[] = "CENT3"; /**< centrality 3 */
const char CENT4[] = "CENT4"; /**< centrality 4 */
const char CENT5[] = "CENT5"; /**< centrality 5 */
const char CENT6[] = "CENT6"; /**< centrality 6 */
const char CENT7[] = "CENT7"; /**< centrality 7 */

// comparisons
const char EQ[] = ".eq."; /**< equal */
const char NE[] = ".ne."; /**< not equal */
const char GT[] = ".gt."; /**< greater than */
const char GE[] = ".ge."; /**< greater than or equal to */
const char LT[] = ".lt."; /**< less than */
const char LE[] = ".le."; /**< less than or equal to */

// character set for object
const char CHARSET_OBJECT[] = "a-zA-Z0-9+-.";

/** type of objects */
enum {
  Muon,
  Egamma,
  Tau,
  Jet,
  Scaler,
  Vector,
  External,
  Count,
  Unknown,
  Signal
};


/**
  * This struct implements data structure for an object
  */
struct Item
{
  std::string name;               /**< object name */
  std::string comparison;         /**< comparison operator */
  std::string threshold;          /**< threshold */
  std::string bx_offset;          /**< bunch crossing offset */
  std::vector<std::string> cuts;  /**< cuts for the object */
  int type;                       /**< object type */
  std::string message;

  Item() : name(), comparison(GE), threshold(), bx_offset("+0"), cuts(), type(Unknown), message() {}

  /** prints Item attributes */
  std::ostream& print(std::ostream& os = std::cout) const;

  /** returns object type */
  int getType() const;

  /** checks if the cut expression is valid or not */
  bool isValidCut(const std::string& cut);

  /** returns object name */
  std::string getObjectName() const;

}; // struct Item


/** parse object expression
  *
  * @param object [in] object expression
  * @param item [in/out] Item instance to store the result
  * @return true if parsing was successfull otherwise false
  */
bool parser(const std::string& object,
            Object::Item& item);


/** checks if the given algorithm expression element is an object or not
 *
 * @param element [in] an element of an algorithm expression
 * @return true if the given element is an object
 */
bool isObject(const std::string& element);


/** list of names */
typedef std::map<std::string, int> reserved;
extern const reserved objectName;     /**< list of allowed object names */
extern const reserved comparisonName; /**< list of allowed comparison operator */
extern const reserved signalName;     /**< list of allowed signal names */

} // namespace Object

#endif // tmGrammar_Object_hh
/* eof */
