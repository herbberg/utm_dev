// Copyright (C) 2005-2008 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from ../xsd-type/complex-external_requirement.xsd.
 */

#ifndef CXX___XSD_TYPE_COMPLEX_EXTERNAL_REQUIREMENT_HXX
#define CXX___XSD_TYPE_COMPLEX_EXTERNAL_REQUIREMENT_HXX

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/version.hxx>

#if (XSD_INT_VERSION != 3010000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/types.hxx>

#include <xsd/cxx/xml/error-handler.hxx>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

#include <xsd/cxx/tree/parsing.hxx>
#include <xsd/cxx/tree/parsing/byte.hxx>
#include <xsd/cxx/tree/parsing/unsigned-byte.hxx>
#include <xsd/cxx/tree/parsing/short.hxx>
#include <xsd/cxx/tree/parsing/unsigned-short.hxx>
#include <xsd/cxx/tree/parsing/int.hxx>
#include <xsd/cxx/tree/parsing/unsigned-int.hxx>
#include <xsd/cxx/tree/parsing/long.hxx>
#include <xsd/cxx/tree/parsing/unsigned-long.hxx>
#include <xsd/cxx/tree/parsing/boolean.hxx>
#include <xsd/cxx/tree/parsing/float.hxx>
#include <xsd/cxx/tree/parsing/double.hxx>

#include <xsd/cxx/xml/dom/serialization-header.hxx>
#include <xsd/cxx/tree/serialization.hxx>
#include <xsd/cxx/tree/serialization/byte.hxx>
#include <xsd/cxx/tree/serialization/unsigned-byte.hxx>
#include <xsd/cxx/tree/serialization/short.hxx>
#include <xsd/cxx/tree/serialization/unsigned-short.hxx>
#include <xsd/cxx/tree/serialization/int.hxx>
#include <xsd/cxx/tree/serialization/unsigned-int.hxx>
#include <xsd/cxx/tree/serialization/long.hxx>
#include <xsd/cxx/tree/serialization/unsigned-long.hxx>
#include <xsd/cxx/tree/serialization/boolean.hxx>
#include <xsd/cxx/tree/serialization/float.hxx>
#include <xsd/cxx/tree/serialization/double.hxx>

/**
 * @brief C++ namespace for the %http://www.w3.org/2001/XMLSchema
 * schema namespace.
 */
namespace xml_schema
{
  // anyType and anySimpleType.
  //

  /**
   * @brief C++ type corresponding to the anyType XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::type type;

  /**
   * @brief C++ type corresponding to the anySimpleType XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::simple_type< type > simple_type;

  /**
   * @brief Alias for the anyType type.
   */
  typedef ::xsd::cxx::tree::type container;


  // 8-bit
  //

  /**
   * @brief C++ type corresponding to the byte XML Schema
   * built-in type.
   */
  typedef signed char byte;

  /**
   * @brief C++ type corresponding to the unsignedByte XML Schema
   * built-in type.
   */
  typedef unsigned char unsigned_byte;


  // 16-bit
  //

  /**
   * @brief C++ type corresponding to the short XML Schema
   * built-in type.
   */
  typedef short short_;

  /**
   * @brief C++ type corresponding to the unsignedShort XML Schema
   * built-in type.
   */
  typedef unsigned short unsigned_short;


  // 32-bit
  //

  /**
   * @brief C++ type corresponding to the int XML Schema
   * built-in type.
   */
  typedef int int_;

  /**
   * @brief C++ type corresponding to the unsignedInt XML Schema
   * built-in type.
   */
  typedef unsigned int unsigned_int;


  // 64-bit
  //

  /**
   * @brief C++ type corresponding to the long XML Schema
   * built-in type.
   */
  typedef long long long_;

  /**
   * @brief C++ type corresponding to the unsignedLong XML Schema
   * built-in type.
   */
  typedef unsigned long long unsigned_long;


  // Supposed to be arbitrary-length integral types.
  //

  /**
   * @brief C++ type corresponding to the integer XML Schema
   * built-in type.
   */
  typedef long long integer;

