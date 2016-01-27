/*====================================================================*
 * declarations  
 *====================================================================*/
/*--------------------------------------------------------------------*
 * headers
 *--------------------------------------------------------------------*/
#include <sstream>

#include "tmXsd/gen-xsd-type/simple-types-parser.hh"
#include "tmXsd/gen-xsd-type/complex-bin-parser.hh"
#include "tmXsd/gen-xsd-type/complex-scale-parser.hh"
#include "tmXsd/gen-xsd-type/complex-scale_set-parser.hh"
#include "tmXsd/gen-xsd-type/complex-ext_signal-parser.hh"
#include "tmXsd/gen-xsd-type/complex-ext_signal_set-parser.hh"
#include "tmXsd/gen-xsd-type/complex-object_requirement-parser.hh"
#include "tmXsd/gen-xsd-type/complex-external_requirement-parser.hh"
#include "tmXsd/gen-xsd-type/complex-cut-parser.hh"
#include "tmXsd/gen-xsd-type/complex-algorithm-parser.hh"
#include "tmXsd/gen-xsd-type/complex-menu-parser.hh"

#include "tmXsd/reader.hh"


/*====================================================================*
 * implementation
 *====================================================================*/
namespace tmxsd
{
  /** Reader for tmxsd::bin */
  template<> tmxsd::bin Reader<tmxsd::bin>::read(std::istream& is)
  {
    bin_p.parsers(unsigned_int_p, real_p, real_p, id_p, id_p);
    bin_p.debug(debug_);

    ::xml_schema::document doc_p(
        bin_p, "http://www.cern.ch/tmxsd/1.0.0", "bin");

    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return bin_p.post_bin();
  }


