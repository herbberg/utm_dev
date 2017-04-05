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

#include "complex-external_requirement.hxx"

namespace tmxsdtree
{
  // external_requirement
  // 

  const external_requirement::name_type& external_requirement::
  name () const
  {
    return this->name_.get ();
  }

  external_requirement::name_type& external_requirement::
  name ()
  {
    return this->name_.get ();
  }

  void external_requirement::
  name (const name_type& x)
  {
    this->name_.set (x);
  }

  void external_requirement::
  name (::std::auto_ptr< name_type > x)
  {
    this->name_.set (x);
  }

  const external_requirement::bx_offset_type& external_requirement::
  bx_offset () const
  {
    return this->bx_offset_.get ();
  }

  external_requirement::bx_offset_type& external_requirement::
  bx_offset ()
  {
    return this->bx_offset_.get ();
  }

  void external_requirement::
  bx_offset (const bx_offset_type& x)
  {
    this->bx_offset_.set (x);
  }

  const external_requirement::comment_optional& external_requirement::
  comment () const
  {
    return this->comment_;
  }

  external_requirement::comment_optional& external_requirement::
  comment ()
  {
    return this->comment_;
  }

  void external_requirement::
  comment (const comment_type& x)
  {
    this->comment_.set (x);
  }

  void external_requirement::
  comment (const comment_optional& x)
  {
    this->comment_ = x;
  }

  void external_requirement::
  comment (::std::auto_ptr< comment_type > x)
  {
    this->comment_.set (x);
  }

  const external_requirement::requirement_id_optional& external_requirement::
  requirement_id () const
  {
    return this->requirement_id_;
  }

  external_requirement::requirement_id_optional& external_requirement::
  requirement_id ()
  {
    return this->requirement_id_;
  }

  void external_requirement::
  requirement_id (const requirement_id_type& x)
  {
    this->requirement_id_.set (x);
  }

  void external_requirement::
  requirement_id (const requirement_id_optional& x)
  {
    this->requirement_id_ = x;
  }

  void external_requirement::
  requirement_id (::std::auto_ptr< requirement_id_type > x)
  {
    this->requirement_id_.set (x);
  }

  const external_requirement::ext_signal_id_optional& external_requirement::
  ext_signal_id () const
  {
    return this->ext_signal_id_;
  }

  external_requirement::ext_signal_id_optional& external_requirement::
  ext_signal_id ()
  {
    return this->ext_signal_id_;
  }

  void external_requirement::
  ext_signal_id (const ext_signal_id_type& x)
  {
    this->ext_signal_id_.set (x);
  }

  void external_requirement::
  ext_signal_id (const ext_signal_id_optional& x)
  {
    this->ext_signal_id_ = x;
  }

  void external_requirement::
  ext_signal_id (::std::auto_ptr< ext_signal_id_type > x)
  {
    this->ext_signal_id_.set (x);
  }

  const external_requirement::datetime_optional& external_requirement::
  datetime () const
  {
    return this->datetime_;
  }

  external_requirement::datetime_optional& external_requirement::
  datetime ()
  {
    return this->datetime_;
  }

  void external_requirement::
  datetime (const datetime_type& x)
  {
    this->datetime_.set (x);
  }

  void external_requirement::
  datetime (const datetime_optional& x)
  {
    this->datetime_ = x;
  }

  void external_requirement::
  datetime (::std::auto_ptr< datetime_type > x)
  {
    this->datetime_.set (x);
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace tmxsdtree
{
  // external_requirement
  //

  external_requirement::
  external_requirement (const name_type& name,
                        const bx_offset_type& bx_offset)
  : ::xml_schema::type (),
    name_ (name, this),
    bx_offset_ (bx_offset, this),
    comment_ (this),
    requirement_id_ (this),
    ext_signal_id_ (this),
    datetime_ (this)
  {
  }

  external_requirement::
  external_requirement (const external_requirement& x,
                        ::xml_schema::flags f,
                        ::xml_schema::container* c)
  : ::xml_schema::type (x, f, c),
    name_ (x.name_, f, this),
    bx_offset_ (x.bx_offset_, f, this),
    comment_ (x.comment_, f, this),
    requirement_id_ (x.requirement_id_, f, this),
    ext_signal_id_ (x.ext_signal_id_, f, this),
    datetime_ (x.datetime_, f, this)
  {
  }

  external_requirement::
  external_requirement (const ::xercesc::DOMElement& e,
                        ::xml_schema::flags f,
                        ::xml_schema::container* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    name_ (this),
    bx_offset_ (this),
    comment_ (this),
    requirement_id_ (this),
    ext_signal_id_ (this),
    datetime_ (this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e, true, false, true);
      this->parse (p, f);
    }
  }

  void external_requirement::
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
        ::std::auto_ptr< name_type > r (
          name_traits::create (i, f, this));

        if (!name_.present ())
        {
          this->name_.set (r);
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
        ::std::auto_ptr< comment_type > r (
          comment_traits::create (i, f, this));

        if (!this->comment_)
        {
          this->comment_.set (r);
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

      if (n.name () == "ext_signal_id" && n.namespace_ ().empty ())
      {
        this->ext_signal_id_.set (ext_signal_id_traits::create (i, f, this));
        continue;
      }

      if (n.name () == "datetime" && n.namespace_ ().empty ())
      {
        this->datetime_.set (datetime_traits::create (i, f, this));
        continue;
      }
    }
  }

  external_requirement* external_requirement::
  _clone (::xml_schema::flags f,
          ::xml_schema::container* c) const
  {
    return new class external_requirement (*this, f, c);
  }

  external_requirement& external_requirement::
  operator= (const external_requirement& x)
  {
    if (this != &x)
    {
      static_cast< ::xml_schema::type& > (*this) = x;
      this->name_ = x.name_;
      this->bx_offset_ = x.bx_offset_;
      this->comment_ = x.comment_;
      this->requirement_id_ = x.requirement_id_;
      this->ext_signal_id_ = x.ext_signal_id_;
      this->datetime_ = x.datetime_;
    }

    return *this;
  }

  external_requirement::
  ~external_requirement ()
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
  operator<< (::xercesc::DOMElement& e, const external_requirement& i)
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

    // ext_signal_id
    //
    if (i.ext_signal_id ())
    {
      ::xercesc::DOMAttr& a (
        ::xsd::cxx::xml::dom::create_attribute (
          "ext_signal_id",
          e));

      a << *i.ext_signal_id ();
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

