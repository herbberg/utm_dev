/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_scale_hh
#define complex_scale_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>

#include "tmXsd/gen-xsd-type/complex-bin.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for scale complex type
 */
  struct scale
  {
    /** constructor */
    scale() :
      object_(), type_(), minimum_(), maximum_(), step_(), n_bits_(),
      bin_(), scale_id_(), datetime_(), n_bins_(), comment_(), debug_()
      { if (debug_) std::cout << "scale::ctor"<< std::endl; }

    /** destructor */
    virtual ~scale()
      { if (debug_) std::cout << "scale::dtor"<< std::endl; }

    // setters and getters
    const std::string& object() const { return object_; }
    void object(const std::string& x) { object_ = x; }

    const std::string& type() const { return type_; }
    void type(const std::string& x) { type_ = x; }

    const std::string& minimum() const { return minimum_; }
    void minimum(const std::string& x) { minimum_ = x; }

    const std::string& maximum() const { return maximum_; }
    void maximum(const std::string& x) { maximum_ = x; }

    const std::string& step() const { return step_; }
    void step(const std::string& x) { step_ = x; }

    unsigned int n_bits() const { return n_bits_; }
    void n_bits(const unsigned int x) { n_bits_ = x; }

    typedef std::vector<tmxsd::bin> bins;
    const bins& bin() const { return bin_; }
    bins& bin() { return bin_; }

    unsigned int scale_id() const { return scale_id_; }
    void scale_id(const unsigned int x) { scale_id_ = x; }

    const std::string& datetime() const {  return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    unsigned int n_bins() const { return n_bins_; }
    void n_bins(const unsigned int x) { n_bins_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string object_;    /**< type of object */
      std::string type_;      /**< type of scale */
      std::string minimum_;   /**< minimum value */
      std::string maximum_;   /**< maximum value */
      std::string step_;      /**< incremental step */
      unsigned int n_bits_;   /**< number of bits */
      bins bin_;              /**< array of bin */
      unsigned int scale_id_; /**< scale_id in DB */
      std::string datetime_;  /**< datetime in DB */
      unsigned int n_bins_;   /**< number of bins */
      std::string comment_;   /**< comment */
      bool debug_;            /**< debug flag */

  }; // struct scale

} // namespace tmxsd

#endif // complex_scale_hh
/* eof */
