//
// auto generated file has been edited
//
#ifndef complex_ext_signal_set_parser_hh
#define complex_ext_signal_set_parser_hh

#include "tmXsd/gen-xsd-type/complex-ext_signal_set-pskel.hh"
#include "tmXsd/gen-xsd-type/complex-ext_signal-parser.hh"

namespace tmxsd
{
  class ext_signal_set_pimpl: public virtual ext_signal_set_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    comment (const std::string&);

    virtual void
    ext_signal (const ::tmxsd::ext_signal&);

    virtual void
    ext_signal_set_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual void
    is_valid (bool);

    virtual ::tmxsd::ext_signal_set
    post_ext_signal_set ();

    void
    debug (bool x) { ext_signal_set_.debug(x); }

    private:
    ::tmxsd::ext_signal_set ext_signal_set_;
  };
}
#endif // complex_ext_signal_set_parser_hh
// eof
