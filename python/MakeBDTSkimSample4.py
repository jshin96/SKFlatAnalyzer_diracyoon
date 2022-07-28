import os
from os import listdir
from os.path import isfile,isdir, join
    

eras = ["2016preVFP", "2016postVFP","2017"]

for era in eras:
    sig_dir="/gv0/Users/jalmond/Run2UltraLegacy_v3/"+era+"/MC/Run2UltraLegacy_v3/"+era+"/"


    skims = ["MC_SkimTree_HNL_SS_ElEl", "MC_SkimTree_HNL_SS_ElMu",  "MC_SkimTree_HNL_SS_MuMu"]
    
    for skim in skims:
        
        if era == "2018":
            if  os.path.exists(sig_dir+skim+"_v1"):
                os.system("mv "  + sig_dir+skim+"_v1 " + sig_dir+skim+"_BDT_TRAIN")
            if  os.path.exists(sig_dir+skim+"_v2"):
                os.system("mv " + sig_dir+skim+"_v2 " + sig_dir+skim+"_BDT_APPLY")

            continue

        else:
            if not os.path.exists(sig_dir+skim+"_BDT_TRAIN"):
                os.system("mkdir -p " + sig_dir+skim+"_BDT_TRAIN")
            if not os.path.exists(sig_dir+skim+"_BDT_APPLY"):
                os.system("mkdir -p " +sig_dir+skim+"_BDT_APPLY")



        _sig_dir=sig_dir+skim
        
        sig_skim_list  = [f for f in listdir(_sig_dir) if isdir(join(_sig_dir,f))]
        
        for sig in sig_skim_list:
            
            if "bdt" in sig:
                newname=sig
                newname=newname.replace("_bdt","")
                print ("mv " + _sig_dir+"/"+sig + " " + _sig_dir+"_BDT_TRAIN/"+newname)
                os.system("mv " + _sig_dir+"/"+sig + " " + _sig_dir +"_BDT_TRAIN/"+newname)

            if "analysis" in sig:
                newname=sig
                newname=newname.replace("_analysis","")

                print ("mv " + _sig_dir+"/"+sig + " " + _sig_dir+"_BDT_APPLY/"+newname)
                os.system("mv " + _sig_dir+"/"+sig + " " + _sig_dir+"_BDT_APPLY/"+newname)
