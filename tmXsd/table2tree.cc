/*====================================================================*
 * declarations  
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "tmXsd/gen-xsd-type/gen-scale_set.hxx"
#include "tmXsd/gen-xsd-type/gen-ext_signal_set.hxx"
#include "tmXsd/gen-xsd-type/gen-menu.hxx"

#include "tmXsd/keywords.hh"
#include "tmXsd/table2tree.hh"
#include "tmXsd/converter.hh"
#include "tmXsd/writer.hh"
#include "tmTable/tmTable.hh"
#include "tmUtil/tmUtil.hh"


/*====================================================================*
 * implementation
 *====================================================================*/
void
tmxsdtree::scale2tree(const tmtable::Scale& data,
                    tmxsdtree::scale_set& scale_set,
                    const bool attribute)
{

  TM_LOG_DBG("tmxsdtree::scale2tree: scale_set");
  // convert SCALE_SET
  tmxsd::Converter<tmxsdtree::scale_set> conv_scale_set;
  conv_scale_set.attribute(attribute);
  scale_set = conv_scale_set.convert(data.scaleSet);

  TM_LOG_DBG("tmxsdtree::scale2tree: scale");
  // convert SCALE
  tmxsdtree::scale_set::scale_sequence& scales(scale_set.scale());
  for (size_t ii = 0; ii < data.scales.size(); ii++)
  {
    const tmtable::Row& row_scale = data.scales.at(ii);
    const std::string& type = tmxsd::getValue(row_scale, "type");
    const std::string& object = tmxsd::getValue(row_scale, "object");
    const std::string key = object + "-" + type;
    tmxsd::Converter<tmxsdtree::scale> conv_scale;
    conv_scale.attribute(attribute);
    tmxsdtree::scale scale = conv_scale.convert(row_scale);

    tmtable::StringTableMap::const_iterator cit = data.bins.find(key);
    if (cit == data.bins.end())
    {
      std::string error("inf> tmxsdtree::scale2tree() no bins for the scale '");
      error += key + "'";
    }
    else
    {
      TM_LOG_DBG("tmxsdtree::scale2tree: bin");
      // convert BIN
      const tmtable::Table table = data.bins.find(key)->second;
      tmxsdtree::scale::bin_sequence& bins(scale.bin());
      for (size_t jj = 0; jj < table.size(); jj++)
      {
        const tmtable::Row& row_bin = table.at(jj);
        tmxsd::Converter<tmxsdtree::bin> conv_bin;
        conv_bin.attribute(attribute);
        tmxsdtree::bin bin = conv_bin.convert(row_bin);
        bins.push_back(bin);
      }
    }

    scales.push_back(scale);
  }
}


void
tmxsdtree::scale2xml(const tmtable::Scale& scale,
                     const char* fileName,
                     const bool attribute)
{
  tmxsdtree::scale_set scale_set("");
  tmxsdtree::scale2tree(scale, scale_set, attribute);

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "scale_set.xsd";

  std::ofstream ofs(fileName);
  tmxsdtree::scale_set_(ofs, scale_set, map);
}


void
tmxsdtree::extSignal2tree(const tmtable::ExtSignal& data,
                          tmxsdtree::ext_signal_set& ext_signal_set,
                          const bool attribute)
{
  TM_LOG_DBG("tmxsdtree::extSignal2tree: EXT_SIGNAL_SET");
  // convert EXT_SIGNAL_SET
  tmxsd::Converter<tmxsdtree::ext_signal_set> conv_ext_signal_set;
  conv_ext_signal_set.attribute(attribute);
  ext_signal_set = conv_ext_signal_set.convert(data.extSignalSet);

  TM_LOG_DBG("tmxsdtree::extSignal2tree: EXT_SIGNAL");
  // convert EXT_SIGNAL
  tmxsdtree::ext_signal_set::ext_signal_sequence& extSignals(ext_signal_set.ext_signal());
  const tmtable::Table& table = data.extSignals;
  for (size_t ii = 0; ii < table.size(); ii++)
  {
    const tmtable::Row& row = table.at(ii);
    tmxsd::Converter<tmxsdtree::ext_signal> conv_ext_signal;
    conv_ext_signal.attribute(attribute);
    tmxsdtree::ext_signal extSignal = conv_ext_signal.convert(row);
    extSignals.push_back(extSignal);
  }
}


void
tmxsdtree::extSignal2xml(const tmtable::ExtSignal& extSignal,
                         const char* fileName,
                         const bool attribute)
{
  tmxsdtree::ext_signal_set ext_signal_set("");
  tmxsdtree::extSignal2tree(extSignal, ext_signal_set, attribute);

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "ext_signal_set.xsd";

  std::ofstream ofs(fileName);
  tmxsdtree::ext_signal_set_(ofs, ext_signal_set, map);
}


