//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-ext_signal-parser.hh"

#include <iostream>

namespace tmxsd
{
  void ext_signal_pimpl::
  pre ()
  {
    ext_signal_.name("");
    ext_signal_.system("");
    ext_signal_.cable(0);
    ext_signal_.channel(0);
    ext_signal_.description("");
    ext_signal_.label("");
    ext_signal_.ext_signal_id(0);
    ext_signal_.datetime("");
  }

  void ext_signal_pimpl::
  name (const std::string& name)
  {
    ext_signal_.name(name);
  }

  void ext_signal_pimpl::
  system (const std::string& system)
  {
    ext_signal_.system(system);
  }

  void ext_signal_pimpl::
  cable (unsigned int cable)
  {
    ext_signal_.cable(cable);
  }

  void ext_signal_pimpl::
  channel (unsigned int channel)
  {
    ext_signal_.channel(channel);
  }

  void ext_signal_pimpl::
  description (const std::string& description)
  {
    ext_signal_.description(description);
  }

  void ext_signal_pimpl::
  label (const std::string& label)
  {
    ext_signal_.label(label);
  }

  void ext_signal_pimpl::
  ext_signal_id (unsigned int ext_signal_id)
  {
    ext_signal_.ext_signal_id(ext_signal_id);
  }

  void ext_signal_pimpl::
  datetime (const std::string& datetime)
  {
    ext_signal_.datetime(datetime);
  }

  ::tmxsd::ext_signal ext_signal_pimpl::
  post_ext_signal ()
  {
    if (ext_signal_.debug())
    {
      std::cout << "post_ext_signal()" << "\n";
      std::cout << "  name: "          << ext_signal_.name() << "\n";
      std::cout << "  system: "        << ext_signal_.system() << "\n";
      std::cout << "  cable: "         << ext_signal_.cable() << "\n";
      std::cout << "  channel: "       << ext_signal_.channel() << "\n";
      std::cout << "  description: "   << ext_signal_.description() << "\n";
      std::cout << "  label: "         << ext_signal_.label() << "\n";
      std::cout << "  ext_signal_id: " << ext_signal_.ext_signal_id() << "\n";
      std::cout << "  datetime: "      << ext_signal_.datetime() << "\n";
    }
    return ext_signal_;
  }
}
// eof
