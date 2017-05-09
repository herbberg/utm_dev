/**
 * @author      Takashi Matsushita
 * Created:     04 Jul 2014
 */

/** @todo nope */

#ifndef tmGrammar_Cut_hh
#define tmGrammar_Cut_hh

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
const char SLICE[] = "SLICE";

const char MU_ETA[] = "MU-ETA";     /**< muon eta */
const char MU_PHI[] = "MU-PHI";     /**< muon phi */
const char MU_CHG[] = "MU-CHG";     /**< muon charge */
const char MU_QLTY[] = "MU-QLTY";   /**< muon quality */
const char MU_ISO[] = "MU-ISO";     /**< muon isolation */
const char MU_SLICE[] = "MU-SLICE"; /**< muon collection slice */

const char EG_ETA[] = "EG-ETA";     /**< egamma eta */
const char EG_PHI[] = "EG-PHI";     /**< egamma phi */
const char EG_QLTY[] = "EG-QLTY";   /**< egamma quality */
const char EG_ISO[] = "EG-ISO";     /**< egamma isolation */
const char EG_SLICE[] = "EG-SLICE"; /**< egamma collection slice */

const char TAU_ETA[] = "TAU-ETA";     /**< tau eta */
const char TAU_PHI[] = "TAU-PHI";     /**< tau phi */
const char TAU_QLTY[] = "TAU-QLTY";   /**< tau quality */
const char TAU_ISO[] = "TAU-ISO";     /**< tau isolation */
const char TAU_SLICE[] = "TAU-SLICE"; /**< tau collection slice */

const char JET_ETA[] = "JET-ETA";     /**< jet eta */
const char JET_PHI[] = "JET-PHI";     /**< jet phi */
const char JET_QLTY[] = "JET-QLTY";   /**< jet quality */
const char JET_SLICE[] = "JET-SLICE"; /**< jet collection slice */

const char ETM_PHI[] = "ETM-PHI"; /**< ETM phi */
const char HTM_PHI[] = "HTM-PHI"; /**< HTM phi */
const char ETMHF_PHI[] = "ETMHF-PHI"; /**< ETM phi */


// cuts for functions
const char MASS[] = "MASS";       /**< mass */
const char DETA[] = "DETA";       /**< delta eta */
const char DPHI[] = "DPHI";       /**< delta phi */
const char DR[] = "DR";           /**< delta R */
const char CHGCOR[] = "CHGCOR";   /**< charge correlation  */
const char TBPT[] = "TBPT";       /**< two body Pt  */
const char ORMDETA[] = "ORMDETA"; /**< delta eta overlap removal */
const char ORMDPHI[] = "ORMDPHI"; /**< delta phi overlap removal */
const char ORMDR[] = "ORMDR";     /**< delta R overlap removal */

// character set for cuts
const char CHARSET_CUT[] = "a-zA-Z0-9_-";
const char CHARSET_CUTS[] = "a-zA-Z0-9_,-"; // TODO: possible weak precept



/**
  * This struct implements data structure for a cut
  */
struct Item
{
  std::vector<std::string> name;  /**< list of name of the cut */
  std::string message;

  Item() : name(), message() {}

  /** print name of the cuts */
  std::ostream& print(std::ostream& os = std::cout) const;

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
extern const reserved cutName;  /**< list of allowed cut names */

} // namespace Cut

#endif // tmGrammar_Cut_hh
/* eof */
