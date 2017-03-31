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

#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Object.hh"
#include "tmGrammar/Function.hh"

#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/join.hpp>

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
/** @endcond */



// ---------------------------------------------------------------------
// static variables
// ---------------------------------------------------------------------

// all the function names
/** @cond INTERNAL */
const reserved::value_type function_names[] = {
  reserved::value_type(comb, 1),
  reserved::value_type(mass, 1),
  reserved::value_type(dist, 1),
  reserved::value_type(mass_inv, 1),
  reserved::value_type(mass_trv, 1)
};
const int n_function_names = sizeof(function_names) / sizeof(function_names[0]);
const reserved functionName(function_names, function_names + n_function_names);


// comb
const char* objComb_[] = {Object::MU, Object::EG, Object::TAU, Object::JET};
const std::vector<std::string> objComb(objComb_, objComb_ + sizeof(objComb_)/sizeof(objComb_[0]));

const char* cutComb_[] = {Cut::CHGCOR};
const std::vector<std::string> cutComb(cutComb_, cutComb_ + sizeof(cutComb_)/sizeof(cutComb_[0]));


// invariant mass
const char* objInvariantMass_[] = {Object::MU, Object::EG, Object::TAU, Object::JET};
const std::vector<std::string> objInvariantMass(objInvariantMass_, objInvariantMass_ + sizeof(objInvariantMass_)/sizeof(objInvariantMass_[0]));

// transverse mass
const char* objTransverseMass_[] = {Object::MU, Object::EG, Object::TAU, Object::JET, Object::ETM, Object::HTM, Object::ETMHF};
const std::vector<std::string> objTransverseMass(objTransverseMass_, objTransverseMass_ + sizeof(objTransverseMass_)/sizeof(objTransverseMass_[0]));

// mass (invariant and transverse)
const char* cutMass_[] = {Cut::MASS, Cut::DETA, Cut::DPHI, Cut::DR, Cut::CHGCOR, Cut::TBPT};
const std::vector<std::string> cutMass(cutMass_, cutMass_ + sizeof(cutMass_)/sizeof(cutMass_[0]));


// dist
const char* objDelta_[] = {Object::MU, Object::EG, Object::TAU, Object::JET};
const std::vector<std::string> objDelta(objDelta_, objDelta_ + sizeof(objDelta_)/sizeof(objDelta_[0]));

const char* objDeltaPhi_[] = {Object::MU, Object::EG, Object::TAU, Object::JET, Object::ETM, Object::HTM};
const std::vector<std::string> objDeltaPhi(objDeltaPhi_, objDeltaPhi_ + sizeof(objDeltaPhi_)/sizeof(objDeltaPhi_[0]));

const char* cutDist_[] = {Cut::DETA, Cut::DPHI, Cut::DR, Cut::CHGCOR};
const std::vector<std::string> cutDist(cutDist_, cutDist_ + sizeof(cutDist_)/sizeof(cutDist_[0]));
/** @endcond */



// ---------------------------------------------------------------------
// constructor & destructor
// ---------------------------------------------------------------------
// nope


// ---------------------------------------------------------------------
// methods
// ---------------------------------------------------------------------
void
Item::print()
{
  std::cout << "func = '" << name;
  std::cout << "' cuts = ";
  for (size_t ii = 0; ii < cuts.size(); ii++) {
    std::cout << "'" << cuts.at(ii) << "'";
  }
  std::cout << std::endl;
  for (size_t ii = 0; ii < objects.size(); ii++) {
    std::cout << "  ";
    objects.at(ii).print();
  }
}


bool
Item::isValidObject(const std::string& object,
                    std::string& message)
{
  const std::vector<std::string>* v = 0;

  if (type == Distance)
  {
    if (metric & DeltaPhi) v = &objDeltaPhi;
    if ((metric & DeltaEta) or (metric & DeltaR)) v = &objDelta;
    if (not v)
    {
      TM_LOG_ERR("Function::isValidObject: no metric specified for dist");
      message += " Function::isValidObject: no metric specified for dist";
    }
  }
  else if (type == Combination)
  {
    v = &objComb;
  }
  else if (type == InvariantMass or type == TransverseMass)
  {
    v = &objInvariantMass;
  }
  else if (type == TransverseMass)
  {
    v = &objTransverseMass;
  }


  if (not v) return false;

  for (size_t ii = 0; ii < v->size(); ii++)
  {
    if (object.compare(0, v->at(ii).length(), v->at(ii)) == 0) return true;
  }

  return false;
}


bool
Item::isValidCut(const std::string& cut,
                 std::string& message)
{
  const std::vector<std::string>* v = 0;

  switch (type)
  {
    case Distance:
      v = &cutDist;
      break;

    case Combination:
      v = &cutComb;
      break;

    case InvariantMass:
    case TransverseMass:
      v = &cutMass;
      break;
  }

  if (not v)
  {
    std::stringstream ss;
    ss << " Function::Item::isValidCut: unkown cut type: " << type;
    message += ss.str();
    return false;
  }

  for (size_t ii = 0; ii < v->size(); ii++)
  {
    if (cut.compare(0, v->at(ii).length(), v->at(ii)) == 0) {
      if (type == Distance or
          type == InvariantMass or
          type == TransverseMass) {
        if (v->at(ii) == Cut::DETA)
        {
          metric |= DeltaEta;
        }
        else if (v->at(ii) == Cut::DPHI)
        {
          metric |= DeltaPhi;
        }
        else if (v->at(ii) == Cut::DR)
        {
          metric |= DeltaR;
        }
      }
      return true;
    }
  }

  message += " Function::Item::isValidCut: unkown cut: '" + cut + "'";

  return false;
}


