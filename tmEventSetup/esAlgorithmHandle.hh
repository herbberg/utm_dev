/**
 * @author      Takashi Matsushita
 * Created:     13 Nov 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esAlgorithmHandle_hh
#define tmEventSetup_esAlgorithmHandle_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include "tmEventSetup/esAlgorithm.hh"


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Algorithm
 */
class esAlgorithmHandle : public esAlgorithm
{
  public:
    // ctor
    esAlgorithmHandle() { };

    // dtor
    virtual ~esAlgorithmHandle() { };

    /** print the contents of instance */
    void print() const;
    static void print(const esAlgorithm&);

    /** initialise the instance
     *
     * @param algorithm [in] tmtable::Row instance of algorithm
     */
    void init(const tmtable::Row& algorithm);

    /** set expression_in_condition_ from the token to condition name map
     * @param map [in]  look-up table: <key, value> = <token, condition name>
     */
    void setExpressionInCondition(const std::map<std::string, std::string>& map);

  private:
    void replace(const std::string& from,
                 const std::string& to);
};

} // namespace tmeventsetup
#endif // tmEventSetup_esAlgorithmHandle_hh
/* eof */
