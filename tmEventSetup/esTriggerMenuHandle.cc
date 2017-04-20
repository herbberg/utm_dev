// utm
#include "tmUtil/tmUtil.hh"

// utm Grammar
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Function.hh"
#include "tmGrammar/Algorithm.hh"

// utm EventSetup
#include "tmEventSetup/tmEventSetup.hh"
#include "tmEventSetup/esBin.hh"
#include "tmEventSetup/esScaleHandle.hh"
#include "tmEventSetup/esCutHandle.hh"
#include "tmEventSetup/esObjectHandle.hh"
#include "tmEventSetup/esConditionHandle.hh"
#include "tmEventSetup/esAlgorithmHandle.hh"
#include "tmEventSetup/esTriggerMenuHandle.hh"

// boost
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

// stl
#include <cmath>
#include <cstdio>
#include <locale>
#include <utility>
#include <sstream>

namespace tmeventsetup
{

// Strings
static const std::string kUnit("Unit");
static const std::string kSingle("Single");
static const std::string kDouble("Double");
static const std::string kTriple("Triple");
static const std::string kQuad("Quad");

// Tuple names
const std::string esTriggerMenuHandle::TupleName[] =
{
  kUnit,
  kSingle,
  kDouble,
  kTriple,
  kQuad,
};


std::vector<std::string>
esTriggerMenuHandle::parse(const std::string& algorithm)
{
  Algorithm::Logic::clear();
  if (not Algorithm::parser(algorithm))
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::parse: failed '" << algorithm << "'");
  }

  return Algorithm::Logic::tokens;
}


const char*
esTriggerMenuHandle::getObjectName(const int type)
{
  switch (type)
  {
    case Muon: return Object::MU;
    case Egamma: return Object::EG;
    case Tau: return Object::TAU;
    case Jet: return Object::JET;
    case ETT: return Object::ETT;
    case HTT: return Object::HTT;
    case ETM: return Object::ETM;
    case HTM: return Object::HTM;
    case EXT: return Object::EXT;
    case MBT0HFP: return Object::MBT0HFP;
    case MBT1HFP: return Object::MBT1HFP;
    case MBT0HFM: return Object::MBT0HFM;
    case MBT1HFM: return Object::MBT1HFM;
    case ETTEM: return Object::ETTEM;
    case ETMHF: return Object::ETMHF;
    case TOWERCOUNT: return Object::TOWERCOUNT;
    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getObjectName: unknown object type '" << type << "'");
      break;
  }

  return 0;
}


const char*
esTriggerMenuHandle::getConditionName(const int type)
{
  switch (type)
  {
    case MuonMuonCorrelation: return "MuonMuonCorrelation";
    case MuonEsumCorrelation: return "MuonEsumCorrelation";
    case CaloMuonCorrelation: return "CaloMuonCorrelation";
    case CaloCaloCorrelation: return "CaloCaloCorrelation";
    case CaloEsumCorrelation: return "CaloEsumCorrelation";
    case InvariantMass:       return "InvariantMass";
    case TransverseMass:       return "TransverseMass";
    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getConditionName: unknown condition type '" << type << "'");
      break;
  }

  return 0;
}


