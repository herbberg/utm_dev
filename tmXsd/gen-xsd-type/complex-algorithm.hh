/**
 * @author      Takashi Matsushita
 * Created:     14 Sep 2014
 */

/** @todo nope */

#ifndef complex_algorithm_hh
#define complex_algorithm_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>

#include "tmXsd/gen-xsd-type/complex-cut.hh"
#include "tmXsd/gen-xsd-type/complex-object_requirement.hh"
#include "tmXsd/gen-xsd-type/complex-external_requirement.hh"

/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for algorithm complex type
 */
  struct algorithm
  {
    /** constructor */
    algorithm() :
      name_(), expression_(), index_(), module_id_(), module_index_(),
      comment_(), cut_(), object_requirement_(), external_requirement_(),
      algorithm_id_(), datetime_(), debug_()
      { if (debug_) std::cout << "algorithm::ctor" << std::endl; }

    /** destructor */
    virtual ~algorithm()
      { if (debug_) std::cout << "algorithm::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& expression() const { return expression_; }
    void expression(const std::string& x) { expression_ = x; }

    unsigned int index() const { return index_; }
    void index(const unsigned int x) { index_ = x; }

    unsigned int module_id() const { return module_id_; }
    void module_id(const unsigned int x) { module_id_ = x; }

    unsigned int module_index() const { return module_index_; }
    void module_index(const unsigned int x) { module_index_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    typedef std::vector<tmxsd::cut> cuts;
    const cuts& cut() const { return cut_; }
    cuts& cut() { return cut_; }

    typedef std::vector<tmxsd::object_requirement> object_requirements;
    const object_requirements& object_requirement() const { return object_requirement_; }
    object_requirements& object_requirement() { return object_requirement_; }

    typedef std::vector<tmxsd::external_requirement> external_requirements;
    const external_requirements& external_requirement() const { return external_requirement_; }
    external_requirements& external_requirement() { return external_requirement_; }

    unsigned int algorithm_id() const { return algorithm_id_; }
    void algorithm_id(const unsigned int x) { algorithm_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string name_;            /**< name */
      std::string expression_;      /**< expression */
      unsigned int index_;          /**< index */
      unsigned int module_id_;      /**< module id */
      unsigned int module_index_;   /**< module index */
      std::string comment_;         /**< comment */
      cuts cut_;                    /**< cut array */
      object_requirements object_requirement_;      /**< object_requirement array */
      external_requirements external_requirement_;  /**< external_requirement array */
      unsigned int algorithm_id_;   /**< algorithm_id in DB */
      std::string datetime_;        /**< datetime in DB */
      bool debug_;                  /**< debug flag */

  }; // struct algorithm

} // namespace tmxsd

#endif // complex_algorithm_hh
/* eof */
