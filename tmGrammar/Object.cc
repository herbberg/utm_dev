/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include "tmUtil/tmUtil.hh"
#include "tmGrammar/Cut.hh"
#include "tmGrammar/Object.hh"
#include "tmGrammar/ObjectGrammar.hh"


/*====================================================================*
 * implementation
 *====================================================================*/
namespace Object
{
// ---------------------------------------------------------------------
// static variables
// ---------------------------------------------------------------------

// all the objects
const reserved::value_type object_names[] = {
  reserved::value_type(MU, 1),
  reserved::value_type(EG, 1),
  reserved::value_type(TAU, 1),
  reserved::value_type(JET, 1),
  reserved::value_type(ETT, 1),
  reserved::value_type(HTT, 1),
  reserved::value_type(ETM, 1),
  reserved::value_type(HTM, 1),
  reserved::value_type(EXT, 1),
  reserved::value_type(MBT0HFP, 1),
  reserved::value_type(MBT1HFP, 1),
  reserved::value_type(MBT0HFM, 1),
  reserved::value_type(MBT1HFM, 1),
  reserved::value_type(ETTEM, 1),
  reserved::value_type(ETMHF, 1),
  reserved::value_type(TOWERCOUNT, 1),
  reserved::value_type(ASYM0X, 1),
  reserved::value_type(ASYM1X, 1),
  reserved::value_type(ASYM2X, 1),
  reserved::value_type(ASYM3X, 1),
};
const int n_object_names = sizeof(object_names) / sizeof(object_names[0]);
const reserved objectName(object_names, object_names + n_object_names);


// particles
const char* cutsMU_[] = {Cut::MU_ETA, Cut::MU_PHI, Cut::MU_CHG, Cut::MU_QLTY, Cut::MU_ISO, Cut::MU_SLICE};
const std::vector<std::string> cutsMU(cutsMU_, cutsMU_ + sizeof(cutsMU_)/sizeof(cutsMU_[0]));

const char* cutsEG_[] = {Cut::EG_ETA, Cut::EG_PHI, Cut::EG_QLTY, Cut::EG_ISO, Cut::EG_SLICE};
const std::vector<std::string> cutsEG(cutsEG_, cutsEG_ + sizeof(cutsEG_)/sizeof(cutsEG_[0]));

const char* cutsTAU_[] = {Cut::TAU_ETA, Cut::TAU_PHI, Cut::TAU_QLTY, Cut::TAU_ISO, Cut::TAU_SLICE};
const std::vector<std::string> cutsTAU(cutsTAU_, cutsTAU_ + sizeof(cutsTAU_)/sizeof(cutsTAU_[0]));

const char* cutsJET_[] = {Cut::JET_ETA, Cut::JET_PHI, Cut::JET_QLTY, Cut::JET_SLICE};
const std::vector<std::string> cutsJET(cutsJET_, cutsJET_ + sizeof(cutsJET_)/sizeof(cutsJET_[0]));


// scalers
const reserved::value_type scalers[] = {
  reserved::value_type(ETT, 1),
  reserved::value_type(HTT, 1),
  reserved::value_type(MBT0HFP, 1),
  reserved::value_type(MBT1HFP, 1),
  reserved::value_type(MBT0HFM, 1),
  reserved::value_type(MBT1HFM, 1),
  reserved::value_type(ETTEM, 1),
  reserved::value_type(TOWERCOUNT, 1),
  reserved::value_type(ASYM0X, 1),
  reserved::value_type(ASYM1X, 1),
  reserved::value_type(ASYM2X, 1),
  reserved::value_type(ASYM3X, 1),
};
const int n_scalers = sizeof(scalers) / sizeof(scalers[0]);
const reserved scalerName(scalers, scalers + n_scalers);


// vectors
const reserved::value_type vectors[] = {
  reserved::value_type(ETM, 1),
  reserved::value_type(HTM, 1),
  reserved::value_type(ETMHF, 1),
};
const int n_vectors = sizeof(vectors) / sizeof(vectors[0]);
const reserved vectorName(vectors, vectors + n_vectors);

const char* cutsVector_[] = {Cut::ETM_PHI, Cut::HTM_PHI, Cut::ETMHF_PHI};
const std::vector<std::string> cutsVector(cutsVector_, cutsVector_ + sizeof(cutsVector_)/sizeof(cutsVector_[0]));


// all the comparisons
const reserved::value_type comparison_names[] = {
  reserved::value_type(EQ, 1),
  reserved::value_type(NE, 1),
  reserved::value_type(GT, 1),
  reserved::value_type(GE, 1),
  reserved::value_type(LT, 1),
  reserved::value_type(LE, 1),
};
const int n_comparison_names = sizeof(comparison_names) / sizeof(comparison_names[0]);
const reserved comparisonName(comparison_names, comparison_names + n_comparison_names);


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
  os << "obj = '" << name
     << "' comp = '" << comparison
     << "' thre = '" << threshold
     << "' bx_o = '" << bx_offset
     << "' cuts = ";
  for (size_t ii = 0; ii < cuts.size(); ii++)
  {
    os << "'" << cuts.at(ii) << "' ";
  }
  os << std::endl;
  return os;
}