esCondition
esTriggerMenuHandle::getObjectCondition(const std::string& token,
                                        const tmtable::Table& cuts_in_algo)
{
  Object::Item item;
  Object::parser(token, item);
  esObjectHandle objectHandle(item, cuts_in_algo);
  objectHandle.setExternalChannelId(external_map_);
  esObject& object = objectHandle;

  esConditionHandle conditionHandle;
  conditionHandle.addObject(object);

  switch (object.getType())
  {
    case Muon: conditionHandle.setType(SingleMuon); break;
    case Egamma: conditionHandle.setType(SingleEgamma); break;
    case Tau: conditionHandle.setType(SingleTau); break;
    case Jet: conditionHandle.setType(SingleJet); break;
    case ETT: conditionHandle.setType(TotalEt); break;
    case HTT: conditionHandle.setType(TotalHt); break;
    case ETM: conditionHandle.setType(MissingEt); break;
    case HTM: conditionHandle.setType(MissingHt); break;
    case EXT: conditionHandle.setType(Externals); break;
    case MBT0HFP: conditionHandle.setType(MinBiasHFP0); break;
    case MBT1HFP: conditionHandle.setType(MinBiasHFP1); break;
    case MBT0HFM: conditionHandle.setType(MinBiasHFM0); break;
    case MBT1HFM: conditionHandle.setType(MinBiasHFM1); break;
    case ETTEM: conditionHandle.setType(TotalEtEM); break;
    case ETMHF: conditionHandle.setType(MissingEtHF); break;
    case TOWERCOUNT: conditionHandle.setType(TowerCount); break;
    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getObjectCondition: not implemented '" << object.getType() << "'");
      break;
  }

  // Set unique condition name
  std::ostringstream name;
  name << TupleName[1] << getObjectName(object.getType()) << "_" << getHashUlong(token);
  conditionHandle.setName(name.str());

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getFunctionCondition(const std::string& token,
                                          const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getFunctionCondition: -");

  esCondition condition;
  Function::Item item;
  Function::parser(token, item);

  if (item.type == Function::Combination)
  {
    condition = getCombCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::Distance)
  {
    condition = getDistCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::InvariantMass)
  {
    condition = getMassCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::TransverseMass)
  {
    condition = getMassCondition(item, cuts_in_algo);
  }
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getFunctionCondition: unknown token: '" << token << "'");
  }

  // Set condition name
  std::ostringstream name;
  name << condition.getName() << "_" << getHashUlong(token);
  condition.setName(name.str());

  return condition;
}


