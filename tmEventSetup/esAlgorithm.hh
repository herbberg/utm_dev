/**
 * @author      Takashi Matsushita
 * Created:     12 Mar 2015
 */

/** @todo nope */

#ifndef tmEventSetup_esAlgorithm_hh
#define tmEventSetup_esAlgorithm_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{

/**
 *  This class implements data structure for Algorithm
 */
class esAlgorithm
{
  public:
    // ctor
    esAlgorithm()
      : name_(), expression_(), expression_in_condition_(), rpn_vector_(),
        index_(), module_id_(), module_index_() { };

    // dtor
    virtual ~esAlgorithm() { };

    /** set rpn_vector_ */
    void setRpnVector(const std::vector<std::string>& x) { rpn_vector_ = x; };

    /** get algorithm name */
    const std::string& getName() const { return name_; };

    /** get algorithm expression in grammar */
    const std::string& getExpression() const { return expression_; };

    /** get algorithm expression in condition */
    const std::string& getExpressionInCondition() const { return expression_in_condition_; };

    /** get reverse polish notion of algorithm expression in condition */
    const std::vector<std::string>& getRpnVector() const { return rpn_vector_; };

    /** get algorithm index */
    unsigned int getIndex() const { return index_; };

    /** get module id */
    unsigned int getModuleId() const { return module_id_; };

    /** get module index */
    unsigned int getModuleIndex() const { return module_index_; };

  protected:
    std::string name_;                    /**< name of algorithm */
    std::string expression_;              /**< algorithm expression in grammar */
    std::string expression_in_condition_; /**< algorithm expression in condition */
    std::vector<std::string> rpn_vector_; /**< reverse polish notation of algorithm expression in condition */
    unsigned int index_;                  /**< index of algorithm (global) */
    unsigned int module_id_;              /**< module id */
    unsigned int module_index_;           /**< index of algorithm in module (local to module id) */
    unsigned int version;
};

} // namespace tmeventsetup
#endif // tmEventSetup_esAlgorithm_hh
/* eof */
