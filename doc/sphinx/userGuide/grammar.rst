..

Grammar
========

Level-1 Trigger algorithms (also referred as seeds) are expressed using a
purpose built language, referred to as UTM grammar.

.. note::

   This page is still a stub.

Functions
---------

Invariant mass
..............

Calculates the invariant mass of two objects.

**Syntax**

  .. code-block:: c

    mass_inv{ obj1, obj2 }[ cut, ... ]

**Objects**

 * requires two objects of type MU, EG, TAU, JET.

**Cuts**

* mass range cut (MASS, required)
* delta-R cut (DR, optional)
* delta-Eta cut (DETA, optional)
* delta-Phi cut (DPHI, optional)
* two body Pt cut (TBPT, optional)


Transverse mass
...............

Calculates the transverse mass of two objects.

**Syntax**

  .. code-block:: c

    mass_trv{ obj1, obj2 }[ cut, ... ]

**Objects**

 * requires two objects of type MU, EG, TAU, JET, ETM, HTM or ETMHF.

**Cuts**

* mass range cut (MASS, required)
* delta-R cut (DR, optional)
* delta-Eta cut (DETA, optional)
* delta-Phi cut (DPHI, optional)
* two body Pt cut (TBPT, optional)

Function cuts
-------------

Two body Pt
...........

Defines a minimum threshold in GeV for the origin object used for mass triggers.

**Syntax**

  .. code-block:: c

    TBPT_<<NAME>>
