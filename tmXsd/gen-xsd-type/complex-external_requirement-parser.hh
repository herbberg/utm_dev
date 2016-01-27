//
// auto generated file has been edited
//
#ifndef complex_external_requirement_parser_hh
#define complex_external_requirement_parser_hh

#include "tmXsd/gen-xsd-type/complex-external_requirement-pskel.hh"

namespace tmxsd
{
  class external_requirement_pimpl: public virtual external_requirement_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    bx_offset (int);

    virtual void
    comment (const std::string&);

    virtual void
    requirement_id (unsigned int);

    virtual void
    ext_signal_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::external_requirement
    post_external_requirement ();

    void
    debug (bool x) { external_requirement_.debug(x); }

    private:
    ::tmxsd::external_requirement external_requirement_;
  };
}

#endif // complex_external_requirement_parser_hh
// eof
