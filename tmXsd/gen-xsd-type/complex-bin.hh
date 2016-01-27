/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_bin_hh
#define complex_bin_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for bin complex type
 */
  struct bin
  {
    /** constructor */
    bin() :
      number_(), minimum_(), maximum_(), bin_id_(), scale_id_(), debug_()
      { if (debug_) std::cout << "bin::ctor" << std::endl; }

    /** destructor */
    virtual ~bin()
      { if (debug_) std::cout << "bin::dtor" << std::endl; }

    // setters and getters
    const std::string& minimum() const { return minimum_; }
    void minimum(const std::string& x) { minimum_ = x; }

    const std::string& maximum() const { return maximum_; }
    void maximum(const std::string& x) { maximum_ = x; }

    unsigned int number() const { return number_; }
    void number(const unsigned int x) { number_ = x; }

    unsigned int bin_id() const { return bin_id_; }
    void bin_id(const unsigned int x) { bin_id_ = x; }

    unsigned int scale_id() const { return scale_id_; }
    void scale_id(const unsigned int x) { scale_id_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      unsigned int number_;   /**< bin number */
      std::string minimum_;   /**< bin minimum */
      std::string maximum_;   /**< bin maximum */
      unsigned int bin_id_;   /**< bin_id in DB */
      unsigned int scale_id_; /**< scale_id in DB */
      bool debug_;            /**< debug flag */

  }; // struct bin

} // namespace tmxsd

#endif // complex_bin_hh
/* eof */
