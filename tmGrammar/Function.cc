/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <regex.h>

#include <algorithm>
#include <string>
#include <vector>

#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Object.hh"
#include "tmGrammar/Function.hh"

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>

/*====================================================================*
 * implementation
 *====================================================================*/
namespace Function
{

/** @cond INTERNAL */
struct Item_
{
  std::string name;
  std::vector<std::string> objects;
  std::string cuts;

  Item_() : name(), objects(), cuts() {}

  void print()
  {
    std::cout << "func = '" << name;
    std::cout << "' objs = ";
    for (size_t ii = 0; ii < objects.size(); ii++) {
      std::cout << "'" << objects.at(ii) << "' ";
    }
    std::cout << "cuts = '" << cuts << "'";
    std::cout << std::endl;
  }
}; // struct Item_

/** Comparison functor for object types .*/
struct equalObjectType
{
  int type;
  equalObjectType(int type) : type(type) {}
  bool operator()(const Object::Item& item) { return item.type == type; }
};

/** Get typ name of cut. TODO
 * getCutType("MU-ISO_FOO"); --> "MU-ISO"
 */
std::string
getCutType(const std::string& cut)
{
  std::vector<std::string> tokens;
  boost::split(tokens, cut, boost::is_any_of("_"));
  return tokens.front();
};

/** @endcond */



// ---------------------------------------------------------------------
// static variables
// ---------------------------------------------------------------------

/** @cond INTERNAL */

// map of functions
const reserved::value_type functionNames[] = {
  reserved::value_type(comb, 1),
  reserved::value_type(comb_orm, 1),
  reserved::value_type(dist, 1),
  reserved::value_type(dist_orm, 1),
  reserved::value_type(mass, 1),
  reserved::value_type(mass_inv, 1),
  reserved::value_type(mass_inv_orm, 1),
  reserved::value_type(mass_trv, 1),
  reserved::value_type(mass_trv_orm, 1),
  reserved::value_type(mass_inv_3_obj, 1)
};
const int nFunctionNames = sizeof(functionNames) / sizeof(functionNames[0]);
const reserved functionName(functionNames, functionNames + nFunctionNames);


// list of cuts for all overlap removal functions
const char* cutOvRm_[] = {
  Cut::ORMDETA,
  Cut::ORMDPHI,
  Cut::ORMDR
};
const std::vector<std::string> cutOvRm(cutOvRm_, cutOvRm_ + sizeof(cutOvRm_)/sizeof(cutOvRm_[0]));


// objects for combination function
const char* objComb_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objComb(objComb_, objComb_ + sizeof(objComb_)/sizeof(objComb_[0]));

// cuts for combination function
const char* cutComb_[] = {
  Cut::CHGCOR,
  Cut::TBPT
};
const std::vector<std::string> cutComb(cutComb_, cutComb_ + sizeof(cutComb_)/sizeof(cutComb_[0]));


// objects for combination with overlap removal function
const char* objCombOvRm_[] = {
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objCombOvRm(objCombOvRm_, objCombOvRm_ + sizeof(objCombOvRm_)/sizeof(objCombOvRm_[0]));

// cuts for combination with overlap removal function
const char* cutCombOvRm_[] = {
  Cut::ORMDETA,
  Cut::ORMDPHI,
  Cut::ORMDR,
  Cut::TBPT
};
const std::vector<std::string> cutCombOvRm(cutCombOvRm_, cutCombOvRm_ + sizeof(cutCombOvRm_)/sizeof(cutCombOvRm_[0]));


// objects for invariant mass function
const char* objMassInv_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objMassInv(objMassInv_, objMassInv_ + sizeof(objMassInv_)/sizeof(objMassInv_[0]));

// cuts for invariant mass function
const char* cutInvMass_[] = {
  Cut::MASS,
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::CHGCOR,
  Cut::TBPT
};
const std::vector<std::string> cutInvMass(cutInvMass_, cutInvMass_ + sizeof(cutInvMass_)/sizeof(cutInvMass_[0]));

// objects for invariant mass function with 3 objects
const char* objMassInvThreeObj_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objMassInvThreeObj(objMassInvThreeObj_, objMassInvThreeObj_ + sizeof(objMassInvThreeObj_)/sizeof(objMassInvThreeObj_[0]));

// cuts for invariant mass function with 3 objects
const char* cutInvMassThreeObj_[] = {
  Cut::MASS
};
const std::vector<std::string> cutInvMassThreeObj(cutInvMassThreeObj_, cutInvMassThreeObj_ + sizeof(cutInvMassThreeObj_)/sizeof(cutInvMassThreeObj_[0]));

// objects for transverse mass function
const char* objMassTrv_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET,
  Object::ETM,
  Object::HTM,
  Object::ETMHF
};
const std::vector<std::string> objMassTrv(objMassTrv_, objMassTrv_ + sizeof(objMassTrv_)/sizeof(objMassTrv_[0]));

// cuts for transverse mass function
const char* cutTrvMass_[] = {
  Cut::MASS,
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::CHGCOR,
  Cut::TBPT
};
const std::vector<std::string> cutTrvMass(cutTrvMass_, cutTrvMass_ + sizeof(cutTrvMass_)/sizeof(cutTrvMass_[0]));


// invariant mass objects with overlap removal
const char* objMassInvOvRm_[] = {
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objMassInvOvRm(objMassInvOvRm_, objMassInvOvRm_ + sizeof(objMassInvOvRm_)/sizeof(objMassInvOvRm_[0]));

// transverse mass objects with overlap removal
const char* objMassTrvOvRm_[] = {
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objMassTrvOvRm(objMassTrvOvRm_, objMassTrvOvRm_ + sizeof(objMassTrvOvRm_)/sizeof(objMassTrvOvRm_[0]));

// invariant mass cuts with overlap removal
const char* cutInvMassOvRm_[] = {
  Cut::ORMDETA,
  Cut::ORMDPHI,
  Cut::ORMDR,
  Cut::MASS,
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::TBPT
};
const std::vector<std::string> cutInvMassOvRm(cutInvMassOvRm_, cutInvMassOvRm_ + sizeof(cutInvMassOvRm_)/sizeof(cutInvMassOvRm_[0]));

// transverse mass cuts with overlap removal
const char* cutTrvMassOvRm_[] = {
  Cut::ORMDETA,
  Cut::ORMDPHI,
  Cut::ORMDR,
  Cut::MASS,
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::TBPT
};
const std::vector<std::string> cutTrvMassOvRm(cutTrvMassOvRm_, cutTrvMassOvRm_ + sizeof(cutTrvMassOvRm_)/sizeof(cutTrvMassOvRm_[0]));


// objects for distance function with eta and phi
const char* objDelta_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objDelta(objDelta_, objDelta_ + sizeof(objDelta_)/sizeof(objDelta_[0]));

// objects for distance function with phi
const char* objDeltaPhi_[] = {
  Object::MU,
  Object::EG,
  Object::TAU,
  Object::JET,
  Object::ETM,
  Object::HTM
};
const std::vector<std::string> objDeltaPhi(objDeltaPhi_, objDeltaPhi_ + sizeof(objDeltaPhi_)/sizeof(objDeltaPhi_[0]));

// cuts for distance function
const char* cutDist_[] = {
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::CHGCOR,
  Cut::TBPT
};
const std::vector<std::string> cutDist(cutDist_, cutDist_ + sizeof(cutDist_)/sizeof(cutDist_[0]));


// objects for distance with overlap removal function with eta and phi
const char* objDeltaOvRm_[] = {
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objDeltaOvRm(objDeltaOvRm_, objDeltaOvRm_ + sizeof(objDeltaOvRm_)/sizeof(objDeltaOvRm_[0]));

// objects for distance with overlap removal function with phi
const char* objDeltaPhiOvRm_[] = {
  Object::EG,
  Object::TAU,
  Object::JET
};
const std::vector<std::string> objDeltaPhiOvRm(objDeltaPhiOvRm_, objDeltaPhiOvRm_ + sizeof(objDeltaPhiOvRm_)/sizeof(objDeltaPhiOvRm_[0]));

// cuts for distance with overlap removal function
const char* cutDistOvRm_[] = {
  Cut::ORMDETA,
  Cut::ORMDPHI,
  Cut::ORMDR,
  Cut::DETA,
  Cut::DPHI,
  Cut::DR,
  Cut::TBPT
};
const std::vector<std::string> cutDistOvRm(cutDistOvRm_, cutDistOvRm_ + sizeof(cutDistOvRm_)/sizeof(cutDistOvRm_[0]));

/** @endcond */



// ---------------------------------------------------------------------
// constructor & destructor
// ---------------------------------------------------------------------
// nope


// ---------------------------------------------------------------------
// methods
// ---------------------------------------------------------------------
std::ostream&
Item::print(std::ostream& os) const
{
  os << "func = '" << name;
  os << "' cuts = ";
  for (size_t ii = 0; ii < cuts.size(); ii++) {
    os << "'" << cuts.at(ii) << "'";
  }
  os << std::endl;
  for (size_t ii = 0; ii < objects.size(); ii++) {
    os << "  ";
    objects.at(ii).print(os);
  }
  return os;
}


bool
Item::isValidObject(const std::string& object,
                    std::string& message)
{
  const std::vector<std::string>* objects = 0;

  switch (type)
  {
    case Distance:
    {
      if (metric & DeltaPhi) objects = &objDeltaPhi;
      if ((metric & DeltaEta) or (metric & DeltaR)) objects = &objDelta;
      if (not objects)
      {
        std::ostringstream oss;
        oss << "no metric specified for " << TM_QUOTE(Function::dist);
        if (message.length())
          message.append(", ");
        message.append(oss.str());
        TM_LOG_ERR(oss.str());
      }
    } break;

    case DistanceOvRm:
    {
      if (metric & DeltaPhi) objects = &objDeltaPhiOvRm;
      if ((metric & DeltaEta) or (metric & DeltaR)) objects = &objDeltaOvRm;
      if (not objects)
      {
        std::ostringstream oss;
        oss << "no metric specified for " << TM_QUOTE(Function::dist_orm);
        if (message.length())
          message.append(", ");
        message.append(oss.str());
        TM_LOG_ERR(oss.str());
      }
    } break;

    case Combination:
      objects = &objComb;
      break;

    case CombinationOvRm:
      objects = &objCombOvRm;
      break;

    case InvariantMass:
      objects = &objMassInv;
      break;

    case InvariantMassThreeObj:
      objects = &objMassInvThreeObj;
      break;

    case InvariantMassOvRm:
      objects = &objMassInvOvRm;
      break;

    case TransverseMass:
      objects = &objMassTrv;
      break;

    case TransverseMassOvRm:
      objects = &objMassTrvOvRm;
      break;

  } // switch (type)

  if (not objects) return false;

  std::vector<std::string>::const_iterator cit;
  for (cit = objects->begin(); cit != objects->end(); ++cit)
  {
    // NOTE: weak compare, reference list should be sorted by string length, descending
    if (object.compare(0, cit->length(), *cit) == 0)
    {
      return true;
    }
  }

  return false;
}


bool
Item::isValidCut(const std::string& cut,
                 std::string& message)
{
  const std::vector<std::string>* cuts = 0;

  switch (type)
  {
    case Distance:
      cuts = &cutDist;
      break;

    case DistanceOvRm:
      cuts = &cutDistOvRm;
      break;

    case Combination:
      cuts = &cutComb;
      break;

    case CombinationOvRm:
      cuts = &cutCombOvRm;
      break;

    case InvariantMass:
      cuts = &cutInvMass;
      break;

    case InvariantMassThreeObj:
      cuts = &cutInvMassThreeObj;
      break;

    case InvariantMassOvRm:
      cuts = &cutInvMassOvRm;
      break;

    case TransverseMass:
      cuts = &cutTrvMass;
      break;

    case TransverseMassOvRm:
      cuts = &cutTrvMassOvRm;
      break;
  }

  if (not cuts)
  {
    std::ostringstream oss;
    oss << "unkown cut type: " << type;
    if (message.length())
      message.append(", ");
    message.append(oss.str());
    TM_LOG_ERR(oss.str());
    return false;
  }

  std::vector<std::string>::const_iterator cit;
  for (cit = cuts->begin(); cit != cuts->end(); ++cit)
  {
    // NOTE: weak compare, reference list should be sorted by string length, descending
    if (cut.compare(0, cit->length(), *cit) == 0)
    {
      // set metric flags
      switch (type)
      {
        case Distance:
        case InvariantMass:
        case InvariantMassThreeObj:
        case TransverseMass:
        case DistanceOvRm:
        case InvariantMassOvRm:
        case TransverseMassOvRm:
        {
          if (*cit == Cut::DETA)
          {
            metric |= DeltaEta;
          }
          else if (*cit == Cut::DPHI)
          {
            metric |= DeltaPhi;
          }
          else if (*cit == Cut::DR)
          {
            metric |= DeltaR;
          }
        } break;
        default:
          break;
      }
      return true;
    }
  }

  std::ostringstream oss;
  oss << "unkown cut: " << TM_QUOTE(cut);
  if (message.length())
    message.append(", ");
  message.append(oss.str());
  TM_LOG_ERR(oss.str());
  return false;
}


int
Item::getType() const
{
  if (dist == name)
  {
    return Distance;
  }
  if (dist_orm == name)
  {
    return DistanceOvRm;
  }
  else if (comb == name)
  {
    return Combination;
  }
  else if (comb_orm == name)
  {
    return CombinationOvRm;
  }
  else if (mass == name) // for backward compatibility
  {
    return InvariantMass;
  }
  else if (mass_inv == name)
  {
    return InvariantMass;
  }
  else if (mass_inv_3_obj == name)
  {
    return InvariantMassThreeObj;
  }
  else if (mass_inv_orm == name)
  {
    return InvariantMassOvRm;
  }
  else if (mass_trv == name)
  {
    return TransverseMass;
  }
  else if (mass_trv_orm == name)
  {
    return TransverseMassOvRm;
  }
  return Unknown;
}

void
Item::appendMessage(const std::string& message)
{
  if (this->message.length())
    this->message.append(", ");
  this->message.append(message);
}


/** @cond INTERNAL */
bool
getObjects(const std::string& token,
           std::vector<std::string>& objects,
           std::string& message)
{
  TM_LOG_DBG(TM_VALUE_DBG(token));

  std::string text(token);
  while (text.length())
  {
    size_t offset = text.find_first_not_of(",]");
    if (offset > text.length()) break;
    text = text.substr(offset);

    const size_t length = text.length();
    const size_t cut_start = text.find_first_of("[");
    const size_t cut_stop = text.find_first_of("]");
    const size_t comma = text.find_first_of(",");

    // ignore comma in cut specification
    size_t end = (cut_start < comma and comma < cut_stop) ? cut_stop : comma;
    end = (end > length) ? length: end;

    TM_LOG_DBG(TM_VALUE_DBG(length) << ", " << TM_VALUE_DBG(end)
      << " [ = " << cut_start << " ] = " << cut_stop << " , " << comma);

    // include ']' in an object
    if (end == cut_stop) end += 1;

    std::string object = text.substr(0, end);
    TM_LOG_DBG(TM_VALUE_DBG(end) << ", " << TM_VALUE_DBG(object));
    objects.push_back(object);
    text = text.substr(end, length-end);
  }

  if (objects.size() < 2)
  {
    std::ostringstream oss;
    oss << "# of object < 2 " << TM_QUOTE(text);
    if (message.length())
      message.append(", ");
    message.append(oss.str());
    TM_LOG_ERR(oss.str());
    return false;
  }

  return true;
}

bool
validateObjectCount(Function::Item& item, const size_t min, const size_t max)
{
  const size_t count = item.objects.size();
  if (count < min or count > max)
  {
    std::ostringstream message;
    message << "invalid object count for function " << TM_QUOTE(item.name) << ": "
            << count << " (" << min << " <= objects <= " << max << ")";
    item.appendMessage(message.str());
    TM_LOG_ERR(message.str());
    return false;
  }
  return true;
}

bool
validateCombinationFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 4))
    return false;

  const size_t count = item.objects.size();
  const int firstType = item.objects.front().getType();

  // Check that all objects are of same type
  const size_t equalCount = std::count_if(item.objects.begin(), item.objects.end(), equalObjectType(firstType));
  if (count != equalCount)
  {
    std::ostringstream message;
    message << "invalid object combination for function "
            << TM_QUOTE(item.name) << ": all objects must be of same type";
    item.appendMessage(message.str());
    TM_LOG_ERR(message.str());
    return false;
  }

  return true;
}

/** Validate overlap removal objects assignment. */
bool
validateOvRmObjects(Function::Item& item)
{
  const size_t count = item.objects.size();
  const size_t countRight = 1;
  const size_t countLeft = count - countRight;
  const int firstType = item.objects.front().getType();
  const int lastType = item.objects.back().getType();

  // Check that first and last object is of different type
  if (firstType == lastType)
  {
    std::ostringstream message;
    message << "invalid object combination for overlap removal function "
            << TM_QUOTE(item.name) << ": right object must be of different type, eg. (tautau + jet)";
    item.appendMessage(message.str());
    TM_LOG_ERR(message.str());
    return false;
  }

  // Check that left objects are of same type
  const size_t equalCount = std::count_if(item.objects.begin(), item.objects.end(), equalObjectType(firstType));
  if (countLeft != equalCount)
  {
    std::ostringstream message;
    message << "invalid object combination for overlap removal function "
            << TM_QUOTE(item.name) << ": left objects must be of same type, eg. (tautau + jet)";
    item.appendMessage(message.str());
    TM_LOG_ERR(message.str());
    return false;
  }

  return true;
}

/** Validate if there is at least one overlap removal cut assigned. */
bool
validateOvRmCuts(Function::Item& item)
{
  std::vector<std::string>::const_iterator cit;
  for (cit = item.cuts.begin(); cit != item.cuts.end(); ++cit)
  {
    const std::string type = getCutType(*cit);
    if (std::count(cutOvRm.begin(), cutOvRm.end(), type))
      return true; // found at least one ovlerap removal cut
  }

  std::ostringstream message;
  message << "missing overlap removal cut for function " << TM_QUOTE(item.name);
  item.appendMessage(message.str());
  TM_LOG_ERR(message.str());

  return false;
}

/** Validate if there is at least one distance cut assigned. */
bool
validateDistanceCuts(Function::Item& item)
{
  std::vector<std::string>::const_iterator cit;
  for (cit = item.cuts.begin(); cit != item.cuts.end(); ++cit)
  {
    const std::string type = getCutType(*cit);
    if (Cut::DR == type or Cut::DETA == type or Cut::DPHI == type)
      return true; // found at least one distance cut
  }

  std::ostringstream message;
  message << " missing distance cut for function " << TM_QUOTE(item.name);
  item.appendMessage(message.str());
  TM_LOG_ERR(message.str());

  return false;
}

/** Validate if there is at least one mass cut assigned. */
bool
validateMassCuts(Function::Item& item)
{
  std::vector<std::string>::const_iterator cit;
  for (cit = item.cuts.begin(); cit != item.cuts.end(); ++cit)
  {
    const std::string type = getCutType(*cit);
    if (Cut::MASS == type)
      return true; // found at least one mass cut
  }

  std::ostringstream message;
  message << "missing mass cut for function " << TM_QUOTE(item.name);
  item.appendMessage(message.str());
  TM_LOG_ERR(message.str());

  return false;
}

/** Validate combination with overlap removal function objects and cuts. */
bool
validateCombinationOvRmFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 5))
    return false;

  // Check overlap removal objects type and order
  if (not validateOvRmObjects(item))
    return false;

  return true;
}

