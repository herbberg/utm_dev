/**
 * @author      Takashi Matsushita
 * Created:     8 Nov 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esCut_hh
#define tmEventSetup_esCut_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>

#include "tmEventSetup/esTypes.hh"
#include "tmEventSetup/esCutValue.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{
/**
 *  This class implements data structure for Cut
 */
class esCut
{
  public:
    // ctor
    esCut()
      : name_(), object_type_(), cut_type_(),
        minimum_(), maximum_(), data_() { };

    // dtor
    virtual ~esCut() { };


    /** set cut name */
    void setName(const std::string& x) { name_ = x; };

    /** set object type */
    void setObjectType(const int x) { object_type_ = x; };

    /** set cut type */
    void setCutType(const int x) { cut_type_ = x; };

    /** set minimum value of cut range (double) */
    void setMinimum(const double x) { minimum_.value = x; };

    /** set minimum value of cut range (HW index) */
    void setMinimum(const unsigned int x) { minimum_.index = x; };

    /** set minimum value of cut range (esCutValue struct) */
    void setMinimum(const esCutValue& x) { minimum_ = x; };

    /** set maximum value of cut range (double) */
    void setMaximum(const double x) { maximum_.value = x; };

    /** set maximum value of cut range (HW index) */
    void setMaximum(const unsigned int x) { maximum_.index = x; };

    /** set maximum value of cut range (esCutValue struct) */
    void setMaximum(const esCutValue& x) { maximum_ = x; };

    /** get cut name */
    const std::string& getName() const { return name_; };

    /** get target object type : combination of esObjectType and esFunctionType enums */
    const int getObjectType() const { return object_type_; };

    /** get cut type */
    const int getCutType() const { return cut_type_; };

    /** get esCutValue struct for minimum value of cut range */
    const tmeventsetup::esCutValue& getMinimum() const { return minimum_; };

    /** get esCutValue struct for maximum value of cut range */
    const tmeventsetup::esCutValue& getMaximum() const { return maximum_; };

    /** get esCutValue struct for minimum value of cut range */
    const double getMinimumValue() const { return minimum_.value; };

    /** get esCutValue struct for maximum value of cut range */
    const double getMaximumValue() const { return maximum_.value; };

    /** get esCutValue struct for minimum value of cut range */
    const unsigned int getMinimumIndex() const { return minimum_.index; };

    /** get esCutValue struct for maximum value of cut range */
    const unsigned int getMaximumIndex() const { return maximum_.index; };

    /** get data */
    const std::string& getData() const { return data_; };

    /** get key */
    const std::string& getKey() const { return key_; };


  protected:
    std::string name_;          /**< name of cut */
    int object_type_;           /**< target object type */
    int cut_type_;              /**< type of cut */
    esCutValue minimum_;        /**< minimum value of cut range */
    esCutValue maximum_;        /**< maximum value of cut range */
    std::string data_;          /**< data for charge/quality/isolation/charge correlation */
    std::string key_;           /**< key for accessing a scale */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esCut_hh
/* eof */
