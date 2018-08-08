/**
 * @author      Takashi Matsushita
 * Created:     23 Feb 2015
 */

#ifndef tmGrammar_ObjectGrammar_hh
#define tmGrammar_ObjectGrammar_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "tmGrammar/Object.hh"


namespace Object
{
/** @cond INTERNAL */
struct Item_
{
  std::string name;
  std::string comparison;
  std::string threshold;
  std::string bx_offset;
  std::string cuts;

  Item_() : name(), comparison(), threshold(), bx_offset(), cuts() {}

  void print()
  {
    std::cout << "obj = '" << name
              << "' comp = '" << comparison
              << "' thre = '" << threshold
              << "' bx_o = '" << bx_offset
              << "' cuts = '" << cuts
              << "'"
              << std::endl;
  }
}; // struct Item_
/** @endcond */

} // namespace Object



BOOST_FUSION_ADAPT_STRUCT(
  Object::Item_,
  (std::string, name)
  (std::string, comparison)
  (std::string, threshold)
  (std::string, bx_offset)
  (std::string, cuts)
)


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Object
{
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/*--------------------------------------------------------------------*
 * grammar
 *--------------------------------------------------------------------*/
template <typename Iterator>
struct object_grammar : qi::grammar<Iterator, Item_(), ascii::space_type>
{
  object_grammar() : object_grammar::base_type(object)
  {
    using qi::string;
    using qi::char_;
    using qi::digit;
    using qi::raw;

    object
      = object_id
        >> -comparison
        >> threshold
        >> -bx_offset
        >> -cuts
      | signal_id
        >> !comparison
        >> !threshold
        >> -bx_offset
      | ext_signal_id
        >> !comparison
        >> !threshold
        >> -bx_offset
    ;

    object_id
      = string(MU)
      | string(EG)
      | string(TAU)
      | string(JET)
      | string(ETTEM)
      | string(ETT)
      | string(HTT)
      | string(ETMHF)
      | string(ETM)
      | string(HTM)
      | string(MBT0HFP)
      | string(MBT1HFP)
      | string(MBT0HFM)
      | string(MBT1HFM)
      | string(TOWERCOUNT)
      | string(ASYMETHF)
      | string(ASYMHTHF)
      | string(ASYMET)
      | string(ASYMHT)
    ;

    signal_id
      = string(CENT0)
      | string(CENT1)
      | string(CENT2)
      | string(CENT3)
      | string(CENT4)
      | string(CENT5)
      | string(CENT6)
      | string(CENT7)
    ;

    ext_signal_id
      = raw[string(EXT) >> raw['_'] >> +char_("a-zA-Z0-9_.")]
    ;

    comparison
      = string(EQ)
      | string(NE)
      | string(GT)
      | string(GE)
      | string(LT)
      | string(LE)
    ;

    threshold
      = raw[+digit >> -('p' >> +digit)]
    ;

    bx_offset
      = raw['+' >> +digit]
      | raw['-' >> +digit]
    ;

    cuts
      = '[' >> +char_(Cut::CHARSET_CUTS) >> ']'
    ;

    BOOST_SPIRIT_DEBUG_NODE(object_id);
    BOOST_SPIRIT_DEBUG_NODE(signal_id);
    BOOST_SPIRIT_DEBUG_NODE(ext_signal_id);
    BOOST_SPIRIT_DEBUG_NODE(comparison);
    BOOST_SPIRIT_DEBUG_NODE(threshold);
    BOOST_SPIRIT_DEBUG_NODE(bx_offset);
    BOOST_SPIRIT_DEBUG_NODE(cuts);
  }

  qi::rule<Iterator, Item_(), ascii::space_type> object;
  qi::rule<Iterator, std::string(), ascii::space_type> object_id, signal_id, ext_signal_type;
  qi::rule<Iterator, std::string(), ascii::space_type> comparison, threshold, bx_offset, cuts;
};

} // namespace Object
#endif // tmGrammar_ObjectGrammar_hh
/* eof */
