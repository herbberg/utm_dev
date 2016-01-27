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

#include "complex-ext_signal-pskel.hh"

namespace tmxsd
{
  // ext_signal_pskel
  //

  void ext_signal_pskel::
  name_parser (::tmxsd::char1k_pskel& p)
  {
    this->name_ = &p;
  }

  void ext_signal_pskel::
  system_parser (::tmxsd::char1k_pskel& p)
  {
    this->system_ = &p;
  }

  void ext_signal_pskel::
  cable_parser (::xml_schema::unsigned_int_pskel& p)
  {
    this->cable_ = &p;
  }

  void ext_signal_pskel::
  channel_parser (::xml_schema::unsigned_int_pskel& p)
  {
    this->channel_ = &p;
  }

  void ext_signal_pskel::
  description_parser (::tmxsd::char4k_pskel& p)
  {
    this->description_ = &p;
  }

  void ext_signal_pskel::
  label_parser (::tmxsd::char1k_pskel& p)
  {
    this->label_ = &p;
  }

  void ext_signal_pskel::
  ext_signal_id_parser (::tmxsd::id_pskel& p)
  {
    this->ext_signal_id_ = &p;
  }

  void ext_signal_pskel::
  datetime_parser (::tmxsd::datetime_pskel& p)
  {
    this->datetime_ = &p;
  }

  void ext_signal_pskel::
  parsers (::tmxsd::char1k_pskel& name,
           ::tmxsd::char1k_pskel& system,
           ::xml_schema::unsigned_int_pskel& cable,
           ::xml_schema::unsigned_int_pskel& channel,
           ::tmxsd::char4k_pskel& description,
           ::tmxsd::char1k_pskel& label,
           ::tmxsd::id_pskel& ext_signal_id,
           ::tmxsd::datetime_pskel& datetime)
  {
    this->name_ = &name;
    this->system_ = &system;
    this->cable_ = &cable;
    this->channel_ = &channel;
    this->description_ = &description;
    this->label_ = &label;
    this->ext_signal_id_ = &ext_signal_id;
    this->datetime_ = &datetime;
  }

  ext_signal_pskel::
  ext_signal_pskel ()
  : name_ (0),
    system_ (0),
    cable_ (0),
    channel_ (0),
    description_ (0),
    label_ (0),
    ext_signal_id_ (0),
    datetime_ (0),
    v_state_stack_ (sizeof (v_state_), &v_state_first_)
  {
  }
}

namespace tmxsd
{
  // ext_signal_pskel
  //

  void ext_signal_pskel::
  name (const std::string&)
  {
  }

  void ext_signal_pskel::
  system (const std::string&)
  {
  }

  void ext_signal_pskel::
  cable (unsigned int)
  {
  }

  void ext_signal_pskel::
  channel (unsigned int)
  {
  }

  void ext_signal_pskel::
  description (const std::string&)
  {
  }

  void ext_signal_pskel::
  label (const std::string&)
  {
  }

  void ext_signal_pskel::
  ext_signal_id (unsigned int)
  {
  }

  void ext_signal_pskel::
  datetime (const std::string&)
  {
  }
}

#include <cassert>

namespace tmxsd
{
  // Element validation and dispatch functions for ext_signal_pskel.
  //
  bool ext_signal_pskel::
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
          vd->func = &ext_signal_pskel::sequence_0;
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

  bool ext_signal_pskel::
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

  void ext_signal_pskel::
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

  void ext_signal_pskel::
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

  void ext_signal_pskel::
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
        if (n == "system" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->system_;

            if (this->system_)
              this->system_->pre ();
          }
          else
          {
            if (this->system_)
            {
              const std::string& tmp (this->system_->post_char1k ());
              this->system (tmp);
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
              "", "system",
              ns, n);
          count = 0;
          state = 2UL;
          // Fall through.
        }
      }
      case 2UL:
      {
        if (n == "cable" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->cable_;

            if (this->cable_)
              this->cable_->pre ();
          }
          else
          {
            if (this->cable_)
            {
              unsigned int tmp (this->cable_->post_unsigned_int ());
              this->cable (tmp);
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
              "", "cable",
              ns, n);
          count = 0;
          state = 3UL;
          // Fall through.
        }
      }
      case 3UL:
      {
        if (n == "channel" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->channel_;

            if (this->channel_)
              this->channel_->pre ();
          }
          else
          {
            if (this->channel_)
            {
              unsigned int tmp (this->channel_->post_unsigned_int ());
              this->channel (tmp);
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
              "", "channel",
              ns, n);
          count = 0;
          state = 4UL;
          // Fall through.
        }
      }
      case 4UL:
      {
        if (n == "description" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->description_;

            if (this->description_)
              this->description_->pre ();
          }
          else
          {
            if (this->description_)
            {
              const std::string& tmp (this->description_->post_char4k ());
              this->description (tmp);
            }

            count = 0;
            state = 5UL;
          }

          break;
        }
        else
        {
          assert (start);
          count = 0;
          state = 5UL;
          // Fall through.
        }
      }
      case 5UL:
      {
        if (n == "label" && ns.empty ())
        {
          if (start)
          {
            this->::xml_schema::complex_content::context_.top ().parser_ = this->label_;

            if (this->label_)
              this->label_->pre ();
          }
          else
          {
            if (this->label_)
            {
              const std::string& tmp (this->label_->post_char1k ());
              this->label (tmp);
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
  // Attribute validation and dispatch functions for ext_signal_pskel.
  //
  bool ext_signal_pskel::
  _attribute_impl_phase_one (const ::xml_schema::ro_string& ns,
                             const ::xml_schema::ro_string& n,
                             const ::xml_schema::ro_string& s)
  {
    if (n == "ext_signal_id" && ns.empty ())
    {
      if (this->ext_signal_id_)
      {
        this->ext_signal_id_->pre ();
        this->ext_signal_id_->_pre_impl ();
        this->ext_signal_id_->_characters (s);
        this->ext_signal_id_->_post_impl ();
        unsigned int tmp (this->ext_signal_id_->post_id ());
        this->ext_signal_id (tmp);
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