/** Validate distance function objects and cuts. */
bool
validateDistanceFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 2))
    return false;

  return true;
}

/** Validate distance with overlap removal function objects and cuts. */
bool
validateDistanceOvRmFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 3))
    return false;

  // Check overlap removal objects type and order
  if (not validateOvRmObjects(item))
    return false;

  if (not validateOvRmCuts(item))
    return false;

  return true;
}

/** Validate invariant mass function objects and cuts. */
bool
validateInvariantMassFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 2))
    return false;

  if (not validateMassCuts(item))
    return false;

  return true;
}

/** Validate invariant mass 3 objects function objects and cuts. */
bool
validateInvariantMassThreeObjFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 3, 3))
    return false;

  if (not validateMassCuts(item))
    return false;

  return true;
}

/** Validate invariant mass with overlap removal function objects and cuts. */
bool
validateInvariantMassOvRmFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 3))
    return false;

  // Check overlap removal objects type and order
  if (not validateOvRmObjects(item))
    return false;

  if (not validateMassCuts(item))
    return false;

  if (not validateOvRmCuts(item))
    return false;

  return true;
}

/** Validate transverse mass function objects and cuts. */
bool
validateTransverseMassFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 2))
    return false;

  if (not validateMassCuts(item))
    return false;

  return true;
}

