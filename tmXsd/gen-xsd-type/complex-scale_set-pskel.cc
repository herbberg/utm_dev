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

#include "complex-scale_set-pskel.hh"

namespace tmxsd
{
  // scale_set_pskel
  //

  void scale_set_pskel::
  name_parser (::tmxsd::char1k_pskel& p)
  {
    this->name_parser_ = &p;
  }

  void scale_set_pskel::
  comment_parser (::tmxsd::char4k_pskel& p)
  {
    this->comment_parser_ = &p;
  }

  void scale_set_pskel::
  scale_parser (::tmxsd::scale_pskel& p)
  {
    this->scale_parser_ = &p;
  }

  void scale_set_pskel::
  scale_set_id_parser (::tmxsd::id_pskel& p)
  {
    this->scale_set_id_parser_ = &p;
  }

  void scale_set_pskel::
  datetime_parser (::tmxsd::datetime_pskel& p)
  {
    this->datetime_parser_ = &p;
  }

  void scale_set_pskel::
  is_valid_parser (::xml_schema::boolean_pskel& p)
  {
    this->is_valid_parser_ = &p;
  }

  void scale_set_pskel::
  parsers (::tmxsd::char1k_pskel& name,
           ::tmxsd::char4k_pskel& comment,
           ::tmxsd::scale_pskel& scale,
           ::tmxsd::id_pskel& scale_set_id,
           ::tmxsd::datetime_pskel& datetime,
           ::xml_schema::boolean_pskel& is_valid)
  {
    this->name_parser_ = &name;
    this->comment_parser_ = &comment;
    this->scale_parser_ = &scale;
    this->scale_set_id_parser_ = &scale_set_id;
    this->datetime_parser_ = &datetime;
    this->is_valid_parser_ = &is_valid;
  }

  scale_set_pskel::
  scale_set_pskel ()
  : name_parser_ (0),
    comment_parser_ (0),
    scale_parser_ (0),
    scale_set_id_parser_ (0),
    datetime_parser_ (0),
    is_valid_parser_ (0),
    v_state_stack_ (sizeof (v_state_), &v_state_first_)
  {
  }
}

namespace tmxsd
{
  // scale_set_pskel
  //

  void scale_set_pskel::
  name (const std::string&)
  {
  }

  void scale_set_pskel::
  comment (const std::string&)
  {
  }

  void scale_set_pskel::
  scale (const ::tmxsd::scale&)
  {
  }

  void scale_set_pskel::
  scale_set_id (unsigned int)
  {
  }

  void scale_set_pskel::
  datetime (const std::string&)
  {
  }

  void scale_set_pskel::
  is_valid (bool)
  {
  }
}

#include <cassert>

namespace tmxsd
{
  // Element validation and dispatch functions for scale_set_pskel.
  //
  bool scale_set_pskel::
  _start_element_impl (const ::xml_schema::ro_string& ns,
                       const ::xml_schema::ro_string& n,
                       const ::xml_schema::ro_string* t)
  {
    XSD_UNUSED (t);

    v_state_& vs = *static_cast< v_state_* > (this->v_state_stack_.top ());
    v_state_descr_* vd = vs.data + (vs.size - 1);

    if (vd->func == 0 && vd->state == 0)
    {
      if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
        return true;
      else
        vd->state = 1;
    }

    while (vd->func != 0)
    {
      (this->*vd->func) (vd->state, vd->count, ns, n, t, true);

      vd = vs.data + (vs.size - 1);

      if (vd->state == ~0UL)
        vd = vs.data + (--vs.size - 1);
      else
        break;
    }

    if (vd->func == 0)
    {
      if (vd->state != ~0UL)
      {
        unsigned long s = ~0UL;

        if (n == "name" && ns.empty ())
          s = 0UL;

        if (s != ~0UL)
        {
          vd->count++;
          vd->state = ~0UL;

          vd = vs.data + vs.size++;
          vd->func = &scale_set_pskel::sequence_0;
          vd->state = s;
          vd->count = 0;

          this->sequence_0 (vd->state, vd->count, ns, n, t, true);
        }
        else
        {
          if (vd->count < 1UL)
            this->_expected_element (
              "", "name",
              ns, n);
          return false;
        }
      }
      else
        return false;
    }

    return true;
  }

