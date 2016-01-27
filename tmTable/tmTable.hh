/**
 * @author      Takashi Matsushita
 * Created:     13 Aug 2014
 */

/** @todo nope */

#ifndef tmtable_tmTable_hh
#define tmtable_tmTable_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <map>
#include <string>
#include <vector>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmtable
{

typedef std::map<std::string, std::string> Row;
typedef std::vector<Row> Table;
typedef std::map<std::string, Table> StringTableMap;


/**
 *  This class implements data structure for Scale DB block
 */
class Scale
{
  public:
    Scale() : scaleSet(), scales(), bins(), isValid_(false) { };

    Row scaleSet;
    Table scales;
    StringTableMap bins;

    std::string getKeyForBin(const Row& scale);
    bool isValid() { return isValid_; }
    void isValid(bool x) { isValid_ = x; }

  private:
    bool isValid_;
};


/**
 *  This class implements data structure for External Signal DB block
 */
class ExtSignal
{
  public:
    ExtSignal() : extSignalSet(), extSignals(), isValid_(false) { };

    Row extSignalSet;
    Table extSignals;

    bool isValid() { return isValid_; }
    void isValid(bool x) { isValid_ = x; }

  private:
    bool isValid_;
};


/**
 *  This class implements data structure for Menu DB block
 */
class Menu
{
  public:
    Menu() : menu(), algorithms(), objects(), externals(), cuts(),
             isValid_(false) { };

    Row menu;
    Table algorithms;
    StringTableMap objects;
    StringTableMap externals;
    StringTableMap cuts;

    bool isValid() { return isValid_; }
    void isValid(bool x) { isValid_ = x; }

  private:
    bool isValid_;
};


/** read an xml file containing scale information
 *
 * @param fileName [in] path of xmf file
 * @param scale [in/out] data structure to hold the content of the given file
 * @param debug [in] debug flag
 */
std::string xml2scale(const char* fileName,
                      tmtable::Scale& scale,
                      const bool debug = false);


/** read an xml file containing external signal information
 *
 * @param fileName [in] path of xmf file
 * @param extSignal [in/out] data structure to hold the content of the given file
 * @param debug [in] debug flag
 */
std::string xml2extSignal(const char* fileName,
                          tmtable::ExtSignal& extSignal,
                          const bool debug = false);

/** read an xml file containing menu information
 *
 * @param fileName [in] path of xmf file
 * @param menu [in/out] data structure to hold the content of the given file
 * @param scale [in/out] data structure to hold the content of the given file
 * @param extSignal [in/out] data structure to hold the content of the given file
 * @param debug [in] debug flag
 */
std::string xml2menu(const char* fileName,
                     tmtable::Menu& menu,
                     tmtable::Scale& scale,
                     tmtable::ExtSignal& extSignal,
                     const bool debug = false);


/** write an xml menu file from the internal data structure
 *
 * @param data [in] Menu internal data structure
 * @param scale [in] Scale internal data structure
 * @param extSignal [in] ExtSignal internal data structure
 * @param fileName [in] output file name
 */
void menu2xml(const tmtable::Menu& data,
              const tmtable::Scale& scale,
              const tmtable::ExtSignal& extSignal,
              const char* fileName);

} // namespace tmtable

#endif // tmtable_tmTable_hh
/* eof */
