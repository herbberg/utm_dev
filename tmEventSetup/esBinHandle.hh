/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esBinHandle_hh
#define tmEventSetup_esBinHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmEventSetup/esBin.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Bin
 */
class esBinHandle : public esBin
{
  public:
    // ctor
    esBinHandle() { }
    esBinHandle(const unsigned int id, 
                const double min,
                const double max)
      : esBin(id, min, max) { };

    // dtor
    virtual ~esBinHandle() { };

    /** print the contents of the instance */
    void print() const;

    static void print(const esBin& bin);
};

} // namespace tmeventsetup
#endif // tmEventSetup_esBinHandle_hh
/* eof */
