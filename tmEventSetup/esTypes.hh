/**
 * @author      Takashi Matsushita
 * Created:     9 Nov 2015
 */

/** @file */
/** @todo nope */

#ifndef tmEventSetup_esTypes_hh
#define tmEventSetup_esTypes_hh

/*====================================================================*
 * declarations
 *====================================================================*/
/*-----------------------------------------------------------------*
 * headers
 *-----------------------------------------------------------------*/
/* nope */


namespace tmeventsetup
{
/*-----------------------------------------------------------------*
 * constants
 *-----------------------------------------------------------------*/
const int Undef = -9999; /**< undefined value for enums */

const char ET_THR[] = "ET"; /**< text for Et threshold */

const char PRECISION[] = "PRECISION";     /**< text for precision type */
const char PRECISION_DELTA[] = "Delta";   /**< text for delta precision type */
const char PRECISION_MASS[] = "Mass";     /**< text for mass precision type */
const char PRECISION_MASSPT[] = "MassPt"; /**< text for mass precision type */
const char PRECISION_MATH[] = "Math";     /**< text for math precision type */


/** type of cuts */
enum esCutType
{
  Threshold,        /**< Et/Pt threshold */
  Eta,              /**< eta cut */
  Phi,              /**< phi cut */
  Charge,           /**< charge cut */
  Quality,          /**< quality cut */
  Isolation,        /**< isolation cut */
  DeltaEta,         /**< delta eta cut for correlation function */
  DeltaPhi,         /**< delta phi cut for correlation function */
  DeltaR,           /**< delta R cut for correlation function */
  Mass,             /**< invariant mass cut for mass function */
  ChargeCorrelation,/**< charge correlation cut for comb function */
  nCutType
};

/** type of objects */
enum esObjectType
{
  Muon,   /**< muon */
  Egamma, /**< electron/gamma */
  Tau,    /**< tau */
  Jet,    /**< jet */
  ETT,    /**< total Et */
  HTT,    /**< total hadronic Et */
  ETM,    /**< missing Et */
  HTM,    /**< missing hadronic Et */
  EXT,    /**< extrnals */
  Precision,  /**< precision type */
  nObjectType
};

/** type of Function */
enum esFunctionType
{
  CombFunction = nObjectType, /**< combination */
  DistFunction,               /**< distance */
  MassFunction                /**< invariant mass */
};

/** list of comparison operator */
enum esComparisonOperator
{
  GE, /**< greater than or equal to */
  NE, /**< not equal to */
  EQ  /**< equal to */
};

/* type of combinations */
enum esCombinationType
{
  MuonMuonCombination,    /**< Muon-Muon combination */
  MuonEsumCombination,    /**< Muon-Esum combination */
  CaloMuonCombination,    /**< Calo-Muon combination */
  CaloCaloCombination,    /**< Calo-Calo combination */
  CaloEsumCombination,    /**< Calo-Esum combination */
  nCombinationType
};

/* type of conditinos */
enum esConditionType
{
  SingleMuon,   /**< single muon condition */
  DoubleMuon,   /**< double muon condition */
  TripleMuon,   /**< triple muon condition */
  QuadMuon,     /**< quad muon condition */
  SingleEgamma, /**< single e/gamma condition */
  DoubleEgamma, /**< double e/gamma condition */
  TripleEgamma, /**< triple e/gamma condition */
  QuadEgamma,   /**< quad e/gamma condition */
  SingleTau,    /**< single tau condition */
  DoubleTau,    /**< double tau condition */
  TripleTau,    /**< triple tau condition */
  QuadTau,      /**< quad tau condition */
  SingleJet,    /**< single jet condition */
  DoubleJet,    /**< double jet condition */
  TripleJet,    /**< triple jet condition */
  QuadJet,      /**< quad jet condition */
  TotalEt,      /**< total Et condition */
  TotalHt,      /**< total Ht condition */
  MissingEt,    /**< missing Et condition */
  MissingHt,    /**< missing Ht condition */
  Externals,    /**< external condition */
  MuonMuonCorrelation,    /**< Muon-Muon correlation condition */
  MuonEsumCorrelation,    /**< Muon-Esum correlation condition */
  CaloMuonCorrelation,    /**< Calo-Muon correlation condition */
  CaloCaloCorrelation,    /**< Calo-Calo correlation condition */
  CaloEsumCorrelation,    /**< Calo-Esum correlation condition */
  InvariantMass,          /**< Invariant mass condition */
  nConditionType
};

/** type of scales */
enum esScaleType
{
  EtScale,          /**< Et scale */
  EtaScale,         /**< eta scale */
  PhiScale,         /**< phi scale */
  DeltaPrecision,   /**< precision for delta */
  MassPrecision,    /**< precision for mass */
  MassPtPrecision,  /**< precision for mass pt */
  MathPrecision,    /**< precision for math */
};

} // namespace tmeventsetup
#endif // tmEventSetup_esTypes_hh
/* eof */
