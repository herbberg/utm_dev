/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esCondition_hh
#define tmEventSetup_esCondition_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>

#include "tmEventSetup/esTypes.hh"
#include "tmEventSetup/esCut.hh"
#include "tmEventSetup/esObject.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{


/**
 *  This class implements data structure for Condition
 */
class esCondition
{
  public:
    // ctor
    esCondition()
      : name_(), type_(Undef),
        objects_(), cuts_() { };

    // dtor
    virtual ~esCondition() { };

    /** set condition name */
    void setName(const std::string& x) { name_ = x; };

    /** set condition type */
    void setType(const int x) { type_ = x; };

    /** get condition name */
    const std::string& getName() const { return name_; };

    /** get condition type */
    const int getType() const { return type_; };

    /** get objects associated with the condition */
    const std::vector<tmeventsetup::esObject>& getObjects() const { return objects_; };

    /** get cuts associated with the condition */
    const std::vector<tmeventsetup::esCut>& getCuts() const { return cuts_; };


  protected:
    std::string name_;                /**< name of condition */
    int type_;                        /**< type of condition */
    std::vector<esObject> objects_;   /**< list of objects used in condition */
    std::vector<esCut> cuts_;         /**< list of cuts applied on condition */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esCondition_hh
/* eof */