  bool scale_set_pskel::
  _end_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n)
  {
    v_state_& vs = *static_cast< v_state_* > (this->v_state_stack_.top ());
    v_state_descr_& vd = vs.data[vs.size - 1];

    if (vd.func == 0 && vd.state == 0)
    {
      if (!::xml_schema::complex_content::_end_element_impl (ns, n))
        assert (false);
      return true;
    }

    assert (vd.func != 0);
    (this->*vd.func) (vd.state, vd.count, ns, n, 0, false);

    if (vd.state == ~0UL)
      vs.size--;

    return true;
  }

  void scale_set_pskel::
  _pre_e_validate ()
  {
    this->v_state_stack_.push ();
    static_cast< v_state_* > (this->v_state_stack_.top ())->size = 0;

    v_state_& vs = *static_cast< v_state_* > (this->v_state_stack_.top ());
    v_state_descr_& vd = vs.data[vs.size++];

    vd.func = 0;
    vd.state = 0;
    vd.count = 0;
  }

  void scale_set_pskel::
  _post_e_validate ()
  {
    v_state_& vs = *static_cast< v_state_* > (this->v_state_stack_.top ());
    v_state_descr_* vd = vs.data + (vs.size - 1);

    ::xml_schema::ro_string empty;
    while (vd->func != 0)
    {
      (this->*vd->func) (vd->state, vd->count, empty, empty, 0, true);
      assert (vd->state == ~0UL);
      vd = vs.data + (--vs.size - 1);
    }

    if (vd->count < 1UL)
      this->_expected_element (
        "", "name");

    this->v_state_stack_.pop ();
  }

  void scale_set_pskel::
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start)
  {
    XSD_UNUSED (t);

    switch (state)
    {
      case 0UL:
      {
        if (n == "name" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->name_parser_;

            if (this->name_parser_)
              this->name_parser_->pre ();
          }
          else
          {
            if (this->name_parser_)
            {
              const std::string& tmp (this->name_parser_->post_char1k ());
              this->name (tmp);
            }

            count = 0;
            state = 1UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "name",
              ns, n);
          count = 0;
          state = 1UL;
          // Fall through.
        }
      }
      case 1UL:
      {
        if (n == "comment" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->comment_parser_;

            if (this->comment_parser_)
              this->comment_parser_->pre ();
          }
          else
          {
            if (this->comment_parser_)
            {
              const std::string& tmp (this->comment_parser_->post_char4k ());
              this->comment (tmp);
            }

            count = 0;
            state = 2UL;
          }

          break;
        }
        else
        {
          assert (start);
          count = 0;
          state = 2UL;
          // Fall through.
        }
      }
      case 2UL:
      {
        if (n == "scale" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->scale_parser_;

            if (this->scale_parser_)
              this->scale_parser_->pre ();
          }
          else
          {
            if (this->scale_parser_)
            {
              const ::tmxsd::scale& tmp (this->scale_parser_->post_scale ());
              this->scale (tmp);
            }

            count++;
          }

          break;
        }
        else
        {
          assert (start);
          count = 0;
          state = ~0UL;
          // Fall through.
        }
      }
      case ~0UL:
        break;
    }
  }
}

namespace tmxsd
{
  // Attribute validation and dispatch functions for scale_set_pskel.
  //
  bool scale_set_pskel::
  _attribute_impl_phase_one (const ::xml_schema::ro_string& ns,
                             const ::xml_schema::ro_string& n,
                             const ::xml_schema::ro_string& s)
  {
    if (n == "scale_set_id" && ns.empty ())
    {
      if (this->scale_set_id_parser_)
      {
        this->scale_set_id_parser_->pre ();
        this->scale_set_id_parser_->_pre_impl ();
        this->scale_set_id_parser_->_characters (s);
        this->scale_set_id_parser_->_post_impl ();
        unsigned int tmp (this->scale_set_id_parser_->post_id ());
        this->scale_set_id (tmp);
      }

      return true;
    }

    if (n == "datetime" && ns.empty ())
    {
      if (this->datetime_parser_)
      {
        this->datetime_parser_->pre ();
        this->datetime_parser_->_pre_impl ();
        this->datetime_parser_->_characters (s);
        this->datetime_parser_->_post_impl ();
        const std::string& tmp (this->datetime_parser_->post_datetime ());
        this->datetime (tmp);
      }

      return true;
    }

    if (n == "is_valid" && ns.empty ())
    {
      if (this->is_valid_parser_)
      {
        this->is_valid_parser_->pre ();
        this->is_valid_parser_->_pre_impl ();
        this->is_valid_parser_->_characters (s);
        this->is_valid_parser_->_post_impl ();
        bool tmp (this->is_valid_parser_->post_boolean ());
        this->is_valid (tmp);
      }

      return true;
    }

    return false;
  }
}

namespace tmxsd
{
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

