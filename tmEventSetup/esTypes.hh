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

// NOTE: enumeration values are stored to the offline frontier database

/** type of cuts */
enum esCutType
{
  Threshold    = 0,  /**< Et/Pt threshold */
  Eta          = 1,  /**< eta cut */
  Phi          = 2,  /**< phi cut */
  Charge       = 3,  /**< charge cut */
  Quality      = 4,  /**< quality cut */
  Isolation    = 5,  /**< isolation cut */
  DeltaEta     = 6,  /**< delta eta cut for correlation function */
  DeltaPhi     = 7,  /**< delta phi cut for correlation function */
  DeltaR       = 8,  /**< delta R cut for correlation function */
  Mass         = 9,  /**< invariant mass cut for mass function */
  ChargeCorrelation = 10,/**< charge correlation cut for comb function */
  Count        = 11, /**< number of counts */
  Slice        = 12, /**< object collection slice */
  TwoBodyPt    = 13, /**< two body Pt for mass_inv/mass_trv function */
  OvRmDeltaEta = 14, /**< overlap removal with delta eta */
  OvRmDeltaPhi = 15, /**< overlap removal with delta phi */
  OvRmDeltaR   = 16,   /**< overlap removal with delta R */
  UnconstraintPt = 18, /**< unconstraint pt cut */
  ImpactParameter = 19, /**< impact parameter cut */
  nCutType     = 120
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
  TOWERCOUNT = 19, /**< calo tower count */
  ASYMET = 26, /**< asymmetry ET */
  ASYMHT = 27, /**< asymmetry HT */
  ASYMETHF = 28, /**< asymmetry ET with HF */
  ASYMHTHF = 29, /**< asymmetry HT with HF */
  CENT0 = 30,
  CENT1 = 31,
  CENT2 = 32,
  CENT3 = 33,
  CENT4 = 34,
  CENT5 = 35,
  CENT6 = 36,
  CENT7 = 37,
  nObjectType = 29
};

