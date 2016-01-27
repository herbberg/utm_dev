//
// auto generated file has been edited
//
#ifndef complex_scale_parser_hh
#define complex_scale_parser_hh

#include "tmXsd/gen-xsd-type/complex-scale-pskel.hh"

namespace tmxsd
{
  class scale_pimpl: public virtual scale_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    object (const ::std::string&);

    virtual void
    type (const ::std::string&);

    virtual void
    minimum (const ::std::string&);

    virtual void
    maximum (const ::std::string&);

    virtual void
    step (const ::std::string&);

    virtual void
    n_bits (unsigned int);

    virtual void
    bin (const ::tmxsd::bin&);

    virtual void
    scale_id (unsigned int);

    virtual void
    datetime (const ::std::string&);

    virtual void
    n_bins (unsigned int);

    virtual void
    comment (const ::std::string&);

    virtual ::tmxsd::scale
    post_scale ();

    void
    debug (bool x) { scale_.debug(x); }

    private:
    ::tmxsd::scale scale_;
  };
}
#endif // complex_scale_parser_hh
// eof