int
Item::getType()
{
  if (name.compare(dist) == 0)
  {
    return Distance;
  }
  else if (name.compare(comb) == 0)
  {
    return Combination;
  }
  else if (name.compare(mass) == 0) // for backward compatibility
  {
    return InvariantMass;
  }
  else if (name.compare(mass_inv) == 0)
  {
    return InvariantMass;
  }
  else if (name.compare(mass_trv) == 0)
  {
    return TransverseMass;
  }
  return Unknown;
}


/** @cond INTERNAL */
bool
getObjects(const std::string& token,
           std::vector<std::string>& objects,
           std::string& message)
{
  TM_LOG_DBG("getObjects: " << token);

  std::string text(token);
  while (text.length()) {
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

    TM_LOG_DBG("len = " << length << " end = " << end
              << " [ = " << cut_start << " ] = " << cut_stop << " , " << comma);

    // include ']' in an object
    if (end == cut_stop) end += 1;

    std::string object = text.substr(0, end);
    TM_LOG_DBG("end = " << end << " " << object);
    objects.push_back(object);
    text = text.substr(end, length-end);
  }

  if (objects.size() < 2) {
    TM_LOG_ERR("Function::getObjects: # of object  < 2 '" << text << "'");
    message += " Function::getObjects: # of object  < 2 '" + text + "'";
    return false;
  }

  return true;
}
/** @endcond */


bool
parser(const std::string& function,
       Function::Item& item)
{
  const std::string trimmed = boost::trim_copy(function);
  const std::string name = std::string("(") + comb + "|" + mass + "|" + mass_inv + "|" + mass_trv + "|" + dist + ")";
  const std::string objects = "\\{(.+)\\}";
  const std::string cuts = "\\[(.+)\\]";
  regex_t regex;

  bool isValid = false;

  // try func(obj)[cut] format
  std::string expression = name + objects + cuts;
  if (tmutil::regex_compile(&regex, expression))
  {
    item.message += "tmutil::regex_compile::error '" + expression + "'";
    return false;
  }

  std::vector<std::string> matched;
  tmutil::regex_match(&regex, trimmed, matched);
  regfree(&regex);

  Function::Item_ item_;
  if (matched.size() == 3) {
    item_.name = matched.at(0);
    item_.cuts = matched.at(2);
    if (not getObjects(matched.at(1), item_.objects, item.message)) return false;
    isValid = true;
  }

  if (not isValid) {
    // try func(obj) format
    expression = name + objects;
    if (tmutil::regex_compile(&regex, expression))
    {
      item.message += "tmutil::regex_compile::error '" + expression + "'";
      return false;
    }

    matched.clear();
    tmutil::regex_match(&regex, trimmed, matched);
    regfree(&regex);

    if (matched.size() == 2) {
      item_.name = matched.at(0);
      if (not getObjects(matched.at(1), item_.objects, item.message)) return false;
    }
  }


  item.name = item_.name;
  item.type = item.getType();

  // cut is mandatory except for Combination
  if ((item.type != Combination) and item_.cuts.empty())
  {
    TM_LOG_ERR("Function::parser: no cut specified");
    item.message += " Function::parser: no cut specified";
    return false;
  }

  // decode cuts
  if (not item_.cuts.empty())
  {
    Cut::Item cut;
    if (not Cut::parser(item_.cuts, cut))
    {
      item.message += cut.message;
      return false;
    }

    for (size_t ii = 0; ii < cut.name.size(); ii++)
    {
      if (not item.isValidCut(cut.name.at(ii), item.message))
      {
        TM_LOG_ERR("Function::parser: '" << cut.name.at(ii)
                  << "' is not valid for " << item.name);
                 + "' is not valid for " + item.name;
        item.message += " Function::parser: '" + cut.name.at(ii)
                     + "' is not valid for " + item.name;
        return false;
      }
      item.cuts.push_back(cut.name.at(ii));
    }
  }


  int objectType = Object::Unknown;

  // decode objects
  for (size_t ii = 0; ii < item_.objects.size(); ii++) {
    Object::Item object;
    if (not Object::parser(item_.objects.at(ii), object))
    {
      item.message += object.message;
      return false;
    }

    if (not item.isValidObject(item_.objects.at(ii), item.message))
    {
      TM_LOG_ERR("Function::parser: '" << item_.objects.at(ii)
                 << "' is not valid for " << item.name
                 << ((item.type == Distance) ? " with the given metric" : ""));
      item.message += " Function::parser: '" + item_.objects.at(ii)
                 + "' is not valid for " + item.name
                 + ((item.type == Distance) ? " with the given metric" : "");
      return false;
    }

    if (item.type == Combination)
    {
      if (objectType == Object::Unknown) objectType = object.getType();
      if (objectType != object.getType())
      {
        TM_LOG_ERR("Function::parser: differnet type of objects passed to comb(): "
                   << function);
        item.message += " Function::parser: differnet type of objects passed to comb(): "
                   + function;
        return false;
      }
    }
    item.objects.push_back(object);
  }


  return true;
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
  bool rc = false;

  for (reserved::const_iterator cit = functionName.begin();
       cit != functionName.end(); ++cit)
  {
    if (element.compare(0, cit->first.length(), cit->first) == 0)
    {
      Item function;
      if (not parser(element, function)) continue;
      rc = true;
      break;
    }
  }

  return rc;
}

} // namespace Function
/* eof */
