//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-bin-parser.hh"

namespace tmxsd
{
  void bin_pimpl::
  pre ()
  {
    bin_.number(0);
    bin_.minimum("");
    bin_.maximum("");
    bin_.bin_id(0);
    bin_.scale_id(0);
  }

  void bin_pimpl::
  maximum (const ::std::string& maximum)
  {
    bin_.maximum(maximum);
  }

  void bin_pimpl::
  minimum (const ::std::string& minimum)
  {
    bin_.minimum(minimum);
  }

  void bin_pimpl::
  number (unsigned int number)
  {
    bin_.number(number);
  }

  void bin_pimpl::
  bin_id (unsigned int bin_id)
  {
    bin_.bin_id(bin_id);
  }

  void bin_pimpl::
  scale_id (unsigned int scale_id)
  {
    bin_.scale_id(scale_id);
  }

  ::tmxsd::bin bin_pimpl::
  post_bin ()
  {
    if (bin_.debug())
    {
      std::cout << "post_bin()" << "\n";
      std::cout << "  number:   " << bin_.number() << "\n";
      std::cout << "  minimum:  " << bin_.minimum() << "\n";
      std::cout << "  maximum:  " << bin_.maximum() << "\n";
      std::cout << "  bin_id:   " << bin_.bin_id() << "\n";
      std::cout << "  scale_id: " << bin_.scale_id() << "\n";
    }
    return bin_;
  }
}
// eof
