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


/*====================================================================*
 * implementation
 *====================================================================*/
namespace tmxsd
{
  /** Converter for tmxsdtree::bin */
  template<> tmxsdtree::bin
  Converter<tmxsdtree::bin>::convert(const tmtable::Row& row)
  {
    tmxsdtree::bin bin(0, "", "");
    success_ = true;

    if (not validateKeys(tmxsd::binKey, row))
    {
      success_ = false;
      return bin;
    }

    bin.number(getValue<uint, std::string>(row, "number"));
    bin.minimum(getValue(row, "minimum"));
    bin.maximum(getValue(row, "maximum"));

    if (attribute_) {
      if (row.find("bin_id") != row.end())
      {
        bin.bin_id(getValue<uint, std::string>(row, "bin_id"));
      }
      if (row.find("scale_id") != row.end())
      {
        bin.scale_id(getValue<uint, std::string>(row, "scale_id"));
      }
    }

    return bin;
  }


  /** Converter for tmxsdtree::scale */
  template<> tmxsdtree::scale
  Converter<tmxsdtree::scale>::convert(const tmtable::Row& row)
  {
    tmxsdtree::scale scale("", "", "", "", "", 0);
    success_ = true;

    if (not validateKeys(tmxsd::scaleKey, row))
    {
      success_ = false;
      return scale;
    }

    scale.object(getValue(row, "object"));
    scale.type(getValue(row, "type"));
    scale.minimum(getValue(row, "minimum"));
    scale.maximum(getValue(row, "maximum"));
    scale.step(getValue(row, "step"));
    scale.n_bits(getValue<uint, std::string>(row, "n_bits"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      scale.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("scale_id") != row.end())
      {
        scale.scale_id(getValue<uint, std::string>(row, "scale_id"));
      }
      if (row.find("datetime") != row.end())
      {
        scale.datetime(getValue(row, "datetime"));
      }
      if (row.find("n_bins") != row.end())
      {
        scale.n_bins(getValue<uint, std::string>(row, "n_bins"));
      }
    }

    return scale;
  }