int
Item::getType() const
{
  if (strncmp(name.c_str(), MU, strlen(MU)) == 0) return Muon;
  if (strncmp(name.c_str(), EG, strlen(EG)) == 0) return Egamma;
  if (strncmp(name.c_str(), TAU, strlen(TAU)) == 0) return Tau;
  if (strncmp(name.c_str(), JET, strlen(JET)) == 0) return Jet;

  for (Object::reserved::const_iterator cit = Object::scalerName.begin();
       cit != Object::scalerName.end(); cit++)
  {
    if (name.compare(0, cit->first.length(), cit->first) == 0) return Scaler;
  }

  for (Object::reserved::const_iterator cit = Object::vectorName.begin();
       cit != Object::vectorName.end(); cit++)
  {
    if (name.compare(0, cit->first.length(), cit->first) == 0) return Vector;
  }

  if (strncmp(name.c_str(), EXT, strlen(EXT)) == 0) return External;

  return Unknown;
}


bool
Item::isValidCut(const std::string& cut)
{
  const std::vector<std::string>* v = 0;
  switch (type) {
    case Muon:
      v = &cutsMU;
      break;

    case Egamma:
      v = &cutsEG;
      break;

    case Tau:
      v = &cutsTAU;
      break;

    case Jet:
      v = &cutsJET;
      break;

    case Vector:
      v = &cutsVector;
      break;

    default:
      break;
  }

  if (not v) return false;

  for (size_t ii = 0; ii < v->size(); ii++)
  {
    if (cut.compare(0, v->at(ii).length(), v->at(ii)) == 0) return true;
  }

  return false;
}


std::string
Item::getObjectName() const
{
  std::string object_name(name);
  if (comparison != GE) object_name += comparison;
  object_name += threshold;
  if (bx_offset != "+0") object_name += bx_offset;

  return object_name;
}


bool
parser(const std::string& token,
       Object::Item& item)
{
  std::string::const_iterator begin = token.begin();
  std::string::const_iterator end = token.end();

  typedef std::string::const_iterator iterator_type;
  typedef object_grammar<iterator_type> object_grammar;
  using boost::spirit::ascii::space;

  Item_ item_;
  object_grammar g;
  bool r = phrase_parse(begin, end, g, space, item_);

  if (not (r and begin == end))
  {
    TM_LOG_ERR("Object::parser: '" << token << "'");
    item.message += " Object::parser: '" + token + "'";
    return false;
  }

  item.name = item_.name;
  if (item_.comparison.empty())
  {
    item.comparison = GE;
  }
  else
  {
    item.comparison = item_.comparison;
  }
  item.threshold = item_.threshold;
  if (item_.bx_offset.empty())
  {
    item.bx_offset = "+0";
  }
  else
  {
    item.bx_offset = item_.bx_offset;
  }

  item.type = item.getType();


  if (item_.cuts.empty()) return true;

  Cut::Item cut;
  if (not Cut::parser(item_.cuts, cut))
  {
    item.message += cut.message;
    return false;
  }

  for (size_t ii = 0; ii < cut.name.size(); ii++)
  {
    if (not item.isValidCut(cut.name.at(ii))) {
      TM_LOG_ERR("Object::parser: '" << cut.name.at(ii)
                 << "' is not valid for '" << item.name << "'");
      item.message += " Object::parser: '" + cut.name.at(ii) +
                      "' is not valid for '" +  item.name + "'";
      return false;
    }
    item.cuts.push_back(cut.name.at(ii));
  }

  return true;
}


bool
isObject(const std::string& element)
{
  bool rc = false;

  for (reserved::const_iterator cit = objectName.begin();
       cit != objectName.end(); ++cit)
  {
    if (element.compare(0, cit->first.length(), cit->first) == 0)
    {
      Item object;
      if (not parser(element, object)) continue;
      rc = true;
      break;
    }
  }

  return rc;
}


} // namespace Object
/* eof */
