//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-external_requirement-parser.hh"

namespace tmxsd
{
  void external_requirement_pimpl::
  pre ()
  {
    external_requirement_.name("");
    external_requirement_.bx_offset(0);
    external_requirement_.comment("");
    external_requirement_.requirement_id(0);
    external_requirement_.ext_signal_id(0);
    external_requirement_.datetime("");
  }

  void external_requirement_pimpl::
  name (const std::string& name)
  {
    external_requirement_.name(name);
  }

  void external_requirement_pimpl::
  bx_offset (int bx_offset)
  {
    external_requirement_.bx_offset(bx_offset);
  }

  void external_requirement_pimpl::
  comment (const std::string& comment)
  {
    external_requirement_.comment(comment);
  }

  void external_requirement_pimpl::
  requirement_id (unsigned int requirement_id)
  {
    external_requirement_.requirement_id(requirement_id);
  }

  void external_requirement_pimpl::
  ext_signal_id (unsigned int ext_signal_id)
  {
    external_requirement_.ext_signal_id(ext_signal_id);
  }

  void external_requirement_pimpl::
  datetime (const std::string& datetime)
  {
    external_requirement_.datetime(datetime);
  }

  ::tmxsd::external_requirement external_requirement_pimpl::
  post_external_requirement ()
  {
    if (external_requirement_.debug())
    {
      std::cout << "post_external_requirement() \n";
      std::cout << "  name:           " << external_requirement_.name() << "\n";
      std::cout << "  bx_offset:      " << external_requirement_.bx_offset() << "\n";
      std::cout << "  comment:        " << external_requirement_.comment() << "\n";
      std::cout << "  requirement_id: " << external_requirement_.requirement_id() << "\n";
      std::cout << "  ext_signal_id:  " << external_requirement_.ext_signal_id() << "\n";
      std::cout << "  datetime:       " << external_requirement_.datetime() << "\n";
    }
    return external_requirement_;
  }
}
// eof
