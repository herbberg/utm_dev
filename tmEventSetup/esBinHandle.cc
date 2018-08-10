#include "tmUtil/tmUtil.hh"
#include "tmEventSetup/esBinHandle.hh"


namespace tmeventsetup
{

void
esBinHandle::print() const
{
  TM_LOG_INF("");
  std::cout << "  HW index = " << hw_index << "\n";
  std::cout << "  minimum = " << minimum << "\n";
  std::cout << "  maximum = " << maximum << "\n";
}


void
esBinHandle::print(const esBin& bin)
{
  TM_LOG_INF("");
  std::cout << "  HW index = " << bin.hw_index << "\n";
  std::cout << "  minimum = " << bin.minimum << "\n";
  std::cout << "  maximum = " << bin.maximum << "\n";
}

} // namespace tmeventsetup

/* eof */
