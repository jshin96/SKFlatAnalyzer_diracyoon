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

    if(HasFlag("HighPt") && ElectronCollV[1].Pt() <60) return;

    
    vector<TString> ElectronsIDs;
 
    vector<TString> vTrig = {"LooseTrig_"};//"LooseTrig_"};//,"TightTrig_"};
    vector<TString> vConv = {"ConvBConvEC_"};//,"ConvBConvEC_","ConvEC_"};
    vector<TString> vCC = {"CCBCCEC_","CCEC_"};//,"CCEC_",""};

    vector<TString> vMVANPBB1,vMVANPEB1,vMVANPEC1;
    vector<TString> vMVANPBB2,vMVANPEB2,vMVANPEC2;

    vector<TString> vMVACFBB, vMVACFEC;

    vector<TString> vMVAConvBB1,vMVAConvEC1;
    vector<TString> vMVAConvBB2, vMVAConvEC2;

    

    if(HasFlag("ELID_NP")){
      
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

      vector<TString> vMVANPBB = {};
      vector<TString> vMVANPEC = {"NPMVAEC10_NPMVAEC20_"};
     
      
      vector<TString> vMVANPPt = {"NPMVAPt20_","NPMVAPt30_","NPMVAPt40_"};

      for(int imva=0 ; imva < 13 ; imva++){
	double mva_d=   -0.2 + double(imva)*.05;
	TString mvaTS= DoubleToString(mva_d);

	vector<TString> vMVANP1 = {"NPMVABB1neg0p5_NPMVAEB1neg0p5_", "NPMVABB1neg0p4_NPMVAEB1neg0p4_","NPMVABB1neg0p3_NPMVAEB1neg0p3_","NPMVABB1neg0p21_NPMVAEB1neg0p21_","NPMVABB1"+mvaTS+"_NPMVAEB1"+mvaTS+"_"};
	for(auto i1 : vMVANP1){
	  for(auto i : vMVANPPt){
	    vMVANPBB.push_back(i1+"NPMVABB2"+mvaTS+"_NPMVAEB2"+mvaTS+"_"+i);
	  }
	}
      }
      

      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {

          for(auto i3 : vMVANPBB) {
            for(auto i4 : vMVANPEC) {
              ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+"DXYv1" );
	      
            }
          }
        }
      }

      vector<TString> vMVANPBB2 = {"NPMVABB10p2_NPMVABB20p2_NPMVAEB10p2_NPMVAEB20p2_"};
      vector<TString> vMVANPEC2 = {};



      for(int imva=0 ; imva < 13 ; imva++){
        double mva_d=   -0.2 + double(imva)*.05;
        TString mvaTS= DoubleToString(mva_d);

        vector<TString> vMVANP1 = {"NPMVAEC1neg0p5_", "NPMVAEC1neg0p4_","NPMVAEC1neg0p3_","NPMVAEC1neg0p21_","NPMVAEC1"+mvaTS+"_"};
        for(auto i1 : vMVANP1){
          for(auto i : vMVANPPt){
            vMVANPEC2.push_back(i1+"NPMVAEC2"+mvaTS+"_"+i);
          }
        }
      }


      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {

          for(auto i3 : vMVANPBB2) {
            for(auto i4 : vMVANPEC2) {
              ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+"DXYv1" );

            }
          }
        }
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

    }
    
    
    /// V1 El
    if(HasFlag("ELID_CF")){
      
      if(HasFlag("HighPt")){
	
	vMVACFBB.clear();
	vMVACFEC.clear();
	
	int nMVACF=31;
	
	for(int imva=0 ; imva < nMVACF ; imva++){
	  double mva_d=  -1. + double(imva)*.05;
	  TString mvaTS= DoubleToString(mva_d);
	  vMVACFBB.push_back("CFMVABB"+mvaTS+"_");
	  vMVACFEC.push_back("CFMVAEC"+mvaTS+"_");
	}
	for(int imva=1 ; imva < 45 ; imva++){
	  double mva_d=  0.5 + double(imva)*.01;
	  TString mvaTS= DoubleToString(mva_d);
	  vMVACFBB.push_back("CFMVABB"+mvaTS+"_");
	  vMVACFEC.push_back("CFMVAEC"+mvaTS+"_");
	}
	
	vector<TString> vMVACFBB2={};
	vector<TString> vMVACFEC2={};
	for(int imva=1 ; imva < 16 ; imva++){
          double mva_d=  0.6 + double(imva)*.02;
          TString mvaTS= DoubleToString(mva_d);
	  vMVACFBB2.push_back("CFMVABB"+mvaTS+"_");
          vMVACFEC2.push_back("CFMVAEC"+mvaTS+"_");
	}

	if(HasFlag("BB")){
	  for(auto i1 : vMVACFBB) {
	    ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_CCEC_LooseTrig_"+i1+"DXYv1"); 
	  }
	}
	if(HasFlag("EC")){
	  for(auto i1 : vMVACFEC) {
	    ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_CCBB_LooseTrig_"+i1+"DXYv1");
	  }
	}
	if(HasFlag("FullEta")){
	  for(auto i1 : vMVACFBB2) {
	    for(auto i2 : vMVACFEC2) {
	      ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_LooseTrig_"+i1+i2+"DXYv1");
	    }
	  }
	}
      }
      else        if(HasFlag("FullPt")){

	vMVACFBB={};
	vMVACFEC={};
	vector<TString> vMVACFPt={"30","40","50","60"};
	

	for(int imva=0 ; imva < 11 ; imva++){
          double mva_d=  0.45 + double(imva)*.04;
          TString mvaTS= DoubleToString(mva_d);
          vMVACFBB.push_back("CFMVABB1"+mvaTS+"_CFMVABB20p85_");
          vMVACFEC.push_back("CFMVAEC1"+mvaTS+"_CFMVAEC20p85_");
        }

	vector<TString> vMVACFBB2;
        vector<TString> vMVACFEC2;

        for(int imva=0 ; imva < 11 ; imva++){
          double mva_dB=  0.3 + double(imva)*.04;
          double mva_dEC=  0.4 + double(imva)*.04;
          TString mvaTSB= DoubleToString(mva_dB);
          TString mvaTSEC= DoubleToString(mva_dEC);
          vMVACFBB2.push_back("CFMVABB1"+mvaTSB+"_CFMVABB20p7_");
          vMVACFEC2.push_back("CFMVAEC1"+mvaTSEC+"_CFMVAEC20p8_");
        }


	for(auto i1 : vMVACFBB) {
	  for(auto i2 : vMVACFEC) {
	    for(auto i3 : vMVACFPt) {
	      ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_LooseTrig_"+i1+"CFMVAPt"+i3+"_"+i2+i3+"_DXYv1");
	    }
	  }
	}
	
	for(auto i1 : vMVACFBB2) {
          for(auto i2 : vMVACFEC2) {
            for(auto i3 : vMVACFPt) {
              ElectronsIDs.push_back("HNLUL_POGT_ConvBConvEC_LooseTrig_"+i1+"CFMVAPt"+i3+"_"+i2+i3+"_DXYv1");
            }
          }
        }
      }
    }
    
    
    
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

      for(auto i1 : vMVACFBB) {
        for(auto i2 : vMVACFEC) {
          for(auto i3 : vMVANPBB2){
            for(auto i4 : vMVANPEB2){
              for(auto i5 : vMVANPEC2) {
                ElectronsIDs.push_back("HNLUL_ConvBConvEC_LooseTrig_NPMVABB1neg1_NPMVAEB1neg1_NPMVAEC1neg1_"+i1+i2+i3+i4+i5+"DXYv1");

                for(auto i6 : vMVAConvBB2){                                                                                                                                   \

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
    
    //cout << "ElectronsIDs size = " << ElectronsIDs.size() << endl;
    for(auto id : ElectronsIDs){

      //cout << id << endl;
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
    if(HasFlag("HighPt") && MuonCollV[1].Pt() <60) return;
  

    vector<TString> ID;
    vector<TString> IDBB;
    vector<TString> IDEC;

    if(HasFlag("MuID_NP")){

      if(HasFlag("HighPt")){
	
	if(HasFlag("BB")){
	  
	  IDEC = {"POGECT_ISOEC0p15_"};
	  TString BBID="NPMVAPt20_NPMVABB1neg1_NPMVABB2";
	  for(unsigned int imva=0 ; imva < 56 ; imva++){
	    double mva_d= 0.4 + double(imva)*0.01;
	    TString mvaTS= DoubleToString(mva_d);
	    IDBB.push_back(BBID+mvaTS+"_");
	  }

	  for(auto i1 : IDBB){
            for(auto i2 : IDEC){
              MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1");
            }
          }

	}
	else if(HasFlag("EC")){

          IDBB = {"POGBT_ISOB0p15_"};
          TString ECID="NPMVAPt20_NPMVAEC1neg1_NPMVAEC2";
          for(unsigned int imva=0 ; imva < 56 ; imva++){
            double mva_d= 0.4 + double(imva)*0.01;
            TString mvaTS= DoubleToString(mva_d);
            IDEC.push_back(ECID+mvaTS+"_");
          }


	  for(auto i1 : IDBB){
            for(auto i2 : IDEC){
              MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1");
            }
          }

	}
	else if(HasFlag("FullEta")){

	  /// B+EC 

	  vector<TString> mvaBB,  mvaEC;
	  for(unsigned int imva=0 ; imva < 16 ; imva++){
            double mva_d= 0.5 + double(imva)*0.02;
            TString mvaTS= DoubleToString(mva_d);
            mvaBB.push_back("NPMVAPt20_NPMVABB1neg1_NPMVABB2"+mvaTS+"_");
	    mvaEC.push_back("NPMVAPt20_NPMVAEC1neg1_NPMVAEC2"+mvaTS+"_");
	  }
	  for(auto ib : mvaBB){
	    for(auto ie : mvaEC){
	      ID.push_back(ib+ie);
	    }
	  }
	  
	  for(auto i1 : ID){
            MuonsIDs.push_back("HNLUL_"+i1+"DXYv1");
          }


	}
	else if(HasFlag("Full")){

          /// B+EC                                                                                                                                                                                               
          vector<TString> mvaBB = {"NPMVAPt20_NPMVABB10p7_NPMVABB20p7_"};
	  vector<TString>mvaEC = {"NPMVAPt20_NPMVAEC10p65_NPMVAEC20p65_"};

          for(auto ib : mvaBB){
            for(auto ie : mvaEC){
              ID.push_back(ib+ie);
            }
          }
	  
	}//FULL
      }// High Pt
      
      
      if(HasFlag("FullPt")){
	
	if(HasFlag("BB")){
	  IDEC = {"POGECT_ISOEC0p15_"};
	  
	  vector<TString> mvaBBTau;
	  for(unsigned int imva=0 ; imva < 21 ; imva++){
	    double mva_d= 2.5 + double(imva)*0.5;
	    TString mvaTS= DoubleToString(mva_d);
	    mvaBBTau.push_back("MVABBTau"+mvaTS+"_");
	  }
	  vector<TString> mvaBBA;
	  for(unsigned int imva=0 ; imva < 21 ; imva++){
	    double mva_d= 0. + double(imva)*0.5;
	    TString mvaTS= DoubleToString(mva_d);
	    mvaBBA.push_back("MVABBA"+mvaTS+"_");
	  }
	  
	  ///
	  TString cVal="";
	  if(GetYear()==2016) cVal="MVABBC0p73_";
	  if(GetYear()==2017) cVal="MVABBC0p71_";
	  if(GetYear()==2018) cVal="MVABBC0p65_";

	  for(auto it : mvaBBTau){
	    for(unsigned int it2 =0; it2 <  mvaBBA.size(); it2++){
	      if( it2 == 0 && it != "MVABBTau2p5_") continue;
	      if(it.Contains("MVABBTau4") && it2 > 16) continue;
	      if(it.Contains("MVABBTau5") && it2 > 14) continue;
	      if(it.Contains("MVABBTau6") && it2 > 10) continue;
	      if(it.Contains("MVABBTau7") && it2 > 8) continue;
	      if(it.Contains("MVABBTau8") && it2 > 7) continue;
	      if(it.Contains("MVABBTau9") && it2 > 6) continue;
	      if(it.Contains("MVABBTau10") && it2 > 6) continue;
	      if(it.Contains("MVABBTau11") && it2 > 5) continue;
	      if(it.Contains("MVABBTau12") && it2 > 5) continue;
	      IDBB.push_back(cVal+it+mvaBBA[it2]);
	    }
	  }

	  for(auto i1 : IDBB){
            for(auto i2 : IDEC){
              MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1");
            }
          }
	}
	if(HasFlag("EC")){

	  TString cVal="";
          if(GetYear()==2016) cVal="MVAECC0p52_";
          if(GetYear()==2017) cVal="MVAECC0p54_";
          if(GetYear()==2018) cVal="MVAECC0p55_";

	  
          IDBB = {"POGBT_ISOB0p15_"};
          vector<TString> mvaECTau;
          for(unsigned int imva=0 ; imva < 21 ; imva++){
            double mva_d= 2.5 + double(imva)*0.5;
            TString mvaTS= DoubleToString(mva_d);
            mvaECTau.push_back("MVAECTau"+mvaTS+"_");
          }
          vector<TString> mvaECA;
          for(unsigned int imva=0 ; imva < 21 ; imva++){
            double mva_d= 0. + double(imva)*0.5;
            TString mvaTS= DoubleToString(mva_d);
            mvaECA.push_back("MVAECA"+mvaTS+"_");
          }

          for(auto it : mvaECTau){
            for(unsigned int it2 =0; it2 <  mvaECA.size(); it2++){
	      if( it2 == 0 && it != "MVAECTau2p5_") continue;
              if(it.Contains("MVAECTau4") && it2 > 16) continue;
              if(it.Contains("MVAECTau5") && it2 > 14) continue;
              if(it.Contains("MVAECTau6") && it2 > 10) continue;
              if(it.Contains("MVAECTau7") && it2 > 8) continue;
              if(it.Contains("MVAECTau8") && it2 > 7) continue;
              if(it.Contains("MVAECTau9") && it2 > 6) continue;
              if(it.Contains("MVAECTau10") && it2 > 6) continue;
              if(it.Contains("MVAECTau11") && it2 > 5) continue;
              if(it.Contains("MVAECTau12") && it2 > 5) continue;

              IDEC.push_back(cVal+it+mvaECA[it2]);
	    }   
          }
	  
	  for(auto i1 : IDBB){
	    for(auto i2 : IDEC){
	      MuonsIDs.push_back("HNLUL_"+i1+i2+"DXYv1");
	    }
	  }


        }

	if(HasFlag("FullEtaSlope")){

          /// B+EC                                                                                                                                                                                        
	  vector<TString> mvaPt = {"NPMVABBPt20","NPMVABBPt30","NPMVABBPt40",};
	  vector<TString> mvaECPt = {"NPMVAECPt20","NPMVAECPt30","NPMVAECPt40",};
	  
          vector<TString> mvaBB,  mvaEC;
	  
	  for(unsigned int imva2=0 ; imva2 < 12 ; imva2++){
	    double mva2B_d= 0.55 + double(imva2)*0.02;
	    double mva2EC_d= 0.6 + double(imva2)*0.02;
	    for(unsigned int imva1=0 ; imva1 < 6 ; imva1++){
	      double mvaB_d= 0.0 + double(imva1)*(mva2B_d/5.);
	      double mvaEC_d= 0.0 + double(imva1)*(mva2EC_d/5.);
	      
	      mvaBB.push_back("NPMVABB1"+DoubleToString(mvaB_d)+"_NPMVABB2"+DoubleToString(mva2B_d)+"_");
	      mvaEC.push_back("NPMVAEC1"+DoubleToString(mvaEC_d)+"_NPMVAEC2"+DoubleToString(mva2EC_d)+"_");
	    }
	  }
	  TString EEID = "NPMVAECPt20_NPMVAEC10p65_NPMVAEC20p65_";
	  TString EEID2 = "NPMVAECPt20_NPMVAEC10p6_NPMVAEC20p6_";
	  TString BBID = "NPMVABBPt20_NPMVABB10p7_NPMVABB20p7_";
	  TString BBID2 = "NPMVABBPt20_NPMVABB10p75_NPMVABB20p75_";
	  for(auto ib : mvaBB)   {
	    for(auto ipt :  mvaPt) {
	      ID.push_back(EEID+ib+"_NPMVABBPt"+ipt+"_NPMVAECPt"+ipt);
	      ID.push_back(EEID2+ib+"_NPMVABBPt"+ipt+"_NPMVAECPt"+ipt);
	    }
	  }
	  
	  for(auto ie : mvaEC){
	    for(auto ipt :  mvaPt) {
	      
	      ID.push_back(BBID+ie+"_NPMVABBPt"+ipt+"_NPMVAECPt"+ipt);
	      ID.push_back(BBID2+ie+"_NPMVABBPt"+ipt+"_NPMVAECPt"+ipt);
	    }
	  }


	  for(auto i1 : ID){
	    MuonsIDs.push_back("HNLUL_"+i1+"DXYv1");
	  }

	  
        }
	if(HasFlag("FullEtaExp")){

	  vector<TString> mvaBB,  mvaEC;

          for(unsigned int imva=0 ; imva < 5 ; imva++){
            double mva_c= 0.55 + double(imva)*0.05;
	    for(unsigned int imva2=0 ; imva2 < 21 ; imva2++){
	      double mva_tau= 2.5 + double(imva2)*0.5;
	      for(unsigned int imva3=0 ; imva3 < 11 ; imva3++){
		double mva_a= 0. + double(imva3)*0.5;
		if( imva3 == 0 && imva2 != 0) continue;
		
		double cutCategory10 =  mva_c - exp(- 10. / mva_tau) * mva_a;
		if(cutCategory10 < 0.) continue;
		
		mvaBB.push_back("MVABBC"+DoubleToString(mva_c)+"_MVABBTau"+DoubleToString(mva_tau)+"_MVABBA"+DoubleToString(mva_a)+"_");
		mvaEC.push_back("MVAECC"+DoubleToString(mva_c)+"_MVAECTau"+DoubleToString(mva_tau)+"_MVAECA"+DoubleToString(mva_a)+"_");
	      }
	    }
	  }

          for(auto ib : mvaBB)  ID.push_back(ib+"MVAECC0p65_MVAECTau0_MVAECA0_");
	  for(auto ie : mvaEC)  ID.push_back(ie+"MVABBC0p77_MVABBTau0_MVABBA0_");
	  for(auto i1 : ID)  MuonsIDs.push_back("HNLUL_"+i1+"DXYv1");
	
	}
      }
    }
    
    if(HasFlag("Mu_Conv")){
      
      vector<TString> mvaConv;
      
      for(unsigned int imva=0 ; imva < 50 ; imva++){
	
	double mva_c= -1 + double(imva)*0.04;
	mvaConv.push_back("MVAConv"+DoubleToString(mva_c)+"_");
	
      }
      
      for(auto ib : mvaConv){
	MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+ ib);
      }
    }
   
    
    
    
    //cout << " MuonsIDs = " <<  MuonsIDs.size() << endl;
    vector<TString> vIsoB  = {"ISOB0p05","ISOB0p06","ISOB0p07", "ISOB0p08","ISOB0p09","ISOB0p1","ISOB0p125","ISOB0p15"};
    vector<TString> vIsoEC = {"ISOEC0p05","ISOEC0p06","ISOEC0p07","ISOEC0p08","ISOEC0p09","ISOEC0p1","ISOEC0p125","ISOEC0p15"};

    if(HasFlag("Mu_Final")){
      MuonsIDs.clear();

      MuonsIDs.push_back("HNLUL_HNL" + GetYearString());
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv1");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv1");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_"+"DXYv1");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGECT_"+"DXYv1");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGECT_");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv2");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv3");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv4");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv5");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv6");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv7");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv8");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+"DXYv9");
      
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv2");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv3");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv4");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv5");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv6");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv7");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv8");
      MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+"DXYv9");
      
      for(unsigned int ib = 0 ; ib < vIsoB.size(); ib++){
	for(unsigned int ie = 0 ; ie < vIsoEC.size(); ie++){
	  TString iISOB = vIsoB[ib];
	  TString iISOEC = vIsoEC[ie];
	  
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_"+iISOB+"_"+iISOEC+"_DXYv5");
	  
	  
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC);
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBM_POGECM_"+iISOB+"_"+iISOEC+"_DXYv1");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBM_POGECM_"+iISOB+"_"+iISOEC+"_DXYv2");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBM_POGECM_"+iISOB+"_"+iISOEC+"_DXYv3");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBM_POGECM_"+iISOB+"_"+iISOEC+"_DXYv4");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBT_POGECT_"+iISOB+"_"+iISOEC+"_DXYv5");
	  MuonsIDs.push_back("HNLUL_HNL" + GetYearString()+"_POGBM_POGECM_"+iISOB+"_"+iISOEC+"_DXYv5");
	}
      }
      
      
      

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
    }
    
    
    MuonsIDs.push_back("HNTight_17028");
    MuonsIDs.push_back("HNTightV2");
    MuonsIDs.push_back("HNTightV3");
    MuonsIDs.push_back("HNL_ULID_2016");
    MuonsIDs.push_back("HNL_ULID_2017");
    MuonsIDs.push_back("HNL_ULID_2018");
    MuonsIDs.push_back("HNL_Peking");
    MuonsIDs.push_back("HNL_Top");


    for (unsigned int i=0; i<MuonsIDs.size(); i++) {
      for (unsigned int j=0; j<MuonsIDs.size(); j++) {
	if(i != j && MuonsIDs[i] == MuonsIDs[j]) {
	  cout << "[Muon::ID]  : " << MuonsIDs[i] << " occurs twice" << endl;

	  exit(ENODATA);

	}
      }
    }


    for(auto id : MuonsIDs){
      //      cout << id << endl;
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
  
  //cout << "weight = " << weight << endl;
  if(MCSample.Contains("Type")){
    if(MCSample.Contains("SS")) weight *= 0.01;
    else weight *= 0.1;
  }
  
  /// MERGE WJet samples for more stats
  if(MCSample.Contains("WJet")){
    vector<TString> vec = {"WJet"};
    double merge_weight = MergeMultiMC( vec, "" );
    weight*= merge_weight;
  }

  /// Merge DY samples for more stats
  if(MCSample.Contains("DYJets_MG")){
    vector<TString> vec = {"DYMG"};
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

  //if(param.Name.Contains("HNTightV2"))  param.WriteOutVerbose=0;

  
  if(!IsData )weight = weight*sf_btagM_NLV;
  if(!IsData && FatjetColl.size()==0)weight = weight*sf_btagM_NLV;
  if(!IsData && FatjetColl.size()>0)weight = weight*sf_btagSR1_NLV;


    
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




