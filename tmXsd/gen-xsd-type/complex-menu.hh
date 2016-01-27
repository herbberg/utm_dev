/**
 * @author      Takashi Matsushita
 * Created:     19 Sep 2014
 */

/** @todo nope */

#ifndef complex_menu_hh
#define complex_menu_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>

#include "tmXsd/gen-xsd-type/complex-algorithm.hh"
#include "tmXsd/gen-xsd-type/complex-ext_signal_set.hh"
#include "tmXsd/gen-xsd-type/complex-scale_set.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for menu complex type
 */
  struct menu
  {
    /** constructor */
    menu() :
      ancestor_id_(), name_(), uuid_menu_(), uuid_firmware_(), global_tag_(),
      grammar_version_(), n_modules_(), is_valid_(), is_obsolete_(),
      comment_(), algorithm_(), scale_set_(), ext_signal_set_(), menu_id_(),
      datetime_(), debug_()
      { if (debug_) std::cout << "menu::ctor" << std::endl; }

    /** destructor */
    virtual ~menu()
      { if (debug_) std::cout << "menu::dtor" << std::endl; }

    // setters and getters
    unsigned int ancestor_id() const { return ancestor_id_; }
    void ancestor_id(const unsigned int x) { ancestor_id_ = x; }

    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& uuid_menu() const { return uuid_menu_; }
    void uuid_menu(const std::string& x) { uuid_menu_ = x; }

    const std::string& uuid_firmware() const { return uuid_firmware_; }
    void uuid_firmware(const std::string& x) { uuid_firmware_ = x; }

    const std::string& global_tag() const { return global_tag_; }
    void global_tag(const std::string& x) { global_tag_ = x; }

    const std::string& grammar_version() const { return grammar_version_; }
    void grammar_version(const std::string& x) { grammar_version_ = x; }

    unsigned int n_modules() const { return n_modules_; }
    void n_modules(const unsigned int x) { n_modules_ = x; }

    bool is_valid() const { return is_valid_; }
    void is_valid(const bool x) { is_valid_ = x; }

    bool is_obsolete() const { return is_obsolete_; }
    void is_obsolete(const bool x) { is_obsolete_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    typedef std::vector<tmxsd::algorithm> algorithms;
    const algorithms& algorithm() const { return algorithm_; }
    algorithms& algorithm() { return algorithm_; }

    const tmxsd::scale_set scale_set() const { return scale_set_; }
    void scale_set(const tmxsd::scale_set& x) { scale_set_ = x; }

    const tmxsd::ext_signal_set ext_signal_set() const { return ext_signal_set_; }
    void ext_signal_set(const tmxsd::ext_signal_set& x) { ext_signal_set_ = x; }

    unsigned int menu_id() const { return menu_id_; }
    void menu_id(const unsigned int x) { menu_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      unsigned int ancestor_id_;    /**< id of ancestor menu */
      std::string name_;            /**< name of the menu */
      std::string uuid_menu_;       /**< uuid of the menu */
      std::string uuid_firmware_;   /**< uuid of the firmware */
      std::string global_tag_;      /**< global_tag of the software */
      std::string grammar_version_;  /**< grammar version of algorithm expression */
      unsigned int n_modules_;      /**< number of modules */
      bool is_valid_;               /**< valid flag */
      bool is_obsolete_;            /**< obsolete flag */
      std::string comment_;         /**< comment */
      algorithms algorithm_;        /**< array of algorithm */
      tmxsd::scale_set scale_set_;   /**< scale_set */
      tmxsd::ext_signal_set ext_signal_set_;   /**< ext_signal_set */
      unsigned int menu_id_;        /**< menu_id in DB */
      std::string datetime_;        /**< datetime in DB */
      bool debug_;                  /**< debug flag */

  }; // struct menu

} // namespace tmxsd

#endif // complex_menu_hh
/* eof */
