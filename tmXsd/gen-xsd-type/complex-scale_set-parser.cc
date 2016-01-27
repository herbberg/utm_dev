//
// auto generated file has been edited
//

#include "tmXsd/gen-xsd-type/complex-scale_set-parser.hh"

namespace tmxsd
{
  void scale_set_pimpl::
  pre ()
  {
    scale_set_.name("");
    scale_set_.scale().clear();
    scale_set_.scale_set_id(0);
    scale_set_.datetime("");
    scale_set_.is_valid(false);
    scale_set_.comment("");
  }

  void scale_set_pimpl::
  name (const std::string& name)
  {
    scale_set_.name(name);
  }

  void scale_set_pimpl::
  scale (const ::tmxsd::scale& scale)
  {
    scale_set_.scale().push_back(scale);
  }

  void scale_set_pimpl::
  scale_set_id (unsigned int scale_set_id)
  {
    scale_set_.scale_set_id(scale_set_id);
  }

  void scale_set_pimpl::
  datetime (const std::string& datetime)
  {
    scale_set_.datetime(datetime);
  }

  void scale_set_pimpl::
  is_valid (bool is_valid)
  {
    scale_set_.is_valid(is_valid);
  }

  void scale_set_pimpl::
  comment (const std::string& comment)
  {
    scale_set_.comment(comment);
  }

  ::tmxsd::scale_set scale_set_pimpl::
  post_scale_set ()
  {
    if (scale_set_.debug())
    {
      std::cout << "post_scale_set()" << "\n";
      std::cout << "  name:         " << scale_set_.name() << "\n";
      std::cout << "  scale:        " << scale_set_.scale().size() << "\n";
      std::cout << "  scale_set_id: " << scale_set_.scale_set_id() << "\n";
      std::cout << "  datetime:     " << scale_set_.datetime() << "\n";
      std::cout << "  is_valid:     " << scale_set_.is_valid() << "\n";
      std::cout << "  comment:      " << scale_set_.comment() << "\n";
    }
    return scale_set_;
  } 
}
// eof