/** Validate transverse mass with overlap removal function objects and cuts. */
bool
validateTransverseMassOvRmFunction(Function::Item& item)
{
  // Check number of objects
  if (not validateObjectCount(item, 2, 3))
    return false;

  // Check overlap removal objects type and order
  if (not validateOvRmObjects(item))
    return false;

  if (not validateMassCuts(item))
    return false;

  if (not validateOvRmCuts(item))
    return false;

  return true;
}
/** @endcond */


bool
parser(const std::string& function,
       Function::Item& item)
{
  const std::string trimmed = boost::trim_copy(function);
  // Build regular expression list of function names.
  std::ostringstream names;
  names << "(";
  reserved::const_iterator cit;
  for (cit = functionName.begin(); cit != functionName.end(); ++cit)
  {
    if (cit != functionName.begin())
      names << "|";
    names << cit->first;
  }
  names << ")";
  const std::string name = names.str();
  const std::string objects = "\\{(.+)\\}";
  const std::string cuts = "\\[(.+)\\]";
  regex_t regex;

  // try func(obj)[cut] format
  std::string expression = name + objects + cuts;
  if (tmutil::regex_compile(&regex, expression))
  {
    std::ostringstream message;
    message << "tmutil::regex_compile::error '" << expression << "'";
    item.appendMessage(message.str());
    return false;
  }

  std::vector<std::string> matched;
  tmutil::regex_match(&regex, trimmed, matched);
  regfree(&regex);

  Function::Item_ item_;

  // if matched function with cuts
  if (matched.size() == 3)
  {
    item_.name = matched.at(0);
    item_.cuts = matched.at(2);
    if (not getObjects(matched.at(1), item_.objects, item.message))
      return false;
  }
  // else try to match function without cuts
  else
  {
    // try func(obj) format
    expression = name + objects;
    if (tmutil::regex_compile(&regex, expression))
    {
      std::ostringstream message;
      message << "tmutil::regex_compile::error '" << expression << "'";
      item.appendMessage(message.str());
      return false;
    }

    matched.clear();
    tmutil::regex_match(&regex, trimmed, matched);
    regfree(&regex);

    if (matched.size() == 2)
    {
      item_.name = matched.at(0);
      if (not getObjects(matched.at(1), item_.objects, item.message))
        return false;
    }
  }

  item.name = item_.name;
  item.type = item.getType();

  // cut is mandatory except for Combination
  if ((item.type != Combination) and item_.cuts.empty())
  {
    std::ostringstream message;
    message << "no cut specified for " << TM_QUOTE(item.name);
    item.appendMessage(message.str());
    TM_LOG_ERR(message.str());
    return false;
  }

  // decode cuts
  if (item_.cuts.size())
  {
    Cut::Item cut;
    if (not Cut::parser(item_.cuts, cut))
    {
      item.appendMessage(cut.message);
      return false;
    }

    // populate function cuts
    for (size_t ii = 0; ii < cut.name.size(); ii++)
    {
      if (not item.isValidCut(cut.name.at(ii), item.message))
      {
        std::ostringstream message;
        message << "cut " << TM_QUOTE(cut.name.at(ii))
                << " is not valid for function " << TM_QUOTE(item.name);
        item.appendMessage(message.str());
        TM_LOG_ERR(message.str());
        return false;
      }
      item.cuts.push_back(cut.name.at(ii));
    }

    // test for mandatory function cuts
    for (size_t ii = 0; ii < item.cuts.size(); ii++)
    {
       // TODO: check allowed cuts for function
    }
  }

  int objectType = Object::Unknown;

  // decode objects
  for (size_t ii = 0; ii < item_.objects.size(); ii++)
  {
    Object::Item object;
    if (not Object::parser(item_.objects.at(ii), object))
    {
      item.appendMessage(object.message);
      return false;
    }

    if (not item.isValidObject(item_.objects.at(ii), item.message))
    {
      std::ostringstream message;
      message << "object " << TM_QUOTE(item_.objects.at(ii))
              << " is not valid for function " << TM_QUOTE(item.name)
              << ((item.type == Distance) ? " with the given metric" : "");
      item.appendMessage(message.str());
      TM_LOG_ERR(message.str());
      return false;
    }

    item.objects.push_back(object);
  }

  // Validate function integrity
  switch (item.type)
  {
    case Combination:
      return validateCombinationFunction(item);

    case CombinationOvRm:
      return validateCombinationOvRmFunction(item);

    case Distance:
      return validateDistanceFunction(item);

    case DistanceOvRm:
      return validateDistanceOvRmFunction(item);

    case InvariantMass:
      return validateInvariantMassFunction(item);

    case InvariantMassThreeObj:
      return validateInvariantMassThreeObjFunction(item);

    case InvariantMassOvRm:
      return validateInvariantMassOvRmFunction(item);

    case TransverseMass:
      return validateTransverseMassFunction(item);

    case TransverseMassOvRm:
      return validateTransverseMassOvRmFunction(item);
  }

  return false;
}


std::vector<std::string>
getCuts(const Item& item)
{
  std::vector<std::string> names;
  for (size_t ii = 0; ii < item.cuts.size(); ii++)
  {
    names.push_back(item.cuts.at(ii));
  }
  return names;
}


std::vector<std::string>
getObjects(const Item& item)
{
  std::vector<std::string> names;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    names.push_back(item.objects.at(ii).getObjectName());
  }
  return names;
}


std::vector<std::string>
getObjectCuts(const Item& item)
{
  std::vector<std::string> cuts;
  for (size_t ii = 0; ii < item.objects.size(); ii++)
  {
    std::string cut = boost::algorithm::join(item.objects.at(ii).cuts, ",");
    cuts.push_back(cut);
  }
  return cuts;
}


bool
isFunction(const std::string& element)
{
  reserved::const_iterator cit;
  for (cit = functionName.begin(); cit != functionName.end(); ++cit)
  {
    if (element.compare(0, cit->first.length(), cit->first) == 0)
    {
      Item function;
      if (parser(element, function))
        return true;
    }
  }

  return false;
}

} // namespace Function
/* eof */
