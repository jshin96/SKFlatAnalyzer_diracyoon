import os
from os import listdir
from os.path import isfile,isdir, join
    

sig_dir="/gv0/Users/jalmond/Run2UltraLegacy_v3/2018/MC/Run2UltraLegacy_v3/2018/"


skims = ["MC_SkimTree_HNL_SS_ElEl", "MC_SkimTree_HNL_SS_ElMu",  "MC_SkimTree_HNL_SS_MuMu"]

for skim in skims:
    _sig_dir=sig_dir+skim

    sig_skim_list  = [f for f in listdir(_sig_dir) if isdir(join(_sig_dir,f))]

   

    for sig in sig_skim_list:
        
        if not "bdt" in sig and not  "analysis" in sig:
            print _sig_dir+"/"+sig
            os.system("rm -rf " + _sig_dir+"/"+sig)

    continue
    for sig in sig_skim_list:

        print " "
        if "bdt" in sig:
            bdt_sig_skim_list  = [f for f in listdir(_sig_dir+"/"+sig) if isdir(join(_sig_dir+"/"+sig,f))]
            for _dir in bdt_sig_skim_list:
                bdt_sig_skim_list_v1  = [f for f in listdir(_sig_dir+"/"+sig + "/" + _dir) if isfile(join(_sig_dir+"/"+sig + "/" + _dir,f))]
                for x in bdt_sig_skim_list_v1:
                    if "MC_1.root" in x or  "MC_2.root" in x or "MC_3.root" in x or "MC_4.root" in x or "MC_5.root" in x or "MC_6.root" in x or "MC_7.root" in x or "MC_8.root" in x or "MC_9.root" in x or "MC_0.root" in x:
                        os.system( "rm " + _sig_dir+"/"+sig + "/" + _dir + "/"+x)

        print " "            
        if "analysis" in sig:
            an_sig_skim_list  = [f for f in listdir(_sig_dir+"/"+sig) if isdir(join(_sig_dir+"/"+sig,f))]
            for _dir in an_sig_skim_list:
                an_sig_skim_list_v1  = [f for f in listdir(_sig_dir+"/"+sig + "/" + _dir) if isfile(join(_sig_dir+"/"+sig + "/" + _dir,f))]

                for x in an_sig_skim_list_v1:
                    if "MC_11.root" in x or  "MC_12.root" in x or "MC_13.root" in x or "MC_14.root" in x or "MC_15.root" in x or "MC_16.root" in x or "MC_17.root" in x or "MC_18.root" in x or "MC_19.root" in x or "MC_10.root" in x:
                        os.system( "rm " + _sig_dir+"/"+sig + "/" + _dir + "/"+x)


                