esCondition
esTriggerMenuHandle::getCombCondition(const Function::Item& item,
                                      const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getCombCondition: -");

  // multi-object condition
  esConditionHandle conditionHandle;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  for (size_t ii = 0; ii < item.cuts.size(); ii++)
  {
    for (size_t jj = 0; jj < cuts_in_algo.size(); jj++)
    {
      tmtable::Row& row = const_cast<tmtable::Row&>(cuts_in_algo.at(jj));
      if (item.cuts.at(ii) != row["name"]) continue;
      esCutHandle cutHandle(row);
      esCut& cut = cutHandle;
      conditionHandle.addCut(cut);
    }
  }

  const esObjectType type = static_cast<esObjectType>(conditionHandle.getObjects().at(0).getType());
  const size_t size = conditionHandle.getObjects().size();
  switch (size)
  {
    case 2:
      switch (type)
      {
        case Muon: conditionHandle.setType(DoubleMuon); break;
        case Egamma: conditionHandle.setType(DoubleEgamma); break;
        case Tau: conditionHandle.setType(DoubleTau); break;
        case Jet: conditionHandle.setType(DoubleJet); break;
        default:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    case 3:
      switch (type)
      {
        case Muon: conditionHandle.setType(TripleMuon); break;
        case Egamma: conditionHandle.setType(TripleEgamma); break;
        case Tau: conditionHandle.setType(TripleTau); break;
        case Jet: conditionHandle.setType(TripleJet); break;
        default:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    case 4:
      switch (type)
      {
        case Muon: conditionHandle.setType(QuadMuon); break;
        case Egamma: conditionHandle.setType(QuadEgamma); break;
        case Tau: conditionHandle.setType(QuadTau); break;
        case Jet: conditionHandle.setType(QuadJet); break;
        default:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: unsupported # of objects '" << size << "'");
      break;
  }

  // Set condition name
  std::ostringstream name;
  name << TupleName[size] << getObjectName(type);
  conditionHandle.setName(name.str());

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getDistCondition(const Function::Item& item,
                                      const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getDistCondition: -");

  // distance (correlation) condition
  if (item.objects.size() != 2)
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getDistCondition: # of conditions != 2 '" << item.objects.size() << "'");
  }

  esConditionHandle conditionHandle;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  size_t nCut = item.cuts.size();
  if (nCut == 0 or nCut > 3)  // deta/dphi/chgcor combination possible
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getDistCondition: # of cuts not in [1,3] '" << nCut << "'");
  }

  bool hasDistCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < item.cuts.size(); jj++)
    {
      TM_LOG_DBG(item.cuts.at(jj));
      if (item.cuts.at(jj) != cut["name"]) continue;
      esCutHandle cutHandle(cut);
      esCut& ref = cutHandle;
      switch (ref.getCutType())
      {
        case DeltaEta:
        case DeltaPhi:
        case DeltaR:
          hasDistCut = true;
          break;
        case ChargeCorrelation:
          break;
        default:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getDistCondition: unknown cut type = '" << ref.getCutType() << "'");
      }
      conditionHandle.addCut(ref);
    }
  }

  if (not hasDistCut)
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getDistCondition: no dist cut specified");
  }


  const esObjectType type1 = static_cast<esObjectType>(conditionHandle.getObjects().at(0).getType());
  const esObjectType type2 = static_cast<esObjectType>(conditionHandle.getObjects().at(1).getType());
  const esCombinationType combination = getObjectCombination(type1, type2);

  switch (combination)
  {
    case MuonMuonCombination:
      conditionHandle.setType(MuonMuonCorrelation);
      break;

    case MuonEsumCombination:
      conditionHandle.setType(MuonEsumCorrelation);
      break;

    case CaloMuonCombination:
      conditionHandle.setType(CaloMuonCorrelation);
      break;

    case CaloCaloCombination:
      conditionHandle.setType(CaloCaloCorrelation);
      break;

    case CaloEsumCombination:
      conditionHandle.setType(CaloEsumCorrelation);
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getDistCondition: unknown combination type = '" << combination << "'");
  }

  // Set condition name
  std::string name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(name);

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getMassCondition(const Function::Item& item,
                                      const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getMassCondition: -");

  // invariant-mass condition
  if (item.objects.size() != 2)
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getMassCondition: # of conditions != 2 '" << item.objects.size() << "'");
  }

  esConditionHandle conditionHandle;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  size_t nCut = item.cuts.size();
  if (nCut == 0 or nCut > 5)  // mass/chgcor/dR|(dEta/dPhi)/tbpt
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getMassCondition: # of cuts not in [1,5] '" << nCut << "'");
  }

  bool hasMassCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < nCut; jj++)
    {
      if (item.cuts.at(jj) != cut["name"]) continue;
      esCutHandle cutHandle(cut);
      esCut& ref = cutHandle;
      if (ref.getCutType() == Mass) hasMassCut = true;
      conditionHandle.addCut(ref);
    }
  }

  if (not hasMassCut)
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getMassCondition: no mass cut specified");
  }

  if (item.type == Function::InvariantMass)
    conditionHandle.setType(InvariantMass);
  else if (item.type == Function::TransverseMass)
    conditionHandle.setType(TransverseMass);

  // Set condition name
  std::string name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(name);

  esCondition& condition = conditionHandle;

  return condition;
}



void
esTriggerMenuHandle::setConditionMap(const std::string& token,
                                     const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::setConditionMap: " << condition_map_.size());
  if (Algorithm::isGate(token)) return;

  esCondition condition;

  if (Object::isObject(token))
  {
    condition = getObjectCondition(token, cuts_in_algo);
  }
  else if (Function::isFunction(token))
  {
    condition = getFunctionCondition(token, cuts_in_algo);
  }
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::setConditionMap: unknown token: '" << token << "'");
  }

  std::pair<std::map<std::string, std::string>::iterator, bool> rc;
  rc = token_to_condition_.insert(std::make_pair(token, condition.getName()));

  condition_map_.insert(std::make_pair(condition.getName(), condition));
#if defined(SWIG)
  condition_map_p_[condition.getName()] = &(condition_map_[condition.getName()]);
#endif
}



