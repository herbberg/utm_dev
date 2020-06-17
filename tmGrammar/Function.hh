/**
 * @author      Takashi Matsushita
 * Created:     03 Jul 2014
 */

/** @todo */

#ifndef tmGrammar_Function_hh
#define tmGrammar_Function_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "tmGrammar/Object.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Function {

// functions
const std::string comb = "comb"; /**< combination */
const std::string dist = "dist"; /**< distance */
const std::string mass = "mass"; /**< invariant mass (alias) */
const std::string mass_inv = "mass_inv"; /**< invariant mass */
const std::string mass_inv_upt = "mass_inv_upt"; /**< invariant mass with unconstraint pt*/
const std::string mass_trv = "mass_trv"; /**< transverse mass */
const std::string mass_inv_3_obj = "mass_inv_3_obj"; /**< invariant mass with 3 objects*/

// overlap removal functions
const std::string comb_orm = "comb_orm"; /**< overlap removal for object combinations */
const std::string dist_orm = "dist_orm"; /**< distance with overlap removal */
const std::string mass_inv_orm = "mass_inv_orm"; /**< invariant mass with overlap removal */
const std::string mass_trv_orm = "mass_trv_orm"; /**< transverse mass with overlap removal */


/** type of functions */
enum {
  Unknown = 0,
  Combination,
  Distance,
  InvariantMass,
  InvariantMassUpt,
  TransverseMass,
  CombinationOvRm,
  DistanceOvRm,
  InvariantMassOvRm,
  TransverseMassOvRm,
  InvariantMassThreeObj,
};

/** type of metric for Distance */
enum {
  DeltaEta = 0x1,
  DeltaPhi = 0x2,
  DeltaR   = 0x4
};


/**
  * This struct implements data structure for a function
  */
struct Item
{
  std::string name;                   /**< function name */
  std::vector<Object::Item> objects;  /**< objects for function */
  std::vector<std::string> cuts;      /**< cuts for function */
  int type;                           /**< function type */
  int metric;                         /**< metric for distance operator */
  std::string message;

  Item() : name(), objects(), cuts(), type(Unknown), metric(Unknown), message() {}

  /** prints Item attributes */
  std::ostream& print(std::ostream& os = std::cout) const;

  /** checks if the object expression is valid or not */
  bool isValidObject(const std::string& object, std::string& message);

  /** checks if the cut expression is valid or not */
  bool isValidCut(const std::string& cut, std::string& message);

  /** get type of function */
  int getType() const;

  /** append to item message */
  void appendMessage(const std::string& message);
};


/** parse object expression
  *
  * @param function [in] function expression
  * @param item [in/out] Item instance to store the result
  * @return true if parsing was successfull otherwise false
  */
bool parser(const std::string& function,
            Item& item);


/** checks if the given algorithm expression element is a function or not
 *
 * @param element [in] an element of an algorithm expression
 * @return true if the given element is a function
 */
bool isFunction(const std::string& element);


/** get cuts of function */
std::vector<std::string> getCuts(const Item& item);

/** get objects of function */
std::vector<std::string> getObjects(const Item& item);


/** get cuts of objects */
std::vector<std::string> getObjectCuts(const Item& item);


/** list of names */
typedef std::map<std::string, int> reserved;
extern const reserved functionName; /**< list of allowed function names */

} // namespace Function

#endif // tmGrammar_Function_hh
/* eof */
