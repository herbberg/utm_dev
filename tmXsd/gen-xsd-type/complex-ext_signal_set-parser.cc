//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-ext_signal_set-parser.hh"

#include <iostream>

namespace tmxsd
{
  void ext_signal_set_pimpl::
  pre ()
  {
    ext_signal_set_.name("");
    ext_signal_set_.comment("");
    ext_signal_set_.ext_signal().clear();
    ext_signal_set_.ext_signal_set_id(0);
    ext_signal_set_.datetime("");
    ext_signal_set_.is_valid(false);
  }

  void ext_signal_set_pimpl::
  name (const std::string& name)
  {
    ext_signal_set_.name(name);
  }

  void ext_signal_set_pimpl::
  comment (const std::string& comment)
  {
    ext_signal_set_.comment(comment);
  }

  void ext_signal_set_pimpl::
  ext_signal (const ::tmxsd::ext_signal& ext_signal)
  {
    ext_signal_set_.ext_signal().push_back(ext_signal);
  }

  void ext_signal_set_pimpl::
  ext_signal_set_id (unsigned int ext_signal_set_id)
  {
    ext_signal_set_.ext_signal_set_id(ext_signal_set_id);
  }

  void ext_signal_set_pimpl::
  datetime (const std::string& datetime)
  {
    ext_signal_set_.datetime(datetime);
  }

  void ext_signal_set_pimpl::
  is_valid (bool is_valid)
  {
    ext_signal_set_.is_valid(is_valid);
  }

  ::tmxsd::ext_signal_set ext_signal_set_pimpl::
  post_ext_signal_set ()
  {
    if (ext_signal_set_.debug())
    {
      std::cout << "post_ext_signal_set()" << "\n";
      std::cout << "  name:              " << ext_signal_set_.name() << "\n";
      std::cout << "  comment:           " << ext_signal_set_.comment() << "\n";
      std::cout << "  ext_signal:        " << ext_signal_set_.ext_signal().size() << "\n";
      std::cout << "  ext_signal_set_id: " << ext_signal_set_.ext_signal_set_id() << "\n";
      std::cout << "  datetime:          " << ext_signal_set_.datetime() << "\n";
      std::cout << "  is_valid:          " << ext_signal_set_.is_valid() << "\n";
    }
    return ext_signal_set_;
  }
}
// eof
