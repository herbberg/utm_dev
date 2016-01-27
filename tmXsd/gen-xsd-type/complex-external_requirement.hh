/**
 * @author      Takashi Matsushita
 * Created:     14 Sep 2014
 */

/** @todo nope */

#ifndef complex_external_requirement_hh
#define complex_external_requirement_hh

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
 * This struct implements data structure for external_requirement complex type
 */
  struct external_requirement
  {
    /** constructor */
    external_requirement() :
      name_(), bx_offset_(), comment_(), requirement_id_(), ext_signal_id_(),
      datetime_(), debug_()
      { if (debug_) std::cout << "external_requirement::ctor" << std::endl; }

    /** destructor */
    virtual ~external_requirement()
      { if (debug_) std::cout << "external_requirement::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    int bx_offset() const { return bx_offset_; }
    void bx_offset(const int x) { bx_offset_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    unsigned int requirement_id() const { return requirement_id_; }
    void requirement_id(const unsigned int x) { requirement_id_ = x; }

    unsigned int ext_signal_id() const { return ext_signal_id_; }
    void ext_signal_id(const unsigned int x) { ext_signal_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string name_;                /**< name */
      int bx_offset_;                   /**< bunch crossing offset */
      std::string comment_;             /**< comment */
      unsigned int requirement_id_;     /**< requirement id in DB */
      unsigned int ext_signal_id_;      /**< ext_signal_id in DB */
      std::string datetime_;            /**< datetime in DB */
      bool debug_;                      /**< debug flag */

  }; // struct external_requirement

} // namespace tmxsd

#endif // complex_external_requirement_hh
/* eof */
