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
const int Undef = -9999; /**< undefined value for enums -- seriously? */

const char ET_THR[] = "ET"; /**< text for Et threshold */

const char COUNT[] = "COUNT";     /**< text for Minimum Bias HF type  */

const char PRECISION[] = "PRECISION";     /**< text for precision type */
const char PRECISION_DELTA[] = "Delta";   /**< text for delta precision type */
const char PRECISION_OVRM_DELTA[] = "OvRmDelta";   /**< text for delta precision for overlap removal type */
const char PRECISION_MASS[] = "Mass";     /**< text for mass precision type */
const char PRECISION_MASSPT[] = "MassPt"; /**< text for mass precision type */
const char PRECISION_MATH[] = "Math";     /**< text for math precision type */
const char PRECISION_TBPT[] = "TwoBodyPt"; /**< text for two body pt precision type */
const char PRECISION_TBPT_MATH[] = "TwoBodyPtMath"; /**< text for two body pt math precision type */

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
  Count,            /**< number of counts */
  Slice,            /**< object collection slice */
  TwoBodyPt,        /**< two body Pt for mass_inv/mass_trv function */
  OvRmDeltaEta, /**< overlap removal with delta eta */
  OvRmDeltaPhi, /**< overlap removal with delta phi */
  OvRmDeltaR,   /**< overlap removal with delta R */
  nCutType
};

/** type of objects */
enum esObjectType
{
  Muon      = 0,  /**< muon */
  Egamma    = 1,  /**< electron/gamma */
  Tau       = 2,  /**< tau */
  Jet       = 3,  /**< jet */
  ETT       = 4,  /**< total Et */
  HTT       = 5,  /**< total hadronic Et */
  ETM       = 6,  /**< missing Et */
  HTM       = 7,  /**< missing hadronic Et */
  EXT       = 8,  /**< extrnals */
  Precision = 9,  /**< precision type */
  MBT0HFP   = 13, /**< Minimum Bias HF+ threshold 0 */
  MBT1HFP   = 14, /**< Minimum Bias HF+ threshold 1 */
  MBT0HFM   = 15, /**< Minimum Bias HF- threshold 0 */
  MBT1HFM   = 16, /**< Minimum Bias HF- threshold 1 */
  ETTEM     = 17, /**< total Et with ECAL only */
  ETMHF     = 18, /**< missing Et with HF */
  TOWERCOUNT = 19, /**< missing Et with HF */
  nObjectType = 17
};

/** type of Function */
enum esFunctionType
{
  CombFunction = 10, /**< combination */
  DistFunction = 11, /**< distance */
  MassFunction = 12,  /**< invariant mass(alias) */
  InvariantMassFunction = 20, /**< invariant mass */
  TransverseMassFunction = 21, /**< transverse mass */
  SingleOvRmFunction = 22, /**< single object with overlap removal */
  DoubleOvRmFunction = 23, /**< double combination with overlap removal */
  TripleOvRmFunction = 24, /**< triple combination with overlap removal */
  QuadOvRmFunction = 25, /**< quad combination with overlap removal */
  DistOvRmFunction = 26, /**< distance with overlap removal */
  InvariantMassOvRmFunction = 27, /**< invariant mass with overlap removal */
  TransverseMassOvRmFunction = 28 /**< transverse mass with overlap removal */
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
  TransverseMass,         /**< Transverse mass condition */
  MinBiasHFP0,  /**< Minimum Bias HF+ threshold 0 */
  MinBiasHFP1,  /**< Minimum Bias HF+ threshold 1 */
  MinBiasHFM0,  /**< Minimum Bias HF+ threshold 0 */
  MinBiasHFM1,  /**< Minimum Bias HF+ threshold 1 */
  TotalEtEM,    /**< total Et with ECAL only condition */
  MissingEtHF,  /**< missing Et with HF condition */
  TowerCount,   /**< Calo tower count */
  SingleEgammaOvRm, /**< single e/gamma condition with overlap removal */
  DoubleEgammaOvRm, /**< double e/gamma condition with overlap removal */
  TripleEgammaOvRm, /**< triple e/gamma condition with overlap removal */
  QuadEgammaOvRm,   /**< quad e/gamma condition with overlap removal */
  SingleTauOvRm,    /**< single tau condition with overlap removal */
  DoubleTauOvRm,    /**< double tau condition with overlap removal */
  TripleTauOvRm,    /**< triple tau condition with overlap removal */
  QuadTauOvRm,      /**< quad tau condition with overlap removal */
  SingleJetOvRm,    /**< single jet condition with overlap removal */
  DoubleJetOvRm,    /**< double jet condition with overlap removal */
  TripleJetOvRm,    /**< triple jet condition with overlap removal */
  QuadJetOvRm,      /**< quad jet condition with overlap removal */
  CaloCaloCorrelationOvRm,    /**< Calo-Calo correlation condition with overlap removal */
  InvariantMassOvRm,          /**< Invariant mass condition with overlap removal */
  TransverseMassOvRm,         /**< Transverse mass condition with overlap removal */
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
  CountScale,       /**< Count scale */
  TwoBodyPtPrecision, /**< precision for two body pt */
  TwoBodyPtMathPrecision, /**< precision for two body math */
  OvRmDeltaPrecision   /**< precision for overlap removal delta */
};

} // namespace tmeventsetup
#endif // tmEventSetup_esTypes_hh
/* eof */
