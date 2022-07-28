import os
from os import listdir
from os.path import isfile,isdir, join
    

eras = ["2016preVFP", "2016postVFP","2017", "2018"]

for era in eras:
    sig_dir="/gv0/Users/jalmond/Run2UltraLegacy_v3/"+era+"/MC/Run2UltraLegacy_v3/"+era+"/"


    skims = ["MC_SkimTree_HNL_SS_ElEl", "MC_SkimTree_HNL_SS_ElMu",  "MC_SkimTree_HNL_SS_MuMu"]
    post_skims = ["_BDT_APPLY", "_BDT_TRAIN"]

    for skim in skims:
        for post_skim in post_skims:
            _sig_dir=sig_dir+skim + post_skim

            sig_skim_list  = [f for f in listdir(_sig_dir) if isdir(join(_sig_dir,f))]
            
            
            
            for sig in sig_skim_list:

                print ("ls  " + _sig_dir + "/"+sig + "/*/*  > " +os.getenv("SKFlat_WD")  + "/data/Run2UltraLegacy_v3/"+era+"/Sample/ForSNU/"+skim + post_skim + "_"+ sig+".txt")
                os.system("ls  " + _sig_dir + "/"+sig + "/*/*  > " +os.getenv("SKFlat_WD")  + "/data/Run2UltraLegacy_v3/"+era+"/Sample/ForSNU/"+skim + post_skim + "_"+ sig+".txt")
                       
