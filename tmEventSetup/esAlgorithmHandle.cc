#include "tmUtil/tmUtil.hh"
#include "tmTable/tmTable.hh"
#include "tmEventSetup/esAlgorithmHandle.hh"


namespace tmeventsetup
{

void
esAlgorithmHandle::replace(const std::string& from,
                           const std::string& to)
{
  size_t p = 0;
  while ((p = expression_in_condition_.find(from, p)) != std::string::npos)
  {
    bool replace = true;
    const size_t index = p + from.length();
    if (index < expression_in_condition_.size())
    {
      switch (expression_in_condition_.at(index))
      {
        case ' ': break;
        case ')': break;
        default: replace = false;
      }
    }
    if (replace) expression_in_condition_.replace(p, from.length(), to);
    p += to.length();
    if (p >= expression_in_condition_.size()) break;
  }
}


void
esAlgorithmHandle::print() const
{
  TM_LOG_INF("tmeventsetup::esAlgorithmHandle::print");
  std::string rpn;
  tmutil::join(rpn_vector_, rpn, ":");
  std::cout << "  name = " << name_ << "\n";
  std::cout << "  expression = " << expression_ << "\n";
  std::cout << "  expression in condition = " << expression_in_condition_ << "\n";
  std::cout << "  rpn vector = " << rpn << "\n";
  std::cout << "  index = " << index_ << "\n";
  std::cout << "  module id = " << module_id_ << "\n";
  std::cout << "  module index = " << module_index_ << "\n";
}


void
esAlgorithmHandle::print(const esAlgorithm& algo)
{
  TM_LOG_INF("tmeventsetup::esAlgorithmHandle::print");
  std::string rpn;
  const std::vector<std::string>& rpn_vector = algo.getRpnVector();
  tmutil::join(rpn_vector, rpn, ":");
  std::cout << "  name = " << algo.getName() << "\n";
  std::cout << "  expression = " << algo.getExpression() << "\n";
  std::cout << "  expression in condition = " << algo.getExpressionInCondition() << "\n";
  std::cout << "  rpn vector = " << rpn << "\n";
  std::cout << "  index = " << algo.getIndex() << "\n";
  std::cout << "  module id = " << algo.getModuleId() << "\n";
  std::cout << "  module index = " << algo.getModuleIndex() << "\n";
}


void
esAlgorithmHandle::init(const tmtable::Row& algorithm)
{
  TM_LOG_DBG("tmeventsetup::esAlgorithmHandle::init: " << algorithm.find("name")->second);

  name_ = algorithm.find("name")->second;
  expression_ = algorithm.find("expression")->second;

  index_ = tmutil::convert<unsigned int>(algorithm.find("index")->second);
  module_id_ = tmutil::convert<unsigned int>(algorithm.find("module_id")->second);
  module_index_ = tmutil::convert<unsigned int>(algorithm.find("module_index")->second);
}


void
esAlgorithmHandle::setExpressionInCondition(const std::map<std::string, std::string>& map)
{
  TM_LOG_DBG("tmeventsetup::esAlgorithmHandle::setExpressionInCondition: ");
  expression_in_condition_ = expression_;
  for (std::map<std::string, std::string>::const_iterator cit = map.begin();
       cit != map.end(); ++cit)
  {
    TM_LOG_DBG("tmeventsetup::esAlgorithmHandle::setExpressionInCondition: " << cit->first << " : " << cit->second);
    replace(cit->first, cit->second);
  }
}

} // namespace tmeventsetup

/* eof */
