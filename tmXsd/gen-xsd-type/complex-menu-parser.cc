//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-menu-parser.hh"


namespace tmxsd
{
  void menu_pimpl::
  pre ()
  {
    menu_.ancestor_id(0);
    menu_.name("");
    menu_.uuid_menu("");
    menu_.uuid_firmware("");
    menu_.global_tag("");
    menu_.grammar_version("");
    menu_.n_modules(0);
    menu_.is_valid(false);
    menu_.is_obsolete(false);
    menu_.comment("");
    menu_.algorithm().clear();
    menu_.menu_id(0);
    menu_.datetime("");
  }

  void menu_pimpl::
  ancestor_id (unsigned int ancestor_id)
  {
    menu_.ancestor_id(ancestor_id);
  }

  void menu_pimpl::
  name (const std::string& name)
  {
    menu_.name(name);
  }

  void menu_pimpl::
  uuid_menu (const std::string& uuid_menu)
  {
    menu_.uuid_menu(uuid_menu);
  }

  void menu_pimpl::
  uuid_firmware (const std::string& uuid_firmware)
  {
    menu_.uuid_firmware(uuid_firmware);
  }

  void menu_pimpl::
  global_tag (const std::string& global_tag)
  {
    menu_.global_tag(global_tag);
  }

  void menu_pimpl::
  grammar_version (const std::string& grammar_version)
  {
    menu_.grammar_version(grammar_version);
  }

  void menu_pimpl::
  n_modules (unsigned int n_modules)
  {
    menu_.n_modules(n_modules);
  }

  void menu_pimpl::
  is_valid (bool is_valid)
  {
    menu_.is_valid(is_valid);
  }

  void menu_pimpl::
  is_obsolete (bool is_obsolete)
  {
    menu_.is_obsolete(is_obsolete);
  }

  void menu_pimpl::
  comment (const std::string& comment)
  {
    menu_.comment(comment);
  }

  void menu_pimpl::
  algorithm (const ::tmxsd::algorithm& algorithm)
  {
    menu_.algorithm().push_back(algorithm);
  }

  void menu_pimpl::
  scale_set (const ::tmxsd::scale_set& scale_set)
  {
    menu_.scale_set(scale_set);
  }

  void menu_pimpl::
  ext_signal_set (const ::tmxsd::ext_signal_set& ext_signal_set)
  {
    menu_.ext_signal_set(ext_signal_set);
  }

  void menu_pimpl::
  menu_id (unsigned int menu_id)
  {
    menu_.menu_id(menu_id);
  }

  void menu_pimpl::
  datetime (const std::string& datetime)
  {
    menu_.datetime(datetime);
  }

  ::tmxsd::menu menu_pimpl::
  post_menu ()
  {
    if (menu_.debug())
    {
      std::cout << "post_menu()" << "\n";
      std::cout << "  ancestor_id:     " << menu_.ancestor_id() << "\n";
      std::cout << "  name:            " << menu_.name() << "\n";
      std::cout << "  uuid_menu:       " << menu_.uuid_menu() << "\n";
      std::cout << "  uuid_firmware:   " << menu_.uuid_firmware() << "\n";
      std::cout << "  global_tag:      " << menu_.global_tag() << "\n";
      std::cout << "  grammar_version: " << menu_.grammar_version() << "\n";
      std::cout << "  n_modules:       " << menu_.n_modules() << "\n";
      std::cout << "  is_valid:        " << menu_.is_valid() << "\n";
      std::cout << "  is_obsolete:     " << menu_.is_obsolete() << "\n";
      std::cout << "  comment:         " << menu_.comment() << "\n";
      std::cout << "  algorithm:       " << menu_.algorithm().size() << "\n";
      std::cout << "  menu_id:         " << menu_.menu_id() << "\n";
      std::cout << "  datetime:        " << menu_.datetime() << "\n";
    }
    return menu_;
  }
}
// eof
