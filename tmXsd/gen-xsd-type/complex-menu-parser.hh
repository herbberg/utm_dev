//
// auto generated file has been edited
//
#ifndef complex_menu_parser_hh
#define complex_menu_parser_hh

#include "tmXsd/gen-xsd-type/complex-menu-pskel.hh"

namespace tmxsd
{
  class menu_pimpl: public virtual menu_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    ancestor_id (unsigned int);

    virtual void
    name (const std::string&);

    virtual void
    uuid_menu (const std::string&);

    virtual void
    uuid_firmware (const std::string&);

    virtual void
    global_tag (const std::string&);

    virtual void
    grammar_version (const std::string&);

    virtual void
    n_modules (unsigned int);

    virtual void
    is_valid (bool);

    virtual void
    is_obsolete (bool);

    virtual void
    comment (const std::string&);

    virtual void
    algorithm (const ::tmxsd::algorithm&);

    virtual void
    scale_set (const ::tmxsd::scale_set&);

    virtual void
    ext_signal_set (const ::tmxsd::ext_signal_set&);

    virtual void
    menu_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::menu
    post_menu ();

    void
    debug (bool x) { menu_.debug(x); }

    private:
    ::tmxsd::menu menu_;
  };
}
#endif // complex_menu_parser_hh
// eof