void
esTriggerMenuHandle::setAlgorithmMap(const tmtable::Row& algorithm)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::setAlgorithmMap: " << algorithm_map_.size());

  esAlgorithmHandle algoHandle;
  algoHandle.init(algorithm);
  algoHandle.setExpressionInCondition(token_to_condition_);
  algoHandle.setRpnVector(parse(algoHandle.getExpressionInCondition()));

  esAlgorithm& algo = algoHandle;

  std::pair<std::map<std::string, esAlgorithm>::iterator, bool> rc;
  rc = algorithm_map_.insert(std::make_pair(algoHandle.getName(), algo));
  if (not rc.second)
  {
    TM_LOG_ERR("tmeventsetup::esTriggerMenuHandle::setAlgorithmMap: " << algoHandle.getName());
  }
#if defined(SWIG)
  algorithm_map_p_[algoHandle.getName()] = &(algorithm_map_[algoHandle.getName()]);
#endif
}


void
esTriggerMenuHandle::setScaleMap(const tmtable::Scale& scale)
{
  const tmtable::Table& scales = scale.scales;
  for (size_t ii = 0; ii < scales.size(); ii++)
  {
    esScaleHandle scaleHandle(scales.at(ii));
    if (scaleHandle.getObjectType() != Precision)
    {
      const tmtable::Table& bins = scale.bins.find(scaleHandle.getName())->second;
      for (size_t jj = 0; jj < bins.size(); jj++)
      {
        const int id =
          boost::lexical_cast<unsigned int>(bins.at(jj).find("number")->second);
        const double min =
          boost::lexical_cast<double>(bins.at(jj).find("minimum")->second);
        const double max =
          boost::lexical_cast<double>(bins.at(jj).find("maximum")->second);
        scaleHandle.addBin(esBin(id, min, max));
      }
      scaleHandle.sortBins();
    }
    esScale& ref = scaleHandle;
    scale_map_[ref.getName()] = ref;
#if defined(SWIG)
    scale_map_p_[ref.getName()] = &(scale_map_[ref.getName()]);
#endif
  }
}


void
esTriggerMenuHandle::setExternalMap(const tmtable::ExtSignal& map)
{
  const tmtable::Table& externals = map.extSignals;
  for (size_t ii = 0; ii < externals.size(); ii++)
  {
    std::string name = externals.at(ii).find("name")->second;
    std::string value = externals.at(ii).find("channel")->second;
    external_map_[name] = boost::lexical_cast<unsigned int>(value);
    TM_LOG_DBG("esTriggerMenuHandle::setExternalMap: " << name << " " << value);
  }
}


unsigned int
esTriggerMenuHandle::getIndex(const esCutValue& cut, const std::string& range, const tmtable::Table& bins)
{
  // Convert double to string representation.
  std::string real = boost::str(boost::format("%+23.16E") % cut.value);
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getIndex: value = " << real);
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getIndex: range = " << range);

  unsigned int index = std::numeric_limits<unsigned int>::max();
  for (size_t ii = 0; ii < bins.size(); ii++)
  {
    if (bins.at(ii).find(range)->second == real)
    {
      std::istringstream ss(bins.at(ii).find("number")->second);
      if (not (ss >> index)) index = std::numeric_limits<unsigned int>::max();
      break;
    }
  }
  return index;
}



