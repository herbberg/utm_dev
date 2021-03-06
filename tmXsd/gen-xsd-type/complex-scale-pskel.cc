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

#include "complex-scale-pskel.hh"

namespace tmxsd
{
  // scale_pskel
  //

  void scale_pskel::
  object_parser (::tmxsd::char64_pskel& p)
  {
    this->object_parser_ = &p;
  }

  void scale_pskel::
  type_parser (::tmxsd::char64_pskel& p)
  {
    this->type_parser_ = &p;
  }

  void scale_pskel::
  minimum_parser (::tmxsd::real_pskel& p)
  {
    this->minimum_parser_ = &p;
  }

  void scale_pskel::
  maximum_parser (::tmxsd::real_pskel& p)
  {
    this->maximum_parser_ = &p;
  }

  void scale_pskel::
  step_parser (::tmxsd::real_pskel& p)
  {
    this->step_parser_ = &p;
  }

  void scale_pskel::
  n_bits_parser (::xml_schema::unsigned_int_pskel& p)
  {
    this->n_bits_parser_ = &p;
  }

  void scale_pskel::
  comment_parser (::tmxsd::char4k_pskel& p)
  {
    this->comment_parser_ = &p;
  }

  void scale_pskel::
  bin_parser (::tmxsd::bin_pskel& p)
  {
    this->bin_parser_ = &p;
  }

  void scale_pskel::
  scale_id_parser (::tmxsd::id_pskel& p)
  {
    this->scale_id_parser_ = &p;
  }

  void scale_pskel::
  datetime_parser (::tmxsd::datetime_pskel& p)
  {
    this->datetime_parser_ = &p;
  }

  void scale_pskel::
  n_bins_parser (::xml_schema::unsigned_int_pskel& p)
  {
    this->n_bins_parser_ = &p;
  }

  void scale_pskel::
  parsers (::tmxsd::char64_pskel& object,
           ::tmxsd::char64_pskel& type,
           ::tmxsd::real_pskel& minimum,
           ::tmxsd::real_pskel& maximum,
           ::tmxsd::real_pskel& step,
           ::xml_schema::unsigned_int_pskel& n_bits,
           ::tmxsd::char4k_pskel& comment,
           ::tmxsd::bin_pskel& bin,
           ::tmxsd::id_pskel& scale_id,
           ::tmxsd::datetime_pskel& datetime,
           ::xml_schema::unsigned_int_pskel& n_bins)
  {
    this->object_parser_ = &object;
    this->type_parser_ = &type;
    this->minimum_parser_ = &minimum;
    this->maximum_parser_ = &maximum;
    this->step_parser_ = &step;
    this->n_bits_parser_ = &n_bits;
    this->comment_parser_ = &comment;
    this->bin_parser_ = &bin;
    this->scale_id_parser_ = &scale_id;
    this->datetime_parser_ = &datetime;
    this->n_bins_parser_ = &n_bins;
  }

  scale_pskel::
  scale_pskel ()
  : object_parser_ (0),
    type_parser_ (0),
    minimum_parser_ (0),
    maximum_parser_ (0),
    step_parser_ (0),
    n_bits_parser_ (0),
    comment_parser_ (0),
    bin_parser_ (0),
    scale_id_parser_ (0),
    datetime_parser_ (0),
    n_bins_parser_ (0),
    v_state_stack_ (sizeof (v_state_), &v_state_first_)
  {
  }
}

namespace tmxsd
{
  // scale_pskel
  //

  void scale_pskel::
  object (const std::string&)
  {
  }

  void scale_pskel::
  type (const std::string&)
  {
  }

  void scale_pskel::
  minimum (const std::string&)
  {
  }

  void scale_pskel::
  maximum (const std::string&)
  {
  }

  void scale_pskel::
  step (const std::string&)
  {
  }

  void scale_pskel::
  n_bits (unsigned int)
  {
  }

  void scale_pskel::
  comment (const std::string&)
  {
  }

  void scale_pskel::
  bin (const ::tmxsd::bin&)
  {
  }

  void scale_pskel::
  scale_id (unsigned int)
  {
  }

  void scale_pskel::
  datetime (const std::string&)
  {
  }

  void scale_pskel::
  n_bins (unsigned int)
  {
  }
}

#include <cassert>

namespace tmxsd
{
  // Element validation and dispatch functions for scale_pskel.
  //
  bool scale_pskel::
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

        if (n == "object" && ns.empty ())
          s = 0UL;

