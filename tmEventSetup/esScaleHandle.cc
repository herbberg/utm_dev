#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Object.hh"
#include "tmGrammar/Cut.hh"
#include "tmEventSetup/esScaleHandle.hh"

// boost
#include <boost/lexical_cast.hpp>

// stl
#include <algorithm>


namespace tmeventsetup
{

esScaleHandle::esScaleHandle(const tmtable::Row& scale)
{
  object_ = static_cast<esObjectType>(Undef);
  const std::string obj = scale.find("object")->second;
  if (obj == Object::MU) object_ = Muon;
  else if (obj == Object::EG) object_ = Egamma;
  else if (obj == Object::TAU) object_ = Tau;
  else if (obj == Object::JET) object_ = Jet;
  else if (obj == Object::HTT) object_ = HTT;
  else if (obj == Object::ETT) object_ = ETT;
  else if (obj == Object::ETM) object_ = ETM;
  else if (obj == Object::HTM) object_ = HTM;
  else if (obj == Object::MBT0HFP) object_ = MBT0HFP;
  else if (obj == Object::MBT1HFP) object_ = MBT1HFP;
  else if (obj == Object::MBT0HFM) object_ = MBT0HFM;
  else if (obj == Object::MBT1HFM) object_ = MBT1HFM;
  else if (obj == Object::ETTEM) object_ = ETTEM;
  else if (obj == Object::ETMHF) object_ = ETMHF;
  else if (obj == Object::TOWERCOUNT) object_ = TOWERCOUNT;
  else if (obj == Object::ASYMET) object_ = ASYMET;
  else if (obj == Object::ASYMHT) object_ = ASYMHT;
  else if (obj == Object::ASYMETHF) object_ = ASYMETHF;
  else if (obj == Object::ASYMHTHF) object_ = ASYMHTHF;
  else if (obj == PRECISION) object_ = Precision;
  else
  {
    TM_FATAL_ERROR("unknown object: " << TM_QUOTE(obj));
  }


  type_ = static_cast<esScaleType>(Undef);
  const std::string type = scale.find("type")->second;
  if (type == ET_THR) type_ = EtScale;
  else if (type == Cut::ETA) type_ = EtaScale;
  else if (type == Cut::PHI) type_ = PhiScale;
  else if (type == Cut::UPT) type_ = UnconstraintPtScale;
  else if (type == COUNT) type_ = CountScale;
  else if (type.find(PRECISION_DELTA) != std::string::npos) type_ = DeltaPrecision;
  else if (type.find(PRECISION_OVRM_DELTA) != std::string::npos) type_ = OvRmDeltaPrecision;
  else if (type.find(PRECISION_MASSPT) != std::string::npos) type_ = MassPtPrecision;
  else if (type.find(PRECISION_MASS) != std::string::npos) type_ = MassPrecision;
  else if (type.find(PRECISION_MATH) != std::string::npos) type_ = MathPrecision;
  else if (type.find(PRECISION_TBPT_MATH) != std::string::npos) type_ = TwoBodyPtMathPrecision;
  else if (type.find(PRECISION_TBPT) != std::string::npos) type_ = TwoBodyPtPrecision;
  else
  {
    TM_FATAL_ERROR("unknown type " << TM_QUOTE(type));
  }

  name_ =  obj + "-" + type;
  minimum_ = boost::lexical_cast<double>(scale.find("minimum")->second);
  maximum_ = boost::lexical_cast<double>(scale.find("maximum")->second);
  step_ = boost::lexical_cast<double>(scale.find("step")->second);
  n_bits_ = boost::lexical_cast<unsigned int>(scale.find("n_bits")->second);
}


void
esScaleHandle::print() const
{
  TM_LOG_INF("");
  std::cout << "  name = " << name_ << "\n";
  std::cout << "  object = " << object_ << "\n";
  std::cout << "  type = " << type_ << "\n";
  std::cout << "  minimum = " << minimum_ << "\n";
  std::cout << "  maximum = " << maximum_ << "\n";
  std::cout << "  step = " << step_ << "\n";
  std::cout << "  n_bits = " << n_bits_ << "\n";
  std::cout << "  # of bins = " << bins_.size() << "\n";
  // for (size_t ii = 0; ii < bins_.size(); ii++) bins_.at(ii)->print();
}


struct less_than
{
  inline bool
  operator() (const esBin& o1, const esBin& o2)
  {
    return (o1.minimum < o2.minimum);
  }
};


void
esScaleHandle::sortBins()
{
  std::sort(bins_.begin(), bins_.end(), less_than());
}

} // namespace tmeventsetup

/* eof */
