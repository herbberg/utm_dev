/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esScaleHandle_hh
#define tmEventSetup_esScaleHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmTable/tmTable.hh"
#include "tmEventSetup/esScale.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Scale
 */
class esScaleHandle : public esScale
{
  public:
    // ctor
    esScaleHandle() { };
    esScaleHandle(const tmtable::Row& scale);

    // dtor
    virtual ~esScaleHandle() { };

    /** add bin to the scale */
    void addBin(const esBin& x) { bins_.push_back(x); };

    /** print the contents of the instance */
    void print() const;

    /** sort the esBin vector with esBin.minimum */
    void sortBins();

};

} // namespace tmeventsetup
#endif // tmEventSetup_esScaleHandle_hh
/* eof */
