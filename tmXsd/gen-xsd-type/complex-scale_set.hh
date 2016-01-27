/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_scale_set_hh
#define complex_scale_set_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>

#include "tmXsd/gen-xsd-type/complex-scale.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for bin complex type
 */
  struct scale_set
  {
    /** constructor */
    scale_set() :
      name_(), scale_(), scale_set_id_(), datetime_(), is_valid_(),
      comment_(), debug_()
      { if (debug_) std::cout << "scale_set::ctor" << std::endl; }

    /** destructor */
    virtual ~scale_set()
      { if (debug_) std::cout << "scale_set::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    typedef std::vector<tmxsd::scale> scales;
    const scales& scale() const { return scale_; }
    scales& scale() { return scale_; }

    unsigned int scale_set_id() const { return scale_set_id_; }
    void scale_set_id(const unsigned int x) { scale_set_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool is_valid() const { return is_valid_; }
    void is_valid(const bool x) { is_valid_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string name_;          /**< name */
      scales scale_;              /**< array of scale */
      unsigned int scale_set_id_; /**< scale_set_id in DB */
      std::string datetime_;      /**< datetime in DB */
      bool is_valid_;             /**< valid flag */
      std::string comment_;       /**< comment */
      bool debug_;                /**< debug flag */

  }; // struct scale_set

} // namespace tmxsd

#endif // complex_scale_set_hh
/* eof */