  /**
   * @brief C++ type corresponding to the nonPositiveInteger XML Schema
   * built-in type.
   */
  typedef long long non_positive_integer;

  /**
   * @brief C++ type corresponding to the nonNegativeInteger XML Schema
   * built-in type.
   */
  typedef unsigned long long non_negative_integer;

  /**
   * @brief C++ type corresponding to the positiveInteger XML Schema
   * built-in type.
   */
  typedef unsigned long long positive_integer;

  /**
   * @brief C++ type corresponding to the negativeInteger XML Schema
   * built-in type.
   */
  typedef long long negative_integer;


  // Boolean.
  //

  /**
   * @brief C++ type corresponding to the boolean XML Schema
   * built-in type.
   */
  typedef bool boolean;


  // Floating-point types.
  //

  /**
   * @brief C++ type corresponding to the float XML Schema
   * built-in type.
   */
  typedef float float_;

  /**
   * @brief C++ type corresponding to the double XML Schema
   * built-in type.
   */
  typedef double double_;

  /**
   * @brief C++ type corresponding to the decimal XML Schema
   * built-in type.
   */
  typedef double decimal;


  // String types.
  //

  /**
   * @brief C++ type corresponding to the string XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::string< char, simple_type > string;

  /**
   * @brief C++ type corresponding to the normalizedString XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::normalized_string< char, string > normalized_string;

  /**
   * @brief C++ type corresponding to the token XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::token< char, normalized_string > token;

  /**
   * @brief C++ type corresponding to the Name XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::name< char, token > name;

  /**
   * @brief C++ type corresponding to the NMTOKEN XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::nmtoken< char, token > nmtoken;

  /**
   * @brief C++ type corresponding to the NMTOKENS XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::nmtokens< char, simple_type, nmtoken > nmtokens;

  /**
   * @brief C++ type corresponding to the NCName XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::ncname< char, name > ncname;

  /**
   * @brief C++ type corresponding to the language XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::language< char, token > language;


  // ID/IDREF.
  //

  /**
   * @brief C++ type corresponding to the ID XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::id< char, ncname > id;

  /**
   * @brief C++ type corresponding to the IDREF XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::idref< type, char, ncname > idref;

  /**
   * @brief C++ type corresponding to the IDREFS XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::idrefs< char, simple_type, idref > idrefs;


  // URI.
  //

  /**
   * @brief C++ type corresponding to the anyURI XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::uri< char, simple_type > uri;


  // Qualified name.
  //

  /**
   * @brief C++ type corresponding to the QName XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::qname< char, simple_type, uri, ncname > qname;


  // Binary.
  //

  /**
   * @brief Binary buffer type.
   */
  typedef ::xsd::cxx::tree::buffer< char > buffer;

  /**
   * @brief C++ type corresponding to the base64Binary XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::base64_binary< char, simple_type > base64_binary;

  /**
   * @brief C++ type corresponding to the hexBinary XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::hex_binary< char, simple_type > hex_binary;


  // Date/time.
  //

  /**
   * @brief Time zone type.
   */
  typedef ::xsd::cxx::tree::time_zone time_zone;

  /**
   * @brief C++ type corresponding to the date XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::date< char, simple_type > date;

  /**
   * @brief C++ type corresponding to the dateTime XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::date_time< char, simple_type > date_time;

  /**
   * @brief C++ type corresponding to the duration XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::duration< char, simple_type > duration;

  /**
   * @brief C++ type corresponding to the gDay XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gday< char, simple_type > gday;

  /**
   * @brief C++ type corresponding to the gMonth XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gmonth< char, simple_type > gmonth;

  /**
   * @brief C++ type corresponding to the gMonthDay XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gmonth_day< char, simple_type > gmonth_day;

  /**
   * @brief C++ type corresponding to the gYear XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gyear< char, simple_type > gyear;

  /**
   * @brief C++ type corresponding to the gYearMonth XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::gyear_month< char, simple_type > gyear_month;

  /**
   * @brief C++ type corresponding to the time XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::time< char, simple_type > time;


  // Entity.
  //

  /**
   * @brief C++ type corresponding to the ENTITY XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::entity< char, ncname > entity;

  /**
   * @brief C++ type corresponding to the ENTITIES XML Schema
   * built-in type.
   */
  typedef ::xsd::cxx::tree::entities< char, simple_type, entity > entities;


