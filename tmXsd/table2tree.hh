/**
 * @author      Takashi Matsushita
 * Created:     18 Aug 2014
 */

/** @todo */

#ifndef tmxsd_table2tree_hh
#define tmxsd_table2tree_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
/* nope */

namespace tmxsdtree
{
  class scale_set;
  class ext_signal_set;
  class menu;
}

namespace tmtable
{
  class Scale;
  class ExtSignal;
  class Menu;
}


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
namespace tmxsdtree
{
/**
 *  convert internal data structure to xml data structure
 *
 *  @param scale [in] internal data structure
 *  @param scale_set [in/out] xml data class
 *  @param attribute [in] flag for writing attributes
 */
void scale2tree(const tmtable::Scale& scale,
                tmxsdtree::scale_set& scale_set,
                const bool attribute=false);


/**
 *  write internal data structure information to xml file
 *
 *  @param scale [in] internal data structure
 *  @param fileName [in] xml file name
 *  @param attribute [in] flag for writing attributes
 */
void scale2xml(const tmtable::Scale& scale,
               const char* fileName,
               const bool attribute=false);


/**
 *  convert internal data structure to xml data structure
 *
 *  @param extSignal [in] internal data structure
 *  @param ext_signal_set [in/out] xml data class
 *  @param attribute [in] flag for writing attributes
 */
void extSignal2tree(const tmtable::ExtSignal& extSignal,
                    tmxsdtree::ext_signal_set& ext_signal_set,
                    const bool attribute=false);


/**
 *  write internal data structure information to xml file
 *
 *  @param extSignal [in] internal data structure
 *  @param fileName [in] xml file name
 *  @param attribute [in] flag for writing attributes
 */
void extSignal2xml(const tmtable::ExtSignal& extSignal,
                   const char* fileName,
                   const bool attribute=false);


/**
 *  convert internal data structure to xml data structure
 *
 *  @param data [in] internal data structure
 *  @param scale [in] internal data structure
 *  @param extSignal [in] internal data structure
 *  @param menu [in/out] xml data class
 *  @param attribute [in] flag for writing attributes
 */
void menu2tree(const tmtable::Menu& data,
               const tmtable::Scale& scale,
               const tmtable::ExtSignal& extSignal,
               tmxsdtree::menu& menu,
               const bool attribute=false);


/**
 *  write internal data structure information to xml file
 *
 *  @param data [in] internal data structure
 *  @param scale [in] internal data structure
 *  @param extSignal [in] internal data structure
 *  @param fileName [in] xml file name
 *  @param attribute [in] flag for writing attributes
 */
void menu2xml(const tmtable::Menu& data,
              const tmtable::Scale& scale,
              const tmtable::ExtSignal& extSignal,
              const char* fileName,
              const bool attribute=false);

}
#endif // tmxsd_table2tree_hh
/* eof */
