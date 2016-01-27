/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo none */

#ifndef validator_hh
#define validator_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmTable/tmTable.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmtable
{
/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
/**
 * check the validity of the bin data
 *
 * @param row [in] bin data
 * @return true if the data is valid, false otherwise
 */
  bool isBin(const tmtable::Row& row);

/**
 * check the validity of the scale data
 *
 * @param row [in] scale data
 * @return true if the data is valid, false otherwise
 */
  bool isScale(const tmtable::Row& row);

/**
 * check the validity of the scale set data
 *
 * @param row [in] scale set data
 * @return true if the data is valid, false otherwise
 */
  bool isScaleSet(const tmtable::Row& row);

/**
 * check the validity of the external signal data
 *
 * @param row [in] external signal data
 * @return true if the data is valid, false otherwise
 */
  bool isExtSignal(const tmtable::Row& row);

/**
 * check the validity of the external signal set data
 *
 * @param row [in] external signal set data
 * @return true if the data is valid, false otherwise
 */
  bool isExtSignalSet(const tmtable::Row& row);

/**
 * check the validity of the cut data
 *
 * @param row [in] cut data
 * @return true if the data is valid, false otherwise
 */
  bool isCut(const tmtable::Row& row);

/**
 * check the validity of the object_requirement data
 *
 * @param row [in] object_requirement data
 * @return true if the data is valid, false otherwise
 */
  bool isObjectRequirement(const tmtable::Row& row);

/**
 * check the validity of the external_requirement data
 *
 * @param row [in] external_requirement data
 * @return true if the data is valid, false otherwise
 */
  bool isExternalRequirement(const tmtable::Row& row);

/**
 * check the validity of the algorithm data
 *
 * @param row [in] algorithm data
 * @return true if the data is valid, false otherwise
 */
  bool isAlgorithm(const tmtable::Row& row);

/**
 * check the validity of the menu data
 *
 * @param row [in] menu data
 * @return true if the data is valid, false otherwise
 */
  bool isMenu(const tmtable::Row& row);

} // namespace tmtable
#endif
