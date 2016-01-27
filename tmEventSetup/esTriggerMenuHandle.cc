#include <cstdio>
#include <locale>
#include <utility>
#include <sstream>

#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Function.hh"
#include "tmGrammar/Algorithm.hh"
#include "tmEventSetup/tmEventSetup.hh"
#include "tmEventSetup/esBin.hh"
#include "tmEventSetup/esScaleHandle.hh"
#include "tmEventSetup/esCutHandle.hh"
#include "tmEventSetup/esObjectHandle.hh"
#include "tmEventSetup/esConditionHandle.hh"
#include "tmEventSetup/esAlgorithmHandle.hh"
#include "tmEventSetup/esTriggerMenuHandle.hh"


namespace tmeventsetup
{

const std::string esTriggerMenuHandle::TupleName[] =
{
  "Unit",
  "Single",
  "Double",
  "Triple",
  "Quad",
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
    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getObjectCondition: not implemented '" << object.getType() << "'");
      break;
  }

  std::string name = TupleName[1] + getObjectName(object.getType());
  name += "_" + tmutil::toString(getHashUlong(token));
  conditionHandle.setName(name);

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
  else
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getFunctionCondition: unknown token: '" << token << "'");
  }

  std::string condition_name = condition.getName();
  condition_name += "_" + tmutil::toString(getHashUlong(token));
  condition.setName(condition_name);

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
        case nObjectType: break;
        case Muon: conditionHandle.setType(DoubleMuon); break;
        case Egamma: conditionHandle.setType(DoubleEgamma); break;
        case Tau: conditionHandle.setType(DoubleTau); break;
        case Jet: conditionHandle.setType(DoubleJet); break;
        case ETT: case HTT: case ETM: case HTM: case EXT:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    case 3:
      switch (type)
      {
        case nObjectType: break;
        case Muon: conditionHandle.setType(TripleMuon); break;
        case Egamma: conditionHandle.setType(TripleEgamma); break;
        case Tau: conditionHandle.setType(TripleTau); break;
        case Jet: conditionHandle.setType(TripleJet); break;
        case ETT: case HTT: case ETM: case HTM: case EXT:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    case 4:
      switch (type)
      {
        case nObjectType: break;
        case Muon: conditionHandle.setType(QuadMuon); break;
        case Egamma: conditionHandle.setType(QuadEgamma); break;
        case Tau: conditionHandle.setType(QuadTau); break;
        case Jet: conditionHandle.setType(QuadJet); break;
        case ETT: case HTT: case ETM: case HTM: case EXT:
          TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: not implemented '" << type << "'");
          break;
      }
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getCombCondition: unsupported # of objects '" << size << "'");
      break;
  }

  std::string condition_name = TupleName[size] + getObjectName(type);
  conditionHandle.setName(condition_name);

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

  std::string condition_name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(condition_name);

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
  if (nCut == 0 or nCut > 2)  // mass/chgcor
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getMassCondition: # of cuts not in [1,2] '" << nCut << "'");
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

  conditionHandle.setType(InvariantMass);
  std::string condition_name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(condition_name);

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
          tmutil::convert<unsigned int>(bins.at(jj).find("number")->second);
        const double min =
          tmutil::convert<double>(bins.at(jj).find("minimum")->second);
        const double max =
          tmutil::convert<double>(bins.at(jj).find("maximum")->second);
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
    external_map_[name] = tmutil::convert<unsigned int>(value);
    TM_LOG_DBG("esTriggerMenuHandle::setExternalMap: " << name << " " << value);
  }
}


unsigned int
esTriggerMenuHandle::getIndex(const esCutValue& cut, const std::string& range, const tmtable::Table& bins)
{
  char buf[BUFSIZ];
  if (snprintf(buf, sizeof(buf), "%+23.16E", cut.value) < 0)
  {
    TM_FATAL_ERROR("tmeventsetup::esTriggerMenuHandle::getIndex: '" << cut.value << "'");
  }
  std::string real(buf);
  TM_LOG_DBG("tmeventsetup::esTriggerMenuHandle::getIndex: value = " << real);

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
        const tmtable::Table& table = bins.find(key)->second;

        const esCutType type = static_cast<esCutType>(cut.getCutType());
        if (type == Threshold)
        {
          const esCutValue& cutValue = cut.getMinimum();
          cut.setMinimum(getIndex(cutValue, "minimum", table));
        }
        else if ((type == Eta) or (type == Phi))
        {
          const esCutValue& minimum = cut.getMinimum();
          cut.setMinimum(getIndex(minimum, "minimum", table));
          const esCutValue& maximum = cut.getMaximum();
          cut.setMaximum(getIndex(maximum, "maximum", table));
        }
      }
    }
  }
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
