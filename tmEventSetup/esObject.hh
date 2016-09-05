/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esObject_hh
#define tmEventSetup_esObject_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <limits>

#include "tmEventSetup/esTypes.hh"
#include "tmEventSetup/esCut.hh"

/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */
namespace tmeventsetup
{

/**
 *  This class implements data structure for Object
 */
class esObject
{
  public:
    // ctor
    esObject()
      : name_(), type_(), comparison_operator_(), bx_offset_(), threshold_(),
        ext_signal_name_(), ext_channel_id_(std::numeric_limits<unsigned int>::max()),
        cuts_(), version(0) { };

    // dtor
    virtual ~esObject() { };

    /** set object name */
    void setName(const std::string& x) { name_ = x; };

    /** set object type */
    void setType(const int x) { type_ = x; };

    /** set comparison operator for threshold */
    void setComparisonOperator(const int x) { comparison_operator_ = x; };

    /** set BX offset of the object */
    void setBxOffset(const int x) { bx_offset_ = x; };

    /** set Et/pT threshold in GeV */
    void setThreshold(double x) { threshold_ = x; };

    /** set external name */
    void setExternalSignalName(const std::string& x) { ext_signal_name_ = x; };

    /** set external channel id */
    void setExternalChannelId(const unsigned int x) { ext_channel_id_ = x; };

    /** set cuts */
    void setCuts(const std::vector<esCut>& x) { cuts_ = x; };

    /** get object name */
    const std::string& getName() const { return name_; };

    /** get object type */
    const int getType() const { return type_; };

    /** get comparison operator for threshold cut */
    const int getComparisonOperator() const { return comparison_operator_ ; };

    /** get BX offset of the object */
    const int getBxOffset() const { return bx_offset_; };

    /** get Et/pT threshold in GeV */
    const double getThreshold() const { return threshold_; };

    /** get external name */
    const std::string& getExternalSignalName() const { return ext_signal_name_; };

    /** get external channel id */
    const unsigned int getExternalChannelId() const { return ext_channel_id_; };

    /** get cuts on the object */
    const std::vector<tmeventsetup::esCut>& getCuts() const { return cuts_; };


  protected:
    std::string name_;                          /**< name of object */
    int type_;                                  /**< type of object */
    int comparison_operator_;                   /**< comparison operator for threshold cut */
    int bx_offset_;                             /**< bunch crossing  offset of object */
    double threshold_;                          /**< threshold in GeV */
    std::string ext_signal_name_;               /**< name of extenal signal, only valid when esObjectType == EXT */
    unsigned int ext_channel_id_;               /**< channel id of external signal, only valid when esObjectType == EXT */
    std::vector<esCut> cuts_;                   /**< list of cuts applied on object */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esObject_hh
/* eof */