  // Namespace information and list stream. Used in
  // serialization functions.
  //
  /**
   * @brief Namespace serialization information.
   */
  typedef ::xsd::cxx::xml::dom::namespace_info < char > namespace_info;

  /**
   * @brief Namespace serialization information map.
   */
  typedef ::xsd::cxx::xml::dom::namespace_infomap < char > namespace_infomap;

  /**
   * @brief List serialization stream.
   */
  typedef ::xsd::cxx::tree::list_stream < char > list_stream;

  // Flags and properties.
  //

  /**
   * @brief Parsing and serialization flags.
   */
  typedef ::xsd::cxx::tree::flags flags;

  /**
   * @brief Parsing properties.
   */
  typedef ::xsd::cxx::tree::properties< char > properties;

  // Exceptions.
  //

  /**
   * @brief Root of the C++/Tree %exception hierarchy.
   */
  typedef ::xsd::cxx::tree::exception< char > exception;

  /**
   * @brief Exception indicating a parsing failure.
   */
  typedef ::xsd::cxx::tree::parsing< char > parsing;

  /**
   * @brief Exception indicating that an expected element
   * was not encountered.
   */
  typedef ::xsd::cxx::tree::expected_element< char > expected_element;

  /**
   * @brief Exception indicating that an unexpected element
   * was encountered.
   */
  typedef ::xsd::cxx::tree::unexpected_element< char > unexpected_element;

  /**
   * @brief Exception indicating that an expected attribute
   * was not encountered.
   */
  typedef ::xsd::cxx::tree::expected_attribute< char > expected_attribute;

  /**
   * @brief Exception indicating that an unexpected enumerator
   * was encountered.
   */
  typedef ::xsd::cxx::tree::unexpected_enumerator< char > unexpected_enumerator;

  /**
   * @brief Exception indicating that the text content was
   * expected for an element.
   */
  typedef ::xsd::cxx::tree::expected_text_content< char > expected_text_content;

  /**
   * @brief Exception indicating that the type information
   * is not available for a type.
   */
  typedef ::xsd::cxx::tree::no_type_info< char > no_type_info;

  /**
   * @brief Exception indicating that the types are not
   * related by inheritance.
   */
  typedef ::xsd::cxx::tree::not_derived< char > not_derived;

  /**
   * @brief Exception indicating that a duplicate ID value
   * was encountered in the object model.
   */
  typedef ::xsd::cxx::tree::duplicate_id< char > duplicate_id;

  /**
   * @brief Exception indicating a serialization failure.
   */
  typedef ::xsd::cxx::tree::serialization< char > serialization;

  /**
   * @brief Exception indicating that a namespace-prefix
   * mapping was not provided.
   */
  typedef ::xsd::cxx::tree::no_namespace_mapping< char > no_namespace_mapping;

  /**
   * @brief Exception indicating that a prefix-namespace
   * mapping was not provided.
   */
  typedef ::xsd::cxx::tree::no_prefix_mapping< char > no_prefix_mapping;

  /**
   * @brief Exception indicating that the xsi prefix is used
   * for another namespace.
   */
  typedef ::xsd::cxx::tree::xsi_already_in_use< char > xsi_already_in_use;

  /**
   * @brief Exception indicating that the size argument exceeds
   * the capacity argument.
   */
  typedef ::xsd::cxx::tree::bounds< char > bounds;

  // Parsing/serialization diagnostics.
  //

  /**
   * @brief Error severity.
   */
  typedef ::xsd::cxx::tree::severity severity;

  /**
   * @brief Error condition.
   */
  typedef ::xsd::cxx::tree::error< char > error;

  /**
   * @brief List of %error conditions.
   */
  typedef ::xsd::cxx::tree::diagnostics< char > diagnostics;

  /**
   * @brief Error handler callback interface.
   */
  typedef ::xsd::cxx::xml::error_handler< char > error_handler;

