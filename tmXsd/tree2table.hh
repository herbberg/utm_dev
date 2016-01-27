/**
 * @author      Takashi Matsushita
 * Created:     13 Aug 2014
 */

/** @todo */

#ifndef tmxsd_tree2table_hh
#define tmxsd_tree2table_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>

#include "tmTable/tmTable.hh"
#include "tmXsd/gen-xsd-type/complex-scale_set.hh"
#include "tmXsd/gen-xsd-type/complex-ext_signal_set.hh"
#include "tmXsd/gen-xsd-type/complex-menu.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
namespace tmxsd
{
/**
 *  convert xml data structure to internal data structure
 *
 *  @param scale_set [in] scale_set class
 *  @param scale [in/out] internal data structure
 */
void tree2scale(const tmxsd::scale_set& scale_set,
                tmtable::Scale& scale);

/**
 *  read xml file and store contents to xml data class
 *
 *  @param fileName [in] xml file name
 *  @param message [in/out] error message
 *  @param debug [in] debug flag
 *  @return scale_set class
 */
tmxsd::scale_set xml2scale_set(const char* fileName,
                               std::string& message,
                               const bool debug = false);

/**
 *  convert xml data structure to internal data structure
 *
 *  @param ext_signal_set [in] ext_signal_set class
 *  @param extSignal [in/out] internal data structure
 */
void tree2extSignal(const tmxsd::ext_signal_set& ext_signal_set,
                    tmtable::ExtSignal& extSignal);

/**
 *  read xml file and store contents to xml data class
 *
 *  @param fileName [in] xml file name
 *  @param message [in/out] error message
 *  @param debug [in] debug flag
 *  @return ext_signal_set class
 */
tmxsd::ext_signal_set xml2ext_signal_set(const char* fileName,
                                         std::string& message,
                                         const bool debug = false);

/**
 *  convert xml data structure to internal data structure
 *
 *  @param data [in] menu class
 *  @param menu [in/out] internal data structure
 *  @param scale [in/out] internal data structure
 *  @param extSignal [in/out] internal data structure
 */
void tree2menu(const tmxsd::menu& data,
               tmtable::Menu& menu,
               tmtable::Scale& scale,
               tmtable::ExtSignal& extSignal);

/**
 *  read xml file and store contents to xml data class
 *
 *  @param fileName [in] xml file name
 *  @param message [in/out] error message
 *  @param debug [in] debug flag
 *  @return menu class
 */
tmxsd::menu xml2menu(const char* fileName,
                     std::string& message,
                     const bool debug = false);

}
#endif
/* eof */
