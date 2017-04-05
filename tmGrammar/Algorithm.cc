/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>

#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Algorithm.hh"

/*====================================================================*
 * implementation
 *====================================================================*/
namespace Algorithm
{
// ---------------------------------------------------------------------
// static variables
// ---------------------------------------------------------------------
// operators in algorithm expression
const char AND[] = "AND";
const char OR[] = "OR";
const char NOT[] = "NOT";
const char XOR[] = "XOR";

/** @cond INTERNAL */
const reserved::value_type gate_names[] = {
  reserved::value_type(AND, 1),
  reserved::value_type(OR, 1),
  reserved::value_type(NOT, 1),
  reserved::value_type(XOR, 1),
};
const int n_gate_names = sizeof(gate_names) / sizeof(gate_names[0]);
const reserved gateName(gate_names, gate_names + n_gate_names);
/** @endcond */

// static token holder
std::vector<std::string> Logic::tokens = std::vector<std::string>();


namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/*--------------------------------------------------------------------*
 * grammar
 *--------------------------------------------------------------------*/
/** @cond INTERNAL */
template <typename Iterator>
struct grammar : qi::grammar<Iterator, Logic(), ascii::space_type>
{
  grammar() : grammar::base_type(logic)
  {
    using qi::lexeme;
    using qi::string;
    using qi::char_;
    using namespace qi::labels;

    using phoenix::bind;
    using phoenix::val;


    logic
      = element
        >> *(op >> element)[bind(&Logic::append, _val, _1)]
    ;

    element
      = (neg >> element)[bind(&Logic::append, _val, _1)]
      | '(' >> logic >> ')'
      | name[bind(&Logic::append, _val, _1)]
    ;

    name
      = lexeme[+char_("a-zA-Z0-9{}[],_.+-")] - op - neg // TODO: possible weak precept
    ;

    op
      = lexeme[string(AND)]
      | lexeme[string(OR)]
      | lexeme[string(XOR)]
    ;

    neg
      = lexeme[string(NOT)]
    ;

    BOOST_SPIRIT_DEBUG_NODE(name);
    BOOST_SPIRIT_DEBUG_NODE(op);
    BOOST_SPIRIT_DEBUG_NODE(neg);
  }

  qi::rule<Iterator, Logic(), ascii::space_type> logic, element;
  qi::rule<Iterator, std::string(), ascii::space_type>  op, neg, name;
}; // struct grammar
/** @endcond */


// ---------------------------------------------------------------------
// constructor & destructor
// ---------------------------------------------------------------------
// nope


// ---------------------------------------------------------------------
// methods
// ---------------------------------------------------------------------
bool
parser(const std::string& algorithm)
{
  std::string::const_iterator begin = algorithm.begin();
  std::string::const_iterator end = algorithm.end();

  typedef std::string::const_iterator iterator_type;
  typedef grammar<iterator_type> grammar;
  using boost::spirit::ascii::space;

  grammar g;
  Logic logic;

  bool r = phrase_parse(begin, end, g, space, logic);

  if (not (r and begin == end))
  {
    TM_LOG_ERR("Algorithm::parser: '" << algorithm << "'");
    return false;
  }
  return true;
}


bool
isGate(const std::string& element)
{
  bool rc = false;

  if (gateName.find(element) != gateName.end())
  {
    rc = true;
  }

  return rc;
}

} // namespace Algorithm
/* eof */