void
tmxsdtree::menu2tree(const tmtable::Menu& data,
                     const tmtable::Scale& scale,
                     const tmtable::ExtSignal& extSignal,
                     tmxsdtree::menu& menu,
                     const bool attribute)
{
  TM_LOG_DBG("tmxsdtree::menu2tree: MENU");
  // convert MENU
  tmxsd::Converter<tmxsdtree::menu> conv_menu;
  conv_menu.attribute(attribute);
  menu = conv_menu.convert(data.menu);

  TM_LOG_DBG("tmxsdtree::menu2tree: SCALE_SET");
  // SCALE_SET
  tmxsdtree::scale_set scale_set("");
  tmxsdtree::scale2tree(scale, scale_set, attribute);
  menu.scale_set(scale_set);

  TM_LOG_DBG("tmxsdtree::menu2tree: EXT_SIGNAL_SET");
  // EXT_SIGNAL_SET
  tmxsdtree::ext_signal_set ext_signal_set("");
  tmxsdtree::extSignal2tree(extSignal, ext_signal_set, attribute);
  menu.ext_signal_set(ext_signal_set);

  tmxsdtree::menu::algorithm_sequence& algorithms(menu.algorithm());
  for (size_t ii = 0; ii < data.algorithms.size(); ii++)
  {
    bool hasComponent = false;

    TM_LOG_DBG("tmxsdtree::menu2tree: ALGORITHM");
    // convert ALGORITHM
    const tmtable::Row& row_algorithm = data.algorithms.at(ii);
    const std::string& key = tmxsd::getValue(row_algorithm, "name");
    tmxsd::Converter<tmxsdtree::algorithm> conv_algorithm;
    conv_algorithm.attribute(attribute);
    tmxsdtree::algorithm algorithm = conv_algorithm.convert(row_algorithm);


    TM_LOG_DBG("tmxsdtree::menu2tree: OBJECT_REQUIREMENT: " << key);
    // convert OBJECT_REQUIREMENT
    tmtable::StringTableMap::const_iterator cit = data.objects.find(key);
    if (cit != data.objects.end())
    {
      hasComponent = true;
      tmxsdtree::algorithm::object_requirement_sequence& objects(algorithm.object_requirement());
      const tmtable::Table table_object = data.objects.find(key)->second;
      for (size_t jj = 0; jj < table_object.size(); jj++)
      {
        const tmtable::Row& row_object = table_object.at(jj);
        tmxsd::Converter<tmxsdtree::object_requirement> conv_object;
        conv_object.attribute(attribute);
        tmxsdtree::object_requirement object = conv_object.convert(row_object);
        objects.push_back(object);
      }
    }


    TM_LOG_DBG("tmxsdtree::menu2tree: EXTERNAL_REQUIREMENT");
    // convert EXTERNAL_REQUIREMENT
    cit = data.externals.find(key);
    if (cit != data.externals.end())
    {
      hasComponent = true;
      tmxsdtree::algorithm::external_requirement_sequence& externals(algorithm.external_requirement());
      const tmtable::Table table_external = data.externals.find(key)->second;
      for (size_t jj = 0; jj < table_external.size(); jj++)
      {
        const tmtable::Row& row_external = table_external.at(jj);
        tmxsd::Converter<tmxsdtree::external_requirement> conv_external;
        conv_external.attribute(attribute);
        tmxsdtree::external_requirement external = conv_external.convert(row_external);
        externals.push_back(external);
      }
    }


    TM_LOG_DBG("tmxsdtree::menu2tree: CUT");
    // convert CUT
    cit = data.cuts.find(key);
    if (cit != data.cuts.end())
    {
      hasComponent = true;
      tmxsdtree::algorithm::cut_sequence& cuts(algorithm.cut());
      const tmtable::Table table_cut = data.cuts.find(key)->second;
      for (size_t jj = 0; jj < table_cut.size(); jj++)
      {
        const tmtable::Row& row_cut = table_cut.at(jj);
        tmxsd::Converter<tmxsdtree::cut> conv_cut;
        conv_cut.attribute(attribute);
        tmxsdtree::cut cut = conv_cut.convert(row_cut);
        cuts.push_back(cut);
      }
    }

    if (not hasComponent)
    {
      std::string error("err> tmxsdtree::menu2tree() key '");
      error += key + "' no component in algorithm";
      throw std::runtime_error(error);
    }

    algorithms.push_back(algorithm);
  }
}


void
tmxsdtree::menu2xml(const tmtable::Menu& data,
                    const tmtable::Scale& scale,
                    const tmtable::ExtSignal& extSignal,
                    const char* fileName,
                    const bool attribute)

{
  tmxsdtree::menu menu(0, "", "", "", "", "", 0);
  tmxsdtree::menu2tree(data, scale, extSignal, menu, attribute);

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "menu.xsd";

  std::ofstream ofs(fileName);
  tmxsdtree::menu_(ofs, menu, map);
}

/* eof */