  /** Converter for tmxsdtree::scale_set */
  template<> tmxsdtree::scale_set
  Converter<tmxsdtree::scale_set>::convert(const tmtable::Row& row)
  {
    tmxsdtree::scale_set scale_set("");
    success_ = true;

    if (not validateKeys(tmxsd::scaleSetKey, row))
    {
      success_ = false;
      return scale_set;
    }

    scale_set.name(getValue(row, "name"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      scale_set.comment(getValue(row, "comment"));
    }
    
    if (attribute_)
    {
      if (row.find("scale_set_id") != row.end())
      {
        scale_set.scale_set_id(getValue<uint, std::string>(row, "scale_set_id"));
      }
      if (row.find("datetime") != row.end())
      {
        scale_set.datetime(getValue(row, "datetime"));
      }
      if (row.find("is_valid") != row.end())
      {
        scale_set.is_valid(getValue<bool, std::string>(row, "is_valid"));
      }
    }

    return scale_set;
  }


  /** Converter for tmxsdtree::ext_signal */
  template<> tmxsdtree::ext_signal
  Converter<tmxsdtree::ext_signal>::convert(const tmtable::Row& row)
  {
    tmxsdtree::ext_signal ext_signal("", "", 0, 0);
    success_ = true;

    if (not validateKeys(extSignalKey, row))
    {
      success_ = false;
      return ext_signal;
    }

    ext_signal.name(getValue(row, "name"));
    ext_signal.system(getValue(row, "system"));
    ext_signal.cable(getValue<uint, std::string>(row, "cable"));
    ext_signal.channel(getValue<uint, std::string>(row, "channel"));

    if ((row.find("description") != row.end()) and
        (not row.find("description")->second.empty()))
    {
      ext_signal.description(getValue(row, "description"));
    }
    if ((row.find("label") != row.end()) and
        (not row.find("label")->second.empty()))
    {
      ext_signal.label(getValue(row, "label"));
    }

    if (attribute_)
    {
      if (row.find("ext_signal_id") != row.end())
      {
        ext_signal.ext_signal_id(getValue<uint, std::string>(row, "ext_signal_id"));
      }
      if (row.find("datetime") != row.end())
      {
        ext_signal.datetime(getValue(row, "datetime"));
      }
    }

    return ext_signal;
  }


  /** Converter for tmxsdtree::ext_signal_set */
  template<> tmxsdtree::ext_signal_set
  Converter<tmxsdtree::ext_signal_set>::convert(const tmtable::Row& row)
  {
    tmxsdtree::ext_signal_set ext_signal_set("");
    success_ = true;

    if (not validateKeys(tmxsd::extSignalSetKey, row))
    {
      success_ = false;
      return ext_signal_set;
    }

    ext_signal_set.name(getValue(row, "name"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      ext_signal_set.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("ext_signal_set_id") != row.end())
      {
        ext_signal_set.ext_signal_set_id(getValue<uint, std::string>(row, "ext_signal_set_id"));
      }
      if (row.find("datetime") != row.end())
      {
        ext_signal_set.datetime(getValue(row, "datetime"));
      }
      if (row.find("is_valid") != row.end())
      {
        ext_signal_set.is_valid(getValue<bool, std::string>(row, "is_valid"));
      }
    }

    return ext_signal_set;
  }


  /** Converter for tmxsdtree::object_requirement */
  template<> tmxsdtree::object_requirement
  Converter<tmxsdtree::object_requirement>::convert(const tmtable::Row& row)
  {
    tmxsdtree::object_requirement object_requirement("", "", "", "", 0);
    success_ = true;

    if (not validateKeys(tmxsd::objectRequirementKey, row))
    {
      success_ = false;
      return object_requirement;
    }

    object_requirement.name(getValue(row, "name"));
    object_requirement.type(getValue(row, "type"));
    object_requirement.comparison_operator(getValue(row, "comparison_operator"));
    object_requirement.threshold(getValue(row, "threshold"));
    object_requirement.bx_offset(getValue<int, std::string>(row, "bx_offset"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      object_requirement.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("requirement_id") != row.end())
      {
        object_requirement.requirement_id(getValue<uint, std::string>(row, "requirement_id"));
      }
      if (row.find("datetime") != row.end())
      {
        object_requirement.datetime(getValue(row, "datetime"));
      }
    }

    return object_requirement;
  }


  /** Converter for tmxsdtree::external_requirement */
  template<> tmxsdtree::external_requirement
  Converter<tmxsdtree::external_requirement>::convert(const tmtable::Row& row)
  {
    tmxsdtree::external_requirement external_requirement("", 0);
    success_ = true;

    if (not validateKeys(tmxsd::externalRequirementKey, row))
    {
      success_ = false;
      return external_requirement;
    }

    external_requirement.name(getValue(row, "name"));
    external_requirement.bx_offset(getValue<int, std::string>(row, "bx_offset"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      external_requirement.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("requirement_id") != row.end())
      {
        external_requirement.requirement_id(getValue<uint, std::string>(row, "requirement_id"));
      }
      if (row.find("ext_signal_id") != row.end())
      {
        external_requirement.ext_signal_id(getValue<uint, std::string>(row, "ext_signal_id"));
      }
      if (row.find("datetime") != row.end())
      {
        external_requirement.datetime(getValue(row, "datetime"));
      }
    }

    return external_requirement;
  }


  /** Converter for tmxsdtree::cut */
  template<> tmxsdtree::cut
  Converter<tmxsdtree::cut>::convert(const tmtable::Row& row)
  {
    tmxsdtree::cut cut("", "", "", "", "", "");
    success_ = true;

    if (not validateKeys(tmxsd::cutKey, row))
    {
      success_ = false;
      return cut;
    }

    cut.name(getValue(row, "name"));
    cut.object(getValue(row, "object"));
    cut.type(getValue(row, "type"));
    cut.minimum(getValue(row, "minimum"));
    cut.maximum(getValue(row, "maximum"));
    cut.data(getValue(row, "data"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      cut.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("cut_id") != row.end())
      {
        cut.cut_id(getValue<uint, std::string>(row, "cut_id"));
      }
      if (row.find("datetime") != row.end())
      {
        cut.datetime(getValue(row, "datetime"));
      }
    }

    return cut;
  }


  /** Converter for tmxsdtree::algorithm */
  template<> tmxsdtree::algorithm
  Converter<tmxsdtree::algorithm>::convert(const tmtable::Row& row)
  {
    tmxsdtree::algorithm algorithm("", "", 0, 0, 0);
    success_ = true;

    if (not validateKeys(tmxsd::algorithmKey, row))
    {
      success_ = false;
      return algorithm;
    }

    algorithm.name(getValue(row, "name"));
    algorithm.expression(getValue(row, "expression"));
    algorithm.index(getValue<uint, std::string>(row, "index"));
    algorithm.module_id(getValue<uint, std::string>(row, "module_id"));
    algorithm.module_index(getValue<uint, std::string>(row, "module_index"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      algorithm.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("algorithm_id") != row.end())
      {
        algorithm.algorithm_id(getValue<uint, std::string>(row, "algorithm_id"));
      }
      if (row.find("datetime") != row.end())
      {
        algorithm.datetime(getValue(row, "datetime"));
      }
    }

    return algorithm;
  }



  /** Converter for tmxsdtree::menu */
  template<> tmxsdtree::menu
  Converter<tmxsdtree::menu>::convert(const tmtable::Row& row)
  {
    tmxsdtree::menu menu(0, "", "", "", "", "", 0);
    success_ = true;

    if (not validateKeys(tmxsd::menuKey, row))
    {
      success_ = false;
      return menu;
    }

    menu.ancestor_id(getValue<uint, std::string>(row, "ancestor_id"));
    menu.name(getValue(row, "name"));
    menu.uuid_menu(getValue(row, "uuid_menu"));
    menu.uuid_firmware(getValue(row, "uuid_firmware"));
    menu.global_tag(getValue(row, "global_tag"));
    menu.grammar_version(getValue(row, "grammar_version"));
    menu.n_modules(getValue<uint, std::string>(row, "n_modules"));
    menu.is_valid(getValue<bool, std::string>(row, "is_valid"));
    menu.is_obsolete(getValue<bool, std::string>(row, "is_obsolete"));

    if ((row.find("comment") != row.end()) and
        (not row.find("comment")->second.empty()))
    {
      menu.comment(getValue(row, "comment"));
    }

    if (attribute_)
    {
      if (row.find("menu_id") != row.end())
      {
        menu.menu_id(getValue<uint, std::string>(row, "menu_id"));
      }
      if (row.find("datetime") != row.end())
      {
        menu.datetime(getValue(row, "datetime"));
      }
    }

    return menu;
  }
} // namespace tmxsd

/* eof */
