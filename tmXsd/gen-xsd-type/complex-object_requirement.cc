// Copyright (c) 2005-2014 Code Synthesis Tools CC
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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "complex-object_requirement.hxx"

namespace tmxsdtree
{
  // object_requirement
  // 

  const object_requirement::name_type& object_requirement::
  name () const
  {
    return this->name_.get ();
  }

  object_requirement::name_type& object_requirement::
  name ()
  {
    return this->name_.get ();
  }

  void object_requirement::
  name (const name_type& x)
  {
    this->name_.set (x);
  }

  void object_requirement::
  name (::std::unique_ptr< name_type > x)
  {
    this->name_.set (std::move (x));
  }

  const object_requirement::type_type& object_requirement::
  type () const
  {
    return this->type_.get ();
  }

  object_requirement::type_type& object_requirement::
  type ()
  {
    return this->type_.get ();
  }

  void object_requirement::
  type (const type_type& x)
  {
    this->type_.set (x);
  }

  void object_requirement::
  type (::std::unique_ptr< type_type > x)
  {
    this->type_.set (std::move (x));
  }

  const object_requirement::comparison_operator_type& object_requirement::
  comparison_operator () const
  {
    return this->comparison_operator_.get ();
  }

  object_requirement::comparison_operator_type& object_requirement::
  comparison_operator ()
  {
    return this->comparison_operator_.get ();
  }

  void object_requirement::
  comparison_operator (const comparison_operator_type& x)
  {
    this->comparison_operator_.set (x);
  }

  void object_requirement::
  comparison_operator (::std::unique_ptr< comparison_operator_type > x)
  {
    this->comparison_operator_.set (std::move (x));
  }

  const object_requirement::threshold_type& object_requirement::
  threshold () const
  {
    return this->threshold_.get ();
  }

  object_requirement::threshold_type& object_requirement::
  threshold ()
  {
    return this->threshold_.get ();
  }

  void object_requirement::
  threshold (const threshold_type& x)
  {
    this->threshold_.set (x);
  }

  void object_requirement::
  threshold (::std::unique_ptr< threshold_type > x)
  {
    this->threshold_.set (std::move (x));
  }

  const object_requirement::bx_offset_type& object_requirement::
  bx_offset () const
  {
    return this->bx_offset_.get ();
  }

  object_requirement::bx_offset_type& object_requirement::
  bx_offset ()
  {
    return this->bx_offset_.get ();
  }

  void object_requirement::
  bx_offset (const bx_offset_type& x)
  {
    this->bx_offset_.set (x);
  }

  const object_requirement::comment_optional& object_requirement::
  comment () const
  {
    return this->comment_;
  }

  object_requirement::comment_optional& object_requirement::
  comment ()
  {
    return this->comment_;
  }

  void object_requirement::
  comment (const comment_type& x)
  {
    this->comment_.set (x);
  }

  void object_requirement::
  comment (const comment_optional& x)
  {
    this->comment_ = x;
  }

  void object_requirement::
  comment (::std::unique_ptr< comment_type > x)
  {
    this->comment_.set (std::move (x));
  }

  const object_requirement::requirement_id_optional& object_requirement::
  requirement_id () const
  {
    return this->requirement_id_;
  }

  object_requirement::requirement_id_optional& object_requirement::
  requirement_id ()
  {
    return this->requirement_id_;
  }

  void object_requirement::
  requirement_id (const requirement_id_type& x)
  {
    this->requirement_id_.set (x);
  }

  void object_requirement::
  requirement_id (const requirement_id_optional& x)
  {
    this->requirement_id_ = x;
  }

  void object_requirement::
  requirement_id (::std::unique_ptr< requirement_id_type > x)
  {
    this->requirement_id_.set (std::move (x));
  }

  const object_requirement::datetime_optional& object_requirement::
  datetime () const
  {
    return this->datetime_;
  }

  object_requirement::datetime_optional& object_requirement::
  datetime ()
  {
    return this->datetime_;
  }

  void object_requirement::
  datetime (const datetime_type& x)
  {
    this->datetime_.set (x);
  }

  void object_requirement::
  datetime (const datetime_optional& x)
  {
    this->datetime_ = x;
  }