  /**
   * @brief DOM interaction.
   */
  namespace dom
  {
    /**
     * @brief Automatic pointer for DOMDocument.
     */
    using ::xsd::cxx::xml::dom::auto_ptr;

#ifndef XSD_CXX_TREE_TREE_NODE_KEY_IN___XML_SCHEMA
#define XSD_CXX_TREE_TREE_NODE_KEY_IN___XML_SCHEMA
    /**
     * @brief DOM user data key for back pointers to tree nodes.
     */
    const XMLCh* const tree_node_key = ::xsd::cxx::tree::user_data_keys::node;
#endif
  }
}

// Forward declarations.
//
namespace tmxsdtree
{
  class external_requirement;
}


#include <memory>    // std::auto_ptr
#include <algorithm> // std::binary_search

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "simple-types.hxx"

/**
 * @brief C++ namespace for the %http://www.cern.ch/tmxsd/1.0.0
 * schema namespace.
 */
namespace tmxsdtree
{
  /**
   * @brief Class corresponding to the %external_requirement schema type.
   *
   * The external_requirement complex type holds information associated to
   * OBJECT/REQUIREMENT tables in the CMS level-1 trigger menu database
   *
   * @nosubgrouping
   */
  class external_requirement: public ::xml_schema::type
  {
    public:
    /**
     * @name name
     *
     * @brief Accessor and modifier functions for the %name
     * required element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::tmxsdtree::char1k name_type;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const name_type&
    name () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    name_type&
    name ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    name (const name_type& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    name (::std::auto_ptr< name_type > p);

    //@}

    /**
     * @name bx_offset
     *
     * @brief Accessor and modifier functions for the %bx_offset
     * required element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::xml_schema::int_ bx_offset_type;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< bx_offset_type, char > bx_offset_traits;

    /**
     * @brief Return a read-only (constant) reference to the element.
     *
     * @return A constant reference to the element.
     */
    const bx_offset_type&
    bx_offset () const;

    /**
     * @brief Return a read-write reference to the element.
     *
     * @return A reference to the element.
     */
    bx_offset_type&
    bx_offset ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    bx_offset (const bx_offset_type& x);

    //@}

    /**
     * @name comment
     *
     * @brief Accessor and modifier functions for the %comment
     * optional element.
     */
    //@{

    /**
     * @brief Element type.
     */
    typedef ::tmxsdtree::char4k comment_type;

    /**
     * @brief Element optional container type.
     */
    typedef ::xsd::cxx::tree::optional< comment_type > comment_optional;

    /**
     * @brief Element traits type.
     */
    typedef ::xsd::cxx::tree::traits< comment_type, char > comment_traits;

    /**
     * @brief Return a read-only (constant) reference to the element
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const comment_optional&
    comment () const;

    /**
     * @brief Return a read-write reference to the element container.
     *
     * @return A reference to the optional container.
     */
    comment_optional&
    comment ();

    /**
     * @brief Set the element value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the element.
     */
    void
    comment (const comment_type& x);

    /**
     * @brief Set the element value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the element.
     * Otherwise the element container is set the 'not present' state.
     */
    void
    comment (const comment_optional& x);

    /**
     * @brief Set the element value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    comment (::std::auto_ptr< comment_type > p);

    //@}

    /**
     * @name requirement_id
     *
     * @brief Accessor and modifier functions for the %requirement_id
     * optional attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::tmxsdtree::id requirement_id_type;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< requirement_id_type > requirement_id_optional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< requirement_id_type, char > requirement_id_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const requirement_id_optional&
    requirement_id () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    requirement_id_optional&
    requirement_id ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    requirement_id (const requirement_id_type& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    requirement_id (const requirement_id_optional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    requirement_id (::std::auto_ptr< requirement_id_type > p);

    //@}

    /**
     * @name ext_signal_id
     *
     * @brief Accessor and modifier functions for the %ext_signal_id
     * optional attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::tmxsdtree::id ext_signal_id_type;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< ext_signal_id_type > ext_signal_id_optional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< ext_signal_id_type, char > ext_signal_id_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const ext_signal_id_optional&
    ext_signal_id () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    ext_signal_id_optional&
    ext_signal_id ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    ext_signal_id (const ext_signal_id_type& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    ext_signal_id (const ext_signal_id_optional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    ext_signal_id (::std::auto_ptr< ext_signal_id_type > p);

    //@}

    /**
     * @name datetime
     *
     * @brief Accessor and modifier functions for the %datetime
     * optional attribute.
     */
    //@{

