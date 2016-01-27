//
// auto generated file has been edited
//
#include <limits>

#include "tmXsd/gen-xsd-type/complex-algorithm-parser.hh"

namespace tmxsd
{
  void algorithm_pimpl::
  pre ()
  {

    algorithm_.name("");
    algorithm_.expression("");
    algorithm_.index(std::numeric_limits<unsigned int>::max());
    algorithm_.module_id(std::numeric_limits<unsigned int>::max());
    algorithm_.module_index(std::numeric_limits<unsigned int>::max());
    algorithm_.comment("");
    algorithm_.cut().clear();
    algorithm_.object_requirement().clear();
    algorithm_.external_requirement().clear();
    algorithm_.algorithm_id(0);
    algorithm_.datetime("");
  }

  void algorithm_pimpl::
  name (const std::string& name)
  {
    algorithm_.name(name);
  }

  void algorithm_pimpl::
  expression (const std::string& expression)
  {
    algorithm_.expression(expression);
  }

  void algorithm_pimpl::
  index (unsigned int index)
  {
    algorithm_.index(index);
  }

  void algorithm_pimpl::
  module_id (unsigned int module_id)
  {
    algorithm_.module_id(module_id);
  }

  void algorithm_pimpl::
  module_index (unsigned int module_index)
  {
    algorithm_.module_index(module_index);
  }

  void algorithm_pimpl::
  comment (const std::string& comment)
  {
    algorithm_.comment(comment);
  }

  void algorithm_pimpl::
  cut (const ::tmxsd::cut& cut)
  {
    algorithm_.cut().push_back(cut);
  }

  void algorithm_pimpl::
  object_requirement (const ::tmxsd::object_requirement& object_requirement)
  {
    algorithm_.object_requirement().push_back(object_requirement);
  }

  void algorithm_pimpl::
  external_requirement (const ::tmxsd::external_requirement& external_requirement)
  {
    algorithm_.external_requirement().push_back(external_requirement);
  }

  void algorithm_pimpl::
  algorithm_id (unsigned int algorithm_id)
  {
    algorithm_.algorithm_id(algorithm_id);
  }

  void algorithm_pimpl::
  datetime (const std::string& datetime)
  {
    algorithm_.datetime(datetime);
  }

  ::tmxsd::algorithm algorithm_pimpl::
  post_algorithm ()
  {
    if (algorithm_.debug())
    {
      std::cout << "post_algorithm()" << "\n";
      std::cout << "  name:                 " << algorithm_.name() << "\n";
      std::cout << "  index:                " << algorithm_.index() << "\n";
      std::cout << "  module_id:            " << algorithm_.module_id() << "\n";
      std::cout << "  module_index:         " << algorithm_.module_index() << "\n";
      std::cout << "  name:                 " << algorithm_.comment() << "\n";
      std::cout << "  cut:                  " << algorithm_.cut().size() << "\n";
      std::cout << "  object_requirement:   " << algorithm_.object_requirement().size() << "\n";
      std::cout << "  external_requirement: " << algorithm_.external_requirement().size() << "\n";
      std::cout << "  algorithm_id:         " << algorithm_.algorithm_id() << "\n";
      std::cout << "  datetime:             " << algorithm_.datetime() << "\n";
    }
    return algorithm_;
  }
}
// eof
