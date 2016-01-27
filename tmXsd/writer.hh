/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo */

#ifndef tmxsd_writer_hh
#define tmxsd_writer_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <iostream>

#include "tmTable/tmTable.hh"



/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/*--------------------------------------------------------------------*
 * function
 *--------------------------------------------------------------------*/
/**
 *  wirtes xml file containing bin information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeBin(const tmtable::Row& row,
                std::ostream& os);

/**
 *  wirtes xml file containing scale information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeScale(const tmtable::Row& row,
                  std::ostream& os);

/**
 *  wirtes xml file containing scale_set information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeScaleSet(const tmtable::Row& row,
                     std::ostream& os);

/**
 *  wirtes xml file containing ext_signal information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeExtSignal(const tmtable::Row& row,
                      std::ostream& os);

/**
 *  wirtes xml file containing ext_signal_set information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeExtSignalSet(const tmtable::Row& row,
                         std::ostream& os);

/**
 *  wirtes xml file containing object/requirement information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeObjectRequirement(const tmtable::Row& row,
                              std::ostream& os);

/**
 *  wirtes xml file containing external/requirement information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeExternalRequirement(const tmtable::Row& row,
                                std::ostream& os);

/**
 *  wirtes xml file containing cut information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeCut(const tmtable::Row& row,
                std::ostream& os);

/**
 *  wirtes xml file containing algorithm information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeAlgorithm(const tmtable::Row& row,
                      std::ostream& os);

/**
 *  wirtes xml file containing menu information
 *
 *  @param row [in] input data
 *  @param os [in/out] ostream to write the results
 *  @return true if success, false otherwise
 */
  bool writeMenu(const tmtable::Row& row,
                 std::ostream& os);
}
#endif // tmxsd_writer_hh
/* eof */