    /**
     * @brief Attribute type.
     */
    typedef ::tmxsdtree::datetime datetime_type;

    /**
     * @brief Attribute optional container type.
     */
    typedef ::xsd::cxx::tree::optional< datetime_type > datetime_optional;

    /**
     * @brief Attribute traits type.
     */
    typedef ::xsd::cxx::tree::traits< datetime_type, char > datetime_traits;

    /**
     * @brief Return a read-only (constant) reference to the attribute
     * container.
     *
     * @return A constant reference to the optional container.
     */
    const datetime_optional&
    datetime () const;

    /**
     * @brief Return a read-write reference to the attribute container.
     *
     * @return A reference to the optional container.
     */
    datetime_optional&
    datetime ();

    /**
     * @brief Set the attribute value.
     *
     * @param x A new value to set.
     *
     * This function makes a copy of its argument and sets it as
     * the new value of the attribute.
     */
    void
    datetime (const datetime_type& x);

    /**
     * @brief Set the attribute value.
     *
     * @param x An optional container with the new value to set.
     *
     * If the value is present in @a x then this function makes a copy 
     * of this value and sets it as the new value of the attribute.
     * Otherwise the attribute container is set the 'not present' state.
     */
    void
    datetime (const datetime_optional& x);

    /**
     * @brief Set the attribute value without copying.
     *
     * @param p A new value to use.
     *
     * This function will try to use the passed value directly instead
     * of making a copy.
     */
    void
    datetime (::std::auto_ptr< datetime_type > p);

    //@}

    /**
     * @name Constructors
     */
    //@{

    /**
     * @brief Create an instance from the ultimate base and
     * initializers for required elements and attributes.
     */
    external_requirement (const name_type&,
                          const bx_offset_type&);

    /**
     * @brief Create an instance from a DOM element.
     *
     * @param e A DOM element to extract the data from.
     * @param f Flags to create the new instance with.
     * @param c A pointer to the object that will contain the new
     * instance.
     */
    external_requirement (const ::xercesc::DOMElement& e,
                          ::xml_schema::flags f = 0,
                          ::xml_schema::container* c = 0);

    /**
     * @brief Copy constructor.
     *
     * @param x An instance to make a copy of.
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     *
     * For polymorphic object models use the @c _clone function instead.
     */
    external_requirement (const external_requirement& x,
                          ::xml_schema::flags f = 0,
                          ::xml_schema::container* c = 0);

    /**
     * @brief Copy the instance polymorphically.
     *
     * @param f Flags to create the copy with.
     * @param c A pointer to the object that will contain the copy.
     * @return A pointer to the dynamically allocated copy.
     *
     * This function ensures that the dynamic type of the instance is
     * used for copying and should be used for polymorphic object
     * models instead of the copy constructor.
     */
    virtual external_requirement*
    _clone (::xml_schema::flags f = 0,
            ::xml_schema::container* c = 0) const;

    //@}

    /**
     * @brief Destructor.
     */
    virtual 
    ~external_requirement ();

    // Implementation.
    //

    //@cond

    protected:
    void
    parse (::xsd::cxx::xml::dom::parser< char >&,
           ::xml_schema::flags);

    protected:
    ::xsd::cxx::tree::one< name_type > name_;
    ::xsd::cxx::tree::one< bx_offset_type > bx_offset_;
    comment_optional comment_;
    requirement_id_optional requirement_id_;
    ext_signal_id_optional ext_signal_id_;
    datetime_optional datetime_;

    //@endcond
  };
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace tmxsdtree
{
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace tmxsdtree
{
  void
  operator<< (::xercesc::DOMElement&, const external_requirement&);
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___XSD_TYPE_COMPLEX_EXTERNAL_REQUIREMENT_HXX
