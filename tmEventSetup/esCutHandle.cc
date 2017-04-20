#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Object.hh"
#include "tmEventSetup/esCutHandle.hh"

#include <boost/algorithm/string/replace.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

namespace tmeventsetup
{

esCutHandle::esCutHandle(const tmtable::Row& cut)
{
  TM_LOG_DBG("tmeventsetup::esCutHandle::setKey");

  name_ = cut.find("name")->second;
  std::string type = cut.find("type")->second;
  TM_LOG_DBG("tmeventsetup::esCutHandle::setKey: name_ = " << name_);
  TM_LOG_DBG("tmeventsetup::esCutHandle::setKey: type = " << type);

  // Split cut type into tokens, eg. "MU-ISO" -> ["MU", "ISO"].
  boost::char_separator<char> sep("-");
  boost::tokenizer<boost::char_separator<char> > tok(type, sep);
  std::vector<std::string> tokens(tok.begin(), tok.end());

  object_type_ = static_cast<esObjectType>(Undef);
  cut_type_ = static_cast<esCutType>(Undef);
  std::string token;
  switch (tokens.size())
  {
    case 2:
      token = tokens.front();
      if (token == Object::MU) object_type_ = Muon;
      else if (token == Object::EG) object_type_ = Egamma;
      else if (token == Object::TAU) object_type_ = Tau;
      else if (token == Object::JET) object_type_ = Jet;
      else if (token == Object::ETM) object_type_ = ETM;
      else if (token == Object::HTM) object_type_ = HTM;
      else if (token == Object::ETT) object_type_ = ETT;
      else if (token == Object::HTT) object_type_ = HTT;
      else if (token == Object::MBT0HFP) object_type_ = MBT0HFP;
      else if (token == Object::MBT1HFP) object_type_ = MBT1HFP;
      else if (token == Object::MBT0HFM) object_type_ = MBT0HFM;
      else if (token == Object::MBT1HFM) object_type_ = MBT1HFM;
      else if (token == Object::ETTEM) object_type_ = ETTEM;
      else if (token == Object::ETMHF) object_type_ = ETMHF;
      else if (token == Object::TOWERCOUNT) object_type_ = TOWERCOUNT;
      else
      {
        TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown object_type '" << token << "'");
      }
      // fall through

    case 1:
      token = tokens.back();
      if (token == ET_THR) cut_type_ = Threshold;
      else if (token == Cut::ISO) cut_type_ = Isolation;
      else if (token == Cut::ETA) cut_type_ = Eta;
      else if (token == Cut::QLTY) cut_type_ = Quality;
      else if (token == Cut::CHG) cut_type_ = Charge;
      else if (token == Cut::PHI) cut_type_ = Phi;
      else if (token == Cut::SLICE) cut_type_ = Slice;
      else if (token == COUNT) cut_type_ = Count;
      else if (token == Cut::DETA)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaEta;
      }
      else if (token == Cut::DPHI)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaPhi;
      }
      else if (token == Cut::DR)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaR;
      }
      else if (token == Cut::MASS)
      {
        object_type_ = static_cast<esObjectType>(MassFunction);
        cut_type_ = Mass;
      }
      else if (token == Cut::CHGCOR)
      {
        object_type_ = static_cast<esObjectType>(CombFunction);
        cut_type_ = ChargeCorrelation;
      }
      else if (token == Cut::TBPT)
      {
        object_type_ = static_cast<esObjectType>(MassFunction);
        cut_type_ = TwoBodyPt;
      }
      else if (token == Cut::ORMDETA)
      {
        object_type_ = static_cast<esObjectType>(DistFunction); // HACK
        cut_type_ = OvRmDeltaEta;
      }
      else if (token == Cut::ORMDPHI)
      {
        object_type_ = static_cast<esObjectType>(DistFunction); // HACK
        cut_type_ = OvRmDeltaPhi;
      }
      else if (token == Cut::ORMDR)
      {
        object_type_ = static_cast<esObjectType>(DistFunction); // HACK
        cut_type_ = OvRmDeltaR;
      }
      else
      {
        TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown cut_type '" << token << "'");
      }
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown case '" << type << "'");
      break;
  }

  std::string minimum = cut.find("minimum")->second;
  std::string maximum = cut.find("maximum")->second;

  if (cut_type_ == Threshold)
  {
    // Convert threshold to floating point representation.
    // TODO: implement common threshold conversion...
    boost::algorithm::replace_all(minimum, "p", ".");
  }

  // Set minimum value if available.
  if (not minimum.empty())
  {
    try
    {
      setMinimumValue(boost::lexical_cast<double>(minimum));
    }
    catch (boost::bad_lexical_cast& e)
    {
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: invalid minimum value '" << minimum << "' for cut '" << name_ << "'");
    }
  }

  // Set maximum value if available.
  if (not maximum.empty())
  {
    try
    {
      setMaximumValue(boost::lexical_cast<double>(maximum));
    }
    catch (boost::bad_lexical_cast& e)
    {
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: invalid maximum value '" << maximum << "' for cut '" << name_ << "'");
    }
  }

  // Set data.
  setData(cut.find("data")->second);
  setKey();
}


