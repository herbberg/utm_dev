/**
 * @author      Takashi Matsushita
 * Created:     23 Feb 2015
 */

#ifndef tmGrammar_CutGrammar_hh
#define tmGrammar_CutGrammar_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/phoenix_bind.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "tmGrammar/Cut.hh"


BOOST_FUSION_ADAPT_STRUCT(
  Cut::Item,
  (std::vector<std::string>, name)
)


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace Cut
{
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

/*--------------------------------------------------------------------*
 * grammar
 *--------------------------------------------------------------------*/
template <typename Iterator>
struct cut_grammar : qi::grammar<Iterator, Item(), ascii::space_type>
{
  cut_grammar() : cut_grammar::base_type(cuts)
  {
    using qi::string;
    using qi::char_;
    using qi::raw;
    using namespace qi::labels;
    using phoenix::push_back;
    using phoenix::bind;

    const std::string charset = "a-zA-Z0-9_";

    cuts
      = cut[push_back(bind(&Item::name, _val), _1)] % ','
    ;

    cut
      // for muon
      = raw[string(MU_ETA) >> '_' >> +char_(charset)]
      | raw[string(MU_PHI) >> '_' >> +char_(charset)]
      | raw[string(MU_CHG) >> '_' >> +char_(charset)]
      | raw[string(MU_QLTY) >> '_' >> +char_(charset)]
      | raw[string(MU_ISO) >> '_' >> +char_(charset)]
      | raw[string(MU_SLICE) >> '_' >> +char_(charset)]
      | raw[string(MU_UPT) >> '_' >> +char_(charset)]
      | raw[string(MU_IP) >> '_' >> +char_(charset)]

      // for egamma
      | raw[string(EG_ETA) >> '_' >> +char_(charset)]
      | raw[string(EG_PHI) >> '_' >> +char_(charset)]
      | raw[string(EG_QLTY) >> '_' >> +char_(charset)]
      | raw[string(EG_ISO) >> '_' >> +char_(charset)]
      | raw[string(EG_SLICE) >> '_' >> +char_(charset)]

      // for tau
      | raw[string(TAU_ETA) >> '_' >> +char_(charset)]
      | raw[string(TAU_PHI) >> '_' >> +char_(charset)]
      | raw[string(TAU_QLTY) >> '_' >> +char_(charset)]
      | raw[string(TAU_ISO) >> '_' >> +char_(charset)]
      | raw[string(TAU_SLICE) >> '_' >> +char_(charset)]

      // for jet
      | raw[string(JET_ETA) >> '_' >> +char_(charset)]
      | raw[string(JET_PHI) >> '_' >> +char_(charset)]
      | raw[string(JET_QLTY) >> '_' >> +char_(charset)]
      | raw[string(JET_SLICE) >> '_' >> +char_(charset)]

      // for missing energy
      | raw[string(ETM_PHI) >> '_' >> +char_(charset)]
      | raw[string(HTM_PHI) >> '_' >> +char_(charset)]
      | raw[string(ETMHF_PHI) >> '_' >> +char_(charset)]

      // for functions
      | raw[string(DETA) >> '_' >> +char_(charset)]
      | raw[string(DPHI) >> '_' >> +char_(charset)]
      | raw[string(DR) >> '_' >> +char_(charset)]
      | raw[string(MASS) >> '_' >> +char_(charset)]
      | raw[string(CHGCOR) >> '_' >> +char_(charset)]
      | raw[string(TBPT) >> '_' >> +char_(charset)]
      | raw[string(ORMDETA) >> '_' >> +char_(charset)]
      | raw[string(ORMDPHI) >> '_' >> +char_(charset)]
      | raw[string(ORMDR) >> '_' >> +char_(charset)]
    ;

    BOOST_SPIRIT_DEBUG_NODE(cut);
  }

  qi::rule<Iterator, Item(), ascii::space_type> cuts;
  qi::rule<Iterator, std::string(), ascii::space_type> cut;
};

} // namespace Cut
#endif // tmGrammar_CutGrammar_hh
/* eof */
