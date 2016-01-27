/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_ext_signal_set_hh
#define complex_ext_signal_set_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>

#include "tmXsd/gen-xsd-type/complex-ext_signal.hh"

namespace tmxsd
{
  struct ext_signal_set
  {
    /** constructor */
    ext_signal_set() :
      name_(), comment_(), ext_signal_(), ext_signal_set_id_(),
      datetime_(), is_valid_(), debug_()
      { if (debug_) std::cout << "ext_signal_set::ctor" << std::endl; }

    /** destructor */
    virtual ~ext_signal_set()
      { if (debug_) std::cout << "ext_signal_set::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    typedef std::vector<tmxsd::ext_signal> ext_signals;
    const ext_signals& ext_signal() const { return ext_signal_; }
    ext_signals& ext_signal() { return ext_signal_; }

    unsigned int ext_signal_set_id() const { return ext_signal_set_id_; }
    void ext_signal_set_id(const unsigned int x) { ext_signal_set_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool is_valid() const { return is_valid_; }
    void is_valid(const bool x) { is_valid_ = x; }
    
    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
    std::string name_;                /**< name */
    std::string comment_;             /**< comment */
    ext_signals ext_signal_;          /**< array of ext_signals */
    unsigned int ext_signal_set_id_;  /**< ext_signal_set_id in DB */
    std::string datetime_;            /**< datetime in DB */
    bool is_valid_;                   /**< valid flag */
    bool debug_;                      /**< debug flag */

  };  // struct ext_signal_set

} // namespace tmxsd

#endif // complex_ext_signal_set_hh
/* eof */
