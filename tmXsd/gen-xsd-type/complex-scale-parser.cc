//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-scale-parser.hh"

namespace tmxsd
{
  void scale_pimpl::
  pre ()
  {
    scale_.object("");
    scale_.type("");
    scale_.minimum("");
    scale_.maximum("");
    scale_.step("");
    scale_.n_bits(0);
    scale_.bin().clear();
    scale_.scale_id(0);
    scale_.datetime("");
    scale_.n_bins(0);
    scale_.comment("");
  }

  void scale_pimpl::
  object (const ::std::string& object)
  {
    scale_.object(object);
  }

  void scale_pimpl::
  type (const ::std::string& type)
  {
    scale_.type(type);
  }

  void scale_pimpl::
  minimum (const ::std::string& minimum)
  {
    scale_.minimum(minimum);
  }

  void scale_pimpl::
  maximum (const ::std::string& maximum)
  {
    scale_.maximum(maximum);
  }

  void scale_pimpl::
  step (const ::std::string& step)
  {
    scale_.step(step);
  }

  void scale_pimpl::
  n_bits (unsigned int n_bits)
  {
    scale_.n_bits(n_bits);
  }

  void scale_pimpl::
  bin (const ::tmxsd::bin& bin)
  {
    scale_.bin().push_back(bin);
  }

  void scale_pimpl::
  scale_id (unsigned int scale_id)
  {
    scale_.scale_id(scale_id);
  }

  void scale_pimpl::
  datetime (const ::std::string& datetime)
  {
    scale_.datetime(datetime);
  }

  void scale_pimpl::
  n_bins (unsigned int n_bins)
  {
    scale_.n_bins(n_bins);
  }

  void scale_pimpl::
  comment (const ::std::string& comment)
  {
    scale_.comment(comment);
  }

  ::tmxsd::scale scale_pimpl::
  post_scale ()
  {
    if (scale_.debug())
    {
      std::cout << "post_scale()" << "\n";
      std::cout << "  object:   " << scale_.object() << "\n";
      std::cout << "  type:     " << scale_.type() << "\n";
      std::cout << "  minimum:  " << scale_.minimum() << "\n";
      std::cout << "  maximum:  " << scale_.maximum() << "\n";
      std::cout << "  step:     " << scale_.step() << "\n";
      std::cout << "  n_bits:   " << scale_.n_bits() << "\n";
      std::cout << "  bin:      " << scale_.bin().size() << "\n";
      std::cout << "  scale_id: " << scale_.scale_id() << "\n";
      std::cout << "  datetime: " << scale_.datetime() << "\n";
      std::cout << "  n_bins:   " << scale_.n_bins() << "\n";
      std::cout << "  comment:  " << scale_.comment() << "\n";
    }
    return scale_;
  }
}
// eof
