#ifndef HNL_LeptonCore_h
#define HNL_LeptonCore_h

#include "TRandom.h"

#include "AnalyzerCore.h"

class HNL_LeptonCore : public AnalyzerCore {


 public:

  enum TheRunEra{
    y2016B,y2016C,y2016D,y2016E,y2016F,y2016G,y2016H,
    y2017B,y2017C,y2017D,y2017E,y2017F,
    y2018A,y2018B,y2018C,y2018D,
    y2016MC,
    y2017MC,
    y2018MC,
    yUL2016B,yUL2016C,yUL2016D,yUL2016E,yUL2016F,yUL2016Flate,yUL2016G,yUL2016H,
    yUL2017B,yUL2017C,yUL2017D,yUL2017E,yUL2017F,
    yUL2018A,yUL2018B,yUL2018C,yUL2018D,
    yUL2016MCAPV,
    yUL2016MCnonAPV,
    yUL2017MC,
  yUL2018MC
  };


  enum ChargeType
  {
    Inclusive=0,
    Plus=1,
    Minus=-1,
  };

  enum Channel
  {
    E=0,
    EE=1,
    EEE=2,
    EEEE=3,
    Mu=10,
    MuMu=11,
    MuMuMu=12,
    MuMuMuMu=13,
    EMu=15,
    EMuL=16,
    EMuLL=17,
    

  };
  enum SearchRegion
  {
    ChannelDepPresel=101,
    ChannelDepSR1=102,
    ChannelDepSR2=103, 
    ChannelDepSR3=104,
    ChannelDepFAILSR3=105,
    SR1=20,
    SR2=21,
    SR3=22,
    SR4=23,
    Presel=24,
    PreselSS=25,
    PreselOS=26,
    SR=27,
    sigmm=28,
    sigee=29,
    sigem=30,
    sigmm_17028=31,
    sigee_17028=32,
    sigem_17028=33,
    SR1Tau=34,
    SR2Tau,
    SR3Tau,  
    ChannelDepCR1,
    ChannelDepCR2,
    ChannelDepCR3,
    CR

  };

  enum LeptonType
  {
    MuonLep=100,
    ElectronLep=101,
    TauLep=102
  };

  HNL_LeptonCore();
  ~HNL_LeptonCore();


  //========== MAIN ANALYZER FUNCTIONS

  void initializeAnalyzer();

  AnalyzerParameter InitialiseHNLParameters( TString analysis_tag, vector<vector<TString> >  param_vec);
  AnalyzerParameter InitialiseHNLParameter(TString s_setup, TString tag);  


  // MET corr
  std::pair<double,double> METXYCorr_Met_MetPhi(double uncormet, double uncormet_phi, int runnb, TString year, bool isMC, int npv, bool isUL =false,bool ispuppi=false);


  //===== TRIGGER

  vector<AnalyzerParameter::Syst> GetSystList(TString SystType);
  double HNLZvtxSF(HNL_LeptonCore::Channel ch);
  bool PassPtTrigger(Event ev, vector<TString> triglist,std::vector<Lepton *> leps);
  void TriggerPrintOut(Event ev);
  bool PassTriggerSelection(HNL_LeptonCore::Channel channel,Event ev, std::vector<Lepton *> leps, TString selection, bool applt_ptcut=true);
  // ============= HELPER FUNCTIONS
  void PrintParam(AnalyzerParameter param);
  TString QToString(HNL_LeptonCore::ChargeType q);
 
  bool CheckLeptonFlavourForChannel(HNL_LeptonCore::Channel channel, std::vector<Lepton *> leps);


  double SetupWeight(Event ev, AnalyzerParameter param);
  double GetPtCutTrigger(TString trigname, int nlep, TString flavour);
  bool CheckSRStream(Event ev,HNL_LeptonCore::Channel channel_ID);
  bool PassTriggerAndCheckStream(bool apply_ptcut,vector<Lepton*> leps, Event ev, vector<TString> triglist);
  TString  DoubleElectronPD();
  TString  SingleElectronPD();
  TString  MuonEGPD();
  TString  DoubleMuonPD();
  bool HasLowMassMeson(std::vector<Lepton *> leps);

  ///=============== GET/SELECT OBJECT
  vector<Gen> GetGenLepronsSignal();
  TString GetProcess();
  TString GetChannelString(HNL_LeptonCore::Channel channel, HNL_LeptonCore::ChargeType  q=HNL_LeptonCore::ChargeType::Inclusive);
  std::vector<Jet> SelBJets(std::vector<Jet>& jetColl, JetTagging::Parameters jtp);
  Particle GetvMET(TString METType, AnalyzerParameter param);
  Particle GetvMET(TString METType);



