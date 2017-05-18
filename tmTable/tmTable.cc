/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/

#include "tmUtil/tmUtil.hh"
#include "tmTable/tmTable.hh"
#include "tmXsd/keywords.hh"
#include "tmXsd/tree2table.hh"
#include "tmXsd/table2tree.hh"

#include <boost/filesystem.hpp>

#include <limits.h>
#include <cstdlib>
#include <unistd.h>
#include <cstddef>
#include <cerrno>

/*====================================================================*
 * implementation
 *====================================================================*/
/*--------------------------------------------------------------------*
 * methods
 *--------------------------------------------------------------------*/
std::string
tmtable::Scale::getKeyForBin(const tmtable::Row& scale)
{
  const std::string object = tmxsd::getValue(scale, "object");
  const std::string type = tmxsd::getValue(scale, "type");
  std::ostringstream key;
  key << object << "-" << type;
  return key.str();
}


/*--------------------------------------------------------------------*
 * functions
 *--------------------------------------------------------------------*/
std::string
tmtable::xml2scale(const char* fileName,
                   tmtable::Scale& scale,
                   const bool debug)
{
  // Get absolute path to file.
  boost::filesystem::path abspath = boost::filesystem::system_complete(fileName);

  // Check if file exists.
  if (not boost::filesystem::exists(abspath))
  {
    TM_FATAL_ERROR("tmtable::xml2scale: file \"" << fileName << "\" does not exist.");
  }

  std::string message;
  tmxsd::scale_set scale_set = tmxsd::xml2scale_set(abspath.string().c_str(), message, debug);
  if (message.empty())
  {
    tmxsd::tree2scale(scale_set, scale);
    scale.isValid(true);
  }
  return message;
}


std::string
tmtable::xml2extSignal(const char* fileName,
                       tmtable::ExtSignal& extSignal,
                       const bool debug)
{
  // Get absolute path to file.
  boost::filesystem::path abspath = boost::filesystem::system_complete(fileName);

  // Check if file exists.
  if (not boost::filesystem::exists(abspath))
  {
    TM_FATAL_ERROR("tmtable::xml2extSignal: file \"" << fileName << "\" does not exist.");
  }

  std::string message;
  tmxsd::ext_signal_set ext_signal_set = tmxsd::xml2ext_signal_set(abspath.string().c_str(), message, debug);
  if (message.empty())
  {
    tmxsd::tree2extSignal(ext_signal_set, extSignal);
    extSignal.isValid(true);
  }
  return message;
}


std::string
tmtable::xml2menu(const char* fileName,
                  tmtable::Menu& menu,
                  tmtable::Scale& scale,
                  tmtable::ExtSignal& extSignal,
                  const bool debug)
{
  // Get absolute path to file.
  boost::filesystem::path abspath = boost::filesystem::system_complete(fileName);

  // Check if file exists.
  if (not boost::filesystem::exists(abspath))
  {
    TM_FATAL_ERROR("tmtable::xml2extSignal: file \"" << fileName << "\" does not exist.");
  }

  boost::filesystem::path cwd = boost::filesystem::current_path();
  std::string message;

  tmxsd::menu data = tmxsd::xml2menu(abspath.string().c_str(), message, debug);

  // If something went wrong we got a message, so try something else...
  if (message.size())
  {
    // Change to XML file location (assuming XSD files resides there).
    boost::filesystem::current_path(abspath.parent_path().string().c_str());
    data = tmxsd::xml2menu(abspath.string().c_str(), message, debug);

    // If again something went wrong, try to change to XSD directory (TODO: a better first choice)
    if (message.size())
    {
      char* xsd = getenv("UTM_XSD_DIR");
      if (xsd)
      {
        try
        {
          // Change to XSD spec location.
          boost::filesystem::current_path(xsd);
        }
        catch (boost::filesystem::filesystem_error& e)
        {
          TM_FATAL_ERROR("tmtable::xml2menu: UTM_XSD_DIR: " << e.what());
        }

        data = tmxsd::xml2menu(abspath.string().c_str(), message, debug);
      }
    }
  }

  try
  {
    // Return to initial directory location.
    boost::filesystem::current_path(cwd);
  }
  catch (boost::filesystem::filesystem_error& e)
  {
    TM_FATAL_ERROR("tmtable::xml2menu: " << e.what());
  }

  if (message.empty())
  {
    tmxsd::tree2menu(data, menu, scale, extSignal);
    menu.isValid(true);
    scale.isValid(true);
    extSignal.isValid(true);
  }
  return message;
}


std::string
tmtable::xml2menu(std::istream& is,
                  tmtable::Menu& menu,
                  tmtable::Scale& scale,
                  tmtable::ExtSignal& extSignal,
                  const bool debug)
{
  char* xsd = getenv("UTM_XSD_DIR");
  if (NULL == xsd)
  {
    TM_FATAL_ERROR("tmtable::xml2menu: UTM_XSD_DIR environment variable not set.");
  }

  if (not boost::filesystem::exists(xsd))
  {
    TM_FATAL_ERROR("tmtable::xml2menu: UTM_XSD_DIR does not exist: " << xsd);
  }

  boost::filesystem::path cwd = boost::filesystem::current_path();

  // Change to XML file location UTM_XSD_DIR
  boost::filesystem::current_path(xsd);

  std::string message;
  tmxsd::menu data = tmxsd::xml2menu(is, message, debug);

  try
  {
    // Return to initial directory location.
    boost::filesystem::current_path(cwd);
  }
  catch (boost::filesystem::filesystem_error& e)
  {
    TM_FATAL_ERROR("tmtable::xml2menu: " << e.what());
  }


  if (message.empty())
  {
    tmxsd::tree2menu(data, menu, scale, extSignal);
    menu.isValid(true);
    scale.isValid(true);
    extSignal.isValid(true);
  }
  return message;
}


void
tmtable::menu2xml(const tmtable::Menu& data,
                  const tmtable::Scale& scale,
                  const tmtable::ExtSignal& extSignal,
                  const char* fileName)
{
  tmxsdtree::menu2xml(data, scale, extSignal, fileName);
}
/* eof */
