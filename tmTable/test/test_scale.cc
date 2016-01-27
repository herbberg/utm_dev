#include <iostream>
#include <algorithm>

#include "tmTable/tmTable.hh"

int
main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "usage: " << argv[0] << " file.xml" << std::endl;
    return 1;
  }

  tmtable::Scale scale;
  tmtable::xml2scale(argv[1], scale);

  // scale set
  std::cout << "scale_set:" << std::endl;
  for (tmtable::Row::const_iterator cit = scale.scaleSet.begin();
       cit != scale.scaleSet.end(); ++cit)
  {
    std::cout << "  " << cit->first << " = " << cit->second << '\n';
  }

  // scales
  std::vector<std::string> keys;

  std::cout << "\nscales:" << std::endl;
  for (size_t ii = 0; ii < scale.scales.size(); ii++)
  {
    for (tmtable::Row::const_iterator cit = scale.scales[ii].begin();
        cit != scale.scales[ii].end(); ++cit)
    {
      std::cout << "  " << cit->first << " = " << cit->second << '\n';
    }
    std::cout << std::endl;
    keys.push_back(scale.getKeyForBin(scale.scales[ii]));
  }

  // bins
  for (size_t ii = 0; ii < keys.size(); ii++)
  {
    const std::string key = keys[ii];
    tmtable::Table bin = scale.bins[key];
    std::cout << key << ":  # of bins = " << bin.size() << '\n';
    for (size_t jj = 0; jj < std::min((size_t)5, scale.scales.size()); jj++)
    {
      for (tmtable::Row::const_iterator cit = bin[jj].begin();
          cit != bin[jj].end(); ++cit)
      {
        std::cout << "    " << cit->first << " = " << cit->second << '\n';
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