  //================== KINEMATIC HELPER
  double M_T(Particle a, Particle b);
  float GetLT(std::vector<Lepton *> leps);
  double GetHT( std::vector<Jet> jets, std::vector<FatJet> fatjets);
  double GetST( std::vector<Electron> electrons, std::vector<Muon> muons, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev);
  double GetST( std::vector<Electron> electrons, std::vector<Muon> muons, std::vector<Jet> jets, std::vector<FatJet> fatjets, Particle met);
  double GetST( std::vector<Lepton *> leps, std::vector<Jet> jets, std::vector<FatJet> fatjets,  Event ev);
  double GetST( std::vector<Lepton *> leps, std::vector<Jet> jets, std::vector<FatJet> fatjets, Particle met);

  bool  ZmasslllWindowCheck(std::vector<Lepton *> leps);
  bool  ZmassOSWindowCheck(std::vector<Lepton *> leps);
  bool  ZmassOSSFWindowCheck(std::vector<Lepton *> leps, double mass_diff);


  float GetMassMinOSSF(std::vector<Lepton *> leps);
  float GetMassMinSSSF(std::vector<Lepton *> leps);
  int GetIndexNonMinOSSF(std::vector<Lepton *> leps);
  int GetIndexNonMinSSSF(std::vector<Lepton *> leps);
  int GetIndexNonBestZ(std::vector<Lepton *> leps,double mass_diff);

  float GetLLMass(std::vector<Lepton *> leps);
  float GetLLMass(std::vector<Muon> leps);
  float GetLLMass(std::vector<Electron> leps);

  float GetMassBestZ(std::vector<Lepton *> leps,  bool bestZ);
  double  GetMass(TString type , std::vector<Jet> jets, std::vector<FatJet> fatjets);

  //================                                                                                                                                                                                        
  //==== Functions                                                                                                                                                                                          
  //================                                                                                                                                                                                        
  TString GetPtLabel(Muon mu);
  TString GetEtaLabel(Muon mu);

  TString GetElType(Electron el, const std::vector<Gen>& gens);
  TString GetElTypeString(Electron el, const std::vector<Gen>& gens);
  TString GetElTypeTString(Electron el, const std::vector<Gen>& gens);
  TString GetLepTypeTString(const Lepton& lep, const std::vector<Gen>& gens);

  //==== LEPTON CHARGE                                                                                                                                                                                           
  bool SameCharge(vector<Electron> els, int ch=0);
  bool SameCharge(vector<Electron> els, vector<Muon> mus,  int ch=0);
  bool SameCharge(vector<Muon> mus, int ch=0);
  bool SameCharge(std::vector<Lepton *> leps, int ch=0);

  /// global var for user flags
  bool RunFake, RunCF,  RunConv, RunSyst;
  bool IsSkimmed;
  bool Signal;
  bool HEM1516 ,BeforeRun319077;
  bool DEBUG;
 
  bool DblEG_Channel;
  bool DblMuon_Channel;
  bool SglMuon_Channel;
  bool SglEG_Channel;
  bool MuonEG_Channel;
  
  bool IsCentral, RunFullAnalysis;
  TRandom3* rand_;
  

  // Trigger vectors used to store year dependant trigger lists
  
  vector<TString> TrigList_HNL_HighPtMu;
  vector<TString> TrigList_HNL_DblMu;
  vector<TString> TrigList_HNL_Mu;
  vector<TString> TrigList_Full_Mu;
  vector<TString> TrigList_POG_Mu;
  
  // EG
  vector<TString> TrigList_HNL_DblEG;
  vector<TString> TrigList_HNL_EG;
  vector<TString> TrigList_POG_EG;
  vector<TString> TrigList_HNL_HighPtEG;

  vector<TString> TrigList_Full_EG;
  
  // MUG
  vector<TString> TrigList_HNL_MuEG;
  vector<TString> TrigList_POG_MuEG;
  vector<TString> TrigList_Full_MuEG;
  
  
  // Lepton ID
  vector<TString> MuonVetoIDs;
  vector<TString> MuonLooseIDs;
  vector<TString> MuonTightIDs;
  vector<TString> ElectronVetoIDs;
  vector<TString> ElectronLooseIDs;
  // Fake rate file
  vector<TString> FakeRateIDs;
  vector<TString> ElectronTightIDs;


  bool run_Debug;
  // Lepton pT cut

