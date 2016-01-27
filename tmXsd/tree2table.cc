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

#include "tmXsd/tree2table.hh"
#include "tmXsd/reader.hh"
#include "tmTable/tmTable.hh"
#include "tmUtil/tmUtil.hh"


/*====================================================================*
 * implementation
 *====================================================================*/
void
tmxsd::tree2scale(const tmxsd::scale_set& scale_set,
                  tmtable::Scale& data)
{
  data.scaleSet["name"] = scale_set.name();

  std::string str;

  str = scale_set.comment();
  if (not str.empty()) data.scaleSet["comment"] = str;

  str = tmutil::toString(scale_set.scale_set_id());
  if (not str.empty()) data.scaleSet["scale_set_id"] = str;

  str = scale_set.datetime();
  if (not str.empty()) data.scaleSet["datetime"] = str;

  str = tmutil::toString(scale_set.is_valid());
  if (not str.empty()) data.scaleSet["is_valid"] = str;

  for (size_t ii = 0; ii < scale_set.scale().size(); ii++)
  {
    const tmxsd::scale& scale = scale_set.scale().at(ii);
    tmtable::Row row_scale;
    row_scale["object"] = scale.object();
    row_scale["type"] = scale.type();
    row_scale["minimum"] = scale.minimum();
    row_scale["maximum"] = scale.maximum();
    row_scale["step"] = scale.step();
    row_scale["n_bits"] = tmutil::toString(scale.n_bits());

    str = scale.comment();
    if (not str.empty()) row_scale["comment"] = str;

    str = tmutil::toString(scale.scale_id());
    if (not str.empty()) row_scale["scale_id"] = str;

    str = scale.datetime();
    if (not str.empty()) row_scale["datetime"] = str;

    str = tmutil::toString(scale.n_bins());
    if (not str.empty()) row_scale["n_bins"] = str;

    tmtable::Table table_bin;
    for (size_t jj = 0; jj < scale.bin().size(); jj++)
    {
      const tmxsd::bin& bin = scale.bin().at(jj);
      tmtable::Row row_bin;
      row_bin["number"] = tmutil::toString(bin.number());
      row_bin["minimum"] = bin.minimum();
      row_bin["maximum"] = bin.maximum();

      str = tmutil::toString(bin.bin_id());
      if (not str.empty()) row_bin["bin_id"] = str;

      str = tmutil::toString(bin.scale_id());
      if (not str.empty()) row_bin["scale_id"] = str;

      table_bin.push_back(row_bin);
    }
    if (table_bin.size()) data.bins[data.getKeyForBin(row_scale)] = table_bin;
    data.scales.push_back(row_scale);
  }
}


tmxsd::scale_set
tmxsd::xml2scale_set(const char* fileName,
                     std::string& message,
                     const bool debug)
{
  message = "";
  std::ifstream ifs(fileName, std::ifstream::in);
  if (not ifs.is_open())
  {
    message = std::string("failed to open '") + fileName + "'";
    return tmxsd::scale_set();
  }

  tmxsd::Reader<tmxsd::scale_set> reader;
  reader.debug(debug);
  tmxsd::scale_set o = reader.read(ifs);
  if (not reader.success()) message = reader.message();
  return o;
}


void
tmxsd::tree2extSignal(const tmxsd::ext_signal_set& ext_signal_set,
                      tmtable::ExtSignal& data)
{
  data.extSignalSet["name"] = ext_signal_set.name();
  std::string str;

  str = ext_signal_set.comment();
  if (not str.empty()) data.extSignalSet["comment"] = str;

  str = tmutil::toString(ext_signal_set.ext_signal_set_id());
  if (not str.empty()) data.extSignalSet["ext_signal_set_id"] = str;

  str = ext_signal_set.datetime();
  if (not str.empty()) data.extSignalSet["datetime"] = str;

  str = tmutil::toString(ext_signal_set.is_valid());
  if (not str.empty()) data.extSignalSet["is_valid"] = str;

  for (size_t ii = 0; ii < ext_signal_set.ext_signal().size(); ii++)
  {
    const tmxsd::ext_signal& ext_signal = ext_signal_set.ext_signal().at(ii);
    tmtable::Row row;
    row["name"] = ext_signal.name();
    row["system"] = ext_signal.system();
    row["cable"] = tmutil::toString(ext_signal.cable());
    row["channel"] = tmutil::toString(ext_signal.channel());

    str = ext_signal.description();
    if (not str.empty()) row["description"] = str;

    str = ext_signal.label();
    if (not str.empty()) row["label"] = str;

    str = tmutil::toString(ext_signal.ext_signal_id());
    if (not str.empty()) row["ext_signal_id"] = str;

    str = ext_signal.datetime();
    if (not str.empty()) row["datetime"] = str;

    data.extSignals.push_back(row);
  }
}


tmxsd::ext_signal_set
tmxsd::xml2ext_signal_set(const char* fileName,
                          std::string& message,
                          const bool debug)
{
  message = "";
  std::ifstream ifs(fileName, std::ifstream::in);
  tmxsd::Reader<tmxsd::ext_signal_set> reader;
  reader.debug(debug);
  tmxsd::ext_signal_set o = reader.read(ifs);
  if (not reader.success()) message = reader.message();
  return o;
}


