//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-cut-parser.hh"

namespace tmxsd
{
  void cut_pimpl::
  pre ()
  {
    cut_.name("");
    cut_.object("");
    cut_.type("");
    cut_.minimum("");
    cut_.maximum("");
    cut_.data("");
    cut_.comment("");
    cut_.cut_id(0);
    cut_.datetime("");
  }

  void cut_pimpl::
  name (const std::string& name)
  {
    cut_.name(name);
  }

  void cut_pimpl::
  object (const std::string& object)
  {
    cut_.object(object);
  }

  void cut_pimpl::
  type (const std::string& type)
  {
    cut_.type(type);
  }

  void cut_pimpl::
  minimum (const std::string& minimum)
  {
    cut_.minimum(minimum);
  }

  void cut_pimpl::
  maximum (const std::string& maximum)
  {
    cut_.maximum(maximum);
  }

  void cut_pimpl::
  data (const std::string& data)
  {
    cut_.data(data);
  }

  void cut_pimpl::
  comment (const std::string& comment)
  {
    cut_.comment(comment);
  }

  void cut_pimpl::
  cut_id (unsigned int cut_id)
  {
    cut_.cut_id(cut_id);
  }

  void cut_pimpl::
  datetime (const std::string& datetime)
  {
    cut_.datetime(datetime);
  }

  ::tmxsd::cut cut_pimpl::
  post_cut ()
  {
    if (cut_.debug())
    {
      std::cout << "post_cut()" << "\n";
      std::cout << "  name:     " << cut_.name() << "\n";
      std::cout << "  object:   " << cut_.object() << "\n";
      std::cout << "  type:     " << cut_.type() << "\n";
      std::cout << "  minimum:  " << cut_.minimum() << "\n";
      std::cout << "  maximum:  " << cut_.maximum() << "\n";
      std::cout << "  data:     " << cut_.data() << "\n";
      std::cout << "  comment:  " << cut_.comment() << "\n";
      std::cout << "  cut_id:   " << cut_.cut_id() << "\n";
      std::cout << "  datetime: " << cut_.datetime() << "\n";
    }
    return cut_;
  }
}
// eof
