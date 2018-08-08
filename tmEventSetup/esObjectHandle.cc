#include "tmUtil/tmUtil.hh"
#include "tmEventSetup/tmEventSetup.hh"
#include "tmEventSetup/esCutHandle.hh"
#include "tmEventSetup/esObjectHandle.hh"

// boost
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/replace.hpp>

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
  bool isThreshold = true;

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
  else if (item.name == Object::MBT0HFP)
  {
    type_ = MBT0HFP;
    isThreshold = false;
  }
  else if (item.name == Object::MBT1HFP)
  {
    type_ = MBT1HFP;
    isThreshold = false;
  }
  else if (item.name == Object::MBT0HFM)
  {
    type_ = MBT0HFM;
    isThreshold = false;
  }
  else if (item.name == Object::MBT1HFM)
  {
    type_ = MBT1HFM;
    isThreshold = false;
  }
  else if (item.name == Object::TOWERCOUNT)
  {
    type_ = TOWERCOUNT;
    isThreshold = false;
  }
  else if (item.name == Object::ASYMET)
  {
    type_ = ASYMET;
    isThreshold = false;
  }
  else if (item.name == Object::ASYMHT)
  {
    type_ = ASYMHT;
    isThreshold = false;
  }
  else if (item.name == Object::ASYMETHF)
  {
    type_ = ASYMETHF;
    isThreshold = false;
  }
  else if (item.name == Object::ASYMHTHF)
  {
    type_ = ASYMHTHF;
    isThreshold = false;
  }
  else if (item.name == Object::CENT0)
  {
    type_ = CENT0;
    isThreshold = false;
  }
  else if (item.name == Object::CENT1)
  {
    type_ = CENT1;
    isThreshold = false;
  }
  else if (item.name == Object::CENT2)
  {
    type_ = CENT2;
    isThreshold = false;
  }
  else if (item.name == Object::CENT3)
  {
    type_ = CENT3;
    isThreshold = false;
  }
  else if (item.name == Object::CENT4)
  {
    type_ = CENT4;
    isThreshold = false;
  }
  else if (item.name == Object::CENT5)
  {
    type_ = CENT5;
    isThreshold = false;
  }
  else if (item.name == Object::CENT6)
  {
    type_ = CENT6;
    isThreshold = false;
  }
  else if (item.name == Object::CENT7)
  {
    type_ = CENT7;
    isThreshold = false;
  }
  else if (item.name == Object::ETTEM) type_ = ETTEM;
  else if (item.name == Object::ETMHF) type_ = ETMHF;
  else if (item.name.rfind(Object::EXT, 0) == 0) type_ = EXT;
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esObjectHandle::init: unknown type '" << item.name << "'");
  }

  // If object is a signal
  if (Object::signalName.count(item.name))
  {
    bx_offset_ = boost::lexical_cast<int>(item.bx_offset);
    return;
  }

  if (type_ == EXT)
  {
    bx_offset_ = boost::lexical_cast<int>(item.bx_offset);
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

  bx_offset_ = boost::lexical_cast<int>(item.bx_offset);
  std::string threshold = item.threshold;
  // TODO: implement common threshold conversion...
  boost::algorithm::replace_all(threshold, "p", ".");
  threshold_ = boost::lexical_cast<double>(threshold);

  // Set proper cut type for object.
  std::string cut_type = ET_THR;
  if (not isThreshold) cut_type = COUNT;

  // Create table for threshold cut.
  tmtable::Row cut;
  cut["name"] = item.name + "-" + cut_type + "_" + item.threshold; // MU-ET_1p2
  cut["object"] = item.name;
  cut["type"] = item.name + "-" + cut_type;
  cut["minimum"] = boost::str(boost::format("%+23.16E") % threshold_);
  cut["maximum"] = "";
  cut["data"] = "";

  // Create threshold cut from table.
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
