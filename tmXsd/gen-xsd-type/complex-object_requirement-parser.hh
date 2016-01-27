//
// auto generated file has been edited
//
#ifndef complex_object_requirement_parser_hh
#define complex_object_requirement_parser_hh

#include "tmXsd/gen-xsd-type/complex-object_requirement-pskel.hh"

namespace tmxsd
{
  class object_requirement_pimpl: public virtual object_requirement_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    type (const std::string&);

    virtual void
    comparison_operator (const std::string&);

    virtual void
    threshold (const std::string&);

    virtual void
    bx_offset (int);

    virtual void
    comment (const std::string&);

    virtual void
    requirement_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::object_requirement
    post_object_requirement ();

    void
    debug (bool x) { object_requirement_.debug(x); }

    private:
    ::tmxsd::object_requirement object_requirement_;
  };
}
#endif // complex_object_requirement_parser_hh
// eof
