import os, subprocess, re 
from os import path


if not "SKFlat_WD" in os.environ:
  print("Set up SKFlat environment."); exit(); 

#[PD(Or PrivateMC dir name), alias, xsec(fb)]
Arr_Sample = [
              ["WZTo3LNu_mllmin4p0_TuneCP5_13TeV-powheg-pythia8", "WZTo3LNu_powheg", 4.42965], 
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN30"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN30"  , 1.],
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN40"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN40"  , 1.],
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN60"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN60"  , 1.],
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN70"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN70"  , 1.],
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN85"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN85"  , 1.],
#              ["TTbarTypeIHeavyN-El_HadTop3L_LO_MN90"  ,"TTbarTypeIHeavyN_wPS-El_HadTop3L_MLM_MN90"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN30"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN30"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN40"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN40"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN60"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN60"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN70"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN70"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN85"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN85"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_HadTop3L_LO_MN90"  ,"TTbarTypeIHeavyN_wPS-Mu_HadTop3L_MLM_MN90"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN100" ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN100" , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN20"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN20"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN30"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN30"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN40"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN40"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN50"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN50"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN60"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN60"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN70"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN70"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN75"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN75"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN85"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN85"  , 1.],
#              ["TTbarTypeIHeavyN-El_2L_LO_MN90"  ,"TTbarTypeIHeavyN_wPS-El_2L_MLM_MN90"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN100" ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN100" , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN20"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN20"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN30"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN30"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN40"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN40"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN50"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN50"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN60"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN60"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN70"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN70"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN75"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN75"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN85"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN85"  , 1.],
#              ["TTbarTypeIHeavyN-Mu_2L_LO_MN90"  ,"TTbarTypeIHeavyN_wPS-Mu_2L_MLM_MN90"  , 1.],
              ]

VerProc=os.getenv('SKFlatV')
Year="2017"
DataType="MC" #MC/DATA +_Skim_...
Category="TTbarTypeIHeavyN_wPS" #"HctoWA"
SamplePath="/gv0/DATA/SKFlat/"+VerProc+"/"+Year+"/"+DataType+"/" #Normal samples
OverWrite = True
Verbose = True
FileListProd = True
NumberProd = True

WorkingPath=os.getenv('SKFlat_WD')
ListPath=WorkingPath+"/data/"+VerProc+"/"+Year+"/Sample/"
CalcCodePath= WorkingPath+"/script/MakeSampleInfo/"

for it_proc in Arr_Sample:
  InputDirName = it_proc[0]
  Alias        = it_proc[1]
  Xsec         = it_proc[2]
  
  Path_Smplinfo = ListPath+"CommonSampleInfo/"+Alias+".txt"
  Path_SmplPath = ListPath+"ForSNU/"+Alias+".txt"

  if path.exists(Path_SmplPath):
    if not OverWrite:
      print("[Error] Skip due to existing path: "+Path_SmplPath); continue;
    else:
      os.system("rm "+Path_SmplPath)
  if path.exists(Path_Smplinfo):
    if not OverWrite:
      print("[Error] Skip due to existing path: "+Path_Smplinfo); continue;
    else:
      os.system("rm "+Path_Smplinfo)


  os.system("touch "+Path_SmplPath)
  os.system("find "+SamplePath+InputDirName+" -name *root >> "+Path_SmplPath)
  os.system("touch "+Path_Smplinfo)
  os.system("echo \"# alias PD xsec nmc sumw\" >> "+Path_Smplinfo)
  if NumberProd:
    CntFile = os.getenv('SKFlatOutputDir')+'/'+VerProc+'/GetEffLumi/'+Year+'/'+DataType+'/GetEffLumi_'+Alias+'.root'
    if not path.exists(CntFile):
      print("[Error] Skip due to absence of count file: "+CntFile); continue;
    CountInfo = subprocess.check_output("root -l -b -q \""+CalcCodePath+"LumiWCalc.C(\\\""+CntFile+"\\\")\"", shell=True);
    Nevent = CountInfo.split()[2]
    SumW   = CountInfo.split()[3]
    os.system("echo \""+Alias+"\t"+InputDirName+"\t"+str(Xsec)+"\t"+Nevent+"\t"+SumW+"\" >> "+Path_Smplinfo)

  if Verbose:
    print("Processed "+Alias+" ("+VerProc+", "+Year+", "+DataType+").")
