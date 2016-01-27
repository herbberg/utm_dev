//
// auto generated file has been edited
//
#include "tmXsd/gen-xsd-type/complex-object_requirement-parser.hh"

namespace tmxsd
{
  void object_requirement_pimpl::
  pre ()
  {
    object_requirement_.name("");
    object_requirement_.type("");
    object_requirement_.comparison_operator("");
    object_requirement_.threshold("");
    object_requirement_.bx_offset(0);
    object_requirement_.comment("");
    object_requirement_.requirement_id(0);
    object_requirement_.datetime("");
  }

  void object_requirement_pimpl::
  name (const std::string& name)
  {
    object_requirement_.name(name);
  }

  void object_requirement_pimpl::
  type (const std::string& type)
  {
    object_requirement_.type(type);
  }

  void object_requirement_pimpl::
  comparison_operator (const std::string& comparison_operator)
  {
    object_requirement_.comparison_operator(comparison_operator);
  }

  void object_requirement_pimpl::
  threshold (const std::string& threshold)
  {
    object_requirement_.threshold(threshold);
  }

  void object_requirement_pimpl::
  bx_offset (int bx_offset)
  {
    object_requirement_.bx_offset(bx_offset);
  }

  void object_requirement_pimpl::
  comment (const std::string& comment)
  {
    object_requirement_.comment(comment);
  }

  void object_requirement_pimpl::
  requirement_id (unsigned int requirement_id)
  {
    object_requirement_.requirement_id(requirement_id);
  }

  void object_requirement_pimpl::
  datetime (const std::string& datetime)
  {
    object_requirement_.datetime(datetime);
  }

  ::tmxsd::object_requirement object_requirement_pimpl::
  post_object_requirement ()
  {
    if (object_requirement_.debug())
    {
      std::cout << "post_object_requirement() \n";
      std::cout << "  name:                " << object_requirement_.name() << "\n";
      std::cout << "  type:                " << object_requirement_.type() << "\n";
      std::cout << "  comparison_operator: " << object_requirement_.comparison_operator() << "\n";
      std::cout << "  threshold:           " << object_requirement_.threshold() << "\n";
      std::cout << "  bx_offset:           " << object_requirement_.bx_offset() << "\n";
      std::cout << "  comment:             " << object_requirement_.comment() << "\n";
      std::cout << "  requirement_id:      " << object_requirement_.requirement_id() << "\n";
      std::cout << "  datetime:            " << object_requirement_.datetime() << "\n";
    }
    return object_requirement_;
  }
}
// eof