void
tmxsd::tree2menu(const tmxsd::menu& data,
                 tmtable::Menu& menu,
                 tmtable::Scale& scale,
                 tmtable::ExtSignal& extSignal)
{
  // SCALE_SET
  tree2scale(data.scale_set(), scale);

  // EXT_SIGNAL_SET
  tree2extSignal(data.ext_signal_set(), extSignal);

  // MENU
  menu.menu["ancestor_id"] = tmutil::toString(data.ancestor_id());
  menu.menu["name"] = data.name();
  menu.menu["uuid_menu"] = data.uuid_menu();
  menu.menu["uuid_firmware"] = data.uuid_firmware();
  menu.menu["global_tag"] = data.global_tag();
  menu.menu["grammar_version"] = data.grammar_version();
  menu.menu["n_modules"] = tmutil::toString(data.n_modules());
  menu.menu["is_valid"] = tmutil::toString(data.is_valid());
  menu.menu["is_obsolete"] = tmutil::toString(data.is_obsolete());

  std::string str;

  str = data.comment();
  if (not str.empty()) menu.menu["comment"] = str;

  str = tmutil::toString(data.menu_id());
  if (not str.empty()) menu.menu["menu_id"] = str;

  str = data.datetime();
  if (not str.empty()) menu.menu["datetime"] = str;


  // ALGORITHM
  for (size_t ii = 0; ii < data.algorithm().size(); ii++)
  {
    const tmxsd::algorithm& algorithm = data.algorithm().at(ii);
    tmtable::Row row_algo;
    row_algo["name"] = algorithm.name();
    row_algo["expression"] = algorithm.expression();
    row_algo["index"] = tmutil::toString(algorithm.index());
    row_algo["module_id"] = tmutil::toString(algorithm.module_id());
    row_algo["module_index"] = tmutil::toString(algorithm.module_index());

    str = algorithm.comment();
    if (not str.empty()) row_algo["comment"] = str;

    str = tmutil::toString(algorithm.algorithm_id());
    if (not str.empty()) row_algo["algorithm_id"] = str;

    str = algorithm.datetime();
    if (not str.empty()) row_algo["datetime"] = str;


    const std::string key = row_algo["name"];

    // CUT
    for (size_t jj = 0; jj < algorithm.cut().size(); jj++)
    {
      const tmxsd::cut& cut = algorithm.cut().at(jj);
      tmtable::Row row_cut;
      row_cut["name"] = cut.name();
      row_cut["object"] = cut.object();
      row_cut["type"] = cut.type();
      row_cut["minimum"] = cut.minimum();
      row_cut["maximum"] = cut.maximum();
      row_cut["data"] = cut.data();

      str = cut.comment();
      if (not str.empty()) row_cut["comment"] = str;

      str = tmutil::toString(cut.cut_id());
      if (not str.empty()) row_cut["cut_id"] = str;

      str = cut.datetime();
      if (not str.empty()) row_cut["datetime"] = str;

      menu.cuts[key].push_back(row_cut);
    }

    // OBJECT_REQUIREMENT
    for (size_t jj = 0; jj < algorithm.object_requirement().size(); jj++)
    {
      const tmxsd::object_requirement& object = algorithm.object_requirement().at(jj);
      tmtable::Row row_object;
      row_object["name"] = object.name();
      row_object["type"] = object.type();
      row_object["comparison_operator"] = object.comparison_operator();
      row_object["threshold"] = object.threshold();
      row_object["bx_offset"] = tmutil::toString(object.bx_offset());

      str = object.comment();
      if (not str.empty()) row_object["comment"] = str;

      str = tmutil::toString(object.requirement_id());
      if (not str.empty()) row_object["requirement_id"] = str;

      str = object.datetime();
      if (not str.empty()) row_object["datetime"] = str;

      menu.objects[key].push_back(row_object);
    }

    // EXTERNAL_REQUIREMENT
    for (size_t jj = 0; jj < algorithm.external_requirement().size(); jj++)
    {
      const tmxsd::external_requirement& external = algorithm.external_requirement().at(jj);
      tmtable::Row row_external;
      row_external["name"] = external.name();
      row_external["bx_offset"] = tmutil::toString(external.bx_offset());

      str = external.comment();
      if (not str.empty()) row_external["comment"] = str;

      str = tmutil::toString(external.requirement_id());
      if (not str.empty()) row_external["requirement_id"] = str;

      str = tmutil::toString(external.ext_signal_id());
      if (not str.empty()) row_external["ext_signal_id"] = str;

      str = external.datetime();
      if (not str.empty()) row_external["datetime"] = str;

      menu.externals[key].push_back(row_external);
    }

    menu.algorithms.push_back(row_algo);
  }
}


tmxsd::menu
tmxsd::xml2menu(const char* fileName,
                std::string& message,
                const bool debug)
{
  message = "";
  std::ifstream ifs(fileName, std::ifstream::in);
  tmxsd::Reader<tmxsd::menu> reader;
  reader.debug(debug);
  tmxsd::menu o = reader.read(ifs);
  if (not reader.success()) message = reader.message();
  return o;
}

/* eof */
