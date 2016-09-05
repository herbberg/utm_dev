/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esBin_hh
#define tmEventSetup_esBin_hh

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
 *  This class implements data structure for Bin
 */
class esBin
{
  public:
    // ctor
    esBin()
      : hw_index(std::numeric_limits<unsigned int>::max()),
        minimum(std::numeric_limits<double>::min()),
        maximum(std::numeric_limits<double>::max()),
        version(0) { };

    esBin(const unsigned int id, 
          const double min,
          const double max)
      : hw_index(id), minimum(min), maximum(max), version(0) { };

    // dtor
    virtual ~esBin() { };

    unsigned int hw_index;   /**< HW index of bin */
    double minimum;          /**< minimum value of bin */
    double maximum;          /**< maximum value of bin */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esBin_hh
/* eof */