  // obj vectors
  vector<Gen> gens;
  vector<FatJet> AllFatJets;

  double weight_Prefire, weight_Prefire_Up, weight_Prefire_Down;


  //==== My tool 

  // PLEP LOTS

  void FillAllMuonPlots(TString label , TString cut,  Muon mu, float w);
  void FillAllMuonPlots(TString label , TString cut,  std::vector<Muon> muons, float w);
  void FillAllElectronPlots(TString label , TString cut,  std::vector<Electron> els, float w);
  void FillAllElectronPlots(TString label , TString cut,  Electron el, float w);


  // === Cut flow                                                                                                                                                                                      
  void FillTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2);
  void FillFullTypeCutflow(TString histname, double weight, vector<TString> lables, TString label1, TString label2);


  void FillEventCutflowDef(TString dirname, TString histname, double weight, vector<TString> lables, TString label);
  void FillEventCutflowAll(TString dirname, TString histname, double weight, vector<TString> lables, TString label);


  void FillCutFlow(bool IsCentral, TString suffix, TString histname, double weight);
  void FillEventCutflow(HNL_LeptonCore::SearchRegion sr,float wt,TString cut,    TString label);
  void FillEventCutflowSR(TString analysis_dir_name,HNL_LeptonCore::SearchRegion sr, float event_weight, TString label);
  void FillEventCutflowPerMass(TString dirname,HNL_LeptonCore::SearchRegion sr, float event_weight, TString region_name,   TString label);




  //// ===============================  TOOLS =============================== ////                                                                                                                 
		   
  double GetFilterEffType1(TString SigProcess, int mass);
  double GetXsec(TString SigProcess, int mass);
 

  //// ===============================  SR PLOTS =============================== ////

  void Fill_RegionPlots(HNL_LeptonCore::Channel channel, int plotCR,TString label_1, TString label_2,  std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Lepton *> leps, Particle  met, double nvtx, double w);
  void Fill_RegionPlots(HNL_LeptonCore::Channel channel, int plotCR,TString label_1, TString label_2,  std::vector<Jet> jets, std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  std::vector<Lepton *> leps, Particle  met, double nvtx, double w);
  void FillAK8Plots(HNL_LeptonCore::Channel channel, int plotCR,TString label_1, TString label_2,  std::vector<Jet> jets, std::vector<Jet> jets_vbf, std::vector<FatJet> fatjets,  std::vector<Lepton *> leps, Particle  met, double nvtx, double w);


  void Fill_SigRegionPlots1(HNL_LeptonCore::Channel channel,TString label_1, TString label_2, TString label_3,  std::vector<Jet> jets, std::vector<FatJet> fatjets,  std::vector<Lepton *> leps, Particle  met, double nvtx, double w, double var1,  double var2, double var3, double var4, double var5, double var6, double var7);


  void Fill_SigRegionPlots3(HNL_LeptonCore::Channel channel, TString label_1, TString label_2, TString label_3,  std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Lepton *> leps , Particle  met, double nvtx, double w, double var1,  double var2, double var3, double var4, double var5, double var6, double var7, double var8, double var9, double var10, double var11);


  void Fill_SigRegionPlots4(HNL_LeptonCore::Channel channel,TString label_1,std::vector<Jet> jets, std::vector<FatJet> fatjets,  std::vector<Lepton *> leps, Particle  met, double nvtx, double w );


  bool  Fill_DefSigRegionPlots3(HNL_LeptonCore::Channel channel, TString label_sr, TString label_mass, TString label_anid,  std::vector<Jet> jets, std::vector<FatJet> fatjets,  std::vector<Lepton *> leps, Particle  met, double nvtx,  double w,  double var1,  double var2, double var3, double var4, double var5, double var6, double var7, double var8, double var9, double var10, double var11);
					       
					       
  void Fill_All_SignalRegion3(HNL_LeptonCore::Channel channel, TString signal_region, bool isdata, TString charge_s, TString label, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Lepton *> leps,  Particle _met,int _npv , double w , bool full);
					
  void Fill_All_SignalRegion1(HNL_LeptonCore::Channel channel, TString signal_region, bool isdata, TString charge_s, TString label, std::vector<Jet> jets, std::vector<FatJet> fatjets, std::vector<Lepton *> leps,  Particle _met,int _npv , double w , bool full);


  //// ===============================  GLOBAL VAR =============================== ////


  TH1D *hist_PUReweight;
  TH1D *hist_PUReweight_Up;
  TH1D *hist_PUReweight_Down;

  double weight_PU, weight_PU_Up, weight_PU_Down;



};



#endif

