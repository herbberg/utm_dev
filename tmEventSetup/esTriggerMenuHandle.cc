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

// String keys
const std::string kUnit("Unit");
const std::string kSingle("Single");
const std::string kDouble("Double");
const std::string kTriple("Triple");
const std::string kQuad("Quad");

// suffix
const std::string kOvRm("OvRm");

// keys for tables
const std::string kName("name");
const std::string kChannel("channel");

// Tuple names
const std::string esTriggerMenuHandle::TupleName[] =
{
  kUnit,
  kSingle,
  kDouble,
  kTriple,
  kQuad,
};

/** Returns const refrence to scale table or throws a std::runtime_error if
 * the required scale does not exist.
 */
const tmtable::Table& getScaleTable(const tmtable::StringTableMap& bins, const std::string& key)
{
    tmtable::StringTableMap::const_iterator result = bins.find(key);

    if (result == bins.end())
    {
      TM_FATAL_ERROR("missing scale set: " << TM_QUOTE(key));
    }

    return result->second;
}


esTriggerMenuHandle::esTriggerMenuHandle() : esTriggerMenu()
{
}


esTriggerMenuHandle::~esTriggerMenuHandle()
{
}


std::vector<std::string>
esTriggerMenuHandle::parse(const std::string& algorithm)
{
  Algorithm::Logic::clear();
  if (not Algorithm::parser(algorithm))
  {
    TM_FATAL_ERROR("parser error: " << TM_QUOTE(algorithm));
  }

  return Algorithm::Logic::tokens;
}


const std::string
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
    case ASYMET: return Object::ASYMET;
    case ASYMHT: return Object::ASYMHT;
    case ASYMETHF: return Object::ASYMETHF;
    case ASYMHTHF: return Object::ASYMHTHF;
    case CENT0: return Object::CENT0;
    case CENT1: return Object::CENT1;
    case CENT2: return Object::CENT2;
    case CENT3: return Object::CENT3;
    case CENT4: return Object::CENT4;
    case CENT5: return Object::CENT5;
    case CENT6: return Object::CENT6;
    case CENT7: return Object::CENT7;
    default:
      TM_FATAL_ERROR("unknown object type: " << TM_QUOTE(type));
      break;
  }

  return "";
}


const std::string
esTriggerMenuHandle::getConditionName(const int type)
{
  switch (type)
  {
    case MuonMuonCorrelation:     return "MuonMuonCorrelation";
    case MuonEsumCorrelation:     return "MuonEsumCorrelation";
    case CaloMuonCorrelation:     return "CaloMuonCorrelation";
    case CaloCaloCorrelation:     return "CaloCaloCorrelation";
    case CaloCaloCorrelationOvRm: return "CaloCaloCorrelationOvRm";
    case CaloEsumCorrelation:     return "CaloEsumCorrelation";
    case InvariantMass:           return "InvariantMass";
    case TransverseMass:          return "TransverseMass";
    case InvariantMassOvRm:       return "InvariantMassOvRm";
    case TransverseMassOvRm:      return "TransverseMassOvRm";
    case UptInvariantMass:        return "UptInvariantMass";
    default:
      TM_FATAL_ERROR("unknown condition type: " << TM_QUOTE(type));
      break;
  }

  return "";
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
    case ASYMET: conditionHandle.setType(AsymmetryEt); break;
    case ASYMHT: conditionHandle.setType(AsymmetryHt); break;
    case ASYMETHF: conditionHandle.setType(AsymmetryEtHF); break;
    case ASYMHTHF: conditionHandle.setType(AsymmetryHtHF); break;
    case CENT0: conditionHandle.setType(Centrality0); break;
    case CENT1: conditionHandle.setType(Centrality1); break;
    case CENT2: conditionHandle.setType(Centrality2); break;
    case CENT3: conditionHandle.setType(Centrality3); break;
    case CENT4: conditionHandle.setType(Centrality4); break;
    case CENT5: conditionHandle.setType(Centrality5); break;
    case CENT6: conditionHandle.setType(Centrality6); break;
    case CENT7: conditionHandle.setType(Centrality7); break;
    default:
      TM_FATAL_ERROR("not implemented: " << object.getType());
      break;
  }

  // If token already occurred set instance name, else create new instance name.
  if (token_to_condition_.count(token))
  {
    conditionHandle.setName(token_to_condition_.at(token));
  }
  else
  {
    std::ostringstream name;
    name << TupleName[1] << getObjectName(object.getType()) << "_i" << token_to_condition_.size(); // enumerate
    conditionHandle.setName(name.str());
  }

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getFunctionCondition(const std::string& token,
                                          const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  esCondition condition;
  Function::Item item;
  Function::parser(token, item);

  if (item.type == Function::Combination)
  {
    condition = getCombCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::CombinationOvRm)
  {
    condition = getOverlapRemovalCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::Distance)
  {
    condition = getDistCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::DistanceOvRm)
  {
    condition = getDistOverlapRemovalCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::InvariantMass)
  {
    condition = getMassCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::InvariantMassOvRm)
  {
    condition = getMassOverlapRemovalCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::TransverseMass)
  {
    condition = getMassCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::TransverseMassOvRm)
  {
    condition = getMassOverlapRemovalCondition(item, cuts_in_algo);
  }
  else if (item.type == Function::UptInvariantMass)
  {
    condition = getMassCondition(item, cuts_in_algo);
  }
  else
  {
    TM_FATAL_ERROR("unknown token: " << TM_QUOTE(token));
  }

  // If token already occurred set instance name, else create new instance name.
  if (token_to_condition_.count(token))
  {
    condition.setName(token_to_condition_.at(token));
  }
  else
  {
    std::ostringstream name;
    name << condition.getName() << "_i" << token_to_condition_.size(); // enumerate
    condition.setName(name.str());
  }

  return condition;
}