void
esTriggerMenuHandle::setHwIndex(const tmtable::StringTableMap& bins)
{
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::setHwIndex:");
  for (std::map<std::string, esCondition>::const_iterator cit = condition_map_.begin();
       cit != condition_map_.end(); cit++)
  {
    const std::vector<esObject>& objects = cit->second.getObjects();
    for (size_t ii = 0; ii < objects.size(); ii++)
    {
      const esObject& object = objects.at(ii);
      const std::vector<esCut>& cuts = object.getCuts();
      for (size_t jj = 0; jj < cuts.size(); jj++)
      {
        esCut& cut = const_cast<esCut&>(cuts.at(jj));
        if (cut.getObjectType() == static_cast<esObjectType>(Undef)) continue;
        const std::string key = cut.getKey();
        TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::setHwIndex: key = " << key);
        const tmtable::Table& table = bins.find(key)->second;

        const esCutType type = static_cast<esCutType>(cut.getCutType());
        if ((type == Threshold) or (type == Count))
        {
          const esCutValue& cutValue = cut.getMinimum();
          cut.setMinimumIndex(getIndex(cutValue, "minimum", table));
        }
        else if ((type == Eta) or (type == Phi))
        {
          const esCutValue& minimum = cut.getMinimum();
          cut.setMinimumIndex(getIndex(minimum, "minimum", table));
          const esCutValue& maximum = cut.getMaximum();
          cut.setMaximumIndex(getIndex(maximum, "maximum", table));
        }
      }
    }
  }
}


void
esTriggerMenuHandle::setPrefix4Precision(const std::vector<esObject>& objects,
                                         std::string& prefix)
{
  if (objects.size() != 2) TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: # of objects != 2");
  const esObject& o1 = objects.at(0);
  const esObject& o2 = objects.at(1);

  switch (o1.getType())
  {
    case Egamma:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-EG-";
          break;
        case Tau:
          prefix = "PRECISION-EG-TAU-";
          break;
        case Jet:
          prefix = "PRECISION-EG-JET-";
          break;
        case Muon:
          prefix = "PRECISION-EG-MU-";
          break;
        case ETM:
          prefix = "PRECISION-EG-ETM-";
          break;
        case HTM:
          prefix = "PRECISION-EG-HTM-";
          break;
        case ETMHF:
          prefix = "PRECISION-EG-ETMHF-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case Tau:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-TAU-";
          break;
        case Tau:
          prefix = "PRECISION-TAU-TAU-";
          break;
        case Jet:
          prefix = "PRECISION-JET-TAU-";
          break;
        case Muon:
          prefix = "PRECISION-TAU-MU-";
          break;
        case ETM:
          prefix = "PRECISION-TAU-ETM-";
          break;
        case HTM:
          prefix = "PRECISION-TAU-HTM-";
          break;
        case ETMHF:
          prefix = "PRECISION-TAU-ETMHF-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case Jet:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-JET-";
          break;
        case Tau:
          prefix = "PRECISION-JET-TAU-";
          break;
        case Jet:
          prefix = "PRECISION-JET-JET-";
          break;
        case Muon:
          prefix = "PRECISION-JET-MU-";
          break;
        case ETM:
          prefix = "PRECISION-JET-ETM-";
          break;
        case HTM:
          prefix = "PRECISION-JET-HTM-";
          break;
        case ETMHF:
          prefix = "PRECISION-JET-ETMHF-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case Muon:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-MU-";
          break;
        case Tau:
          prefix = "PRECISION-TAU-MU-";
          break;
        case Jet:
          prefix = "PRECISION-JET-MU-";
          break;
        case Muon:
          prefix = "PRECISION-MU-MU-";
          break;
        case ETM:
          prefix = "PRECISION-MU-ETM-";
          break;
        case HTM:
          prefix = "PRECISION-MU-HTM-";
          break;
        case ETMHF:
          prefix = "PRECISION-MU-ETMHF-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case ETM:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-ETM-";
          break;
        case Tau:
          prefix = "PRECISION-TAU-ETM-";
          break;
        case Jet:
          prefix = "PRECISION-JET-ETM-";
          break;
        case Muon:
          prefix = "PRECISION-MU-ETM-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case HTM:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-HTM-";
          break;
        case Tau:
          prefix = "PRECISION-TAU-HTM-";
          break;
        case Jet:
          prefix = "PRECISION-JET-HTM-";
          break;
        case Muon:
          prefix = "PRECISION-MU-HTM-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    case ETMHF:
      switch (o2.getType())
      {
        case Egamma:
          prefix = "PRECISION-EG-ETMHF-";
          break;
        case Tau:
          prefix = "PRECISION-TAU-ETMHF-";
          break;
        case Jet:
          prefix = "PRECISION-JET-ETMHF-";
          break;
        case Muon:
          prefix = "PRECISION-MU-ETMHF-";
          break;
        default:
          TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
      }
      break;

    default:
      TM_FATAL_ERROR("esTriggerMenuHandle::setPrefix4Precision: unsupported type = " << o1.getType());
  }
}


