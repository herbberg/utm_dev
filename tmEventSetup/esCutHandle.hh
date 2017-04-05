/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esCutHandle_hh
#define tmEventSetup_esCutHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>

#include "tmTable/tmTable.hh"
#include "tmEventSetup/esCut.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{
/**
 *  This class implements data structure for Cut
 */
class esCutHandle : public esCut
{
  public:
    // ctor
    esCutHandle() { };
    esCutHandle(const tmtable::Row& cut);

    // dtor
    virtual ~esCutHandle() { };

    /** print the contents of instance */
    void print() const;

    static void print(const esCut&);

    /** set data */
    void setData(const std::string& data);

    /** get a key for accessing a scale */
    void setKey();
};

} // namespace tmeventsetup
#endif // tmEventSetup_esCutHandle_hh
/* eof */
