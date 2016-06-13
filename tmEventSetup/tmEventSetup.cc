#include <cmath>

#include "tmUtil/tmUtil.hh"
#include "tmTable/tmTable.hh"
#include "tmEventSetup/esTriggerMenuHandle.hh"
#include "tmEventSetup/tmEventSetup.hh"


namespace tmeventsetup
{
  const std::string GRAMMAR_VERSION = "0.3";
  
  const long long pow10[] =
  {
                      1, 
                     10,
                    100,
                   1000,
                  10000,
                 100000,
                1000000,
               10000000,
              100000000,
             1000000000,
            10000000000,
           100000000000,
          1000000000000,
         10000000000000,
        100000000000000,
       1000000000000000,
      10000000000000000,
     100000000000000000
  };

const esTriggerMenu*
_getTriggerMenu(const tmtable::Menu& menu, const tmtable::Scale& scale, const tmtable::ExtSignal& extSignal)
{
  TM_LOG_DBG("tmeventsetup::_getTriggerMenu: ");

  esTriggerMenuHandle* estm = new esTriggerMenuHandle();
  const std::string text;
  std::map<std::string, std::string>::const_iterator cit;

  estm->setExternalMap(extSignal);
  estm->setScaleMap(scale);

  const std::string version = getValue(menu.menu, "grammar_version");
  if (version > GRAMMAR_VERSION)
  {
    std::stringstream ss;
    ss << "utm: grammar version mismatch: " << version << " > " << GRAMMAR_VERSION;
    throw std::runtime_error(ss.str());
  }

  estm->setName(getValue(menu.menu, "name"));
  estm->setVersion(version);
  estm->setComment(getValue(menu.menu, "comment"));
  estm->setDatetime(getValue(menu.menu, "datetime"));
  estm->setFirmwareUuid(getValue(menu.menu, "uuid_firmware"));
  estm->setScaleSetName(getValue(scale.scaleSet, "name"));
  estm->setNmodules(tmutil::convert<unsigned int>(getValue(scale.scaleSet, "n_modules")));

  for (size_t ii = 0; ii < menu.algorithms.size(); ii++)
  {
    const tmtable::Row& algorithm = menu.algorithms.at(ii);
    const std::string& algo_name = algorithm.find("name")->second;

    tmtable::StringTableMap::const_iterator cit = menu.cuts.find(algo_name);
    const tmtable::Table cuts_in_algo = (cit != menu.cuts.end()) ? cit->second : tmtable::Table();
    std::vector<std::string> rpn = estm->parse(algorithm.find("expression")->second);

    for (size_t jj = 0; jj < rpn.size(); jj++)
    {
      estm->setConditionMap(rpn.at(jj), cuts_in_algo);
    }
    estm->setAlgorithmMap(algorithm);
  }

  // set HW index
  estm->setHwIndex(scale.bins);

  // set Function cuts
  estm->setFunctionCuts();

  esTriggerMenu* p = estm;
  return p;
}


const esTriggerMenu*
getTriggerMenu(const std::string& path)
{
  TM_LOG_DBG("tmeventsetup::getTriggerMenu: " << path);

  // read menu
  tmtable::Menu menu;
  tmtable::Scale scale;
  tmtable::ExtSignal extSignal;

  std::string message;
  message = tmtable::xml2menu(path.c_str(), menu, scale, extSignal);
  if (message.size())
  {
    TM_LOG_ERR("tmeventsetup::getTriggerMenu: " << message);
    TM_FATAL_ERROR("couldn't open an input file");
  }

  return _getTriggerMenu(menu, scale, extSignal);
}


const esTriggerMenu*
getTriggerMenu(std::istringstream& iss)
{
  TM_LOG_DBG("tmeventsetup::getTriggerMenu: ");

  // read menu
  tmtable::Menu menu;
  tmtable::Scale scale;
  tmtable::ExtSignal extSignal;

  std::string message;
  message = tmtable::xml2menu(iss, menu, scale, extSignal);
  if (message.size())
  {
    TM_LOG_ERR("tmeventsetup::getTriggerMenu: " << message);
    TM_FATAL_ERROR("couldn't open an input file");
  }

  return _getTriggerMenu(menu, scale, extSignal);
}


std::string
getValue(const std::map<std::string, std::string> map,
         const std::string& key)
{
  std::string value = "";
  std::map<std::string, std::string>::const_iterator cit;

  cit = map.find(key);
  if (cit != map.end())
  {
    value = cit->second;
  }

  return value;
}


long
getHash(const std::string& s)
{
  std::locale loc;
  const std::collate<char>& coll = std::use_facet<std::collate<char> >(loc);
  return coll.hash(s.data(), s.data() + s.length());
}


unsigned long
getHashUlong(const std::string& s)
{
  return (unsigned long)getHash(s);
}


unsigned long
getMmHashN(const std::string& s)
{
  const void* key = s.c_str();
  int len = s.size();
  unsigned int seed = 0xdeadbabe;

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	unsigned int h = seed ^ len;

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k;

		k  = data[0];
		k |= data[1] << 8;
		k |= data[2] << 16;
		k |= data[3] << 24;

		k *= m; 
		k ^= k >> r; 
		k *= m;

		h *= m;
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}


std::string
getExternalName(const std::string& name)
{
  const std::string prefix = "EXT_";

  std::string ext_name(name);
  std::string::size_type index = ext_name.find(prefix);
  if (index == 0) ext_name.erase(index, prefix.length());

  index = ext_name.find("+");
  if (index) ext_name = ext_name.substr(0, index);
  index = ext_name.find("-");
  if (index) ext_name = ext_name.substr(0, index);

  return ext_name;
}


esCombinationType
getObjectCombination(int type1,
                     int type2)
{ 
  return getObjectCombination(static_cast<esObjectType>(type1),
                              static_cast<esObjectType>(type2));
}


esCombinationType
getObjectCombination(esObjectType type1,
                     esObjectType type2)
{
  esCombinationType combination = static_cast<esCombinationType>(Undef);

  switch (type1)
  {
    case Muon:
      switch (type2)
      {
        case Muon:
          combination = MuonMuonCombination;
          break;
        case Egamma:
        case Tau:
        case Jet:
          combination = CaloMuonCombination;
          break;
        case ETM:
        case HTM:
        case ETMHF:
          combination = MuonEsumCombination;
          break;
        default:
          TM_FATAL_ERROR("tmeventsetup::getObjectCombination: unknown object type = '" << type2 << "'");
      }
      break;

    case Egamma:
    case Tau:
    case Jet:
      switch (type2)
      {
        case Muon:
          combination = CaloMuonCombination;
          break;
        case Egamma:
        case Tau:
        case Jet:
          combination = CaloCaloCombination;
          break;
        case ETM:
        case HTM:
        case ETMHF:
          combination = CaloEsumCombination;
          break;
        default:
          TM_FATAL_ERROR("tmeventsetup::getObjectCombination: unknown object type = '" << type2 << "'");
      }
      break;

    case ETM:
    case HTM:
    case ETMHF:
      switch (type2)
      {
        case Muon:
          combination = MuonEsumCombination;
          break;
        case Egamma:
        case Tau:
        case Jet:
          combination = CaloEsumCombination;
          break;
        default:
          TM_FATAL_ERROR("tmeventsetup::getObjectCombination: unknown object type = '" << type2 << "'");
      }
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::getObjectCombination: unknown object type = '" << type2 << "'");
  }

  return combination;
}


void
getPrecisions(std::map<std::string, unsigned int>& precision,
              const std::map<std::string, tmeventsetup::esScale>& scaleMap)
{
  for (std::map<std::string, tmeventsetup::esScale>::const_iterator cit = scaleMap.begin();
       cit != scaleMap.end(); cit++)
  {
    switch (cit->second.getScaleType())
    {
      case DeltaPrecision:
      case MassPrecision:
      case MassPtPrecision:
      case MathPrecision:
        break;

      default:
        continue;
    }

    std::pair<std::map<std::string, unsigned int>::iterator, bool> rc;
    rc = precision.insert(std::make_pair(cit->first, cit->second.getNbits()));
    if (not rc.second)
    {
      TM_FATAL_ERROR("tmeventsetup::getPrecisions: insertion failed");
    }
  }
}


#if defined(SWIG)
void
getPrecisionsPy(std::map<std::string, unsigned int>& precision,
                const std::map<std::string, tmeventsetup::esScale*>& scaleMap)
{
  for (std::map<std::string, tmeventsetup::esScale*>::const_iterator cit = scaleMap.begin();
       cit != scaleMap.end(); cit++)
  {
    switch (cit->second->getScaleType())
    {
      case DeltaPrecision:
      case MassPrecision:
      case MassPtPrecision:
      case MathPrecision:
        break;
      default:
        continue;
    }

    std::pair<std::map<std::string, unsigned int>::iterator, bool> rc;
    rc = precision.insert(std::make_pair(cit->first, cit->second->getNbits()));
    if (not rc.second)
    {
      TM_FATAL_ERROR("tmeventsetup::getPrecisionsPy: insertion failed");
    }
  }
}
#endif


long long
toFixedPoint(double real,
             const size_t precision)
{

  if (precision > (sizeof(pow10)/sizeof(pow10[0]) - 1))
    TM_FATAL_ERROR("tmeventsetup::toFixedPoint: unsupported precision '" << precision << "'");

  real *= pow10[precision];
  const long long integer = real >= 0.0 ? (real + 0.5) : (real - 0.5);
  return integer;
}


void
setLut(std::vector<long long>& lut,
       const std::vector<double>& array,
       const unsigned int precision)
{
  lut.clear();
  for (size_t ii = 0; ii < array.size(); ii++)
  {
    lut.push_back(toFixedPoint(array.at(ii), precision));
  }
}


size_t
getLut(std::vector<long long>& lut,
       const esScale* scale,
       const unsigned int precision)
{
  lut.resize(pow(2, scale->getNbits()));
  std::fill(lut.begin(), lut.end(), 0);
  const std::vector<tmeventsetup::esBin> bins = scale->getBins();
  for (size_t ii = 0; ii < bins.size(); ii++)
  {
    double centre = (bins.at(ii).minimum + bins.at(ii).maximum)*0.5;
    lut.at(ii) = toFixedPoint(centre, precision);
  }

  return bins.size();
}


bool
isCaloMuonScale(const esScale* scale1,
                const esScale* scale2)
{
  bool rc = true;

  if (scale1->getScaleType() != scale2->getScaleType())
  {
    TM_FATAL_ERROR("tmeventsetup::isCaloMuonScale: different scale type given: "
                    << scale1->getScaleType() << " != " << scale2->getScaleType());
  }

  switch (scale1->getObjectType())
  {
    case Egamma:
    case Tau:
    case Jet:
    case ETM:
    case HTM:
    case ETMHF:
      break;

    default:
      TM_FATAL_ERROR("tmeventsetup::isCaloMuonScale: scale1 not for calo: "
                     << scale1->getObjectType());
  }

  if (scale2->getObjectType() != Muon) TM_FATAL_ERROR("tmeventsetup::isCaloMuonScale: scale2 not for muon: " << scale2->getObjectType());

  return rc;
}


size_t
getCaloMuonEtaConversionLut(std::vector<long long>& lut,
                            const esScale* scale1,
                            const esScale* scale2)
{
  const esScaleType type = static_cast<esScaleType>(scale1->getScaleType());
  if (type != EtaScale) TM_FATAL_ERROR("tmeventsetup::getCaloMuonEtaConversionLut: not EtaScale : " << type);

  if (not isCaloMuonScale(scale1, scale2)) TM_FATAL_ERROR("tmeventsetup::getCaloMuonEtaConversionLut: not a calo muon scale pair");

  const double step1 = scale1->getStep();
  const double step2 = scale2->getStep();
  if (step1 == 0.0 or step2 == 0.0) TM_FATAL_ERROR("tmeventsetup::getCaloMuonEtaConversionLut: step size is 0.0");

  if (step1 <= step2) TM_FATAL_ERROR("tmeventsetup::getCaloMuonEtaConversionLut: step size of scale2 should be smaller");


  lut.clear();

  const int ratio = step1 / step2;
  const int offset = ratio / 2;
  const size_t n = pow(2, scale1->getNbits());

  for (size_t ii = 0; ii < n/2; ii++)
  {
    lut.push_back(offset + ratio*ii);
  }
  for (size_t ii = n/2; ii < n; ii++)
  {
    lut.push_back(offset + ratio*(ii - static_cast<int>(n)));
  }

  return n;
}


size_t
getCaloMuonPhiConversionLut(std::vector<long long>& lut,
                            const esScale* scale1,
                            const esScale* scale2)
{
  const esScaleType type = static_cast<esScaleType>(scale1->getScaleType());
  if (type != PhiScale) TM_FATAL_ERROR("tmeventsetup::getCaloMuonPhiConversionLut: not PhiScale : " << type);

  if (not isCaloMuonScale(scale1, scale2)) TM_FATAL_ERROR("tmeventsetup::getCaloMuonPhiConversionLut: not a calo muon scale pair");

  const double step1 = scale1->getStep();
  const double step2 = scale2->getStep();
  if (step1 == 0.0 or step2 == 0.0) TM_FATAL_ERROR("tmeventsetup::getCaloMuonPhiConversionLut: step size is 0.0");

  if (step1 <= step2) TM_FATAL_ERROR("tmeventsetup::getCaloMuonPhiConversionLut: step size of scale2 should be smaller");


  lut.resize(pow(2, scale1->getNbits()));
  std::fill(lut.begin(), lut.end(), 0);

  const int ratio = step1 / step2;
  const int offset = ratio / 2;

  for (size_t ii = 0; ii < scale1->getBins().size(); ii++)
  {
    lut.at(ii) = offset + ratio*ii;
  }

  return scale1->getBins().size();
}


size_t
getDeltaVector(std::vector<double>& array,
               const esScale* scale1,
               const esScale* scale2)
{
  const double step = std::min(scale1->getStep(), scale2->getStep());
  const double range1 = scale1->getMaximum() - scale1->getMinimum();
  const double range2 = scale2->getMaximum() - scale2->getMinimum();
  const double range = std::max(range1, range2);
  const size_t n = ceil(range / step);
  const size_t bitwidth = ceil(log10(n) / log10(2));
  array.resize(pow(2, bitwidth));
  std::fill(array.begin(), array.end(), 0);
  for (size_t ii = 0; ii < n; ii++)
  {
    array.at(ii) = step * ii;
  }

  return n;
}


void
applyCos(std::vector<double>& array,
         const size_t n)
{
  if (n > array.size()) TM_FATAL_ERROR("tmeventsetup::applyCos:");

  for (size_t ii = 0; ii < n; ii++)
  {
    array.at(ii) = cos(array.at(ii));
  }
}


void
applyCosh(std::vector<double>& array,
          const size_t n)
{
  if (n > array.size()) TM_FATAL_ERROR("tmeventsetup::applyCosh:");

  for (size_t ii = 0; ii < n; ii++)
  {
    array.at(ii) = cosh(array.at(ii));
  }
}

} // namespace tmeventsetup

/* eof */
