/*====================================================================*
 * declarations
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstddef>
#include <cerrno>
#include <string.h>

#include "tmUtil/tmUtil.hh"
#include "tmTable/tmTable.hh"
#include "tmXsd/keywords.hh"
#include "tmXsd/tree2table.hh"
#include "tmXsd/table2tree.hh"


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
  std::string key = object + "-" + type;
  return key;
}


/*--------------------------------------------------------------------*
 * functions
 *--------------------------------------------------------------------*/
std::string
tmtable::xml2scale(const char* fileName,
                   tmtable::Scale& scale,
                   const bool debug)
{
  char fullpath[PATH_MAX];
  if (realpath(fileName, fullpath) == NULL)
  {
    TM_FATAL_ERROR("tmtable::xml2scale: " << tmutil::getcwd() << " " << fileName);
  }

  std::string message;
  tmxsd::scale_set scale_set = tmxsd::xml2scale_set(fullpath, message, debug);
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
  char fullpath[PATH_MAX];
  if (realpath(fileName, fullpath) == NULL)
  {
    TM_FATAL_ERROR("tmtable::xml2extSignal: " << tmutil::getcwd() << " " << fileName);
  }

  std::string message;
  tmxsd::ext_signal_set ext_signal_set = tmxsd::xml2ext_signal_set(fullpath, message, debug);
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
  char fullpath[PATH_MAX];
  if (realpath(fileName, fullpath) == NULL)
  {
    TM_FATAL_ERROR("tmtable::xml2menu: " << tmutil::getcwd() << " " << fileName);
  }

  std::string cwd = tmutil::getcwd();
  std::string message;

  tmxsd::menu data = tmxsd::xml2menu(fullpath, message, debug);
  if (message.size())
  {
    tmutil::chdir(fullpath);
    data = tmxsd::xml2menu(fullpath, message, debug);

    if (message.size())
    {
      char* xsd = getenv("UTM_XSD_DIR");
      if (xsd)
      {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)-1) == NULL)
        {
          TM_FATAL_ERROR("tmtable::xml2menu: getcwd: " << strerror(errno));
        }

        if (::chdir(xsd) == -1)
        {
          TM_FATAL_ERROR("tmtable::xml2menu: chdir: " << strerror(errno));
        }

        data = tmxsd::xml2menu(fullpath, message, debug);
        if (::chdir(cwd) == -1)
        {
          TM_FATAL_ERROR("tmtable::xml2menu: chdir: " << strerror(errno));
        }
      }
    }
  }

  tmutil::chdir(cwd);

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
