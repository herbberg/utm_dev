/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_object_requirement_hh
#define complex_object_requirement_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <string>
#include <vector>
#include <iostream>


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 * This struct implements data structure for object_requirement complex type
 */
  struct object_requirement
  {
    /** constructor */
    object_requirement() :
      name_(), type_(), comparison_operator_(), threshold_(), bx_offset_(),
      comment_(), requirement_id_(), datetime_(), debug_()
      { if (debug_) std::cout << "object_requirement::ctor" << std::endl; }

    /** destructor */
    virtual ~object_requirement()
      { if (debug_) std::cout << "object_requirement::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& type() const { return type_; }
    void type(const std::string& x) { type_ = x; }

    const std::string& comparison_operator() const { return comparison_operator_; }
    void comparison_operator(const std::string& x) { comparison_operator_ = x; }

    const std::string& threshold() const { return threshold_; }
    void threshold(const std::string& x) { threshold_ = x; }

    int bx_offset() const { return bx_offset_; }
    void bx_offset(const int x) { bx_offset_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    unsigned int requirement_id() const { return requirement_id_; }
    void requirement_id(const unsigned int x) { requirement_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string name_;                /**< name */
      std::string type_;                /**< object type */
      std::string comparison_operator_; /**< comparison operator used for threshold cut */
      std::string threshold_;           /**< pt/Et threshold */
      int bx_offset_;                   /**< bunch crossing offset */
      std::string comment_;             /**< comment */
      unsigned int requirement_id_;     /**< requirement id in DB */
      std::string datetime_;            /**< datetime in DB */
      bool debug_;                      /**< debug flag */

  }; // struct object_requirement

} // namespace tmxsd

#endif // complex_object_requirement_hh
/* eof */
