#include "tmUtil/tmUtil.hh"
#include "tmEventSetup/esCutHandle.hh"
#include "tmEventSetup/esObjectHandle.hh"
#include "tmEventSetup/esConditionHandle.hh"


namespace tmeventsetup
{
void
esConditionHandle::print() const
{
  TM_LOG_INF("tmeventsetup::esConditionHandle::print");
  std::cout << "  name = " << name_ << "\n";
  std::cout << "  type = " << type_ << "\n";
  std::cout << "  # of objects = " << objects_.size() << "\n";
  std::cout << "  # of cuts = " << cuts_.size() << "\n";
  for (size_t ii = 0; ii < objects_.size(); ii++) esObjectHandle::print(objects_.at(ii));
  for (size_t ii = 0; ii < cuts_.size(); ii++) esCutHandle::print(cuts_.at(ii));
}


void
esConditionHandle::print(const esCondition& cond)
{
  TM_LOG_INF("tmeventsetup::esConditionHandle::print");
  std::cout << "  name = " << cond.getName() << "\n";
  std::cout << "  type = " << cond.getType() << "\n";
  const std::vector<esObject>& objects = cond.getObjects();
  std::cout << "  # of objects = " << objects.size() << "\n";
  const std::vector<esCut>& cuts = cond.getCuts();
  std::cout << "  # of cuts = " << cuts.size() << "\n";
  for (size_t ii = 0; ii < objects.size(); ii++) esObjectHandle::print(objects.at(ii));
  for (size_t ii = 0; ii < cuts.size(); ii++) esCutHandle::print(cuts.at(ii));
}

} // namespace tmeventsetup

/* eof */
