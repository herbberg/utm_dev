..

Event Setup
===========

This module permits to parse and convert an XML trigger menu into an event setup
providing an auto generated set of conditions representing the algorithms
functionality.

The event setup interface is based on the following classes:

* esTriggerMenu (``tmeventsetup::esEventSetup``): represents a menus event setup.

Scales
------

Required object scales for 0.7.x

==========  ===========================
Object      Type
==========  ===========================
EG          ET
EG          ETA
EG          PHI
ETM         ET
ETM         PHI
ETMHF       ET
ETMHF       PHI
ETT         ET
ETTEM       ET
HTM         ET
HTM         PHI
HTT         ET
JET         ET
JET         ETA
JET         PHI
MBT0HFM     COUNT
MBT0HFP     COUNT
MBT1HFM     COUNT
MBT1HFP     COUNT
MU          ET
MU          ETA
MU          PHI
TAU         ET
TAU         ETA
TAU         PHI
TOWERCOUNT  COUNT
ASYM0X      COUNT
ASYM1X      COUNT
ASYM2X      COUNT
ASYM3X      COUNT
==========  ===========================

Required precision scales for 0.7.x (with example values from scale set
``scales_2018_04_18``)

=========  ===========================  ================
Object     Type                         n Bits (current)
=========  ===========================  ================
PRECISION  EG-EG-Delta                  3
PRECISION  EG-EG-DeltaOverlapRemoval    3
PRECISION  EG-EG-Mass                   1
PRECISION  EG-EG-MassPt                 1
PRECISION  EG-EG-Math                   3
PRECISION  EG-EG-TwoBodyPt              1
PRECISION  EG-EG-TwoBodyPtMath          3
PRECISION  EG-ETM-Delta                 3
PRECISION  EG-HTM-Delta                 3
PRECISION  EG-JET-Delta                 3
PRECISION  EG-JET-DeltaOverlapRemoval   3
PRECISION  EG-JET-Mass                  1
PRECISION  EG-JET-MassPt                1
PRECISION  EG-JET-Math                  3
PRECISION  EG-JET-TwoBodyPt             1
PRECISION  EG-JET-TwoBodyPtMath         3
PRECISION  EG-MU-Delta                  3
PRECISION  EG-MU-DeltaOverlapRemoval    3
PRECISION  EG-MU-Mass                   1
PRECISION  EG-MU-MassPt                 1
PRECISION  EG-MU-Math                   4
PRECISION  EG-MU-TwoBodyPt              1
PRECISION  EG-MU-TwoBodyPtMath          4
PRECISION  EG-TAU-Delta                 3
PRECISION  EG-TAU-DeltaOverlapRemoval   3
PRECISION  EG-TAU-Mass                  1
PRECISION  EG-TAU-MassPt                1
PRECISION  EG-TAU-Math                  3
PRECISION  EG-TAU-TwoBodyPt             1
PRECISION  EG-TAU-TwoBodyPtMath         3
PRECISION  JET-ETM-Delta                3
PRECISION  JET-HTM-Delta                3
PRECISION  JET-JET-Delta                3
PRECISION  JET-JET-DeltaOverlapRemoval  3
PRECISION  JET-JET-Mass                 1
PRECISION  JET-JET-MassPt               1
PRECISION  JET-JET-Math                 3
PRECISION  JET-JET-TwoBodyPt            1
PRECISION  JET-JET-TwoBodyPtMath        3
PRECISION  JET-MU-Delta                 3
PRECISION  JET-MU-DeltaOverlapRemoval   3
PRECISION  JET-MU-Mass                  1
PRECISION  JET-MU-MassPt                1
PRECISION  JET-MU-Math                  4
PRECISION  JET-MU-TwoBodyPt             1
PRECISION  JET-MU-TwoBodyPtMath         4
PRECISION  JET-TAU-Delta                3
PRECISION  JET-TAU-DeltaOverlapRemoval  3
PRECISION  JET-TAU-Mass                 1
PRECISION  JET-TAU-MassPt               1
PRECISION  JET-TAU-Math                 3
PRECISION  JET-TAU-TwoBodyPt            1
PRECISION  JET-TAU-TwoBodyPtMath        3
PRECISION  MU-ETM-Delta                 3
PRECISION  MU-HTM-Delta                 3
PRECISION  MU-MU-Delta                  3
PRECISION  MU-MU-DeltaOverlapRemoval    3
PRECISION  MU-MU-Mass                   1
PRECISION  MU-MU-MassPt                 1
PRECISION  MU-MU-Math                   4
PRECISION  MU-MU-TwoBodyPt              1
PRECISION  MU-MU-TwoBodyPtMath          4
PRECISION  TAU-ETM-Delta                3
PRECISION  TAU-HTM-Delta                3
PRECISION  TAU-MU-Delta                 3
PRECISION  TAU-MU-DeltaOverlapRemoval   3
PRECISION  TAU-MU-Mass                  1
PRECISION  TAU-MU-MassPt                1
PRECISION  TAU-MU-Math                  4
PRECISION  TAU-MU-TwoBodyPt             1
PRECISION  TAU-MU-TwoBodyPtMath         4
PRECISION  TAU-TAU-Delta                3
PRECISION  TAU-TAU-DeltaOverlapRemoval  3
PRECISION  TAU-TAU-Mass                 1
PRECISION  TAU-TAU-MassPt               1
PRECISION  TAU-TAU-Math                 3
PRECISION  TAU-TAU-TwoBodyPt            1
PRECISION  TAU-TAU-TwoBodyPtMath        3
=========  ===========================  ================
