/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esCutValue_hh
#define tmEventSetup_esCutValue_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <limits>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for CutValue
 */
struct esCutValue
{
  // ctor
  esCutValue()
    : value(std::numeric_limits<double>::max()),
      index(std::numeric_limits<unsigned int>::max()) { };

  double value;               /**< cut value */
  unsigned int index;         /**< HW index for the cut value */
  unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esCutValue_hh
/* eof */