void
esCutHandle::setData(const std::string& data)
{
  data_ = data;
  switch (cut_type_)
  {
    case Quality:
    case Isolation:
    {
      // LUT data stored as comma separated values, take or of all the bit patterns
      // TODO: common function for LUT validation and conversion.

      // Split comma separated LUT data, eg. "1,2,3" -> ["1", "2", "3"].
      boost::char_separator<char> sep(",");
      boost::tokenizer<boost::char_separator<char> > tok(data, sep);
      std::vector<std::string> tokens(tok.begin(), tok.end());

      // Logical OR for LUT values, eg. 1,2,3 -> 0xe
      unsigned int value = 0;
      for (size_t ii = 0; ii < tokens.size(); ++ii)
      {
        try
        {
          value |= (1 << boost::lexical_cast<unsigned int>(tokens.at(ii)));
        }
        catch(boost::bad_lexical_cast& e)
        {
          TM_FATAL_ERROR("tmeventsetup::esCutHandle::setData: invalid LUT data for quality/isolation: '" << data << "'");
        }
      }
      data_ = boost::lexical_cast<std::string>(value);
    } break;

    default:
      break;
  }
}


void
esCutHandle::setKey()
{
  TM_LOG_DBG("tmeventsetup::esCutHandle::setKey");
  switch (object_type_)
  {
    case Muon: key_ = Object::MU; break;
    case Egamma: key_ = Object::EG; break;
    case Tau: key_ = Object::TAU; break;
    case Jet: key_ = Object::JET; break;
    case ETM: key_ = Object::ETM; break;
    case HTM: key_ = Object::HTM; break;
    case ETT: key_ = Object::ETT; break;
    case HTT: key_ = Object::HTT; break;
    case MBT0HFP: key_ = Object::MBT0HFP; break;
    case MBT1HFP: key_ = Object::MBT1HFP; break;
    case MBT0HFM: key_ = Object::MBT0HFM; break;
    case MBT1HFM: key_ = Object::MBT1HFM; break;
    case ETTEM: key_ = Object::ETTEM; break;
    case ETMHF: key_ = Object::ETMHF; break;
    case TOWERCOUNT: key_ = Object::TOWERCOUNT; break;
    case CombFunction: break;
    case DistFunction: break;
    case MassFunction: break; // alias for invariant mass
    case InvariantMassFunction: break;
    case TransverseMassFunction: break;
    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::setKey: error '" << object_type_ << "'");
      break;
  }

  key_ += "-";

  switch (cut_type_)
  {
    case Threshold: key_ += ET_THR; break;
    case Eta: key_ += Cut::ETA; break;
    case Phi: key_ += Cut::PHI; break;
    case Charge: key_ += Cut::CHG; break;
    case Quality: key_ += Cut::QLTY; break;
    case Isolation: key_ += Cut::ISO; break;
    case DeltaEta: key_ += Cut::DETA; break;
    case DeltaPhi: key_ += Cut::DPHI; break;
    case DeltaR: key_ += Cut::DR; break;
    case Mass: key_ += Cut::MASS; break;
    case ChargeCorrelation: key_ += Cut::CHGCOR; break;
    case Slice: key_ += Cut::SLICE; break;
    case Count: key_ += COUNT; break;
    case TwoBodyPt: key_ += Cut::TBPT; break;
    case OvRmDeltaEta: key_ += Cut::ORMDETA; break;
    case OvRmDeltaPhi: key_ += Cut::ORMDPHI; break;
    case OvRmDeltaR: key_ += Cut::ORMDR; break;
    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::setKey: error '" << cut_type_ << "'");
      break;
  }
  TM_LOG_DBG("tmeventsetup::esCutHandle::setKey: " << key_);
}


void
esCutHandle::print() const
{
  std::cout << "tmeventsetup::esCutHandle::print\n";
  std::cout << "  name = " << name_ << "\n";
  std::cout << "  object type = " << object_type_ << "\n";
  std::cout << "  cut type = " << cut_type_ << "\n";
  std::cout << "  minimum.value = " << minimum_.value << "\n";
  std::cout << "  minimum.index = " << minimum_.index << "\n";
  std::cout << "  maximum.value = " << maximum_.value << "\n";
  std::cout << "  maximum.index = " << maximum_.index << "\n";
  std::cout << "  data = " << data_ << "\n";
  std::cout << "  key = " << key_ << "\n";
  std::cout << "  precision = " << minimum_.index << "\n";
}

void
esCutHandle::print(const esCut& cut)
{
  std::cout << "tmeventsetup::esCutHandle::print\n";
  std::cout << "  name = " << cut.getName() << "\n";
  std::cout << "  object type = " << cut.getObjectType() << "\n";
  std::cout << "  cut type = " << cut.getCutType() << "\n";
  std::cout << "  minimum.value = " << cut.getMinimum().value << "\n";
  std::cout << "  minimum.index = " << cut.getMinimum().index << "\n";
  std::cout << "  maximum.value = " << cut.getMaximum().value << "\n";
  std::cout << "  maximum.index = " << cut.getMaximum().index << "\n";
  std::cout << "  data = " << cut.getData() << "\n";
  std::cout << "  key = " << cut.getKey() << "\n";
  std::cout << "  precision = " << cut.getPrecision() << "\n";
}

} // namespace tmeventsetup

/* eof */
