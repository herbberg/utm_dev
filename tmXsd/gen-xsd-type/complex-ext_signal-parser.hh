//
// auto generated file has been edited
//
#ifndef complex_ext_signal_parser_hh
#define complex_ext_signal_parser_hh

#include "tmXsd/gen-xsd-type/complex-ext_signal-pskel.hh"

namespace tmxsd
{
  class ext_signal_pimpl: public virtual ext_signal_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    system (const std::string&);

    virtual void
    cable (unsigned int);

    virtual void
    channel (unsigned int);

    virtual void
    description (const std::string&);

    virtual void
    label (const std::string&);

    virtual void
    ext_signal_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::ext_signal
    post_ext_signal ();

    void
    debug (bool x) { ext_signal_.debug(x); }

    private:
    ::tmxsd::ext_signal ext_signal_;
  };
}
#endif // complex_ext_signal_parser_hh
// eof
