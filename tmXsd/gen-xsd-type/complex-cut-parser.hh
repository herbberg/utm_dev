//
// auto generated file has been edited
//
#ifndef complex_cut_parser_hh
#define complex_cut_parser_hh

#include "tmXsd/gen-xsd-type/complex-cut-pskel.hh"

namespace tmxsd
{
  class cut_pimpl: public virtual cut_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    object (const std::string&);

    virtual void
    type (const std::string&);

    virtual void
    minimum (const std::string&);

    virtual void
    maximum (const std::string&);

    virtual void
    data (const std::string&);

    virtual void
    comment (const std::string&);

    virtual void
    cut_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::cut
    post_cut ();

    void
    debug (bool x) { cut_.debug(x); }

    private:
    ::tmxsd::cut cut_;
  };
}
#endif
// eof
