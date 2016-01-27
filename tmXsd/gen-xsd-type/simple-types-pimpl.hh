// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX___XSD_TYPE_SIMPLE_TYPES_PIMPL_HH
#define CXX___XSD_TYPE_SIMPLE_TYPES_PIMPL_HH

#include "simple-types-pskel.hh"

namespace tmxsd
{
  class id_pimpl: public virtual id_pskel,
    public ::xml_schema::unsigned_int_pimpl
  {
    public:
    virtual void
    pre ();

    virtual unsigned int
    post_id ();
  };

  class uuid_pimpl: public virtual uuid_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_uuid ();
  };

  class datetime_pimpl: public virtual datetime_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_datetime ();
  };

  class real_pimpl: public virtual real_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_real ();
  };

  class char64_pimpl: public virtual char64_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_char64 ();
  };

  class char1k_pimpl: public virtual char1k_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_char1k ();
  };

  class char4k_pimpl: public virtual char4k_pskel,
    public ::xml_schema::string_pimpl
  {
    public:
    virtual void
    pre ();

    virtual std::string
    post_char4k ();
  };
}

#endif // CXX___XSD_TYPE_SIMPLE_TYPES_PIMPL_HH
