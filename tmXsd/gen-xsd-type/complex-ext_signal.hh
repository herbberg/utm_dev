/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_ext_signal_hh
#define complex_ext_signal_hh

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
 * This struct implements data structure for ext_signal complex type
 */
  struct ext_signal
  {
    /** constructor */
    ext_signal() :
      name_(), system_(), cable_(), channel_(), description_(),
      label_(), ext_signal_id_(), datetime_(), debug_()
      { if (debug_) std::cout << "ext_signal::ctor" << std::endl; }

    virtual ~ext_signal()
      { if (debug_) std::cout << "ext_signal::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& system() const { return system_; }
    void system(const std::string& x) { system_ = x; }

    unsigned int cable() const { return cable_; }
    void cable(const unsigned int x) { cable_ = x; }

    unsigned int channel() const { return channel_; }
    void channel(const unsigned int x) { channel_ = x; }

    const std::string& description() const { return description_; }
    void description(const std::string& x) { description_ = x; }

    const std::string& label() const { return label_; }
    void label(const std::string& x) { label_ = x; }

    unsigned int ext_signal_id() const { return ext_signal_id_; }
    void ext_signal_id(const unsigned int x) { ext_signal_id_ = x; }

    const std::string& datetime() const {  return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
    std::string name_;            /**< name */
    std::string system_;          /**< name of system providing the signal */
    unsigned int cable_;          /**< cable id of signal */
    unsigned int channel_;        /**< channel id of GT */
    std::string description_;     /**< description of input signal */
    std::string label_;           /**< cable label */
    unsigned int ext_signal_id_;  /**< ext_signal_id in DB */
    std::string datetime_;        /**< datetime in DB */
    bool debug_;                  /**< debug flag */
  };
}
#endif
/* eof */
