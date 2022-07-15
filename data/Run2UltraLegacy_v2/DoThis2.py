import os
from os import path

ListEra = ['2016a', '2016b', '2017', '2018']
FileNameBase="FR_MC_"
#"FR_MC_"
InputDir="Box/MCFakeRate/"
#InputDir="Box/FakeRate/TopHN17SST/"
#InputDir="Box/NvtxRWMu/"
#OutDir="FakeRate/DataFR/MuFR/"
#OutDir="FakeRate/DataFR/ElFR/"
#OutDir="FakeRate/NvtxSF/MuFR/"
OutDir="FakeRate/MCFR/ElFR/"
for Era in ListEra:
  EraLong =Era;
  if Era=='2016a': EraLong="2016preVFP"
  if Era=='2016b': EraLong="2016postVFP"
  InFilePath = InputDir+FileNameBase+Era+".root"
  OutDirPath = EraLong+"/"+OutDir
  
  if not path.exists(OutDirPath):
    os.system("mkdir -pv "+OutDirPath)
  os.system("cp -rv "+InFilePath+" "+OutDirPath)
