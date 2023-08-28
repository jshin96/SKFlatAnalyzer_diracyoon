import os
from os import path

ListEra = ['2016a', '2016b', '2017', '2018']
#ListEra = ['2016b', '2017', '2018']
FileNameBase="FR_"
#FileNameBase="FR_MC_"
#InputDir="Box/CFRate/TopHNSST/"
#InputDir="Box/FakeRateMeas/MeasFR/MuFR/"
InputDir="Box/MuFR/"
#InputDir="Box/MuFR/"
#InputDir="Box/MCFakeRate/Mu/"
#InputDir="Box/NvtxRWMu/"
#OutDir="CFRate/"
OutDir="FakeRate/DataFR/MuFR/"
#OutDir="FakeRate/NvtxSF/MuFR/"
#OutDir="FakeRate/MCFR/MuFR/"
for Era in ListEra:
  EraLong =Era;
  if Era=='2016a': EraLong="2016preVFP"
  if Era=='2016b': EraLong="2016postVFP"
  InFilePath = InputDir+FileNameBase+Era+".root"
  OutDirPath = EraLong+"/"+OutDir
  
  if not path.exists(OutDirPath):
    os.system("mkdir -pv "+OutDirPath)
  os.system("cp -rv "+InFilePath+" "+OutDirPath)
