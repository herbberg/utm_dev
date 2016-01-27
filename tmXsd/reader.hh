/**
 * @author      Takashi Matsushita
 * Created:     19 Aug 2014
 */

/** @todo */

#ifndef tmxsd_reader_hh
#define tmxsd_reader_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
#include <iostream>

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


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 *  This class implements xml file reader
 */
  template<class T> class Reader
  {
    public:
      Reader()
        : boolean_p(), int_p(), unsigned_int_p(), string_p(),
          char64_p(), char1k_p(), char4k_p(), uuid_p(),
          real_p(), id_p(), datetime_p(),
          bin_p(), scale_p(), scale_set_p(), ext_signal_p(),
          ext_signal_set_p(), object_requirement_p(),
          external_requirement_p(), cut_p(), algorithm_p(),
          menu_p(), message_(""), success_(true), debug_(false) {}
      virtual ~Reader() {};

      /** reads xml file from the istream and returns instance of class T*/
      T read(std::istream& is);

      /** gets error message */
      std::string& message() { return message_; }

      /** checks if the read() operation was successful or not */
      bool success() { return success_; }

      /** set debug flag */
      void debug(bool x) { debug_ = x; }

    private:
      ::xml_schema::boolean_pimpl boolean_p;
      ::xml_schema::int_pimpl int_p;
      ::xml_schema::unsigned_int_pimpl unsigned_int_p;
      ::xml_schema::string_pimpl string_p;

      ::tmxsd::char64_pimpl char64_p;
      ::tmxsd::char1k_pimpl char1k_p;
      ::tmxsd::char4k_pimpl char4k_p;
      ::tmxsd::uuid_pimpl uuid_p;
      ::tmxsd::real_pimpl real_p;
      ::tmxsd::id_pimpl id_p;
      ::tmxsd::datetime_pimpl datetime_p;

      ::tmxsd::bin_pimpl bin_p;
      ::tmxsd::scale_pimpl scale_p;
      ::tmxsd::scale_set_pimpl scale_set_p;

      ::tmxsd::ext_signal_pimpl ext_signal_p;
      ::tmxsd::ext_signal_set_pimpl ext_signal_set_p;

      ::tmxsd::object_requirement_pimpl object_requirement_p;
      ::tmxsd::external_requirement_pimpl external_requirement_p;
      ::tmxsd::cut_pimpl cut_p;
      ::tmxsd::algorithm_pimpl algorithm_p;
      ::tmxsd::menu_pimpl menu_p;

      std::string message_;
      bool success_;
      bool debug_;
  };


/*-----------------------------------------------------------------*
 * template specialisation
 *-----------------------------------------------------------------*/
  template<> tmxsd::bin
  Reader<tmxsd::bin>::read(std::istream& is);

  template<> tmxsd::scale
  Reader<tmxsd::scale>::read(std::istream& is);

  template<> tmxsd::scale_set
  Reader<tmxsd::scale_set>::read(std::istream& is);
  template<> tmxsd::ext_signal Reader<tmxsd::ext_signal>::read(std::istream& is);
  template<> tmxsd::ext_signal_set
  Reader<tmxsd::ext_signal_set>::read(std::istream& is);

  template<> tmxsd::object_requirement
  Reader<tmxsd::object_requirement>::read(std::istream& is);

  template<> tmxsd::external_requirement
  Reader<tmxsd::external_requirement>::read(std::istream& is);

  template<> tmxsd::cut
  Reader<tmxsd::cut>::read(std::istream& is);

  template<> tmxsd::algorithm
  Reader<tmxsd::algorithm>::read(std::istream& is);

  template<> tmxsd::menu
  Reader<tmxsd::menu>::read(std::istream& is);

}
#endif // tmxsd_reader_hh
/* eof */
