// http://www.boost.org/doc/libs/1_51_0/libs/spirit/doc/html/spirit/introduction.html
// EBNF: http://www.drdobbs.com/cpp/the-spirit-parser-library-inline-parsing/184401692
/**
 * @author      Takashi Matsushita
 * Created:     23 Feb 2015
 */

#ifndef tmGrammar_FunctionGrammar_hh
#define tmGrammar_FunctionGrammar_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "tmGrammar/Function.hh"


namespace Function
{
/** @cond INTERNAL */
struct Item_
{
  std::string name;
  std::vector<std::string> objects;
  std::vector<std::string> cuts;

  Item_() : name(), objects(), cuts() {}

  void print()
  {
    std::cout << "func = '" << name;
    std::cout << "' cuts = '";
    for (size_t ii = 0; ii < cuts.size(); ii++)
    {
      std::cout << cuts.at(ii) << "' '";
    }
    std::cout << "' objs = '";
    for (size_t ii = 0; ii < objects.size(); ii++)
    {
      std::cout << objects.at(ii) << "' '";
    }
    std::cout << "'" << std::endl;
  }
}; // struct Item_

/** @endcond */

} // namespace Function



BOOST_FUSION_ADAPT_STRUCT(
  Function::Item_,
  (std::string, name)
  (std::vector<std::string>, objects)
  (std::vector<std::string>, cuts)
)


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Function
{
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/*--------------------------------------------------------------------*
 * grammar
 *--------------------------------------------------------------------*/
template <typename Iterator>
struct function_grammar : qi::grammar<Iterator, Item_(), ascii::space_type>
{
  function_grammar() : function_grammar::base_type(function)
  {
    using qi::string;
    using qi::char_;

    function
      = name
        >> objects
        >> -cuts
    ;

    name
      = string(comb)
      | string(dist)
      | string(mass) // alias for mass_inv
      | string(mass_inv)
      | string(mass_inv_upt)
      | string(mass_trv)
      | string(comb_orm)
      | string(dist_orm)
      | string(mass_inv_orm)
      | string(mass_trv_orm)
      | string(mass_inv_3_obj)
    ;

    objects
      // TODO: fix it, do not recognize ',' in some cases
      = '{' >> object % ',' >> '}'
    ;

    object
      = +char_(Object::CHARSET_OBJECT) >> -qi::raw[('[' >> +char_(Cut::CHARSET_CUTS) >> ']')]
    ;

    cuts
      = '[' >> cut % ',' >> ']'
    ;

    cut
      = +char_(Cut::CHARSET_CUT)
    ;

    BOOST_SPIRIT_DEBUG_NODE(name);
    BOOST_SPIRIT_DEBUG_NODE(objects);
    BOOST_SPIRIT_DEBUG_NODE(object);
    BOOST_SPIRIT_DEBUG_NODE(cuts);
    BOOST_SPIRIT_DEBUG_NODE(cut);
  }

  qi::rule<Iterator, Item_(), ascii::space_type> function;
  qi::rule<Iterator, std::string(), ascii::space_type> name;
  qi::rule<Iterator, std::vector<std::string>(), ascii::space_type> objects, cuts;
  qi::rule<Iterator, std::string(), ascii::space_type> object, cut;

};

} // namespace Function
#endif // tmGrammar_FunctionGrammar_hh
/* eof */
