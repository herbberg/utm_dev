// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX___XSD_TYPE_COMPLEX_BIN_PIMPL_HH
#define CXX___XSD_TYPE_COMPLEX_BIN_PIMPL_HH

#include "complex-bin-pskel.hh"

#include "simple-types-pimpl.hh"

namespace tmxsd
{
  class bin_pimpl: public virtual bin_pskel
  {
    public:
    virtual void
    pre ();

    virtual void
    number (unsigned int);

    virtual void
    minimum (const std::string&);

    virtual void
    maximum (const std::string&);

    virtual void
    bin_id (unsigned int);

    virtual void
    scale_id (unsigned int);

    virtual ::tmxsd::bin
    post_bin ();
  };
}

#endif // CXX___XSD_TYPE_COMPLEX_BIN_PIMPL_HH
