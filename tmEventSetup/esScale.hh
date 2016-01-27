/**
 * @author      Takashi Matsushita
 * Created:     9 Nov 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esScale_hh
#define tmEventSetup_esScale_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <map>
#include <string>
#include <vector>

#include "tmEventSetup/esTypes.hh"
#include "tmEventSetup/esBin.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Scale
 */
class esScale
{
  public:
    // ctor
    esScale()
      : name_(), object_(), type_(), minimum_(), maximum_(),
        step_(), n_bits_(), bins_() { };

    // dtor
    virtual ~esScale() { };

    /** get scale name */
    const std::string& getName() const { return name_; };

    /** get target object type */
    int getObjectType() const { return object_; };

    /** get scale type */
    int getScaleType() const { return type_; };

    /** get minimum value of the scale */
    double getMinimum() const { return minimum_; };

    /** get maximum value of the scale */
    double getMaximum() const { return maximum_; };

    /** get step size of linear scale */
    double getStep() const { return step_; };

    /** get number of bits for the scale */
    unsigned int getNbits() const { return n_bits_; };

    /** get bins for the scale */
    const std::vector<tmeventsetup::esBin>& getBins() const { return bins_; };


  protected:
    std::string name_;        /**< name of scale */
    int object_;              /**< type of object */
    int type_;                /**< type of scale */
    double minimum_;          /**< minimum value of scale */
    double maximum_;          /**< maximum value of scale */
    double step_;             /**< step size of linear scale */
    unsigned int n_bits_;     /**< number of bits for scale */
    std::vector<esBin> bins_; /**< array of esBin */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esScale_hh
/* eof */
