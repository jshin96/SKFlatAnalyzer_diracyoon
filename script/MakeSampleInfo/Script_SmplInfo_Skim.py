import os, subprocess, re 
from os import path


if not "SKFlat_WD" in os.environ:
  print("Set up SKFlat environment."); exit(); 

#[PD(Or PrivateMC dir name), alias, xsec(fb)]
Arr_MCSample = [
  "DYJetsToMuMu_MiNNLO", "DYJetsToEE_MiNNLO",
#  "DYJets10to50_MG",
#  "WW_pythia", "WZ_pythia", "ZZ_pythia"
#  "WJets_MG",
#  "WZTo3LNu_amcatnlo", "ZZTo4L_powheg", "ttWToLNu", "ttZToLLNuNu", "ttHToNonbb", "tZq",
#  "GluGluHToZZTo4L", "VBF_HToZZTo4L", "VHToNonbb", "WWW", "WWZ", "WZZ", "ZZZ",
#  "ZGToLLG", "WGToLNuG", "TTG", "TG",
#  "WJets_amcatnlo", "DYJets", "TTLJ_powheg", "TTLL_powheg", 
#  "SingleTop_tW_antitop_NoFullyHad", "SingleTop_tW_top_NoFullyHad", "SingleTop_sch_Lep", "SingleTop_tch_antitop_Incl", "SingleTop_tch_top_Incl",
#"WAJJToLNuAJJ_EWK_private", "WGJJToLNuGJJ_EWK_private", "WpWpJJ_EWK_private", "WpWpJJ_QCD_private", "WGJJToLNu", "WZJJToLNu", 
]
Arr_Stream = [
  #"DoubleMuon", "MuonEG", "DoubleEG", "SingleElectron", "SingleMuon", #1617
  "DoubleMuon", "MuonEG", "EGamma", "SingleMuon", #18
]

Arr_Year   = ["2016a", "2016b", "2017", "2018"] #MC
#Arr_Year   = ["2016a", "2016b", "2017"]         #DATA1617
#Arr_Year   = ["2018"]                           #DATA18
Arr_Era16a = ["B_ver2", "C", "D", "E", "F"]
Arr_Era16b = ["F", "G", "H"]
Arr_Era17  = ["B", "C", "D", "E", "F"]
Arr_Era18  = ["A", "B", "C", "D"]
Arr_Era    = ["All"]


VerProc=os.getenv('SKFlatV')
WorkingPath=os.getenv('SKFlat_WD')
DataType="MC" #MC/DATA
SkimName="SS2lOR3l"
OverWrite = True
Verbose = True

if DataType == "MC":
  for Year in Arr_Year:
    YearLong=Year
    if '16a' in Year:
      YearLong='2016preVFP'
    if '16b' in Year:
      YearLong='2016postVFP'

    SamplePath="/gv0/DATA/SKFlat/"+VerProc+"/"+YearLong+"/"+DataType+"_SkimTree_"+SkimName+"/"
    ListPath=WorkingPath+"/data/"+VerProc+"/"+YearLong+"/Sample/"

    for Alias in Arr_MCSample:
      Path_Smplinfo = ListPath+"CommonSampleInfo/"+Alias+".txt"
      Path_SmplPath = ListPath+"ForSNU/SkimTree_"+SkimName+"_"+Alias+".txt"
    
      if not path.exists(Path_Smplinfo):
        print("[Error] Skip due to non-existing path: "+Path_Smplinfo); continue;
      if path.exists(Path_SmplPath):
        if not OverWrite:
          print("[Error] Skip due to existing path: "+Path_SmplPath); continue;
        else:
          os.system("rm "+Path_SmplPath)
    
      SmplinfoLine = subprocess.check_output("sed -n -e '2p' "+Path_Smplinfo, shell=True);
      SmplinfoArray = SmplinfoLine.split();
      if SmplinfoArray[0] != Alias:
        print("[Error] Sample info not found in the expected location: "+Alias); continue;
    
      DatasetName = SmplinfoArray[1]
      os.system("touch "+Path_SmplPath)
      os.system("find "+SamplePath+DatasetName+" -name *root >> "+Path_SmplPath)
    
    
      if Verbose:
        print("Processed "+Alias+" ("+VerProc+", "+YearLong+", MC).")

if DataType == "DATA":
  for Year in Arr_Year:
    YearLong=Year
    Arr_Era = []
    if '16a' in Year:
      YearLong='2016preVFP'
      Arr_Era = Arr_Era16a
    if '16b' in Year:
      YearLong='2016postVFP'
      Arr_Era = Arr_Era16b
    if '17' in Year:
      Arr_Era = Arr_Era17
    if '18' in Year:
      Arr_Era = Arr_Era18

    for TmpStr in Arr_Stream:
      for Era in Arr_Era:
        Stream=TmpStr
        if ('18' in Year) and (TmpStr=="DoubleEG"): Stream="EGamma"
        DatasetName = Stream+"_"+Era
        ListPath=WorkingPath+"/data/"+VerProc+"/"+YearLong+"/Sample/"
        SamplePath="/gv0/DATA/SKFlat/"+VerProc+"/"+YearLong+"/"+DataType+"_SkimTree_"+SkimName+"/"
        Path_SmplPath = ListPath+"ForSNU/SkimTree_"+SkimName+"_"+Stream+"_"+Era+".txt"
    
        if not path.exists(SamplePath+Stream+"/period"+Era):
          print("[Error] Skip due to non-existing path for "+Stream+","+Year+"-"+Era); continue;
        if path.exists(Path_SmplPath):
          if not OverWrite:
            print("[Error] Skip due to existing path: "+Path_SmplPath); continue;
          else:
            os.system("rm "+Path_SmplPath)
    
        os.system("touch "+Path_SmplPath)
        os.system("find "+SamplePath+Stream+"/period"+Era+" -name *root >> "+Path_SmplPath)
      
    
        if Verbose:
          print("Processed "+Stream+" ("+VerProc+", "+YearLong+"-"+Era+", Data).")
