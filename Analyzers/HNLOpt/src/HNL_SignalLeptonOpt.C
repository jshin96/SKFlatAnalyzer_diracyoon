#include "HNL_SignalLeptonOpt.h"

void HNL_SignalLeptonOpt::initializeAnalyzer(){

  // All default settings like trigger/ PD/ BJet are decalred in HNL_LeptonCore::initializeAnalyzer to make them consistent for all HNL codes

  HNL_LeptonCore::initializeAnalyzer();
  cout << "SetupMVAReader " << endl;
  SetupMVAReader();


  RunHighPt= HasFlag("RunHighPt");
  RunEE = HasFlag("RunEE");
  
}


void HNL_SignalLeptonOpt::executeEvent(){
  
  
  if(!IsData)  gens = GetGens();

  AnalyzerParameter param_signal = HNL_LeptonCore::InitialiseHNLParameter("HNLOpt","_UL");
  
  
  //cout << "########################################################" << endl;
  bool opt_IDEl=RunEE;

  std::vector<Electron>   ElectronCollV = GetElectrons(param_signal.Electron_Veto_ID, 10., 2.5);
  std::vector<Muon>       MuonCollV     = GetMuons    (param_signal.Muon_Veto_ID, 5., 2.4);
  if(opt_IDEl){

    if(!SameCharge(ElectronCollV)) return;
    if(MuonCollV.size() > 0) return;

    /// TEMP
    if(RunHighPt){
      if(ElectronCollV[1].Pt() <20) return;
    }

    vector<TString> ElectronsIDs;

    vector<TString> vTrig = {"LooseTrig_"};//"LooseTrig_"};//,"TightTrig_"};
    vector<TString> vConv = {"ConvBConvEC_"};//,"ConvBConvEC_","ConvEC_"};
    vector<TString> vCC = {"CCBCCEC_","CCEC_"};//,"CCEC_",""};

    
    vector<TString> vMVANPBB1;
    vector<TString> vMVANPEB1;
    vector<TString> vMVANPEC1;

    vector<TString> vMVANPBB2;
    vector<TString> vMVANPEB2;
    vector<TString> vMVANPEC2;

    vector<TString> vMVACFBB;
    vector<TString> vMVACFEC;


    if(HasFlag("ELID_NP1")){
      
      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();
	    
      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();
      
      vMVACFBB.clear();
      vMVACFEC.clear();

      vMVACFBB = {"CFMVABB0p86_"};
      vMVACFEC = {"CFMVAEC0p78_"};

      vMVANPBB1 = {"NPMVABB1neg1_"};
      vMVANPEB1 = {"NPMVAEB1neg1_"};
      vMVANPEC1 = {"NPMVAEC1neg1_"};
      
      
      int nMVA=8;

      for(int imva=0 ; imva < nMVA ; imva++){
	double mva_d=  -1. + double(imva)*.1;
	TString mvaTS= DoubleToString(mva_d);
	vMVANPBB2.push_back("NPMVABB2"+mvaTS+"_");
	vMVANPEB2.push_back("NPMVAEB2"+mvaTS+"_");
	vMVANPEC2.push_back("NPMVAEC2"+mvaTS+"_");
      }
      for(int imva=1 ; imva < 25 ; imva++){
	double mva_d=   -0.3 + double(imva)*.05;
	TString mvaTS= DoubleToString(mva_d);
	vMVANPBB2.push_back("NPMVABB2"+mvaTS+"_");
	vMVANPEB2.push_back("NPMVAEB2"+mvaTS+"_");
	vMVANPEC2.push_back("NPMVAEC2"+mvaTS+"_");
      }
    }
    else if(HasFlag("ELID_NP2")){


      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();

      vMVACFBB = {"CFMVABB0p86_"};
      vMVACFEC= {"CFMVAEC0p78_"};

      vMVANPBB1={"NPMVABB1neg1_"};
      vMVANPEB1={"NPMVAEB1neg1_"};
      vMVANPEC1={"NPMVAEC1neg1_"};

      vMVANPEC2.push_back("NPMVAEC20_");

      int nMVA=5;
      for(int imva=0 ; imva < nMVA ; imva++){
        double mva_d=  -1. + double(imva)*.2;
        TString mvaTS= DoubleToString(mva_d);
        vMVANPBB2.push_back("NPMVABB2"+mvaTS+"_");
        vMVANPEB2.push_back("NPMVAEB2"+mvaTS+"_");
      }
      for(int imva=1 ; imva < 25 ; imva++){
        double mva_d=   -0.2 + double(imva)*.025;
        TString mvaTS= DoubleToString(mva_d);
        vMVANPBB2.push_back("NPMVABB2"+mvaTS+"_");
        vMVANPEB2.push_back("NPMVAEB2"+mvaTS+"_");
      }
      for(int imva=1 ; imva < 8 ; imva++){
        double mva_d=   0.4 + double(imva)*.05;
        TString mvaTS= DoubleToString(mva_d);
        vMVANPBB2.push_back("NPMVABB2"+mvaTS+"_");
        vMVANPEB2.push_back("NPMVAEB2"+mvaTS+"_");
      }

      
    }
    //HNLOpt_UL_ElOpt_HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p85_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1

    else if(HasFlag("ELID_NP3")){

      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();


      vMVACFBB = {"CFMVABB0p86_"};
      vMVACFEC= {"CFMVAEC0p78_"};

      vMVANPBB1={"NPMVABB1neg1_"};
      vMVANPEB1={"NPMVAEB1neg1_"};
      vMVANPEC1={"NPMVAEC1neg1_"};

      vMVANPBB2.push_back("NPMVABB20p15_");
      vMVANPEB2.push_back("NPMVAEB20_");
      

      int nMVA=95;
      for(int imva=0 ; imva < nMVA ; imva++){
        double mva_d=  -1. + double(imva)*.02;
        TString mvaTS= DoubleToString(mva_d);
	vMVANPEC2.push_back("NPMVAEC2"+mvaTS+"_");      
      }
    }

    else if(HasFlag("ELID_NP4")){

      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();
      
      //vMVACFBB = {"CFMVABB0p86_"};
      vMVACFBB = {"CFMVABB0p70_"};   
      vMVACFEC= {"CFMVAEC0p78_"};

      //vMVANPBB1={"NPMVABB1neg1_"};
      //vMVANPEB1={"NPMVAEB1neg1_"};
      //vMVANPEC1={"NPMVAEC1neg1_"};

      vMVANPBB2.push_back("NPMVABB20p15_");
      vMVANPEB2.push_back("NPMVAEB20_");
      vMVANPEC2.push_back("NPMVAEC20_");
      
      //int nMVA=95;

      for(int imva=0 ; imva < 8 ; imva++){
        double mva_d=  -1. + double(imva)*.1;
        TString mvaTS= DoubleToString(mva_d);
        vMVANPBB1.push_back("NPMVABB1"+mvaTS+"_");
        vMVANPEB1.push_back("NPMVAEB1"+mvaTS+"_");
        vMVANPEC1.push_back("NPMVAEC1"+mvaTS+"_");
      }
      for(int imva=1 ; imva < 41 ; imva++){
        double mva_d=  -0.3 + double(imva)*.02;
        TString mvaTS= DoubleToString(mva_d);
	vMVANPBB1.push_back("NPMVABB1"+mvaTS+"_");
	vMVANPEB1.push_back("NPMVAEB1"+mvaTS+"_");
	vMVANPEC1.push_back("NPMVAEC1"+mvaTS+"_");
      }

      for(int imva=1 ; imva < 7 ; imva++){
	double mva_d=  0.5 + double(imva)*.05;
        TString mvaTS= DoubleToString(mva_d);
        vMVANPBB1.push_back("NPMVABB1"+mvaTS+"_");
        vMVANPEB1.push_back("NPMVAEB1"+mvaTS+"_");
        vMVANPEC1.push_back("NPMVAEC1"+mvaTS+"_");
      }
    }


    /// V1 El
    if(HasFlag("ELID_CF")){


      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();

      int nMVACF=36;
      
      for(int imva=0 ; imva < nMVACF ; imva++){
	double mva_d=  -0.8 + double(imva)*.05;
	TString mvaTS= DoubleToString(mva_d);
	vMVACFBB.push_back("CFMVABB"+mvaTS+"_");
	vMVACFEC.push_back("CFMVAEC"+mvaTS+"_");
      }
    }
    else if(HasFlag("ELID_CF1")){

      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();


      vMVANPBB1={"NPMVABB1neg1_"};
      vMVANPEB1={"NPMVAEB1neg1_"};
      vMVANPEC1={"NPMVAEC1neg1_"};


      vMVANPBB2 = {"NPMVABB20p15_"};
      vMVANPEB2 = {"NPMVAEB20_"};
      vMVANPEC2 = {"NPMVAEC20_"};



      int nMVACF=50;

      vMVACFBB = {"CFMVABB0p7_"};

      for(int imva=0 ; imva < nMVACF ; imva++){
	double mva_d=  0. + double(imva)*.02;
	TString mvaTS= DoubleToString(mva_d);
        vMVACFEC.push_back("CFMVAEC"+mvaTS+"_");
      }      
    }
    else if(HasFlag("ELID_CF2")){


      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();


      vMVANPBB1={"NPMVABB1neg1_"};
      vMVANPEB1={"NPMVAEB1neg1_"};
      vMVANPEC1={"NPMVAEC1neg1_"};


      vMVANPBB2 = {"NPMVABB20p15_"};
      vMVANPEB2 = {"NPMVAEB20_"};
      vMVANPEC2 = {"NPMVAEC20_"};

      int nMVACF=50;
      
      vMVACFEC = {"CFMVAEC0p85_"};

      for(int imva=0 ; imva < nMVACF ; imva++){
        double mva_d=  0. + double(imva)*.02;
        TString mvaTS= DoubleToString(mva_d);
        vMVACFBB.push_back("CFMVABB"+mvaTS+"_");
      }
    }





    //HNLOpt_UL_ElOpt_HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p85_NPMVABB20p15_NPMVAEB20_NPMVAEC2neg0p04_DXYv1

    vector<TString> vMVAConvBB1;
    vector<TString> vMVAConvEC1;

    vector<TString> vMVAConvBB2;
    vector<TString> vMVAConvEC2;

    if(HasFlag("ELID_Conv")){

      vMVANPBB1.clear();
      vMVANPEB1.clear();
      vMVANPEC1.clear();

      vMVANPBB2.clear();
      vMVANPEB2.clear();
      vMVANPEC2.clear();

      vMVACFBB.clear();
      vMVACFEC.clear();


            
      vMVANPBB1={"NPMVABB1neg1_"};
      vMVANPEB1={"NPMVAEB1neg1_"};
      vMVANPEC1={"NPMVAEC1neg1_"};


      vMVANPBB2 = {"NPMVABB20p15_"};
      vMVANPEB2 = {"NPMVAEB20_"};
      vMVANPEC2 = {"NPMVAEC20_"};

      
      vMVACFBB = {"CFMVABB0p7_"};
      vMVACFEC= {"CFMVAEC0p8_"};
      
      int nMVACV=36;
      for(int imva=0 ; imva < nMVACV ; imva++){
	double mva_d=  -1. + double(imva)*.05;
	TString mvaTS= DoubleToString(mva_d);
	vMVAConvBB2.push_back("CVMVABB2"+mvaTS+"_");
	vMVAConvEC2.push_back("CVMVAEC2"+mvaTS+"_");
	
      }
    }


    //HNLOpt_UL_ElOpt_HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p85_NPMVABB20p5_NPMVAEB20p5_NPMVAEC20p5__DXYv1
    
    //    for(int i1 = 0; i1 <  vMVANPBB2.size(); i1++){
    /*
    for(auto i2 : vMVACFBB) {
      for(auto i3 : vMVACFEC) {
	ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_LooseTrig_"+i2+i3+"DXYv1"); 
	ElectronsIDs.push_back("HNLUL_MVAWP90_ISOB0p1_ISOEC0p1_ConvBConvEC_LooseTrig_"+i2+i3+"DXYv1"); 
	ElectronsIDs.push_back("HNLUL_MVAWP80_ISOB0p1_ISOEC0p1_ConvBConvEC_LooseTrig_"+i2+i3+"DXYv1"); 
	ElectronsIDs.push_back("HNLUL_MVAWP90_ISOB0p1_ISOEC0p1_ConvBConvEC_LooseTrig_DXYv1");
	ElectronsIDs.push_back("HNLUL_MVAWP90_ISOB0p1_ISOEC0p1_ConvBConvEC_LooseTrig");
	ElectronsIDs.push_back("HNLUL_MVAWP90_ISOB0p1_ISOEC0p1_LooseTrig");
      }
      }*/

    vector<TString> vIsoB  = {"ISOB0p05","ISOB0p06","ISOB0p07","ISOB0p08","ISOB0p09","ISOB0p1","ISOB0p11","ISOB0p12","ISOB0p15"};
    vector<TString> vIsoEC = {"ISOEC0p05","ISOEC0p06","ISOEC0p07","ISOEC0p08","ISOEC0p09","ISOEC0p1","ISOEC0p11","ISOEC0p12","ISOEC0p15"};

    if(HasFlag("ELID_NP1")){
      for(auto i1 : vMVACFBB) {
	for(auto i2 : vMVACFEC) {
	  
	  for(unsigned int i3 = 0 ; i3 < vMVANPBB2.size(); i3++){
	    for(auto i4 : vMVANPEC2) {
	      ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+vMVANPBB2[i3]+vMVANPEB2[i3]+i4+"DXYv1");
	      
	    }
	  }
	}
      }
    }
    if(HasFlag("ELID_NP2")){
      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {

          for(auto i3 : vMVANPBB2){
	    for(auto i4 : vMVANPEB2){
	      for(auto i5 : vMVANPEC2) {
		ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+i5+"DXYv1");
		
	      }
	    }
          }
        }
      }
    }
    if(HasFlag("ELID_NP3")){
      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {

          for(auto i3 : vMVANPBB2){
            for(auto i4 : vMVANPEB2){
              for(auto i5 : vMVANPEC2) {
		ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+i5+"DXYv1");

              }
            }
          }
	}
      }
    }
    if(HasFlag("ELID_NP4")){
      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {

          for(int i3=0; i3 < vMVANPBB1.size(); i3++){
	    for(auto i4 : vMVANPEC1) {
	      ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_" + i1+i2+vMVANPBB1[i3]+vMVANPEB1[i3]+i4 + "NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");
	      
            }
          }
        }
      }
    }

    if(HasFlag("ELID_CF1") || HasFlag("ELID_CF2") ){
      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {
          for(auto i3 : vMVANPBB2){
            for(auto i4 : vMVANPEB2){
              for(auto i5 : vMVANPEC2) {
                ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+i5+"DXYv1");

              }
            }
          }
        }
      }
    }

    if(HasFlag("ELID_Conv")){
      for(auto i1 : vMVACFBB) {
	for(auto i2 : vMVACFEC) {
          for(auto i3 : vMVANPBB2){
            for(auto i4 : vMVANPEB2){
              for(auto i5 : vMVANPEC2) {
		ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+i5+"DXYv1");
		
		for(auto i6 : vMVAConvBB2){                                                                                                                                                                         
		  for(auto i7 : vMVAConvEC2){        
		    ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CVMVABB1neg1_CVMVAEC1neg1_"+i1+i2+i3+i4+i5+i6+i7+"DXYv1");
		    
		  }
		}
              }
            }
          }
        }
      }
    }


    if(HasFlag("ELID_Iso")){
      
      for(auto i5 : vIsoB){ 
	for(auto i6 : vIsoEC){ 
	  ElectronsIDs.push_back("HNLUL_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");
	  ElectronsIDs.push_back("HNLUL_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv2");
	  ElectronsIDs.push_back("HNLUL_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv3");
	  ElectronsIDs.push_back("HNLUL_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv4");
	  ElectronsIDs.push_back("HNLUL_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20");
	  
	  ElectronsIDs.push_back("HNLUL_MVABWP80MVAECWP90_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");
	  ElectronsIDs.push_back("HNLUL_MVABWP90MVAECWP80_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");
	  ElectronsIDs.push_back("HNLUL_MVAWP80_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");
	  ElectronsIDs.push_back("HNLUL_MVAWP90_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_CFMVABB0p7_CFMVAEC0p8_NPMVABB20p15_NPMVAEB20_NPMVAEC20_DXYv1");

          ElectronsIDs.push_back("HNLUL_MVABWP80MVAECWP90_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_CFMVABB0p7_CFMVAEC0p8_DXYv1");
          ElectronsIDs.push_back("HNLUL_MVABWP90MVAECWP80_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_CFMVABB0p7_CFMVAEC0p8_DXYv1");
          ElectronsIDs.push_back("HNLUL_MVAWP80_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_CFMVABB0p7_CFMVAEC0p8_DXYv1");
          ElectronsIDs.push_back("HNLUL_MVAWP90_"+i5+"_"+i6+"_ConvBConvEC_LooseTrig_CFMVABB0p7_CFMVAEC0p8_NPMVAEC20_DXYv1");
	  

	}
      }
    }


    for(auto iTrig : vTrig){
      for(auto iConv : vConv){
	for(auto iCC : vCC){
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"POGT_DXYv1");
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"POGM_DXYv1");
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"MVAWP90_ISOB0p1_ISOEC0p1_DXYv1"); 
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"MVAWP80_ISOB0p1_ISOEC0p1_DXYv1"); 
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"POGTNoIso_ISOB0p1_ISOEC0p1_DXYv1");
	  ElectronsIDs.push_back("HNLUL_"+iTrig+iConv+iCC+"POGMNoIso_ISOB0p1_ISOEC0p1_DXYv1");
	}
      }
    }


    ElectronsIDs.push_back("HNTight_17028");
    ElectronsIDs.push_back("HNTightV2");
    ElectronsIDs.push_back("passPOGTight");
    ElectronsIDs.push_back("passPOGMedium");
    ElectronsIDs.push_back("passMediumID");
    ElectronsIDs.push_back("passTightID");
    ElectronsIDs.push_back("passHEEPID");
    ElectronsIDs.push_back("passMVAID_noIso_WP90Opt");
    ElectronsIDs.push_back("passMVAID_noIso_WP80Opt");
    ElectronsIDs.push_back("passMVAID_noIso_WP80");
    ElectronsIDs.push_back("passMVAID_Iso_WP80");
    ElectronsIDs.push_back("passMVAID_Iso_WP90");
    ElectronsIDs.push_back("HNHEEPID");
    ElectronsIDs.push_back("SUSYTight");
    ElectronsIDs.push_back("HN2016MVA");
    ElectronsIDs.push_back("HN2016MVA2");
    ElectronsIDs.push_back("HN2016POGCC");
    ElectronsIDs.push_back("HNOpt");
    ElectronsIDs.push_back("HNTight2016Update");
    //ElectronsIDs.push_back("HNTight_Opt_ECCC_Iso1_dxy1_dz1");
    //ElectronsIDs.push_back("");
    //ElectronsIDs.push_back("");
    ElectronsIDs.push_back("HNTight_ULInProgress");
    

    for(auto id : ElectronsIDs){

      if (!id.Contains("HNLUL")){

        param_signal.Name = param_signal.DefName + "_"+ id;
        param_signal.SRConfig  = "";

        param_signal.Electron_Tight_ID=id;
        param_signal.Electron_FR_ID = id;
      }
      else{

        param_signal.Name = param_signal.DefName + "_ElOpt_"+ id;
        param_signal.SRConfig  = "";

        param_signal.Electron_Tight_ID="ElOpt_"+id;
        param_signal.Electron_FR_ID = "ElOptLoose_"+id;

      }
      param_signal.Muon_Tight_ID = "HNTightV2";
      param_signal.Muon_FR_ID = "HNLooseV1";


      //cout << param_signal.Name << endl;
      RunULAnalysis(param_signal,ElectronCollV,MuonCollV);

      param_signal.Name = param_signal.DefName;
      param_signal.SRConfig  = "";
    }
  }



  


  bool opt_IDMu=!RunEE;
  if(opt_IDMu){

    vector<TString> MuonsIDs;

    if(!SameCharge(MuonCollV)) return;
    if(ElectronCollV.size() > 0) return;

    /// TEMP                                                                                                                               
    //if(HasFlag("PtBin1") && MuonCollV[1].Pt() <20) return;
    //if(HasFlag("PtBin2") && MuonCollV[1].Pt() <40) return;
    if(HasFlag("HighPt") && MuonCollV[1].Pt() <60) return;
  

    vector<TString> IDBB;
    vector<TString> IDEC;

    if(HasFlag("MuID_NP")){

      if(HasFlag("HighPt")){
	
	if(HasFlag("BB")){
	  
	  IDEC = {"POGECT_ISOEC0p15_"};
	  TString BBID="NPMVABB1neg1_NPMVABB2neg1_NPMVABB3neg1_NPMVABB4";
	  for(unsigned int imva=0 ; imva < 56 ; imva++){
	    double mva_d= 0.4 + double(imva)*0.01;
	    TString mvaTS= DoubleToString(mva_d);
	    IDBB.push_back(BBID+mvaTS);
	  }
	}
	if(HasFlag("EC")){

          IDBB = {"POGBT_ISOB0p15_"};
          TString ECID="NPMVAEC1neg1_NPMVAEC2neg1_NPMVAEC3neg1_NPMVAEC4";
          for(unsigned int imva=0 ; imva < 56 ; imva++){
            double mva_d= 0.4 + double(imva)*0.01;
            TString mvaTS= DoubleToString(mva_d);
            IDEC.push_back(ECID+mvaTS);
          }
	}
      }
    }
    
    for(auto i1 : IDBB){
      for(auto i2 : IDEC){
	MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1");
	MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1_ISOB0p1_ISOEC0p1");
      }
    }
    

    vector<TString> vIsoB  = {"ISOB0p05","ISOB0p075","ISOB0p1","ISOB0p125","ISOB0p15","ISOB0p4"};
    vector<TString> vIsoEC = {"ISOEC0p05","ISOEC0p075","ISOEC0p1","ISOEC0p125","ISOEC0p15","ISOEC0p4"};

    if(HasFlag("MuID_Iso")){


      for(unsigned int ib = 0 ; ib < vIsoB.size(); ib++){
	for(unsigned int ie = 0 ; ie < vIsoEC.size(); ie++){
	  if(ie  > ib) continue;
	  TString iISOB = vIsoB[ib];
	  TString iISOEC = vIsoEC[ie];
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC);
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC);
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC);
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_MVAB0p75_MVAEC0p65_"+iISOB+"_"+iISOEC+"_DXYv5");
	  MuonsIDs.push_back("HNLUL_POGT_"+iISOB+"_"+iISOEC+"_DXYv5");
	  MuonsIDs.push_back("HNLUL_POGM_"+iISOB+"_"+iISOEC+"_DXYv5");
	}
      }
    }

    MuonsIDs.push_back("HNTight_17028");
    MuonsIDs.push_back("HNTightV2");

    MuonsIDs.push_back("HNTight_Iso05_dxy_01_ip_3"); ;
    MuonsIDs.push_back("HNTight_Iso05_dxy_01_ip_4");
    MuonsIDs.push_back("HNTight_Iso05_dxy_01_ip_999");
    MuonsIDs.push_back("HNTight_Iso05_dxy_02_ip_3");
    MuonsIDs.push_back("HNTight_Iso05_dxy_02_ip_4");
    MuonsIDs.push_back("HNTight_Iso05_dxy_02_ip_999");
    MuonsIDs.push_back("HNTight_Iso05_dxy_05_ip_3");
    MuonsIDs.push_back("HNTight_Iso05_dxy_05_ip_4");
    MuonsIDs.push_back("HNTight_Iso05_dxy_05_ip_999");


    MuonsIDs.push_back("HNTight_Iso06_dxy_01_ip_3");
    MuonsIDs.push_back("HNTight_Iso06_dxy_01_ip_4");
    MuonsIDs.push_back("HNTight_Iso06_dxy_01_ip_999");
    MuonsIDs.push_back("HNTight_Iso06_dxy_02_ip_3");
    MuonsIDs.push_back("HNTight_Iso06_dxy_02_ip_4");
    MuonsIDs.push_back("HNTight_Iso06_dxy_02_ip_999");
    MuonsIDs.push_back("HNTight_Iso06_dxy_05_ip_3");
    MuonsIDs.push_back("HNTight_Iso06_dxy_05_ip_4");
    MuonsIDs.push_back("HNTight_Iso06_dxy_05_ip_999");

    MuonsIDs.push_back("HNTight_Iso07_dxy_01_ip_3");
    MuonsIDs.push_back("HNTight_Iso07_dxy_01_ip_4");
    MuonsIDs.push_back("HNTight_Iso07_dxy_01_ip_999");
    MuonsIDs.push_back("HNTight_Iso07_dxy_02_ip_3");
    MuonsIDs.push_back("HNTight_Iso07_dxy_02_ip_4");
    MuonsIDs.push_back("HNTight_Iso07_dxy_02_ip_999");
    MuonsIDs.push_back("HNTight_Iso07_dxy_05_ip_3");
    MuonsIDs.push_back("HNTight_Iso07_dxy_05_ip_4");
    MuonsIDs.push_back("HNTight_Iso07_dxy_05_ip_999");

    MuonsIDs.push_back("HNTight_Iso08_dxy_01_ip_3");
    MuonsIDs.push_back("HNTight_Iso08_dxy_01_ip_4");
    MuonsIDs.push_back("HNTight_Iso08_dxy_01_ip_999");
    MuonsIDs.push_back("HNTight_Iso08_dxy_02_ip_3");
    MuonsIDs.push_back("HNTight_Iso08_dxy_02_ip_4");
    MuonsIDs.push_back("HNTight_Iso08_dxy_02_ip_999");
    MuonsIDs.push_back("HNTight_Iso08_dxy_05_ip_3");
    MuonsIDs.push_back("HNTight_Iso08_dxy_05_ip_4");
    MuonsIDs.push_back("HNTight_Iso08_dxy_05_ip_999");

    MuonsIDs.push_back("HNTight_Iso10_dxy_01_ip_3");
    MuonsIDs.push_back("HNTight_Iso10_dxy_01_ip_4");
    MuonsIDs.push_back("HNTight_Iso10_dxy_01_ip_999");
    MuonsIDs.push_back("HNTight_Iso10_dxy_02_ip_3");
    MuonsIDs.push_back("HNTight_Iso10_dxy_02_ip_4");
    MuonsIDs.push_back("HNTight_Iso10_dxy_02_ip_999");
    MuonsIDs.push_back("HNTight_Iso10_dxy_05_ip_3");
    MuonsIDs.push_back("HNTight_Iso10_dxy_05_ip_4");
    MuonsIDs.push_back("HNTight_Iso10_dxy_05_ip_999");


    MuonsIDs.push_back("HNTightPFIsoLoose");
    MuonsIDs.push_back("HNTightPFIsoMedium");
    MuonsIDs.push_back("HNTightPFIsoTight");
    MuonsIDs.push_back("HNTightPFIsoVeryTight");
    MuonsIDs.push_back("HNTightPFIsoVeryVeryTight");
    MuonsIDs.push_back("POGTightPFIsoLoose");
    MuonsIDs.push_back("POGTightPFIsoMedium");
    MuonsIDs.push_back("POGTightPFIsoTight");
    MuonsIDs.push_back("POGTightPFIsoVeryTight");
    MuonsIDs.push_back("POGTightPFIsoVeryVeryTight");

    for(auto id : MuonsIDs){

      if(id.Contains("HNLUL")){
        param_signal.Name = param_signal.DefName  + "_MuOpt_"+ id;
        param_signal.SRConfig  = "";
        param_signal.Muon_Tight_ID="MuOpt_"+id;
        param_signal.Muon_FR_ID = "MuOptLoose_"+id;
        param_signal.Electron_Tight_ID = "HNTightV2";
        param_signal.Electron_FR_ID = "HNLooseV4";

        RunULAnalysis(param_signal,ElectronCollV,MuonCollV);
      }
      else{
        param_signal.Name = param_signal.DefName  + id;
        param_signal.SRConfig  = "";

        param_signal.Muon_Tight_ID=id;
        param_signal.Muon_FR_ID = id;
        param_signal.Electron_Tight_ID = "HNTightV2";
        param_signal.Electron_FR_ID = "HNLooseV4";

        RunULAnalysis(param_signal,ElectronCollV,MuonCollV);

      }
    }

  }

  
  

  if(!IsData) RunSyst=false;
  if(RunSyst){
    TString param_signal_name = param_signal.Name;
    vector<AnalyzerParameter::Syst> SystList;// = GetSystList("Initial");

    for(auto isyst : SystList){
      param_signal.syst_ = AnalyzerParameter::Syst(isyst);
      
      param_signal.Name = "Syst_"+param_signal.GetSystType()+param_signal_name;
      param_signal.DefName = "Syst_"+param_signal.GetSystType()+param_signal_name;
      RunULAnalysis(param_signal,ElectronCollV,MuonCollV);
    }
  }    


  return ;
}

