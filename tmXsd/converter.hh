/**
 * @author      Takashi Matsushita
 * Created:     26 Feb 2015
 */

/** @todo */

#ifndef tmxsd_converter_hh
#define tmxsd_converter_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/

#include "tmTable/tmTable.hh"


namespace tmxsdtree
{
  class bin;
  class scale;
  class scale_set;
  class ext_signal;
  class ext_signal_set;
  class object_requirement;
  class external_requirement;
  class cut;
  class algorithm;
  class menu;
}


/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
/* nope */


namespace tmxsd
{
/**
 *  This class implements converter from a table row to an xml data structure
 */
  template<class T> class Converter
  {
    public:
      Converter() : success_(true), attribute_(false) {}
      virtual ~Converter() {};

      /** convert a row to xml data structure of type T */
      T convert(const tmtable::Row& row);

      /* checks if the convert() operation was successful or not */
      bool success() { return success_; }

      /* get a toggle for converting optional attributes */
      bool attribute() { return attribute_; }

      /* set a toggle for converting optional attributes */
      void attribute(const bool attribute) { attribute_ = attribute; }


    private:
      bool success_;
      bool attribute_;
  };


/*-----------------------------------------------------------------*
 * template specialisation
 *-----------------------------------------------------------------*/
  template<> tmxsdtree::bin
  Converter<tmxsdtree::bin>::convert(const tmtable::Row& row);

  template<> tmxsdtree::scale
  Converter<tmxsdtree::scale>::convert(const tmtable::Row& row);

  template<> tmxsdtree::scale_set
  Converter<tmxsdtree::scale_set>::convert(const tmtable::Row& row);

  template<> tmxsdtree::ext_signal
  Converter<tmxsdtree::ext_signal>::convert(const tmtable::Row& row);

  template<> tmxsdtree::ext_signal_set
  Converter<tmxsdtree::ext_signal_set>::convert(const tmtable::Row& row);

  template<> tmxsdtree::object_requirement
  Converter<tmxsdtree::object_requirement>::convert(const tmtable::Row& row);

  template<> tmxsdtree::external_requirement
  Converter<tmxsdtree::external_requirement>::convert(const tmtable::Row& row);

  template<> tmxsdtree::algorithm
  Converter<tmxsdtree::algorithm>::convert(const tmtable::Row& row);

  template<> tmxsdtree::cut
  Converter<tmxsdtree::cut>::convert(const tmtable::Row& row);

  template<> tmxsdtree::menu
  Converter<tmxsdtree::menu>::convert(const tmtable::Row& row);

}
#endif // tmxsd_converter_hh
/* eof */
