/**
 * @author      Takashi Matsushita
 * Created:     04 Jul 2014
 */

/** @todo nope */

#ifndef Cut_hh
#define Cut_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <vector>
#include <string>
#include <map>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Cut {

// cuts for objects
const char ETA[] = "ETA";
const char PHI[] = "PHI";
const char CHG[] = "CHG";
const char QLTY[] = "QLTY";
const char ISO[] = "ISO";

const char MU_ETA[] = "MU-ETA";   /**< muon eta */
const char MU_PHI[] = "MU-PHI";   /**< muon phi */
const char MU_CHG[] = "MU-CHG";   /**< muon charge */
const char MU_QLTY[] = "MU-QLTY"; /**< muon quality */
const char MU_ISO[] = "MU-ISO";   /**< muon isolation */

const char EG_ETA[] = "EG-ETA";   /**< egamma eta */
const char EG_PHI[] = "EG-PHI";   /**< egamma phi */
const char EG_QLTY[] = "EG-QLTY"; /**< egamma quality */
const char EG_ISO[] = "EG-ISO";   /**< egamma isolation */

const char TAU_ETA[] = "TAU-ETA";   /**< tau eta */
const char TAU_PHI[] = "TAU-PHI";   /**< tau phi */
const char TAU_QLTY[] = "TAU-QLTY"; /**< tau quality */
const char TAU_ISO[] = "TAU-ISO";   /**< tau isolation */

const char JET_ETA[] = "JET-ETA";   /**< jet eta */
const char JET_PHI[] = "JET-PHI";   /**< jet phi */
const char JET_QLTY[] = "JET-QLTY"; /**< jet quality */

const char ETM_PHI[] = "ETM-PHI"; /**< ETM phi */
const char HTM_PHI[] = "HTM-PHI"; /**< HTM phi */


// cuts for functions
const char MASS[] = "MASS";     /**< mass */
const char DETA[] = "DETA";     /**< delta eta */
const char DPHI[] = "DPHI";     /**< delta phi */
const char DR[] = "DR";         /**< delta R */
const char CHGCOR[] = "CHGCOR"; /**< charge correlation  */


// character set for cuts
const char CHARSET_CUT[] = "a-zA-Z0-9_-";
const char CHARSET_CUTS[] = "a-zA-Z0-9_,-";



/**
  * This struct implements data structure for a cut
  */
struct Item
{
  std::vector<std::string> name;  /**< list of name of the cut */
  std::string message;

  Item() : name(), message() {}

  /** print name of the cuts */
  void print();

}; // struct Item


/** parse cut expression
  *
  * @param cut [in] cut expression
  * @param item [in/out] Item instance to store thre result
  * @return true if parsing was successfull otherwise false
  */
bool parser(const std::string& cut,
            Cut::Item& item);


/** list of names */
typedef std::map<std::string, int> reserved;
extern const reserved cutName;  /**< list of allowed cut name */

} // namespace Cut

#endif // Cut_hh
/* eof */
