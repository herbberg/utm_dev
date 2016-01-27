//
// auto generated file has been edited
//

#ifndef complex_scale_set_parser_hh
#define complex_scale_set_parser_hh

#include "tmXsd/gen-xsd-type/complex-scale_set-pskel.hh"

namespace tmxsd
{
  class scale_set_pimpl: public virtual scale_set_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    scale (const ::tmxsd::scale&);

    virtual void
    scale_set_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual void
    is_valid (bool);

    virtual void
    comment (const std::string&);

    virtual ::tmxsd::scale_set
    post_scale_set ();

    const ::tmxsd::scale_set& scale_set() { return scale_set_; }

    void
    debug (bool x) { scale_set_.debug(x); }

    private:
    ::tmxsd::scale_set scale_set_;
  };
}
#endif // complex_scale_set_parser_hh
// eof
