/**
 * @author      Takashi Matsushita
 * Created:     03 Jul 2014
 */

/** @todo */

#ifndef tmGrammar_Algorithm_hh
#define tmGrammar_Algorithm_hh

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


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Algorithm {

// operators in algorithm expression
extern const char AND[];  /**< AND */
extern const char OR[];   /**< OR */
extern const char NOT[];  /**< NOT */
extern const char XOR[];  /**< XOR */


/** parse algorithm expression
 *
 * @param algorithm [in] algorithm expression
 * @return true if parsing was successfull otherwise false
 */
bool parser(const std::string& algorithm);


/** checks if the given algorithm expression element is a gate or not
 *
 * @param element [in] an element of an algorithm expression
 * @return true if the given element is a gate
 */
bool isGate(const std::string& element); // TODO: nomenclature, isOperator


/**
  * This struct implements static array and associated methods
 */
struct Logic
{
  Logic() {}

  /** static variable to hold tokens in algorithm expression */
  static std::vector<std::string> tokens;

  /** clears tokens array */
  static void clear() { tokens.clear(); }

  /** appends a token to tokens array */
  void append(const std::string& s) { tokens.push_back(s); }

  /** get tokens array */
  static const std::vector<std::string>& getTokens() { return tokens; }

  /** print contents of tokens */
  static std::ostream& print(std::ostream& os = std::cout)
  {
    os << "tokens: \n";
    for (size_t ii = 0; ii < tokens.size(); ii++)
      os << "  " << tokens.at(ii) << std::endl;
    return os;
  }
}; // struct Logic



/** list of names */
typedef std::map<std::string, int> reserved;
extern const reserved gateName; /**< list of allowed operator names */

} // namespace Algorithm

#endif // tmGrammar_Algorithm_hh
/* eof */
