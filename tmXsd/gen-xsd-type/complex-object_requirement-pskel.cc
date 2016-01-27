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

// Begin prologue.
//
//
// End prologue.

#include "complex-object_requirement-pskel.hh"

namespace tmxsd
{
  // object_requirement_pskel
  //

  void object_requirement_pskel::
  name_parser (::tmxsd::char1k_pskel& p)
  {
    this->name_ = &p;
  }

  void object_requirement_pskel::
  type_parser (::tmxsd::char64_pskel& p)
  {
    this->type_ = &p;
  }

  void object_requirement_pskel::
  comparison_operator_parser (::tmxsd::char64_pskel& p)
  {
    this->comparison_operator_ = &p;
  }

  void object_requirement_pskel::
  threshold_parser (::tmxsd::real_pskel& p)
  {
    this->threshold_ = &p;
  }

  void object_requirement_pskel::
  bx_offset_parser (::xml_schema::int_pskel& p)
  {
    this->bx_offset_ = &p;
  }

  void object_requirement_pskel::
  comment_parser (::tmxsd::char4k_pskel& p)
  {
    this->comment_ = &p;
  }

  void object_requirement_pskel::
  requirement_id_parser (::tmxsd::id_pskel& p)
  {
    this->requirement_id_ = &p;
  }

  void object_requirement_pskel::
  datetime_parser (::tmxsd::datetime_pskel& p)
  {
    this->datetime_ = &p;
  }

  void object_requirement_pskel::
  parsers (::tmxsd::char1k_pskel& name,
           ::tmxsd::char64_pskel& type,
           ::tmxsd::char64_pskel& comparison_operator,
           ::tmxsd::real_pskel& threshold,
           ::xml_schema::int_pskel& bx_offset,
           ::tmxsd::char4k_pskel& comment,
           ::tmxsd::id_pskel& requirement_id,
           ::tmxsd::datetime_pskel& datetime)
  {
    this->name_ = &name;
    this->type_ = &type;
    this->comparison_operator_ = &comparison_operator;
    this->threshold_ = &threshold;
    this->bx_offset_ = &bx_offset;
    this->comment_ = &comment;
    this->requirement_id_ = &requirement_id;
    this->datetime_ = &datetime;
  }

  object_requirement_pskel::
  object_requirement_pskel ()
  : name_ (0),
    type_ (0),
    comparison_operator_ (0),
    threshold_ (0),
    bx_offset_ (0),
    comment_ (0),
    requirement_id_ (0),
    datetime_ (0),
    v_state_stack_ (sizeof (v_state_), &v_state_first_)
  {
  }
}

namespace tmxsd
{
  // object_requirement_pskel
  //

  void object_requirement_pskel::
  name (const std::string&)
  {
  }

  void object_requirement_pskel::
  type (const std::string&)
  {
  }

  void object_requirement_pskel::
  comparison_operator (const std::string&)
  {
  }

  void object_requirement_pskel::
  threshold (const std::string&)
  {
  }

  void object_requirement_pskel::
  bx_offset (int)
  {
  }

  void object_requirement_pskel::
  comment (const std::string&)
  {
  }

  void object_requirement_pskel::
  requirement_id (unsigned int)
  {
  }

  void object_requirement_pskel::
  datetime (const std::string&)
  {
  }
}

#include <cassert>

namespace tmxsd
{
  // Element validation and dispatch functions for object_requirement_pskel.
  //
  bool object_requirement_pskel::
  _start_element_impl (const ::xml_schema::ro_string& ns,
                       const ::xml_schema::ro_string& n,
                       const ::xml_schema::ro_string* t)
  {
    while (&t == 0) /* might be unused */;

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
          vd->func = &object_requirement_pskel::sequence_0;
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

  bool object_requirement_pskel::
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

  void object_requirement_pskel::
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

  void object_requirement_pskel::
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

  void object_requirement_pskel::
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start)
  {
    while (&t == 0) /* might be unused */;

    switch (state)
    {
      case 0UL:
      {
        if (n == "name" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->name_;

            if (this->name_)
              this->name_->pre ();
          }
          else
          {
            if (this->name_)
            {
              const std::string& tmp (this->name_->post_char1k ());
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
        if (n == "type" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->type_;

            if (this->type_)
              this->type_->pre ();
          }
          else
          {
            if (this->type_)
            {
              const std::string& tmp (this->type_->post_char64 ());
              this->type (tmp);
            }

            count = 0;
            state = 2UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "type",
              ns, n);
          count = 0;
          state = 2UL;
          // Fall through.
        }
      }
      case 2UL:
      {
        if (n == "comparison_operator" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->comparison_operator_;

            if (this->comparison_operator_)
              this->comparison_operator_->pre ();
          }
          else
          {
            if (this->comparison_operator_)
            {
              const std::string& tmp (this->comparison_operator_->post_char64 ());
              this->comparison_operator (tmp);
            }

            count = 0;
            state = 3UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "comparison_operator",
              ns, n);
          count = 0;
          state = 3UL;
          // Fall through.
        }
      }
      case 3UL:
      {
        if (n == "threshold" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->threshold_;

            if (this->threshold_)
              this->threshold_->pre ();
          }
          else
          {
            if (this->threshold_)
            {
              const std::string& tmp (this->threshold_->post_real ());
              this->threshold (tmp);
            }

            count = 0;
            state = 4UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "threshold",
              ns, n);
          count = 0;
          state = 4UL;
          // Fall through.
        }
      }
      case 4UL:
      {
        if (n == "bx_offset" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->bx_offset_;

            if (this->bx_offset_)
              this->bx_offset_->pre ();
          }
          else
          {
            if (this->bx_offset_)
            {
              int tmp (this->bx_offset_->post_int ());
              this->bx_offset (tmp);
            }

            count = 0;
            state = 5UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "bx_offset",
              ns, n);
          count = 0;
          state = 5UL;
          // Fall through.
        }
      }
      case 5UL:
      {
        if (n == "comment" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->comment_;

            if (this->comment_)
              this->comment_->pre ();
          }
          else
          {
            if (this->comment_)
            {
              const std::string& tmp (this->comment_->post_char4k ());
              this->comment (tmp);
            }

            count = 0;
            state = ~0UL;
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
  // Attribute validation and dispatch functions for object_requirement_pskel.
  //
  bool object_requirement_pskel::
  _attribute_impl_phase_one (const ::xml_schema::ro_string& ns,
                             const ::xml_schema::ro_string& n,
                             const ::xml_schema::ro_string& s)
  {
    if (n == "requirement_id" && ns.empty ())
    {
      if (this->requirement_id_)
      {
        this->requirement_id_->pre ();
        this->requirement_id_->_pre_impl ();
        this->requirement_id_->_characters (s);
        this->requirement_id_->_post_impl ();
        unsigned int tmp (this->requirement_id_->post_id ());
        this->requirement_id (tmp);
      }

      return true;
    }

    if (n == "datetime" && ns.empty ())
    {
      if (this->datetime_)
      {
        this->datetime_->pre ();
        this->datetime_->_pre_impl ();
        this->datetime_->_characters (s);
        this->datetime_->_post_impl ();
        const std::string& tmp (this->datetime_->post_datetime ());
        this->datetime (tmp);
      }

      return true;
    }

    return false;
  }
}

namespace tmxsd
{
}

// Begin epilogue.
//
//
// End epilogue.

