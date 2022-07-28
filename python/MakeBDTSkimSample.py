import os
from os import listdir
from os.path import isfile,isdir, join
    

eras = ["2016preVFP", "2016postVFP","2017"]

for era in eras:
    sig_dir="/gv0/Users/jalmond/Run2UltraLegacy_v3/"+era+"/MC/Run2UltraLegacy_v3/"+era+"/"


    skims = ["MC_SkimTree_HNL_SS_ElEl", "MC_SkimTree_HNL_SS_ElMu",  "MC_SkimTree_HNL_SS_MuMu"]

    for skim in skims:
        
        _sig_dir=sig_dir+skim
        
        sig_skim_list  = [f for f in listdir(_sig_dir) if isdir(join(_sig_dir,f))]
        
  
        for sig in sig_skim_list:

            print " "

            if not os.path.exists(_sig_dir+"/"+sig +"_bdt"):
                os.system("cp -r " + _sig_dir+"/"+sig  + "  " +_sig_dir+"/"+sig +"_bdt")
                print ("cp -r " + _sig_dir+"/"+sig  + "  " +_sig_dir+"/"+sig +"_bdt")

            if not os.path.exists(_sig_dir+"/"+sig +"_analysis"):
                os.system("cp -r " + _sig_dir+"/"+sig  + "  " +_sig_dir+"/"+sig +"_analysis")
                print ("cp -r " + _sig_dir+"/"+sig  + "  " +_sig_dir+"/"+sig +"_analysis")
                
                
