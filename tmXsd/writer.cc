/*====================================================================*
 * declarations  
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "tmXsd/gen-xsd-type/gen-bin.hxx"
#include "tmXsd/gen-xsd-type/gen-scale.hxx"
#include "tmXsd/gen-xsd-type/gen-scale_set.hxx"
#include "tmXsd/gen-xsd-type/gen-ext_signal.hxx"
#include "tmXsd/gen-xsd-type/gen-ext_signal_set.hxx"
#include "tmXsd/gen-xsd-type/gen-object_requirement.hxx"
#include "tmXsd/gen-xsd-type/gen-external_requirement.hxx"
#include "tmXsd/gen-xsd-type/gen-cut.hxx"
#include "tmXsd/gen-xsd-type/gen-algorithm.hxx"
#include "tmXsd/gen-xsd-type/gen-menu.hxx"

#include "tmUtil/tmUtil.hh"
#include "tmXsd/keywords.hh"
#include "tmXsd/converter.hh"
#include "tmXsd/writer.hh"


/*====================================================================*
 * implementation
 *====================================================================*/
// ---------------------------------------------------------------------
// functions
// ---------------------------------------------------------------------
bool
tmxsd::writeBin(const tmtable::Row& row,
                std::ostream& os)
{
  Converter<tmxsdtree::bin> converter;
  tmxsdtree::bin bin = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "bin.xsd";

  tmxsdtree::bin_(os, bin, map);
  return true;
}


bool
tmxsd::writeScale(const tmtable::Row& row,
                  std::ostream& os)
{
  Converter<tmxsdtree::scale> converter;
  tmxsdtree::scale scale = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "scale.xsd";

  tmxsdtree::scale_(os, scale, map);
  return true;
}


bool
tmxsd::writeScaleSet(const tmtable::Row& row,
                     std::ostream& os)
{
  Converter<tmxsdtree::scale_set> converter;
  tmxsdtree::scale_set scale_set = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "scale_set.xsd";

  tmxsdtree::scale_set_(os, scale_set, map);
  return true;
}


bool
tmxsd::writeExtSignal(const tmtable::Row& row,
                      std::ostream& os)
{
  Converter<tmxsdtree::ext_signal> converter;
  tmxsdtree::ext_signal ext_signal = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "ext_signal.xsd";

  tmxsdtree::ext_signal_(os, ext_signal, map);
  return true;
}


bool
tmxsd::writeExtSignalSet(const tmtable::Row& row,
                         std::ostream& os)
{
  Converter<tmxsdtree::ext_signal_set> converter;
  tmxsdtree::ext_signal_set ext_signal_set = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "ext_signal_set.xsd";

  tmxsdtree::ext_signal_set_(os, ext_signal_set, map);
  return true;
}


bool
tmxsd::writeObjectRequirement(const tmtable::Row& row,
                              std::ostream& os)
{
  Converter<tmxsdtree::object_requirement> converter;
  tmxsdtree::object_requirement object_requirement = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "object_requirement.xsd";

  tmxsdtree::object_requirement_(os, object_requirement, map);
  return true;
}


bool
tmxsd::writeExternalRequirement(const tmtable::Row& row,
                                std::ostream& os)
{
  Converter<tmxsdtree::external_requirement> converter;
  tmxsdtree::external_requirement external_requirement = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "external_requirement.xsd";

  tmxsdtree::external_requirement_(os, external_requirement, map);
  return true;
}


bool
tmxsd::writeCut(const tmtable::Row& row,
                std::ostream& os)
{
  Converter<tmxsdtree::cut> converter;
  tmxsdtree::cut cut = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "cut.xsd";

  tmxsdtree::cut_(os, cut, map);
  return true;
}



bool
tmxsd::writeAlgorithm(const tmtable::Row& row,
                      std::ostream& os)
{
  Converter<tmxsdtree::algorithm> converter;
  tmxsdtree::algorithm algorithm = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "algorithm.xsd";

  tmxsdtree::algorithm_(os, algorithm, map);
  return true;
}



bool
tmxsd::writeMenu(const tmtable::Row& row,
                 std::ostream& os)
{
  Converter<tmxsdtree::menu> converter;
  tmxsdtree::menu menu = converter.convert(row);
  if (not converter.success()) return false;

  xml_schema::namespace_infomap map;
  map["tmxsd"].name = "http://www.cern.ch/tmxsd/1.0.0";
  map["tmxsd"].schema = "menu.xsd";

  tmxsdtree::menu_(os, menu, map);
  return true;
}

/* eof */