esCondition
esTriggerMenuHandle::getCombCondition(const Function::Item& item,
                                      const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  // multi-object condition
  esConditionHandle conditionHandle;

  // populate condition with objects
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  // populate condition with cuts
  for (size_t ii = 0; ii < item.cuts.size(); ii++)
  {
    for (size_t jj = 0; jj < cuts_in_algo.size(); jj++)
    {
      tmtable::Row& row = const_cast<tmtable::Row&>(cuts_in_algo.at(jj));
      if (item.cuts.at(ii) != row[kName]) continue;
      esCutHandle cutHandle(row);
      esCut& cut = cutHandle;
      conditionHandle.addCut(cut);
    }
  }

  const esObjectType type = static_cast<esObjectType>(conditionHandle.getObjects().at(0).getType());

  // count of objects
  const size_t count = conditionHandle.getObjects().size();

  // distinguish number of objects
  switch (count)
  {
    case 2: // double condition
      switch (type)
      {
        case Muon: conditionHandle.setType(DoubleMuon); break;
        case Egamma: conditionHandle.setType(DoubleEgamma); break;
        case Tau: conditionHandle.setType(DoubleTau); break;
        case Jet: conditionHandle.setType(DoubleJet); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    case 3: // triple condition
      switch (type)
      {
        case Muon: conditionHandle.setType(TripleMuon); break;
        case Egamma: conditionHandle.setType(TripleEgamma); break;
        case Tau: conditionHandle.setType(TripleTau); break;
        case Jet: conditionHandle.setType(TripleJet); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    case 4: // quad condition
      switch (type)
      {
        case Muon: conditionHandle.setType(QuadMuon); break;
        case Egamma: conditionHandle.setType(QuadEgamma); break;
        case Tau: conditionHandle.setType(QuadTau); break;
        case Jet: conditionHandle.setType(QuadJet); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    default:
      TM_FATAL_ERROR("unsupported # of objects: " << count);
      break;
  }

  // Set condition name
  std::ostringstream name;
  name << TupleName[count] << getObjectName(type); // TODO: segfault possible
  conditionHandle.setName(name.str());

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getOverlapRemovalCondition(const Function::Item& item,
                                                const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  esConditionHandle conditionHandle;

  // populate condition with objects
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  // populate condition with cuts
  for (size_t ii = 0; ii < item.cuts.size(); ii++)
  {
    for (size_t jj = 0; jj < cuts_in_algo.size(); jj++)
    {
      tmtable::Row& row = const_cast<tmtable::Row&>(cuts_in_algo.at(jj));
      if (item.cuts.at(ii) != row[kName]) continue;
      esCutHandle cutHandle(row);
      esCut& cut = cutHandle;
      conditionHandle.addCut(cut);
    }
  }

  // get list of objects to process
  const std::vector<esObject>& objects = conditionHandle.getObjects();

  // get type of first object
  const esObjectType type = static_cast<esObjectType>(objects.front().getType());

  // get type of possible different object (always last one)
  const esObjectType typeReference = static_cast<esObjectType>(objects.back().getType());

  // check for appended reference object of different type
  const bool hasReference = (type != typeReference);

  // count of objects (without possible reference)
  const size_t count = (hasReference ? objects.size() - 1 : objects.size());

  // distinguish number of left side objects
  switch (count)
  {
    case 1: // SingleOverlapRemoval
      switch (type)
      {
        case Egamma: conditionHandle.setType(SingleEgammaOvRm); break;
        case Tau: conditionHandle.setType(SingleTauOvRm); break;
        case Jet: conditionHandle.setType(SingleJetOvRm); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;
    case 2: // DoubleOverlapRemoval
      switch (type)
      {
        case Egamma: conditionHandle.setType(DoubleEgammaOvRm); break;
        case Tau: conditionHandle.setType(DoubleTauOvRm); break;
        case Jet: conditionHandle.setType(DoubleJetOvRm); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    case 3: // TripleOverlapRemoval
      switch (type)
      {
        case Egamma: conditionHandle.setType(TripleEgammaOvRm); break;
        case Tau: conditionHandle.setType(TripleTauOvRm); break;
        case Jet: conditionHandle.setType(TripleJetOvRm); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    case 4: // QuadOverlapRemoval
      switch (type)
      {
        case Egamma: conditionHandle.setType(QuadEgammaOvRm); break;
        case Tau: conditionHandle.setType(QuadTauOvRm); break;
        case Jet: conditionHandle.setType(QuadJetOvRm); break;
        default:
          TM_FATAL_ERROR("not implemented: " << TM_QUOTE(type));
          break;
      }
      break;

    default:
      TM_FATAL_ERROR("unsupported # of objects: " << count);
      break;
  }

  // Set condition name
  std::ostringstream name;
  name << TupleName[count] << getObjectName(type) << kOvRm;  // TODO: segfault possible
  conditionHandle.setName(name.str());

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getDistCondition(const Function::Item& item,
                                      const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  // distance (correlation) condition
  if (item.objects.size() != 2)
  {
    TM_FATAL_ERROR("# of objects != 2: " << item.objects.size());
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
    TM_FATAL_ERROR("# of cuts not in range [1,3]: " << nCut);
  }

  bool hasDistCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < item.cuts.size(); jj++)
    {
      TM_LOG_DBG("item.cuts.at(" << jj << "): " << item.cuts.at(jj));
      if (item.cuts.at(jj) != cut[kName]) continue;
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
        case TwoBodyPt:
          break;
        default:
          TM_FATAL_ERROR("unknown cut type: " << ref.getCutType());
      }
      conditionHandle.addCut(ref);
    }
  }

  if (not hasDistCut)
  {
    TM_FATAL_ERROR("no dist cut specified");
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
      TM_FATAL_ERROR("unknown combination type: " << combination);
  }

  // Set condition name
  std::string name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(name);

  esCondition& condition = conditionHandle;
  return condition;
}


esCondition
esTriggerMenuHandle::getDistOverlapRemovalCondition(const Function::Item& item,
                                                    const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  // distance (correlation) condition with overlap removal
  if (item.objects.size() < 2 or
      item.objects.size() > 3)
  {
    TM_FATAL_ERROR("# of objects != 2 or 2+1: " << item.objects.size());
  }

  esConditionHandle conditionHandle;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  size_t nCut = item.cuts.size();
  if (nCut == 0 or nCut > 6)  // deta/dphi/chgcor/ormdeta/ormdphi/ormdr combination possible
  {
    TM_FATAL_ERROR("# of cuts not in range [1,6]: " << nCut);
  }

  bool hasDistCut = false;
  bool hasOvRmCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < item.cuts.size(); jj++)
    {
      TM_LOG_DBG("item.cuts.at(" << jj << "): " << item.cuts.at(jj));
      if (item.cuts.at(jj) != cut[kName]) continue;
      esCutHandle cutHandle(cut);
      esCut& ref = cutHandle;
      switch (ref.getCutType())
      {
        case DeltaEta:
        case DeltaPhi:
        case DeltaR:
          hasDistCut = true;
          break;
        case OvRmDeltaEta:
        case OvRmDeltaPhi:
        case OvRmDeltaR:
          hasOvRmCut = true;
          break;
        case ChargeCorrelation:
          break;
        case TwoBodyPt:
          break;
        default:
          TM_FATAL_ERROR("unknown cut type: " << ref.getCutType());
      }
      conditionHandle.addCut(ref);
    }
  }

  if (not hasDistCut)
  {
    TM_FATAL_ERROR("missing dist cut (mandatory)");
  }

  if (not hasOvRmCut)
  {
    TM_FATAL_ERROR("missing overlap removal cut (mandatory)");
  }

  const esObjectType type1 = static_cast<esObjectType>(conditionHandle.getObjects().at(0).getType());
  const esObjectType type2 = static_cast<esObjectType>(conditionHandle.getObjects().at(1).getType());
  const esCombinationType combination = getObjectCombination(type1, type2);

  switch (combination)
  {
    case CaloCaloCombination: // NOTE !
      conditionHandle.setType(CaloCaloCorrelationOvRm); // NOTE !
      break;

    default:
      TM_FATAL_ERROR("unknown combination type: " << combination);
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
  TM_LOG_DBG("-");

  // invariant-mass condition
  if (item.objects.size() != 2)
  {
    TM_FATAL_ERROR("# of objects != 2: " << item.objects.size());
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
    TM_FATAL_ERROR("# of cuts not in range [1,5]: " << nCut);
  }

  bool hasMassCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < nCut; jj++)
    {
      if (item.cuts.at(jj) != cut[kName]) continue;
      esCutHandle cutHandle(cut);
      esCut& ref = cutHandle;
      if (ref.getCutType() == Mass) hasMassCut = true;
      conditionHandle.addCut(ref);
    }
  }

  if (not hasMassCut)
  {
    TM_FATAL_ERROR("no mass cut specified");
  }

  if (item.type == Function::InvariantMass)
    conditionHandle.setType(InvariantMass);
  else if (item.type == Function::TransverseMass)
    conditionHandle.setType(TransverseMass);
  else if (item.type == Function::UptInvariantMass)
    conditionHandle.setType(UptInvariantMass);

  // Set condition name
  std::string name = getConditionName(conditionHandle.getType());
  conditionHandle.setName(name);

  esCondition& condition = conditionHandle;

  return condition;
}


esCondition
esTriggerMenuHandle::getMassOverlapRemovalCondition(const Function::Item& item,
                                                    const tmtable::Table& cuts_in_algo)
{
  TM_LOG_DBG("-");

  // invariant-mass condition
  if (item.objects.size() < 2 or
      item.objects.size() > 3)
  {
    TM_FATAL_ERROR("# of objects != 2 or 2+1: " << item.objects.size());
  }

  esConditionHandle conditionHandle;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    esObjectHandle objectHandle(item.objects.at(ii), cuts_in_algo);
    esObject& object = objectHandle;
    conditionHandle.addObject(object);
  }

  size_t nCut = item.cuts.size();
  if (nCut == 0 or nCut > 7)  // mass/dR|(dEta/dPhi)/tbpt
  {
    TM_FATAL_ERROR("# of cuts not in range [1,7]: " << nCut);
  }

  bool hasMassCut = false;
  bool hasOvRmCut = false;
  for (size_t ii = 0; ii < cuts_in_algo.size(); ii++)
  {
    tmtable::Row& cut = const_cast<tmtable::Row&>(cuts_in_algo.at(ii));
    for (size_t jj = 0; jj < nCut; jj++)
    {
      if (item.cuts.at(jj) != cut[kName]) continue;
      esCutHandle cutHandle(cut);
      esCut& ref = cutHandle;
      if (ref.getCutType() == Mass) hasMassCut = true;
      if (ref.getCutType() == OvRmDeltaEta) hasOvRmCut = true;
      if (ref.getCutType() == OvRmDeltaPhi) hasOvRmCut = true;
      if (ref.getCutType() == OvRmDeltaR) hasOvRmCut = true;
      conditionHandle.addCut(ref);
    }
  }

  if (not hasMassCut)
  {
    TM_FATAL_ERROR("missing mass cut (mandatory)");
  }

  if (not hasOvRmCut)
  {
    TM_FATAL_ERROR("missing overlap removal cut (mandatory)");
  }

  if (item.type == Function::InvariantMassOvRm)
    conditionHandle.setType(InvariantMassOvRm);
  else if (item.type == Function::TransverseMassOvRm)
    conditionHandle.setType(TransverseMassOvRm);

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
  TM_LOG_DBG(TM_VALUE_DBG(condition_map_.size()));
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
    TM_FATAL_ERROR("unknown token: " << TM_QUOTE(token));
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
  TM_LOG_DBG(TM_VALUE_DBG(algorithm_map_.size()));

  esAlgorithmHandle algoHandle;
  algoHandle.init(algorithm);
  algoHandle.setExpressionInCondition(token_to_condition_);
  algoHandle.setRpnVector(parse(algoHandle.getExpressionInCondition()));

  esAlgorithm& algo = algoHandle;

  std::pair<std::map<std::string, esAlgorithm>::iterator, bool> rc;
  rc = algorithm_map_.insert(std::make_pair(algoHandle.getName(), algo));
  if (not rc.second)
  {
    TM_LOG_ERR("failed to insert algorithm: " << TM_QUOTE(algoHandle.getName()));
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
      const tmtable::Table& bins = getScaleTable(scale.bins, scaleHandle.getName());
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
    std::string name = externals.at(ii).find(kName)->second;
    std::string value = externals.at(ii).find(kChannel)->second;
    external_map_[name] = boost::lexical_cast<unsigned int>(value);
    TM_LOG_DBG(TM_QUOTE(name) << " : " << TM_QUOTE(value));
  }
}


unsigned int
esTriggerMenuHandle::getIndex(const esCutValue& cut, const std::string& range, const tmtable::Table& bins)
{
  // Convert double to string representation.
  std::string real = boost::str(boost::format("%+23.16E") % cut.value);
  TM_LOG_DBG(TM_VALUE_DBG(real));
  TM_LOG_DBG(TM_VALUE_DBG(range));

  unsigned int index = std::numeric_limits<unsigned int>::max();
  for (size_t ii = 0; ii < bins.size(); ii++)
  {
    // TODO: segfaults if key 'range' not found
    if (bins.at(ii).find(range)->second == real)
    {
      // TODO: segfaults if key 'number' not found
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
  TM_LOG_DBG("");
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
        TM_LOG_DBG(TM_VALUE_DBG(key));

        const esCutType type = static_cast<esCutType>(cut.getCutType());
        if ((type == Threshold) or (type == Count))
        {
          const tmtable::Table& table = getScaleTable(bins, key);
          const esCutValue& cutValue = cut.getMinimum();
          cut.setMinimumIndex(getIndex(cutValue, "minimum", table));
        }
        else if ((type == Eta) or (type == Phi))
        {
          const tmtable::Table& table = getScaleTable(bins, key);
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
  // Allow more than two objects to accept overlap removal conditions (third object).
  if (objects.size() < 2)
  {
    TM_FATAL_ERROR("# of objects < 2: " << objects.size());
  }
  const esObject& o1 = objects.at(0); // first type
  const esObject& o2 = objects.at(1); // second type

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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
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
          TM_FATAL_ERROR("unsupported type: " << o2.getType());
      }
      break;

    default:
      TM_FATAL_ERROR("unsupported type: " << o1.getType());
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
      case OvRmDeltaPrecision:
        break;

      default:
        continue;
    }

    std::pair<std::map<std::string, unsigned int>::iterator, bool> rc;
    rc = dictionary.insert(std::make_pair(cit->first, cit->second.getNbits()));
    if (not rc.second)
    {
      TM_FATAL_ERROR("insertion failure: " << TM_QUOTE(cit->first));
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
        case OvRmDeltaEta:
        case OvRmDeltaPhi:
        case OvRmDeltaR:
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
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        // Note: calculate M^2/2 for mass
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * 0.5 * scale) / scale;
        maximum = std::ceil(maximum * maximum *0.5 * scale) / scale;
      }
      else if (type == DeltaR)
      {
        key += "Delta";
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        // Note: calculate dR^2 for dR
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * scale) / scale;
        maximum = std::ceil(maximum * maximum * scale) / scale;
      }
      else if (type == OvRmDeltaR)
      {
        key += "DeltaOverlapRemoval";
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        // Note: calculate dR^2 for dR
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * scale) / scale;
        maximum = std::ceil(maximum * maximum * scale) / scale;
      }
      else if (type == TwoBodyPt)
      {
        key += "TwoBodyPt";
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * minimum * scale) / scale;
        // TODO: actually this is not used for two body pt threshold
        maximum = std::ceil(maximum * maximum * scale) / scale;
      }
      else if (type == DeltaEta or type == DeltaPhi)
      {
        key += "Delta";
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * scale) / scale;
        maximum = std::ceil(maximum * scale) / scale;
      }
      else if (type == OvRmDeltaEta or type == OvRmDeltaPhi)
      {
        key += "DeltaOverlapRemoval";
        if (not dictionary.count(key))
        {
          TM_FATAL_ERROR("missing precision scale set: " << TM_QUOTE(key));
        }
        precision = dictionary.find(key)->second;
        const double scale = tmutil::pow10(precision);
        minimum = std::floor(minimum * scale) / scale;
        maximum = std::ceil(maximum * scale) / scale;
      }
      else
      {
        TM_FATAL_ERROR("unsupported cut " << TM_QUOTE(cut.getName()) << " of type: " << type);
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

      std::map<std::string, esCondition>::const_iterator cit = condition_map_.find(token);
      if (cit == condition_map_.end())
      {
        TM_FATAL_ERROR("missing condition: " << TM_QUOTE(token));
      }

      const esCondition& condition = cit->second;
      esConditionHandle::print(condition);
    }
  }
}


} // namespace tmeventsetup

/* eof */
