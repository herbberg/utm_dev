//
// auto generated file has been edited
//
#ifndef complex_bin_parser_hh
#define complex_bin_parser_hh

#include "tmXsd/gen-xsd-type/complex-bin-pskel.hh"

namespace tmxsd
{
  class bin_pimpl: public virtual bin_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    maximum (const ::std::string&);

    virtual void
    minimum (const ::std::string&);

    virtual void
    number (unsigned int);

    virtual void
    bin_id (unsigned int);

    virtual void
    scale_id (unsigned int);

    virtual ::tmxsd::bin
    post_bin ();

    void
    debug(bool x) { bin_.debug(x); }

    private:
    ::tmxsd::bin bin_;
  };
}
#endif
// eof
