import os
from os import path

#EraList    = ['2016b', '2018']
#EraList    = ['2016a', '2017']
EraList    = ['2016a', '2016b', '2017', '2018']
#SFTypeList = ['ID']
SFTypeList = ['Mu17Leg1', 'Mu8Leg2']
#SFTypeList = ['ID', 'Ele23Leg1', 'Ele12Leg2']
IDBase     = 'POGMIDTIso' # TopHNT 
#IDBase     = 'TopHNTIsoIP_POGMID' # TopHNT 
#IDBase     = 'TopHNSST' # TopHNSST TopHNSST_NMHit01
#InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_El'
#InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_El/MiNNLO'
#InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_El/aMCatNLO/NMHit01'
#InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_Mu/IDEffMeas'
InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_Mu/Validation'
#InputDir   = '/data6/Users/jbhyun/cmssw/TagAndProbe/Electron/tnp_tamsa/results/TopHN_Mu/TrigEffMeas/AbsEta'
ObjType    = 'Muon' # Electron Muon
TestRun = False

for Era in EraList:
  EraLong = ""
  if Era=="2016a": EraLong="2016preVFP"
  elif Era=="2016b": EraLong="2016postVFP"
  else : EraLong=Era
  
  for SFType in SFTypeList:
    InFilePath=InputDir+'/'
    if 'ID' in SFType: InFilePath+=IDBase+'_'+Era+'/efficiency.root'
    else: InFilePath+=SFType+'_'+IDBase+'_'+Era+'/efficiency.root'

    OutFileDir=EraLong+'/ID/'+ObjType+'/'
    OutFilePath=OutFileDir
    if 'ID' in SFType: OutFilePath+='IDEff_'+IDBase+'_'+Era+'.root'
    elif 'Leg1' in SFType:
      OutFilePath+='TrigEff_'+SFType+'_'+IDBase+'_'+Era+'.root'
      OutFilePath = OutFilePath.replace("Leg1","") 
    elif 'Leg2' in SFType:
      OutFilePath+='TrigEff_'+SFType+'_'+IDBase+'_'+Era+'.root'
      OutFilePath = OutFilePath.replace("Leg2","") 
    else: pass

    if not path.exists(InFilePath):
      print("missing infile path: "+InFilePath)
      continue
    if not path.exists(OutFileDir):
      print("missing outfile dir: "+OutFileDir)
      continue
    if TestRun: print("cp -v "+InFilePath+" "+OutFilePath)
    else: os.system("cp -v "+InFilePath+" "+OutFilePath)

