#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Object.hh"
#include "tmEventSetup/esCutHandle.hh"


namespace tmeventsetup
{

esCutHandle::esCutHandle(const tmtable::Row& cut)
{
  name_ = cut.find("name")->second;

  std::vector<std::string> tokens;
  tmutil::tokenise(cut.find("type")->second, tokens, "-");

  object_type_ = static_cast<esObjectType>(Undef);
  cut_type_ = static_cast<esCutType>(Undef);
  std::string text;
  switch (tokens.size())
  {
    case 2:
      text = tokens.front();
      if (text == Object::MU) object_type_ = Muon;
      else if (text == Object::EG) object_type_ = Egamma;
      else if (text == Object::TAU) object_type_ = Tau;
      else if (text == Object::JET) object_type_ = Jet;
      else if (text == Object::ETM) object_type_ = ETM;
      else if (text == Object::HTM) object_type_ = HTM;
      else if (text == Object::ETT) object_type_ = ETT;
      else if (text == Object::HTT) object_type_ = HTT;
      else
      {
        TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown object_type '" << text << "'");
      }
      // fall through

    case 1:
      text = tokens.back();
      if (text == ET_THR) cut_type_ = Threshold;
      else if (text == Cut::ISO) cut_type_ = Isolation;
      else if (text == Cut::ETA) cut_type_ = Eta;
      else if (text == Cut::QLTY) cut_type_ = Quality;
      else if (text == Cut::CHG) cut_type_ = Charge;
      else if (text == Cut::PHI) cut_type_ = Phi;
      else if (text == Cut::DETA)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaEta;
      }
      else if (text == Cut::DPHI)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaPhi;
      }
      else if (text == Cut::DR)
      {
        object_type_ = static_cast<esObjectType>(DistFunction);
        cut_type_ = DeltaR;
      }
      else if (text == Cut::MASS)
      {
        object_type_ = static_cast<esObjectType>(MassFunction);
        cut_type_ = Mass;
      }
      else if (text == Cut::CHGCOR)
      {
        object_type_ = static_cast<esObjectType>(CombFunction);
        cut_type_ = ChargeCorrelation;
      }
      else
      {
        TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown cut_type '" << text << "'");
      }
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::ctor: unknown case '" << cut.find("type")->second << "'");
      break;
  }

  minimum_.value = tmutil::convert<double>(cut.find("minimum")->second);
  maximum_.value = tmutil::convert<double>(cut.find("maximum")->second);
  setData(cut.find("data")->second);
  setKey();
}


void
esCutHandle::setData(const std::string& x)
{
  data_ = x;
  switch (cut_type_)
  {
    case Quality:
    case Isolation:
      if (data_.find(',') == std::string::npos)
      {
        unsigned int data = (1 << tmutil::convert<unsigned int>(x));
        data_ = tmutil::toString(data);
      }
      else
      {
        // LUT data stored as comma separated values, take or of all the bit patterns
        std::vector<std::string> tokens;
        tmutil::tokenise(x, tokens, ",");
        unsigned int data = 0;
        for (size_t ii = 0; ii < tokens.size(); ii++)
        {
          data |= (1 << tmutil::convert<unsigned int>(tokens.at(ii)));
        }
        data_ = tmutil::toString(data);
      }

    default:
      break;
  }
}


void
esCutHandle::setKey()
{
  TM_LOG_DBG("tmeventsetup::esCutHandle::getKey");
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
    case CombFunction: break;
    case DistFunction: break;
    case MassFunction: break;
    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::getKey: error '" << object_type_ << "'");
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
    default:
      TM_FATAL_ERROR("tmeventsetup::esCutHandle::getKey: error '" << cut_type_ << "'");
      break;
  }
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
}

} // namespace tmeventsetup

/* eof */