  void object_requirement::
  datetime (::std::unique_ptr< datetime_type > x)
  {
    this->datetime_.set (std::move (x));
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace tmxsdtree
{
  // object_requirement
  //

  object_requirement::
  object_requirement (const name_type& name,
                      const type_type& type,
                      const comparison_operator_type& comparison_operator,
                      const threshold_type& threshold,
                      const bx_offset_type& bx_offset)
  : ::xml_schema::type (),
    name_ (name, this),
    type_ (type, this),
    comparison_operator_ (comparison_operator, this),
    threshold_ (threshold, this),
    bx_offset_ (bx_offset, this),
    comment_ (this),
    requirement_id_ (this),
    datetime_ (this)
  {
  }

  object_requirement::
  object_requirement (const object_requirement& x,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    name_ (x.name_, f, this),
    type_ (x.type_, f, this),
    comparison_operator_ (x.comparison_operator_, f, this),
    threshold_ (x.threshold_, f, this),
    bx_offset_ (x.bx_offset_, f, this),
    comment_ (x.comment_, f, this),
    requirement_id_ (x.requirement_id_, f, this),
    datetime_ (x.datetime_, f, this)
  {
  }

  object_requirement::
  object_requirement (const ::xercesc::DOMElement& e,
                      ::xml_schema::flags f,
                      ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    name_ (this),
    type_ (this),
    comparison_operator_ (this),
    threshold_ (this),
    bx_offset_ (this),
    comment_ (this),
    requirement_id_ (this),
    datetime_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
      this->parse (p, f);
    }
  }

  void object_requirement::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_content (); p.next_content (false))
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // name
      //
      if (n.name () == "name" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< name_type > r (
          name_traits::create (i, f, this));

        if (!name_.present ())
        {
          this->name_.set (::std::move (r));
          continue;
        }
      }

      // type
      //
      if (n.name () == "type" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< type_type > r (
          type_traits::create (i, f, this));

        if (!type_.present ())
        {
          this->type_.set (::std::move (r));
          continue;
        }
      }

      // comparison_operator
      //
      if (n.name () == "comparison_operator" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< comparison_operator_type > r (
          comparison_operator_traits::create (i, f, this));

        if (!comparison_operator_.present ())
        {
          this->comparison_operator_.set (::std::move (r));
          continue;
        }
      }

      // threshold
      //
      if (n.name () == "threshold" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< threshold_type > r (
          threshold_traits::create (i, f, this));

        if (!threshold_.present ())
        {
          this->threshold_.set (::std::move (r));
          continue;
        }
      }

      // bx_offset
      //
      if (n.name () == "bx_offset" && n.namespace_ ().empty ())
      {
        if (!bx_offset_.present ())
        {
          this->bx_offset_.set (bx_offset_traits::create (i, f, this));
          continue;
        }
      }

      // comment
      //
      if (n.name () == "comment" && n.namespace_ ().empty ())
      {
        ::std::unique_ptr< comment_type > r (
          comment_traits::create (i, f, this));

        if (!this->comment_)
        {
          this->comment_.set (::std::move (r));
          continue;
        }
      }

      break;
    }

    if (!name_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "name",
        "");
    }

    if (!type_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "type",
        "");
    }

    if (!comparison_operator_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "comparison_operator",
        "");
    }

    if (!threshold_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "threshold",
        "");
    }

    if (!bx_offset_.present ())
    {
      throw ::xsd::cxx::tree::expected_element< char > (
        "bx_offset",
        "");
    }

    while (p.more_attributes ())
    {
      const ::xercesc::DOMAttr& i (p.next_attribute ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      if (n.name () == "requirement_id" && n.namespace_ ().empty ())
      {
        this->requirement_id_.set (requirement_id_traits::create (i, f, this));
        continue;
      }

      if (n.name () == "datetime" && n.namespace_ ().empty ())
      {
        this->datetime_.set (datetime_traits::create (i, f, this));
        continue;
      }
    }
  }

  object_requirement* object_requirement::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class object_requirement (*this, f, c);
  }

  object_requirement& object_requirement::
  operator= (const object_requirement& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->name_ = x.name_;
      this->type_ = x.type_;
      this->comparison_operator_ = x.comparison_operator_;
      this->threshold_ = x.threshold_;
      this->bx_offset_ = x.bx_offset_;
      this->comment_ = x.comment_;
      this->requirement_id_ = x.requirement_id_;
      this->datetime_ = x.datetime_;
    }

    return *this;
  }

  object_requirement::
  ~object_requirement ()
  {
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace tmxsdtree
{
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace tmxsdtree
{
  void
  operator<< (::xercesc::DOMElement& e, const object_requirement& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // name
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "name",
          e));

      s << i.name ();
    }

    // type
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "type",
          e));

      s << i.type ();
    }

    // comparison_operator
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "comparison_operator",
          e));

      s << i.comparison_operator ();
    }

    // threshold
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "threshold",
          e));

      s << i.threshold ();
    }

    // bx_offset
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "bx_offset",
          e));

      s << i.bx_offset ();
    }

    // comment
    //
    if (i.comment ())
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "comment",
          e));

      s << *i.comment ();
    }

    // requirement_id
    //
    if (i.requirement_id ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "requirement_id",
          e));

      a << *i.requirement_id ();
    }

    // datetime
    //
    if (i.datetime ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "datetime",
          e));

      a << *i.datetime ();
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

