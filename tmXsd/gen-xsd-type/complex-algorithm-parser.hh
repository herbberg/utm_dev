//
// auto generated file has been edited
//
#ifndef complex_algorithm_parser_hh
#define complex_algorithm_parser_hh

#include "tmXsd/gen-xsd-type/complex-menu.hh"
#include "tmXsd/gen-xsd-type/complex-algorithm-pskel.hh"

namespace tmxsd
{
  class algorithm_pimpl: public virtual algorithm_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    name (const std::string&);

    virtual void
    expression (const std::string&);

    virtual void
    index (unsigned int);

    virtual void
    module_id (unsigned int);

    virtual void
    module_index (unsigned int);

    virtual void
    comment (const std::string&);

    virtual void
    cut (const ::tmxsd::cut&);

    virtual void
    object_requirement (const ::tmxsd::object_requirement&);

    virtual void
    external_requirement (const ::tmxsd::external_requirement&);

    virtual void
    algorithm_id (unsigned int);

    virtual void
    datetime (const std::string&);

    virtual ::tmxsd::algorithm
    post_algorithm ();

    void
    debug (bool x) { algorithm_.debug(x); }

    private:
    ::tmxsd::algorithm algorithm_;
  };
}
#endif // complex_algorithm_parser_hh
// eof
