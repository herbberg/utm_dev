/**
 * @author      Takashi Matsushita
 * Created:     13 Nov 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esConditionHandle_hh
#define tmEventSetup_esConditionHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmEventSetup/esCondition.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Condition
 */
class esConditionHandle : public esCondition
{
  public:
    // ctor
    esConditionHandle() { };

    // dtor
    virtual ~esConditionHandle() { };

    /** print the contents of instance */
    void print() const;
    static void print(const esCondition& condition);

    /** add object to condition */
    void addObject(esObject& x) { objects_.push_back(x); }

    /** add cut to condition */
    void addCut(esCut& x) { cuts_.push_back(x); }
};

} // namespace tmeventsetup
#endif // tmEventSetup_esConditionHandle_hh
/* eof */
