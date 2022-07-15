import os, subprocess, re 
from os import path
from DataSetMap import Map_Sample 


if not "SKFlat_WD" in os.environ:
  print("Set up SKFlat environment."); exit(); 

#[PD(Or PrivateMC dir name), alias, xsec(fb)]
#Arr_Year = ["2017"]
Arr_Year = ["2016a", "2016b", "2017", "2018"]

VerProc=os.getenv('SKFlatV')
WorkingPath=os.getenv('SKFlat_WD')
DataType="MC" #MC/DATA +_Skim_...
OverWrite = True
Verbose = True
FileListProd = True
NumberProd = True


for Year in Arr_Year:
  YearLong=Year
  if '16a' in Year:
    YearLong='2016preVFP'
  if '16b' in Year:
    YearLong='2016postVFP'
  SamplePath="/gv0/DATA/SKFlat/"+VerProc+"/"+YearLong+"/"+DataType+"/"
  ListPath=WorkingPath+"/data/"+VerProc+"/"+YearLong+"/Sample/"
  CalcCodePath= WorkingPath+"/script/MakeSampleInfo/"

  for it_proc in Map_Sample:
    Alias        = it_proc[0]
    Xsec         = it_proc[1]
    InputDirName = it_proc[2]
    
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
      print("Processed "+Alias+" ("+VerProc+", "+YearLong+", "+DataType+").")