void HNL_SignalLeptonOpt::RunULAnalysis(AnalyzerParameter param, vector<Electron> ElectronCollV, vector<Muon> MuonCollV){

  if(run_Debug) cout << "HNL_SignalLeptonOpt::executeEvent " << endl;

  Event ev = GetEvent();
  double weight =SetupWeight(ev,param);
  
  if(MCSample.Contains("WJet")){
    vector<TString> vec = {"WJet"};
    double merge_weight = MergeMultiMC( vec, "" );
    weight*= merge_weight;
  }

  
  // HL ID

  TString el_ID = (RunFake) ?  param.Electron_FR_ID : param.Electron_Tight_ID ;
  TString mu_ID = (RunFake) ?  param.Muon_FR_ID :  param.Muon_Tight_ID ;

  double Min_Muon_Pt     = (RunFake) ? 3. : 5.;
  double Min_Electron_Pt = (RunFake) ? 7. : 10.;



  std::vector<Muon>       MuonCollTInit; 
  std::vector<Electron>   ElectronCollTInit ;

  for(auto ilep : ElectronCollV) {
    if(ilep.Pt() < Min_Electron_Pt) continue;
    if(ilep.PassID(el_ID)) ElectronCollTInit.push_back(ilep);
  }
  for(auto ilep : MuonCollV) {
    if(ilep.Pt() < Min_Muon_Pt) continue;
    if(ilep.PassID(mu_ID)) MuonCollTInit.push_back(ilep);
  }

  std::vector<Muon>       MuonCollT     = GetLepCollByRunType    ( MuonCollTInit,gens,param);
  std::vector<Electron>   ElectronCollT  =  GetLepCollByRunType   ( ElectronCollTInit,gens,param);
  
  //cout << "MuonCollT " << MuonCollT.size() << " ID = " << mu_ID << endl;
  
  
  std::vector<Lepton *> leps_veto  = MakeLeptonPointerVector(MuonCollV,ElectronCollV);

  std::vector<Tau>        TauColl        = GetTaus     (leps_veto,param.Tau_Veto_ID,20., 2.3);

  // Creat Lepton vector to have lepton blind codes 

  Particle METv = GetvMET("PuppiT1xyCorr",param); // returns MET with systematic correction



  std::vector<FatJet> fatjets_tmp  = GetFatJets(param, param.FatJet_ID, 200., 5.);
  std::vector<FatJet> FatjetColl   = SelectAK8Jetsv2(fatjets_tmp, 200., 2.7, true,  1., true, -999, true, 40., 130.,-999, ElectronCollV, MuonCollV);
  std::vector<Jet> jets_tmp     = GetJets   ( param, param.Jet_ID, 20., 5.);

  std::vector<Jet> JetCollLoose                    = SelectAK4Jets(jets_tmp,     15., 4.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, FatjetColl);
  std::vector<Jet> BJetCollNLV                    = SelectAK4Jets(jets_tmp,     20., 2.4, false,  0.4,0.8, "",   ElectronCollV,MuonCollV, FatjetColl);
  std::vector<Jet> JetColl                        = SelectAK4Jets(jets_tmp,     20., 2.7, true,  0.4,0.8, "",   ElectronCollV,MuonCollV, FatjetColl);
  std::vector<Jet> VBF_JetColl                    = SelectAK4Jets(jets_tmp,     30., 4.7, true,  0.4,0.8, "",  ElectronCollV,MuonCollV, FatjetColl);  
  

  JetTagging::Parameters param_jetsM = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Medium, JetTagging::incl, JetTagging::mujets);
  JetTagging::Parameters param_jetsT = JetTagging::Parameters(JetTagging::DeepJet, JetTagging::Tight, JetTagging::incl, JetTagging::mujets);

  std::vector<Jet> BJetColl    = SelectBJets(param,  BJetCollNLV, param_jetsM);
  double sf_btagM_NLV               = GetBJetSF(param, BJetCollNLV, param_jetsM);
  std::vector<Jet> BJetCollSR1    = SelectBJets(param,  BJetCollNLV, param_jetsT);
  double sf_btagSR1_NLV               = GetBJetSF(param, BJetCollNLV, param_jetsT);

  
  param.WriteOutVerbose=1; // Does not Fill Cutflow OR Region Plotter  

  if(param.Name.Contains("HNTightV2"))  param.WriteOutVerbose=0;

  
  if(!IsData )weight = weight*sf_btagM_NLV;
  if(!IsData && FatjetColl.size()==0)weight = weight*sf_btagM_NLV;
  if(!IsData && FatjetColl.size()>0)weight = weight*sf_btagSR1_NLV;


  if (IsSignal()){
    weight*=1/xsec;
  }
    
  /// Runs adapted SR functionality
  //FillSignalRegionForOpt(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV, TauColl, JetCollLoose, JetColl, VBF_JetColl,FatjetColl , BJetColl, ev,METv, param,weight);


  //if(IsData)cout << "Run data " << param.Name << endl;
  // Runs main SR functionality
  RunAllSignalRegions(Inclusive, ElectronCollT,ElectronCollV,MuonCollT,MuonCollV, TauColl, JetCollLoose, JetColl, VBF_JetColl,FatjetColl , BJetColl,BJetCollSR1, ev,METv, param,weight);


  return;
  

}



 


HNL_SignalLeptonOpt::HNL_SignalLeptonOpt(){

  TMVA::Tools::Instance();
  MVAReader = new TMVA::Reader();


}
 
HNL_SignalLeptonOpt::~HNL_SignalLeptonOpt(){

  delete MVAReader;
}




