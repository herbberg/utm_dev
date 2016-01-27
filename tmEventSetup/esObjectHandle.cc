#include "tmUtil/tmUtil.hh"
#include "tmEventSetup/tmEventSetup.hh"
#include "tmEventSetup/esCutHandle.hh"
#include "tmEventSetup/esObjectHandle.hh"


namespace tmeventsetup
{

esObjectHandle::esObjectHandle(const Object::Item& item)
{
  init(item);
}


esObjectHandle::esObjectHandle(const Object::Item& item, const tmtable::Table& cuts_in_algo)
{
  init(item);
  for (size_t ii = 0; ii < item.cuts.size(); ii++)
  {
    for (size_t jj = 0; jj < cuts_in_algo.size(); jj++)
    {
      tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(jj));
      if (item.cuts.at(ii) != cut["name"]) continue;

      // add object name if it is not included in the cut["type"]
      if (cut["type"].find("-") == std::string::npos)
      {
        cut["type"] = item.name + "-" + cut["type"];
      }
      esCutHandle handle = esCutHandle(cut);
      esCut& ref = handle;
      cuts_.push_back(ref);
    }
  }
}


void
esObjectHandle::init(const Object::Item& item)
{
  name_ = item.getObjectName();

  type_ = static_cast<esObjectType>(Undef);
  if (item.name == Object::MU) type_ = Muon;
  else if (item.name == Object::EG) type_ = Egamma;
  else if (item.name == Object::TAU) type_ = Tau;
  else if (item.name == Object::JET) type_ = Jet;
  else if (item.name == Object::ETT) type_ = ETT;
  else if (item.name == Object::HTT) type_ = HTT;
  else if (item.name == Object::ETM) type_ = ETM;
  else if (item.name == Object::HTM) type_ = HTM;
  else if (item.name.rfind(Object::EXT, 0) == 0) type_ = EXT;
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esObjectHandle::init: unknown type '" << item.name << "'");
  }

  if (type_ == EXT)
  {
    bx_offset_ = tmutil::convert<int>(item.bx_offset);
    ext_signal_name_ = getExternalName(name_);
    return;
  }

  comparison_operator_ = static_cast<esComparisonOperator>(Undef);
  if (item.comparison == Object::GE) comparison_operator_ = GE;
  else if (item.comparison == Object::NE) comparison_operator_ = NE;
  else if (item.comparison == Object::EQ) comparison_operator_ = EQ;
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esObjectHandle::init: unknown comparison operator '" << item.comparison << "'");
  }
  
  bx_offset_ = tmutil::convert<int>(item.bx_offset);
  std::string threshold = item.threshold;
  tmutil::replace(threshold, "p", ".");
  threshold_ = tmutil::convert<double>(threshold);

  tmtable::Row cut;
  cut["name"] = item.name + "-" + ET_THR + "_" + threshold;
  cut["object"] = item.name;
  cut["type"] = item.name + "-" + ET_THR;
  cut["minimum"] = threshold;
  cut["maximum"] = "";
  cut["data"] = "";
  esCutHandle handle = esCutHandle(cut);
  esCut& ref = handle;
  cuts_.push_back(ref);
}


void
esObjectHandle::setExternalChannelId(const std::map<std::string, unsigned int>& map)
{
  if (type_ != EXT) return;
  ext_channel_id_ = map.find(ext_signal_name_)->second;
}


void
esObjectHandle::print() const
{
  TM_LOG_INF("tmeventsetup::esObjectHandle::print");
  std::cout << "  name = " << name_ << "\n";
  std::cout << "  type = " << type_ << "\n";
  std::cout << "  op = " << comparison_operator_ << "\n";
  std::cout << "  bx offset = " << bx_offset_ << "\n";
  std::cout << "  threshold = " << threshold_ << "\n";
  std::cout << "  # of cuts = " << cuts_.size() << "\n";
  for (size_t ii = 0; ii < cuts_.size(); ii++) esCutHandle::print(cuts_.at(ii));
}


void
esObjectHandle::print(const esObject& object)
{
  TM_LOG_INF("tmeventsetup::esObjectHandle::print");
  std::cout << "  name = " << object.getName() << "\n";
  std::cout << "  type = " << object.getType() << "\n";
  std::cout << "  op = " << object.getComparisonOperator() << "\n";
  std::cout << "  bx offset = " << object.getBxOffset() << "\n";
  std::cout << "  threshold = " << object.getThreshold() << "\n";
  const std::vector<esCut>& cuts = object.getCuts();
  std::cout << "  # of cuts = " << cuts.size() << "\n";
  for (size_t ii = 0; ii < cuts.size(); ii++) esCutHandle::print(cuts.at(ii));
}

} // namespace tmeventsetup

/* eof */
