..

XML Format
==========

Menu
----

Example XML:

  .. code-block:: xml

    <!-- menu skeleton with meta data -->
    <tmxsd:menu xmlns:tmxsd="http://www.cern.ch/tmxsd/1.0.0"
                xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                xsi:schemaLocation="http://www.cern.ch/tmxsd/1.0.0 menu.xsd">
      <ancestor_id>0</ancestor_id><!-- deprecated -->
      <name>L1Menu_Sample</name>
      <uuid_menu>b365c54f-9324-4548-952b-97af2ae5425c</uuid_menu>
      <uuid_firmware>00000000-0000-0000-0000-000000000000</uuid_firmware>
      <global_tag/><!-- deprecated -->
      <grammar_version>0.5</grammar_version>
      <n_modules>0</n_modules>
      <is_valid>true</is_valid>
      <is_obsolete>false</is_obsolete>
      <comment>Test menu based on L1Menu_Collision2016_v10 with scales_2017_01_12.</comment>
      <!-- algorithm, scale_set, ext_signal_set, ... -->
    </tmxsd:menu>

Object requirement cuts
-----------------------

SLICE cut
.........

Example XML:

  .. code-block:: xml

    <!-- slice cut slicing object collections (encoded data) -->
    <cut>
      <name>MU-SLICE_LEADING</name>
      <object>MU</object>
      <type>SLICE</type>
      <minimum>+0.0000000000000000E+00</minimum><!-- not used -->
      <maximum>+0.0000000000000000E+00</maximum><!-- not used -->
      <data>0,0</data><!-- [lower, upper] index -->
    </cut>


Function cuts
-------------

DETA cut
........

Example XML:

  .. code-block:: xml

    <!-- delta-eta cut with range in dimensionless quantity (minimum and maximum) -->
    <cut>
      <name>DETA_MAX_2p1</name>
      <object></object>
      <type>DETA</type>
      <minimum>+0.0000000000000000E+00</minimum><!-- lower limit -->
      <maximum>+2.1000000000000000E+00</maximum><!-- upper limit -->
      <data/>
    </cut>

DPHI cut
........

Example XML:

  .. code-block:: xml

    <!-- delta-phi cut with range in radian (minimum and maximum) -->
    <cut>
      <name>DPHI_MIN_1p4</name>
      <object></object>
      <type>DPHI</type>
      <minimum>+1.4000000000000000E+00</minimum><!-- lower limit [rad] -->
      <maximum>+1.0000000000000000E+01</maximum><!-- upper limit [rad] -->
      <data/>
    </cut>

DR cut
......

Example XML:

  .. code-block:: xml

    <!-- delta-R cut with range in dimensionless quantity (minimum and maximum) -->
    <cut>
      <name>DR_MIN_1p4</name>
      <object></object>
      <type>DR</type>
      <minimum>+1.4000000000000000E+00</minimum><!-- lower limit -->
      <maximum>+1.1800000000000001E+01</maximum><!-- upper limit -->
      <data/>
    </cut>

ORMDETA cut
...........

Example XML:

  .. code-block:: xml

    <!-- overlap removal cut using delta-eta with range in dimensionless quantity (minimum and maximum) -->
    <cut>
      <name>ORMDETA_MAX_2p1</name>
      <object></object>
      <type>ORMDETA</type>
      <minimum>+0.0000000000000000E+00</minimum><!-- lower limit -->
      <maximum>+2.1000000000000000E+00</maximum><!-- upper limit -->
      <data/>
    </cut>

ORMDPHI cut
...........

Example XML:

  .. code-block:: xml

    <!-- overlap removal cut using delta-phi with range in radian (minimum and maximum) -->
    <cut>
      <name>ORMDPHI_MIN_1p4</name>
      <object></object>
      <type>ORMDPHI</type>
      <minimum>+1.4000000000000000E+00</minimum><!-- lower limit [rad] -->
      <maximum>+1.0000000000000000E+01</maximum><!-- upper limit [rad] -->
      <data/>
    </cut>

ORMDR cut
.........

Example XML:

  .. code-block:: xml

    <!-- overlap removal cut using delta-R with range in dimensionless quantity (minimum and maximum) -->
    <cut>
      <name>ORMDR_MIN_1p4</name>
      <object></object>
      <type>ORMDR</type>
      <minimum>+1.4000000000000000E+00</minimum><!-- lower limit -->
      <maximum>+1.1800000000000001E+01</maximum><!-- upper limit -->
      <data/>
    </cut>

Mass cut
........

Example XML:

  .. code-block:: xml

    <!-- mass cut with range in GeV (minimum and maximum) -->
    <cut>
      <name>MASS_MIN_400</name>
      <object></object>
      <type>MASS</type>
      <minimum>+4.0000000000000000E+02</minimum><!-- lower limit [GeV] -->
      <maximum>+1.5198200000000000E+05</maximum><!-- upper limit [GeV] -->
      <data/>
    </cut>

Two body Pt cut
...............

Example XML:

  .. code-block:: xml

    <!-- two body Pt cut with threshold in GeV (minimum) -->
    <cut>
      <name>TBPT_2p1</name>
      <object></object>
      <type>TBPT</type>
      <minimum>+2.1000000000000000E+00</minimum><!-- threshold [GeV] -->
      <maximum>+0.0000000000000000E+00</maximum><!-- not used -->
      <data/>
    </cut>