/** type of Function */
enum esFunctionType
{
  CombFunction = 10, /**< combination */
  DistFunction = 11, /**< distance */
  MassFunction = 12,  /**< invariant mass(alias) */
  InvariantMassFunction = 20, /**< invariant mass */
  TransverseMassFunction = 21, /**< transverse mass */
  CombOvRmFunction = 22, /**< object combinations with overlap removal */
  DistOvRmFunction = 23, /**< distance with overlap removal */
  InvariantMassOvRmFunction = 24, /**< invariant mass with overlap removal */
  TransverseMassOvRmFunction = 25, /**< transverse mass with overlap removal */
  nFunctionType = 9
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
  SingleMuon     = 0, /**< single muon condition */
  DoubleMuon     = 1, /**< double muon condition */
  TripleMuon     = 2, /**< triple muon condition */
  QuadMuon       = 3, /**< quad muon condition */
  SingleEgamma   = 4, /**< single e/gamma condition */
  DoubleEgamma   = 5, /**< double e/gamma condition */
  TripleEgamma   = 6, /**< triple e/gamma condition */
  QuadEgamma     = 7, /**< quad e/gamma condition */
  SingleTau      = 8, /**< single tau condition */
  DoubleTau      = 9, /**< double tau condition */
  TripleTau      = 10, /**< triple tau condition */
  QuadTau        = 11, /**< quad tau condition */
  SingleJet      = 12, /**< single jet condition */
  DoubleJet      = 13, /**< double jet condition */
  TripleJet      = 14, /**< triple jet condition */
  QuadJet        = 15, /**< quad jet condition */
  TotalEt        = 16, /**< total Et condition */
  TotalHt        = 17, /**< total Ht condition */
  MissingEt      = 18, /**< missing Et condition */
  MissingHt      = 19, /**< missing Ht condition */
  Externals      = 20, /**< external condition */
  MuonMuonCorrelation = 21, /**< Muon-Muon correlation condition */
  MuonEsumCorrelation = 22, /**< Muon-Esum correlation condition */
  CaloMuonCorrelation = 23, /**< Calo-Muon correlation condition */
  CaloCaloCorrelation = 24, /**< Calo-Calo correlation condition */
  CaloEsumCorrelation = 25, /**< Calo-Esum correlation condition */
  InvariantMass  = 26, /**< Invariant mass condition */
  MinBiasHFP0    = 27, /**< Minimum Bias HF+ threshold 0 */
  MinBiasHFP1    = 28, /**< Minimum Bias HF+ threshold 1 */
  MinBiasHFM0    = 29, /**< Minimum Bias HF+ threshold 0 */
  MinBiasHFM1    = 30, /**< Minimum Bias HF+ threshold 1 */
  TotalEtEM      = 31, /**< total Et with ECAL only condition */
  MissingEtHF    = 32, /**< missing Et with HF condition */
  TowerCount     = 33, /**< Calo tower count */
  TransverseMass = 34, /**< Transverse mass condition */
  SingleEgammaOvRm = 35, /**< single e/gamma condition with overlap removal */
  DoubleEgammaOvRm = 36, /**< double e/gamma condition with overlap removal */
  TripleEgammaOvRm = 37, /**< triple e/gamma condition with overlap removal */
  QuadEgammaOvRm = 38, /**< quad e/gamma condition with overlap removal */
  SingleTauOvRm  = 39, /**< single tau condition with overlap removal */
  DoubleTauOvRm  = 40, /**< double tau condition with overlap removal */
  TripleTauOvRm  = 41, /**< triple tau condition with overlap removal */
  QuadTauOvRm    = 42, /**< quad tau condition with overlap removal */
  SingleJetOvRm  = 43, /**< single jet condition with overlap removal */
  DoubleJetOvRm  = 44, /**< double jet condition with overlap removal */
  TripleJetOvRm  = 45, /**< triple jet condition with overlap removal */
  QuadJetOvRm    = 46, /**< quad jet condition with overlap removal */
  CaloCaloCorrelationOvRm = 47, /**< Calo-Calo correlation condition with overlap removal */
  InvariantMassOvRm = 48, /**< Invariant mass condition with overlap removal */
  TransverseMassOvRm = 49, /**< Transverse mass condition with overlap removal */
  AsymmetryEt = 50, /**< asymmetry Et */
  AsymmetryHt = 51, /**< asymmetry Ht */
  AsymmetryEtHF = 52, /**< asymmetry Et with HF */
  AsymmetryHtHF = 53, /**< asymmetry Ht with HF */
  Centrality0 = 54, /**< centrality 0 signal */
  Centrality1 = 55, /**< centrality 1 signal */
  Centrality2 = 56, /**< centrality 2 signal */
  Centrality3 = 57, /**< centrality 3 signal */
  Centrality4 = 58, /**< centrality 4 signal */
  Centrality5 = 59, /**< centrality 5 signal */
  Centrality6 = 60, /**< centrality 6 signal */
  Centrality7 = 61, /**< centrality 7 signal */
  nConditionType = 62
};

/** type of scales */
enum esScaleType
{
  EtScale         = 0, /**< Et scale */
  EtaScale        = 1, /**< eta scale */
  PhiScale        = 2, /**< phi scale */
  DeltaPrecision  = 3, /**< precision for delta */
  MassPrecision   = 4, /**< precision for mass */
  MassPtPrecision = 5, /**< precision for mass pt */
  MathPrecision   = 6, /**< precision for math */
  CountScale      = 7, /**< Count scale */
  TwoBodyPtPrecision = 8, /**< precision for two body pt */
  TwoBodyPtMathPrecision = 9, /**< precision for two body math */
  OvRmDeltaPrecision = 10, /**< precision for overlap removal delta */
  UnconstraintPtScale = 11, /**< unconstraint pt scale */
  nScaleType = 12
};

} // namespace tmeventsetup
#endif // tmEventSetup_esTypes_hh
/* eof */
