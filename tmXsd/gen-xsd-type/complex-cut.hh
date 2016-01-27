/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo nope */

#ifndef complex_cut_hh
#define complex_cut_hh

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
 * This struct implements data structure for cut complex type
 */
  struct cut
  {
    /** constructor */
    cut() :
      name_(), object_(), type_(), minimum_(), maximum_(), data_(),
      comment_(), cut_id_(), datetime_(), debug_()
      { if (debug_) std::cout << "cut::ctor" << std::endl; }

    /** destructor */
    virtual ~cut()
      { if (debug_) std::cout << "cut::dtor" << std::endl; }

    // setters and getters
    const std::string& name() const { return name_; }
    void name(const std::string& x) { name_ = x; }

    const std::string& object() const { return object_; }
    void object(const std::string& x) { object_ = x; }

    const std::string& type() const { return type_; }
    void type(const std::string& x) { type_ = x; }

    const std::string& minimum() const { return minimum_; }
    void minimum(const std::string& x) { minimum_ = x; }

    const std::string& maximum() const { return maximum_; }
    void maximum(const std::string& x) { maximum_ = x; }

    const std::string& data() const { return data_; }
    void data(const std::string& x) { data_ = x; }

    const std::string& comment() const { return comment_; }
    void comment(const std::string& x) { comment_ = x; }

    unsigned int cut_id() const { return cut_id_; }
    void cut_id(const unsigned int x) { cut_id_ = x; }

    const std::string& datetime() const { return datetime_; }
    void datetime(const std::string& x) { datetime_ = x; }

    bool debug() const { return debug_; }
    void debug(const bool x) { debug_ = x; }

    private:
      std::string name_;      /**< cut name */
      std::string object_;    /**< object name */
      std::string type_;      /**< cut type */
      std::string minimum_;   /**< minimum for range type */
      std::string maximum_;   /**< maximum for range type */
      std::string data_;      /**< cut data for other type */
      std::string comment_;   /**< comment */
      unsigned int cut_id_;   /**< cut_id in DB */
      std::string datetime_;  /**< datetime in DB */
      bool debug_;            /**< debug flag */

  };  // struct cut

} // namespace tmxsd

#endif // complex_cut_hh
/* eof */