        if (s != ~0UL)
        {
          vd->count++;
          vd->state = ~0UL;

          vd = vs.data + vs.size++;
          vd->func = &scale_pskel::sequence_0;
          vd->state = s;
          vd->count = 0;

          this->sequence_0 (vd->state, vd->count, ns, n, t, true);
        }
        else
        {
          if (vd->count < 1UL)
            this->_expected_element (
              "", "object",
              ns, n);
          return false;
        }
      }
      else
        return false;
    }

    return true;
  }

  bool scale_pskel::
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

  void scale_pskel::
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

  void scale_pskel::
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
        "", "object");

    this->v_state_stack_.pop ();
  }

  void scale_pskel::
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
        if (n == "object" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->object_parser_;

            if (this->object_parser_)
              this->object_parser_->pre ();
          }
          else
          {
            if (this->object_parser_)
            {
              this->object (this->object_parser_->post_char64 ());
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
              "", "object",
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
            this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

            if (this->type_parser_)
              this->type_parser_->pre ();
          }
          else
          {
            if (this->type_parser_)
            {
              this->type (this->type_parser_->post_char64 ());
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
        if (n == "minimum" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->minimum_parser_;

            if (this->minimum_parser_)
              this->minimum_parser_->pre ();
          }
          else
          {
            if (this->minimum_parser_)
            {
              this->minimum (this->minimum_parser_->post_real ());
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
              "", "minimum",
              ns, n);
          count = 0;
          state = 3UL;
          // Fall through.
        }
      }
      case 3UL:
      {
        if (n == "maximum" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->maximum_parser_;

            if (this->maximum_parser_)
              this->maximum_parser_->pre ();
          }
          else
          {
            if (this->maximum_parser_)
            {
              this->maximum (this->maximum_parser_->post_real ());
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
              "", "maximum",
              ns, n);
          count = 0;
          state = 4UL;
          // Fall through.
        }
      }
      case 4UL:
      {
        if (n == "step" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->step_parser_;

            if (this->step_parser_)
              this->step_parser_->pre ();
          }
          else
          {
            if (this->step_parser_)
            {
              this->step (this->step_parser_->post_real ());
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
              "", "step",
              ns, n);
          count = 0;
          state = 5UL;
          // Fall through.
        }
      }
      case 5UL:
      {
        if (n == "n_bits" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->n_bits_parser_;

            if (this->n_bits_parser_)
              this->n_bits_parser_->pre ();
          }
          else
          {
            if (this->n_bits_parser_)
            {
              this->n_bits (this->n_bits_parser_->post_unsigned_int ());
            }

            count = 0;
            state = 6UL;
          }

          break;
        }
        else
        {
          assert (start);
          if (count < 1UL)
            this->_expected_element (
              "", "n_bits",
              ns, n);
          count = 0;
          state = 6UL;
          // Fall through.
        }
      }
      case 6UL:
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
              this->comment (this->comment_parser_->post_char4k ());
            }

            count = 0;
            state = 7UL;
          }

          break;
        }
        else
        {
          assert (start);
          count = 0;
          state = 7UL;
          // Fall through.
        }
      }
      case 7UL:
      {
        if (n == "bin" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->bin_parser_;

            if (this->bin_parser_)
              this->bin_parser_->pre ();
          }
          else
          {
            if (this->bin_parser_)
            {
              this->bin (this->bin_parser_->post_bin ());
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
  // Attribute validation and dispatch functions for scale_pskel.
  //
  bool scale_pskel::
  _attribute_impl_phase_one (const ::xml_schema::ro_string& ns,
                             const ::xml_schema::ro_string& n,
                             const ::xml_schema::ro_string& s)
  {
    if (n == "scale_id" && ns.empty ())
    {
      if (this->scale_id_parser_)
      {
        this->scale_id_parser_->pre ();
        this->scale_id_parser_->_pre_impl ();
        this->scale_id_parser_->_characters (s);
        this->scale_id_parser_->_post_impl ();
        this->scale_id (this->scale_id_parser_->post_id ());
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
        this->datetime (this->datetime_parser_->post_datetime ());
      }

      return true;
    }

    if (n == "n_bins" && ns.empty ())
    {
      if (this->n_bins_parser_)
      {
        this->n_bins_parser_->pre ();
        this->n_bins_parser_->_pre_impl ();
        this->n_bins_parser_->_characters (s);
        this->n_bins_parser_->_post_impl ();
        this->n_bins (this->n_bins_parser_->post_unsigned_int ());
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

