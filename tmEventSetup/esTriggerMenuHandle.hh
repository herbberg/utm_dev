/**
 * @author      Takashi Matsushita
 * Created:     14 Nov 2015
 */

/** @file */
/** @todo nope */

#ifndef tmEventSetup_esTriggerMenuHandle_hh
#define tmEventSetup_esTriggerMenuHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmTable/tmTable.hh"
#include "tmGrammar/Function.hh"
#include "tmEventSetup/esCutValue.hh"
#include "tmEventSetup/esTriggerMenu.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{
/**
 *  This class implements data structure for TriggerMenu
 */
class esTriggerMenuHandle : public esTriggerMenu
{
  public:
    static const std::string TupleName[]; /**< list of tuple name to be used for condition name */

    // ctor
    esTriggerMenuHandle() { };

    // dtor
    virtual ~esTriggerMenuHandle() { };

    /** parse algorithm expression
     *
     * @param algorithm [in] algorithm expression
     * @return copy of tokens in algorithm expression
     */
    std::vector<std::string> parse(const std::string& algorithm);

    /** print the contents of instance */
    void print() const;

    /** set HW index for instances of esCutValue
     *
     * @param bins [in] list of bins for scales (Scale.bins)
     */
    void setHwIndex(const tmtable::StringTableMap& bins);

    /** set values in algorithm_map_
     *
     * @param algorithm [in] tmtable::Row instance of algorithm
     */
    void setAlgorithmMap(const tmtable::Row& algorithm);

    /** set values in condition_map_
     *
     * @param token [in] token of algorithm expression
     * @param cuts_in_algo [in] list of cuts used in the given algorithm
     */
    void setConditionMap(const std::string& token,
                         const tmtable::Table& cuts_in_algo);

    /** set values in scale_map_
     *
     * @param cuts_in_algo [in] list of cuts used in the given algorithm
     */
    void setScaleMap(const tmtable::Scale& scale);

    /** set values in external_map_
     *
     * @param map [in] external signal mapping
     */
    void setExternalMap(const tmtable::ExtSignal& map);

  private:
    /** get object condition
     *
     * @param token [in] token of algorithm expression in grammar
     * @param cuts_in_algo [in] list of cuts used in algorithm
     */
    esCondition getObjectCondition(const std::string& token,
                                   const tmtable::Table& cuts_in_algo);
    /** get function condition
     *
     * @param token [in] token of algorithm expression in grammar
     * @param cuts_in_algo [in] list of cuts used in algorithm
     */
    esCondition getFunctionCondition(const std::string& token,
                                     const tmtable::Table& cuts_in_algo);
    /** get multi-object condition
     *
     * @param token [in] token of algorithm expression in grammar
     * @param cuts_in_algo [in] list of cuts used in algorithm
     */
    esCondition getCombCondition(const Function::Item& item,
                                 const tmtable::Table& cuts_in_algo);

    /** get distance (correlation) condition
     *
     * @param token [in] token of algorithm expression in grammar
     * @param cuts_in_algo [in] list of cuts used in algorithm
     */
    esCondition getDistCondition(const Function::Item& item,
                                 const tmtable::Table& cuts_in_algo);

    /** get invariant mass condition
     *
     * @param token [in] token of algorithm expression in grammar
     * @param cuts_in_algo [in] list of cuts used in algorithm
     */
    esCondition getMassCondition(const Function::Item& item,
                                 const tmtable::Table& cuts_in_algo);

    /** get name of object
     *
     * @param type [in] type of object
     * @return character array representing object name
     */
    const char* getObjectName(const int type);

    /** get name of condition
     *
     * @param type [in] type of condition
     * @return character array representing object name
     */
    const char* getConditionName(const int type);

    /** get HW index of a bin
     *
     * @param cut [in] esCutValue with value set
     * @param range [in] "minimum" or "maximum"
     * @param bins [in] tmtable::Table instance for scale
     * @return HW index of a bin
     */
    unsigned int getIndex(const esCutValue& cut, const std::string& range, const tmtable::Table& bins);
};

} // namespace tmeventsetup
#endif // tmEventSetup_esTriggerMenuHandle_hh
/* eof */