void
esTriggerMenuHandle::setFunctionCuts()
{
  std::map<std::string, unsigned int> dictionary;

  for (std::map<std::string, tmeventsetup::esScale>::const_iterator cit = scale_map_.begin();
       cit != scale_map_.end(); cit++)
  {
    switch (cit->second.getScaleType())
    {
      case DeltaPrecision:
      case MassPrecision:
      case TwoBodyPtPrecision:
        break;

      default:
        continue;
    }

    std::pair<std::map<std::string, unsigned int>::iterator, bool> rc;
    rc = dictionary.insert(std::make_pair(cit->first, cit->second.getNbits()));
    if (not rc.second)
    {
      TM_FATAL_ERROR("esTriggerMenuHandle::setFixedPointCuts: insertion failure");
    }
  }

  if (dictionary.empty()) return; // hm, why bail out?


  for (std::map<std::string, esCondition>::const_iterator cit = condition_map_.begin();
       cit != condition_map_.end(); cit++)
  {
    const std::vector<tmeventsetup::esCut>& cuts = cit->second.getCuts();

    for (size_t ii = 0; ii < cuts.size(); ii++)
    {
      tmeventsetup::esCut& cut = const_cast<tmeventsetup::esCut&>(cuts.at(ii));
      const int type = cut.getCutType();
      switch (type)
      {
        case DeltaEta:
        case DeltaPhi:
        case DeltaR:
        case Mass:
        case TwoBodyPt:
          break;
        default:
          continue;
      }

      const std::vector<esObject>& objects = cit->second.getObjects();
      std::string key;
      setPrefix4Precision(objects, key);

      double minimum = cut.getMinimumValue();
      double maximum = cut.getMaximumValue();

      unsigned int precision = 0;
      if (type == Mass)
      {
        key += "Mass";
        precision = dictionary.find(key)->second;
        // Note: calculate M^2/2 for mass
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * 0.5 * scale) / scale;
        maximum = std::ceil(maximum * maximum *0.5 * scale) / scale;
      }
      else if (type == DeltaR)
      {
        key += "Delta";
        precision = dictionary.find(key)->second;
        // Note: calculate dR^2 for dR
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * scale) / scale;
        maximum = std::ceil(maximum * maximum * scale) / scale;
      }
      else if (type == TwoBodyPt)
      {
        key += "TwoBodyPt";
        precision = dictionary.find(key)->second;
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * scale) / scale;
        // TODO: actually this is not used for two body pt threshold
        maximum = std::ceil(maximum * maximum * scale) / scale;
      }
      else
      {
        key += "Delta";
        precision = dictionary.find(key)->second;
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * scale) / scale;
        maximum = std::ceil(maximum * scale) / scale;
      }

      cut.setMinimumValue(minimum);
      cut.setMaximumValue(maximum);
      cut.setPrecision(precision); // TODO set both minimum/maximum index
    } // for cut
  } // for condition
}


void
esTriggerMenuHandle::print() const
{
  for (std::map<std::string, esAlgorithm>::const_iterator cit = algorithm_map_.begin();
       cit != algorithm_map_.end(); cit++)
  {
    const esAlgorithm& algorithm = cit->second;
    esAlgorithmHandle::print(algorithm);
    const std::vector<std::string>& rpn = algorithm.getRpnVector();
    for (size_t ii = 0; ii < rpn.size(); ii++)
    {
      const std::string& token = rpn.at(ii);
      if (Algorithm::isGate(token)) continue;
      const esCondition& condition = condition_map_.find(token)->second;
      esConditionHandle::print(condition);
    }
  }
}


} // namespace tmeventsetup

/* eof */