  /** Reader for tmxsd::scale */
  template<> tmxsd::scale Reader<tmxsd::scale>::read(std::istream& is)
  {
    bin_p.parsers(unsigned_int_p, real_p, real_p, id_p, id_p);
    bin_p.debug(debug_);

    scale_p.parsers(
        char64_p, char64_p, real_p, real_p, real_p, unsigned_int_p, char4k_p,
        bin_p, id_p, datetime_p, unsigned_int_p); 
    scale_p.debug(debug_);

    ::xml_schema::document doc_p(
        scale_p, "http://www.cern.ch/tmxsd/1.0.0", "scale");

    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = "parser error: " + ss.str();
      success_ = false;
    }
    return scale_p.post_scale();
  }


  /** Reader for tmxsd::scale_set */
  template<> tmxsd::scale_set Reader<tmxsd::scale_set>::read(std::istream& is)
  {
    bin_p.parsers(
        unsigned_int_p, real_p, real_p, id_p, id_p);
    bin_p.debug(debug_);

    scale_p.parsers(
        char64_p, char64_p, real_p, real_p, real_p, unsigned_int_p, char4k_p,
        bin_p, id_p, datetime_p, unsigned_int_p); 
    scale_p.debug(debug_);

    scale_set_p.parsers(
        char1k_p, char4k_p, scale_p, id_p, datetime_p, boolean_p);
    scale_set_p.debug(debug_);

    ::xml_schema::document doc_p(
        scale_set_p, "http://www.cern.ch/tmxsd/1.0.0", "scale_set");

    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return scale_set_p.post_scale_set();
  }


  /** Reader for tmxsd::ext_signal */
  template<> tmxsd::ext_signal Reader<tmxsd::ext_signal>::read(std::istream& is)
  {
    ext_signal_p.parsers(
        char1k_p, char1k_p, unsigned_int_p, unsigned_int_p, char4k_p,
        char1k_p, id_p, datetime_p);
    ext_signal_p.debug(debug_);

    ::xml_schema::document doc_p(
      ext_signal_p, "http://www.cern.ch/tmxsd/1.0.0", "ext_signal");

    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return ext_signal_p.post_ext_signal();
  }


  /** Reader for tmxsd::ext_signal_set */
  template<> tmxsd::ext_signal_set Reader<tmxsd::ext_signal_set>::read(std::istream& is)
  {
    ext_signal_p.parsers(
        char1k_p, char1k_p, unsigned_int_p, unsigned_int_p, char4k_p,
        char1k_p, id_p, datetime_p);
    ext_signal_p.debug(debug_);

    ext_signal_set_p.parsers(
        char1k_p, char4k_p, ext_signal_p, id_p, datetime_p, boolean_p);
    ext_signal_set_p.debug(debug_);

    ::xml_schema::document doc_p(
      ext_signal_set_p, "http://www.cern.ch/tmxsd/1.0.0", "ext_signal_set");

    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return ext_signal_set_p.post_ext_signal_set();
  }


  /** Reader for tmxsd::object_requirement */
  template<> tmxsd::object_requirement Reader<tmxsd::object_requirement>::read(std::istream& is)
  {
    object_requirement_p.parsers(
        char1k_p, char64_p, char64_p, real_p, int_p, char4k_p,
        id_p, datetime_p);
    object_requirement_p.debug(debug_);

    ::xml_schema::document doc_p(
      object_requirement_p,
      "http://www.cern.ch/tmxsd/1.0.0", "object_requirement");


    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return object_requirement_p.post_object_requirement();
  }


  /** Reader for tmxsd::external_requirement */
  template<> tmxsd::external_requirement Reader<tmxsd::external_requirement>::read(std::istream& is)
  {
    external_requirement_p.parsers(
        char1k_p, int_p, char4k_p, id_p, id_p, datetime_p);
    external_requirement_p.debug(debug_);

    ::xml_schema::document doc_p(
      external_requirement_p,
      "http://www.cern.ch/tmxsd/1.0.0", "external_requirement");


    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return external_requirement_p.post_external_requirement();
  }


  /** Reader for tmxsd::cut */
  template<> tmxsd::cut Reader<tmxsd::cut>::read(std::istream& is)
  {
    cut_p.parsers(
        char1k_p, char64_p, char64_p, real_p, real_p, char4k_p, char4k_p, id_p, datetime_p);
    cut_p.debug(debug_);

    ::xml_schema::document doc_p(
      cut_p, "http://www.cern.ch/tmxsd/1.0.0", "cut");


    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return cut_p.post_cut();
  }


  /** Reader for tmxsd::algorithm */
  template<> tmxsd::algorithm Reader<tmxsd::algorithm>::read(std::istream& is)
  {
    cut_p.parsers(
        char1k_p, char64_p, char64_p, real_p, real_p, char4k_p, char4k_p, id_p, datetime_p);
    cut_p.debug(debug_);

    object_requirement_p.parsers(
        char1k_p, char64_p, char64_p, real_p, int_p, char4k_p,
        id_p, datetime_p);
    object_requirement_p.debug(debug_);

    external_requirement_p.parsers(
        char1k_p, int_p, char4k_p, id_p, id_p, datetime_p);
    external_requirement_p.debug(debug_);

    algorithm_p.parsers(
        char1k_p, char4k_p, unsigned_int_p, unsigned_int_p, unsigned_int_p,
        char4k_p, cut_p, object_requirement_p, external_requirement_p,
        id_p, datetime_p);
    algorithm_p.debug(debug_);

    ::xml_schema::document doc_p(
      algorithm_p, "http://www.cern.ch/tmxsd/1.0.0", "algorithm");


    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return algorithm_p.post_algorithm();
  }


  /** Reader for tmxsd::menu */
  template<> tmxsd::menu Reader<tmxsd::menu>::read(std::istream& is)
  {
    // scale_set
    bin_p.parsers(
        unsigned_int_p, real_p, real_p, id_p, id_p);
    bin_p.debug(debug_);

    scale_p.parsers(
        char64_p, char64_p, real_p, real_p, real_p, unsigned_int_p, char4k_p,
        bin_p, id_p, datetime_p, unsigned_int_p); 
    scale_p.debug(debug_);

    scale_set_p.parsers(
        char1k_p, char4k_p, scale_p, id_p, datetime_p, boolean_p);
    scale_set_p.debug(debug_);


    // ext_signal_set
    ext_signal_p.parsers(
        char1k_p, char1k_p, unsigned_int_p, unsigned_int_p, char4k_p,
        char1k_p, id_p, datetime_p);
    ext_signal_p.debug(debug_);

    ext_signal_set_p.parsers(
        char1k_p, char4k_p, ext_signal_p, id_p, datetime_p, boolean_p);
    ext_signal_set_p.debug(debug_);


    // menu
    cut_p.parsers(
        char1k_p, char64_p, char64_p, real_p, real_p, char4k_p, char4k_p, id_p, datetime_p);
    cut_p.debug(debug_);

    object_requirement_p.parsers(
        char1k_p, char64_p, char64_p, real_p, int_p, char4k_p,
        id_p, datetime_p);
    object_requirement_p.debug(debug_);

    external_requirement_p.parsers(
        char1k_p, int_p, char4k_p, id_p, id_p, datetime_p);
    external_requirement_p.debug(debug_);

    algorithm_p.parsers(
        char1k_p, char4k_p, unsigned_int_p, unsigned_int_p, unsigned_int_p,
        char4k_p, cut_p, object_requirement_p, external_requirement_p,
        id_p, datetime_p);
    algorithm_p.debug(debug_);

    menu_p.parsers(
        id_p, char1k_p, uuid_p, uuid_p, char1k_p, char64_p, unsigned_int_p,
        boolean_p, boolean_p, char4k_p, algorithm_p, scale_set_p,
        ext_signal_set_p, id_p, datetime_p);
    menu_p.debug(debug_);

    ::xml_schema::document doc_p(
      menu_p, "http://www.cern.ch/tmxsd/1.0.0", "menu");


    try
    {
      doc_p.parse(is);
    }
    catch (const ::xml_schema::exception& e)
    {
      std::stringstream ss;
      ss << e;
      message_ = ss.str();
      success_ = false;
    }
    return menu_p.post_menu();
  }
} // namespace tmxsd
/* eof */
