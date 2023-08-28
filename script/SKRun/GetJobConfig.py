import os, sys

List_MC_Test = [
  #["tHq", 3], ["tZq", 1],
  #["ttWToLNu", 2], ["ttZToLLNuNu", 4], ["ttHToNonbb", 2],
  #["DYJets10to50_MG", 13],
  ["TTLL_powheg", 25],
  ["DYJets", 25],
]


List_MC_Pr1l = [
  #["WJets_MG", 13],
  ["WJets_amcatnlo", 13], ["DYJets", 21], ["DYJets10to50_MG", 13],
  ["TTLJ_powheg", 20], ["TTLL_powheg", 20],
  ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2],
  ["SingleTop_sch_Lep", 5], ["SingleTop_tch_antitop_Incl", 10], ["SingleTop_tch_top_Incl", 10],
  ["WZ_pythia", 2], ["WW_pythia", 2], ["ZZ_pythia", 2]
]

List_MC_PrOS2l = [ 
  ["DYJets", 21], ["DYJets10to50_MG", 13], ["TTLL_powheg", 13], ["WZ_pythia", 2], ["WW_pythia", 2], ["ZZ_pythia", 2], ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2],
]

List_MC_PrSS2l = [
  ["WZTo3LNu_amcatnlo", 1], ["ZZTo4L_powheg", 5], ["ttWToLNu", 2], ["ttZToLLNuNu", 4], ["ttHToNonbb", 2], ["tZq", 1], #["tHq", 3],
  ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["VHToNonbb", 1], ["WWW", 1], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1],
]

List_MC_Pr3l = [
  ["WZTo3LNu_amcatnlo", 1], ["ZZTo4L_powheg", 5], ["ttWToLNu", 2], ["ttZToLLNuNu", 4], ["ttHToNonbb", 2], ["tZq", 1], ["tHq", 3],
  ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["VHToNonbb", 1], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1],["WWW", 1], 
]

List_MC_Pr4l = [
  ["ZZTo4L_powheg", 5], ["ttZToLLNuNu", 5], ["ttHToNonbb", 5], ["tHq", 3],
  ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["VHToNonbb", 1], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1]
]

List_MC_Cv2l = [
  #["DYJets", 25], ["ZGToLLG", 5], ["WGToLNuG", 5], ["TTG", 2], ["TG", 1], #["ZGToLLG", 5], ["WGToLNuG", 5], ["TTG", 2], ["TG", 1], 
  ["DYJets10to50_MG", 13], ["DYJets", 25], ["WJets_amcatnlo", 13], ["TTLJ_powheg", 25], ["TTLL_powheg", 13], 
  ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2], ["SingleTop_sch_Lep", 5], ["SingleTop_tch_antitop_Incl", 10], ["SingleTop_tch_top_Incl", 10],
]

List_MC_Cv3l = [
  ["ZGToLLG", 5], ["TTG", 2], ["DYJets", 25], 
]

List_MC_Fk2l = [
  ["WJets_MG", 10], ["WJets_amcatnlo", 13], ["DYJets", 25], ["TTLJ_powheg", 25], ["TTLL_powheg", 13], ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2], ["SingleTop_sch_Lep", 5], ["SingleTop_tch_antitop_Incl", 10], ["SingleTop_tch_top_Incl", 10], 
]

List_MC_Fk3l = [
  ["DYJets", 25], ["TTLL_powheg", 13], ["TTLJ_powheg", 13],
]

#List_MC_CF2l = [["DYJetsToEE_MiNNLO", 25], ["TTLL_powheg", 13],]
List_MC_CF2l = [["DYJetsToEE_MiNNLO", 25], ["TTLL_powheg", 13], ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2]]

List_MC_CFMeas = [["DYJetsToEE_MiNNLO", 25]]

List_MC_TrigEff = [ ["DYJets", 21], ["DYJets10to50_MG", 13], ["TTLL_powheg", 13] ]

List_MC_TrigClos = [ ["DYJets", 21], ["TTLL_powheg", 13], ] #2l clos
#List_MC_TrigClos = [ ["WZTo3LNu_amcatnlo", 1], ["ttWToLNu", 2], ["ttZToLLNuNu", 4], ["ttHToNonbb", 2], ] #3l clos


List_MC_TT = [["TTLJ_powheg", 20], ["TTLL_powheg", 20]]

List_MC_QCD = [["QCD_Pt_15to30", 5], ["QCD_Pt_30to50", 5], ["QCD_Pt_50to80", 5], ["QCD_Pt_80to120", 5], ["QCD_Pt_120to170", 5], ["QCD_Pt_170to300", 5], ["QCD_Pt_300to470", 5], ["QCD_Pt_470to600", 5], ["QCD_Pt_600to800", 5], ["QCD_Pt_800to1000", 5], ["QCD_Pt_1000to1400", 5], ["QCD_Pt_1400to1800", 5], ["QCD_Pt_1800to2400", 5], ["QCD_Pt_2400to3200", 5], ["QCD_Pt_3200toInf", 5]]


List_MC_QCD_MuFilt = [
 ["QCD_Pt-15To20_MuEnriched", 5],  ["QCD_Pt-20To30_MuEnriched", 5],  ["QCD_Pt-30To50_MuEnriched", 5],  ["QCD_Pt-50To80_MuEnriched", 5],  ["QCD_Pt-80To120_MuEnriched" , 5],  ["QCD_Pt-120To170_MuEnriched", 5],  ["QCD_Pt-170To300_MuEnriched", 5],  ["QCD_Pt-300To470_MuEnriched", 5],  ["QCD_Pt-470To600_MuEnriched", 5],  ["QCD_Pt-600To800_MuEnriched", 5],  ["QCD_Pt-800To1000_MuEnriched" , 5],  ["QCD_Pt-1000_MuEnriched", 5],
]

List_MC_QCD_EMFilt = [
 ["QCD_Pt-20to30_EMEnriched", 5],  ["QCD_Pt-30to50_EMEnriched", 5],  ["QCD_Pt-50to80_EMEnriched", 5],  ["QCD_Pt-80to120_EMEnriched" , 5],  ["QCD_Pt-120to170_EMEnriched", 5],  ["QCD_Pt-170to300_EMEnriched", 5],  ["QCD_Pt-300toInf_EMEnriched", 5],
 ["QCD_Pt_20to30_bcToE", 5],  ["QCD_Pt_30to80_bcToE", 5],  ["QCD_Pt_80to170_bcToE", 5],  ["QCD_Pt_170to250_bcToE", 5],  ["QCD_Pt_250toInf_bcToE", 5],
]

List_MC_QCD_Filt = List_MC_QCD_MuFilt + List_MC_QCD_EMFilt



List_MC_ttVH = [
  ["ttWToLNu", 2], ["ttZToLLNuNu", 4], ["ttHToNonbb", 2], ["tZq", 1]
]



##SIGNAL
List_HNTop_2L_El_Pivot = [["TT_HeavyN-El_2L_MN20", 1], ["TT_HeavyN-El_2L_MN50", 1], ["TT_HeavyN-El_2L_MN75", 1], ["TT_HeavyN-El_2L_MN85", 1], ["TT_HeavyN-El_2L_MN100", 1]]

List_HNTop_2L_Mu_Pivot = [["TT_HeavyN-Mu_2L_MN20", 1], ["TT_HeavyN-Mu_2L_MN50", 1], ["TT_HeavyN-Mu_2L_MN75", 1], ["TT_HeavyN-Mu_2L_MN85", 1], ["TT_HeavyN-Mu_2L_MN100", 1]]

List_HNTop_2L_El_Else = [["TT_HeavyN-El_2L_MN30", 1], ["TT_HeavyN-El_2L_MN40", 1], ["TT_HeavyN-El_2L_MN60", 1], ["TT_HeavyN-El_2L_MN70", 1], ["TT_HeavyN-El_2L_MN95", 1],]

List_HNTop_2L_Mu_Else = [["TT_HeavyN-Mu_2L_MN30", 1], ["TT_HeavyN-Mu_2L_MN40", 1], ["TT_HeavyN-Mu_2L_MN60", 1], ["TT_HeavyN-Mu_2L_MN70", 1], ["TT_HeavyN-Mu_2L_MN95", 1],]


List_HNTop_El_Pivot = [
  ["TT_HeavyN-El_2L_MN20", 1], ["TT_HeavyN-El_HadSMTop_3L_MN20", 1], ["TT_HeavyN-El_LepSMTop_3L_MN20", 1], ["TT_HeavyN-El_4L_MN20", 1],
  ["TT_HeavyN-El_2L_MN50", 1], ["TT_HeavyN-El_HadSMTop_3L_MN50", 1], ["TT_HeavyN-El_LepSMTop_3L_MN50", 1], ["TT_HeavyN-El_4L_MN50", 1],
  ["TT_HeavyN-El_2L_MN75", 1], ["TT_HeavyN-El_HadSMTop_3L_MN75", 1], ["TT_HeavyN-El_LepSMTop_3L_MN75", 1], ["TT_HeavyN-El_4L_MN75", 1],
  ["TT_HeavyN-El_2L_MN85", 1], ["TT_HeavyN-El_4L_MN85", 1], ["TT_HeavyN-El_HadSMTop_3L_MN85", 1], ["TT_HeavyN-El_LepSMTop_3L_MN85", 1],
  ["TT_HeavyN-El_2L_MN100", 1], ["TT_HeavyN-El_4L_MN100", 1], ["TT_HeavyN-El_HadSMTop_3L_MN100", 1], ["TT_HeavyN-El_LepSMTop_3L_MN100", 1],
]

List_HNTop_Mu_Pivot = [
  ["TT_HeavyN-Mu_2L_MN20", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN20", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN20", 1], ["TT_HeavyN-Mu_4L_MN20", 1],
  ["TT_HeavyN-Mu_2L_MN50", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN50", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN50", 1], ["TT_HeavyN-Mu_4L_MN50", 1],
  ["TT_HeavyN-Mu_2L_MN75", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN75", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN75", 1], ["TT_HeavyN-Mu_4L_MN75", 1],
  ["TT_HeavyN-Mu_2L_MN85", 1], ["TT_HeavyN-Mu_4L_MN85", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN85", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN85", 1],
  ["TT_HeavyN-Mu_2L_MN100", 1], ["TT_HeavyN-Mu_4L_MN100", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN100", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN100", 1],
]

List_HNTop_El_Else = [
  ["TT_HeavyN-El_2L_MN30", 1], ["TT_HeavyN-El_4L_MN30", 1], ["TT_HeavyN-El_HadSMTop_3L_MN30", 1], ["TT_HeavyN-El_LepSMTop_3L_MN30", 1],
  ["TT_HeavyN-El_2L_MN40", 1], ["TT_HeavyN-El_4L_MN40", 1], ["TT_HeavyN-El_HadSMTop_3L_MN40", 1], ["TT_HeavyN-El_LepSMTop_3L_MN40", 1],
  ["TT_HeavyN-El_2L_MN60", 1], ["TT_HeavyN-El_4L_MN60", 1], ["TT_HeavyN-El_HadSMTop_3L_MN60", 1], ["TT_HeavyN-El_LepSMTop_3L_MN60", 1],
  ["TT_HeavyN-El_2L_MN70", 1], ["TT_HeavyN-El_4L_MN70", 1], ["TT_HeavyN-El_HadSMTop_3L_MN70", 1], ["TT_HeavyN-El_LepSMTop_3L_MN70", 1],
  ["TT_HeavyN-El_2L_MN95", 1], ["TT_HeavyN-El_4L_MN95", 1], ["TT_HeavyN-El_HadSMTop_3L_MN95", 1], ["TT_HeavyN-El_LepSMTop_3L_MN95", 1],
]

List_HNTop_Mu_Else = [
  ["TT_HeavyN-Mu_2L_MN30", 1], ["TT_HeavyN-Mu_4L_MN30", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN30", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN30", 1],
  ["TT_HeavyN-Mu_2L_MN40", 1], ["TT_HeavyN-Mu_4L_MN40", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN40", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN40", 1],
  ["TT_HeavyN-Mu_2L_MN60", 1], ["TT_HeavyN-Mu_4L_MN60", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN60", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN60", 1],
  ["TT_HeavyN-Mu_2L_MN70", 1], ["TT_HeavyN-Mu_4L_MN70", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN70", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN70", 1],
  ["TT_HeavyN-Mu_2L_MN95", 1], ["TT_HeavyN-Mu_4L_MN95", 1], ["TT_HeavyN-Mu_HadSMTop_3L_MN95", 1], ["TT_HeavyN-Mu_LepSMTop_3L_MN95", 1],
]

List_HNTop_2L_Pivot = List_HNTop_2L_El_Pivot + List_HNTop_2L_Mu_Pivot
List_HNTop_2L_Else  = List_HNTop_2L_El_Else  + List_HNTop_2L_Mu_Else
List_HNTop_2L_All   = List_HNTop_2L_Pivot    + List_HNTop_2L_Else
List_HNTop_Pivot = List_HNTop_El_Pivot + List_HNTop_Mu_Pivot
List_HNTop_Else  = List_HNTop_El_Else  + List_HNTop_Mu_Else
List_HNTop_All   = List_HNTop_Pivot    + List_HNTop_Else



##DATA
List_Data_SglMu_2016a = [ ["SingleMuon", 15, "B_ver2"], ["SingleMuon", 7, "C"], ["SingleMuon", 11, "D"], ["SingleMuon", 11, "E"], ["SingleMuon", 7, "F"] ]
List_Data_SglEl_2016a = [ ["SingleElectron", 15, "B_ver2"], ["SingleElectron", 7, "C"], ["SingleElectron", 11, "D"], ["SingleElectron", 11, "E"], ["SingleElectron", 7, "F"] ]
List_Data_DblMu_2016a = [ ["DoubleMuon", 15, "B_ver2"], ["DoubleMuon", 7, "C"], ["DoubleMuon", 11, "D"], ["DoubleMuon", 11, "E"], ["DoubleMuon", 7, "F"] ]
List_Data_DblEG_2016a = [ ["DoubleEG", 15, "B_ver2"], ["DoubleEG", 7, "C"], ["DoubleEG", 11, "D"], ["DoubleEG", 11, "E"], ["DoubleEG", 7, "F"] ]
List_Data_MuEG_2016a  = [ ["MuonEG", 15, "B_ver2"], ["MuonEG", 7, "C"], ["MuonEG", 11, "D"], ["MuonEG", 11, "E"], ["MuonEG", 7, "F"] ]

List_Data_SglMu_2016b = [ ["SingleMuon", 5, "F"], ["SingleMuon", 16, "G"], ["SingleMuon", 14, "H"] ]
List_Data_SglEl_2016b = [ ["SingleElectron", 5, "F"], ["SingleElectron", 16, "G"], ["SingleElectron", 14, "H"] ]
List_Data_DblMu_2016b = [ ["DoubleMuon", 5, "F"], ["DoubleMuon", 16, "G"], ["DoubleMuon", 14, "H"] ]
List_Data_DblEG_2016b = [ ["DoubleEG", 5, "F"], ["DoubleEG", 16, "G"], ["DoubleEG", 14, "H"] ]
List_Data_MuEG_2016b  = [ ["MuonEG", 5, "F"], ["MuonEG", 16, "G"], ["MuonEG", 14, "H"] ]

List_Data_SglMu_2017 = [ ["SingleMuon", 9, "B"], ["SingleMuon", 21, "C"], ["SingleMuon", 8, "D"], ["SingleMuon", 16, "E"], ["SingleMuon", 21, "F"] ]
List_Data_SglEl_2017 = [ ["SingleElectron", 9, "B"], ["SingleElectron", 21, "C"], ["SingleElectron", 8, "D"], ["SingleElectron", 16, "E"], ["SingleElectron", 21, "F"] ]
List_Data_DblMu_2017 = [ ["DoubleMuon", 13, "B"], ["DoubleMuon", 15, "C"], ["DoubleMuon", 7, "D"], ["DoubleMuon", 15, "E"], ["DoubleMuon", 24, "F"] ]
List_Data_DblEG_2017 = [ ["DoubleEG", 9, "B"], ["DoubleEG", 21, "C"], ["DoubleEG", 8, "D"], ["DoubleEG", 16, "E"], ["DoubleEG", 21, "F"] ]
List_Data_MuEG_2017  = [ ["MuonEG", 13, "B"], ["MuonEG", 15, "C"], ["MuonEG", 7, "D"], ["MuonEG", 15, "E"], ["MuonEG", 24, "F"] ]

List_Data_SglMu_2018 = [ ["SingleMuon", 18, "A"], ["SingleMuon", 9, "B"], ["SingleMuon", 9, "C"], ["SingleMuon", 39, "D"] ]
List_Data_SglEl_2018 = [ ["EGamma", 18, "A"], ["EGamma", 9, "B"], ["EGamma", 9, "C"], ["EGamma", 39, "D"] ]
List_Data_DblMu_2018 = [ ["DoubleMuon", 18, "A"], ["DoubleMuon", 9, "B"], ["DoubleMuon", 9, "C"], ["DoubleMuon", 39, "D"] ]
List_Data_DblEG_2018 = [ ["EGamma", 18, "A"], ["EGamma", 9, "B"], ["EGamma", 9, "C"], ["EGamma", 39, "D"] ]
List_Data_MuEG_2018  = [ ["MuonEG", 18, "A"], ["MuonEG", 9, "B"], ["MuonEG", 9, "C"], ["MuonEG", 39, "D"] ]

List_Data_1LPD_2016a = List_Data_SglMu_2016a + List_Data_SglEl_2016a
List_Data_2LPD_2016a = List_Data_DblMu_2016a + List_Data_DblEG_2016a + List_Data_MuEG_2016a
List_Data_SF2L_2016a = List_Data_DblEG_2016a + List_Data_DblMu_2016a
List_Data_DiEl_2016a = List_Data_DblEG_2016a

List_Data_1LPD_2016b = List_Data_SglMu_2016b + List_Data_SglEl_2016b
List_Data_2LPD_2016b = List_Data_DblMu_2016b + List_Data_DblEG_2016b + List_Data_MuEG_2016b
List_Data_SF2L_2016b = List_Data_DblEG_2016b + List_Data_DblMu_2016b
List_Data_DiEl_2016b = List_Data_DblEG_2016b

List_Data_1LPD_2017 = List_Data_SglMu_2017 + List_Data_SglEl_2017
List_Data_2LPD_2017 = List_Data_DblMu_2017 + List_Data_DblEG_2017 + List_Data_MuEG_2017
List_Data_SF2L_2017 = List_Data_DblEG_2017 + List_Data_DblMu_2017
List_Data_DiEl_2017 = List_Data_DblEG_2017

List_Data_1LPD_2018 = List_Data_SglMu_2018
List_Data_2LPD_2018 = List_Data_DblMu_2018 + List_Data_DblEG_2018 + List_Data_MuEG_2018
List_Data_SF2L_2018 = List_Data_DblEG_2018 + List_Data_DblMu_2018
List_Data_DiEl_2018 = List_Data_DblEG_2018


##ANALYZER DEPENDENT
#List_Lumi_2017 = List_HNTop_Pivot #[["TT_HeavyN-El_2L_MN50", 1]]
List_Lumi_2017 = List_HNTop_All

#List_Lumi_2017 = List_HNTop_Pivot


List_MC_DYMiNNLO = [["DYJetsToMuMu_MiNNLO", 20], ["DYJetsToEE_MiNNLO", 20]] 

List_SkimTree_SS2lOR3l_BkdMC = [["DYJetsToMuMu_MiNNLO", 25]]

#List_SkimTree_SS2lOR3l_BkdMC = [["WZ_pythia", 2], ["WW_pythia", 2], ["ZZ_pythia", 2],]
#List_SkimTree_SS2lOR3l_BkdMC = List_MC_PrSS2l + List_MC_Cv2l + List_HNTop_Pivot


########################################################################################

List_ControlPlots_BkdMC_2017 = [
#  ["DYJets", 21], ["DYJets10to50_MG", 13],
#  ["WZTo2L2Q_amcatnlo", 7], ["WZTo3LNu_powheg", 3], ["ZZTo2L2Q_amcatnlo", 7], ["ZZTo2L2Nu_powheg", 3], ["ZZTo4L_powheg", 3], ["WWTo2L2Nu_powheg", 3], 
#  ["TTLL_powheg", 13], ["SingleTop_tW_antitop_NoFullyHad", 2], ["SingleTop_tW_top_NoFullyHad", 2],
#  ["WZ_pythia", 1], ["WW_pythia", 2], ["ZZ_pythia", 1], 
  ["TTLL_powheg", 13], ["TTLJ_powheg", 7],
]


List_BTagEff_MC_BkdMC_2017 = [["TTLJ_powheg", 8], ["TTLL_powheg", 13], ["DYJets", 21]]
List_BTagEff_MC_BkdMC_2018 = [["TTLJ_powheg", 50], ["TTLL_powheg", 13]]

List_TestRun_Data_2016_TriMu = [
  ["DoubleMuon", 15, "B_ver2"], ["DoubleMuon", 7, "C"], ["DoubleMuon", 11, "D"], ["DoubleMuon", 11, "E"], ["DoubleMuon", 8, "F"], ["DoubleMuon", 16, "G"], ["DoubleMuon", 14, "H"],
]
List_TestRun_Data_2016_ElDiMu = [
  ["MuonEG", 15, "B_ver2"], ["MuonEG", 7, "C"], ["MuonEG", 11, "D"], ["MuonEG", 11, "E"], ["MuonEG", 8, "F"], ["MuonEG", 16, "G"], ["MuonEG", 14, "H"],
]
List_TestRun_Data_2017_TriMu = [
  ["DoubleMuon", 13, "B"], ["DoubleMuon", 15, "C"], ["DoubleMuon", 7, "D"], ["DoubleMuon", 15, "E"], ["DoubleMuon", 24, "F"],
]
List_TestRun_Data_2017_ElDiMu = [
  ["MuonEG", 13, "B"], ["MuonEG", 15, "C"], ["MuonEG", 7, "D"], ["MuonEG", 15, "E"], ["MuonEG", 24, "F"],
]
List_TestRun_Data_2018_TriMu = [
  ["DoubleMuon", 18, "A"], ["DoubleMuon", 9, "B"], ["DoubleMuon", 9, "C"], ["DoubleMuon", 39, "D"],
]
List_TestRun_Data_2018_ElDiMu = [
  ["MuonEG", 18, "A"], ["MuonEG", 9, "B"], ["MuonEG", 9, "C"], ["MuonEG", 39, "D"],
]


List_HNTopFeas_BkdMC_2016 = [
  ["DYJets", 25], ["TTLL_powheg", 13],
  ["ZZTo4L_powheg", 20], ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["ttHToNonbb", 2], ["ttZToLLNuNu", 4], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1],
  ["WZTo3LNu_powheg", 5], ["ttWToLNu", 2], ["WWW", 1], #Only Trilep  
  ["WJets_MG", 13], ["TTLJ_powheg", 25], #Only SS2l
  ["WGToLNuG", 5], ["ZGTo2LG", 5], ["TTG", 5], ["TG", 1], ["VHToNonbb", 1], ["WpWp_EWK", 1], ["WpWp_QCD", 1],
]

List_HNTopFeas_BkdMC_2017 = [
  #["DYJets", 25], ["TTLL_powheg", 13],
  ["ZZTo4L_powheg", 3], ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["ttHToNonbb", 2], ["VHToNonbb", 1], ["ttZToLLNuNu", 4], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1],
  ["WZTo3LNu_powheg", 1], ["ttWToLNu", 2], ["WWW", 1], #Only Trilep  
  ["ZGToLLG", 5], ["TTG", 2],
  #["WJets_MG", 7], ["TTLJ_powheg", 7], #Only SS2l
  #["WGToLNuG", 5], ["TG", 1], ["WpWp_EWK", 1], ["WpWp_QCD", 1],#SS2l
]

List_HNTopFeas_BkdMC_2018 = [
  ["DYJets", 25], ["TTLL_powheg", 13],
  ["ZZTo4L_powheg", 20], ["GluGluHToZZTo4L", 2], ["VBF_HToZZTo4L", 1], ["ttHToNonbb", 2], ["ttZToLLNuNu", 4], ["WWZ", 1], ["WZZ", 1], ["ZZZ", 1],
  ["WZTo3LNu_powheg", 1], ["ttWToLNu", 2], ["WWW", 1], #Only Trilep  
  ["WJets_MG", 13], ["TTLJ_powheg", 25], #Only SS2l
  ["WGToLNuG", 5], ["ZGToLLG", 5], ["TTG", 2], ["TG", 1], ["VHToNonbb", 1], ["WpWp_EWK", 1], ["WpWp_QCD", 1],
]


List_SkimTree_SS2lOR3l_Data_2016 = [
  ["DoubleMuon", 15, "B_ver2"], ["DoubleMuon", 7, "C"], ["DoubleMuon", 11, "D"], ["DoubleMuon", 11, "E"], ["DoubleMuon", 8, "F"], ["DoubleMuon", 16, "G"], ["DoubleMuon", 14, "H"],
  ["MuonEG", 15, "B_ver2"], ["MuonEG", 7, "C"], ["MuonEG", 11, "D"], ["MuonEG", 11, "E"], ["MuonEG", 8, "F"], ["MuonEG", 16, "G"], ["MuonEG", 14, "H"],
  ["DoubleEG", 15, "B_ver2"], ["DoubleEG", 7, "C"], ["DoubleEG", 11, "D"], ["DoubleEG", 11, "E"], ["DoubleEG", 8, "F"], ["DoubleEG", 16, "G"], ["DoubleEG", 14, "H"],
]
List_SkimTree_SS2lOR3l_Data_2017 = [
  ["DoubleMuon", 13, "B"], ["DoubleMuon", 15, "C"], ["DoubleMuon", 7, "D"], ["DoubleMuon", 15, "E"], ["DoubleMuon", 24, "F"],
  ["MuonEG", 13, "B"], ["MuonEG", 15, "C"], ["MuonEG", 7, "D"], ["MuonEG", 15, "E"], ["MuonEG", 24, "F"],
  ["DoubleEG", 13, "B"], ["DoubleEG", 15, "C"], ["DoubleEG", 7, "D"], ["DoubleEG", 15, "E"], ["DoubleEG", 24, "F"],
]
List_SkimTree_SS2lOR3l_Data_2018 = [
  ["DoubleMuon", 18, "A"], ["DoubleMuon", 9, "B"], ["DoubleMuon", 9, "C"], ["DoubleMuon", 39, "D"],
  ["MuonEG", 18, "A"], ["MuonEG", 9, "B"], ["MuonEG", 9, "C"], ["MuonEG", 39, "D"],
  ["EGamma", 18, "A"], ["EGamma", 9, "B"], ["EGamma", 9, "C"], ["EGamma", 39, "D"],
]

List_SkimTree_TrigInfo_Data_2017 = [
  ["SingleMuonTrigInfo", 13, "B"], ["SingleMuonTrigInfo", 15, "C"], ["SingleMuonTrigInfo", 7, "D"], ["SingleMuonTrigInfo", 15, "E"], ["SingleMuonTrigInfo", 24, "F"],
  ["SingleElectronTrigInfo", 13, "B"], ["SingleElectronTrigInfo", 15, "C"], ["SingleElectronTrigInfo", 7, "D"], ["SingleElectronTrigInfo", 15, "E"], ["SingleElectronTrigInfo", 24, "F"],
]

List_SkimTree_SS2lOR3l_BkdMC_2017 = [
  ["TTLJ_powheg", 25], ["TTLL_powheg", 25],
]



List_SkimRateCheck_BkdMC_2016 = [
  ["DYJets", 25], ["TTLL_powheg", 13], ["WJets_MG", 13], ["TTLJ_powheg", 25], #Only SS2l
]


List_MCPUDist17_BkdMC_2017 = [
  ["DYJets_MG_HT-40to70", 10], ["DYJets_MG_HT-70to100", 10], ["DYJets_MG_HT-100to200", 10], ["DYJets_MG_HT-200to400", 10], ["DYJets_MG_HT-400to600", 10], ["DYJets_MG_HT-600to800", 10], ["DYJets_MG_HT-800to1200", 5], ["DYJets_MG_HT-1200to2500", 5], ["DYJets_MG_HT-2500toInf", 5], 
]







List_GenMatchingValid_BkdMC_2016 = [
  ["ZGTo2LG", 5], ["TTLJ_powheg", 25],
]

List_GenMatchingValid_BkdMC_2017 = [
  ["ZGToLLG", 5], ["TTLJ_powheg", 7],
]

List_GenMatchingValid_BkdMC_2018 = [
  ["ZGToLLG", 5], ["TTLJ_powheg", 25],
]

List_GenMatchingValid_SigMC_2017 = [
#  ["TT_TTobNMu_SS2L_LO_MN20", 1], ["TT_TTobNMu_SS2L_LO_MN50", 1], ["TT_TTobNMu_SS2L_LO_MN100", 1],
  ["TTbarTypeIHeavyN-El_2L_MLM_MN100",1], ["TTbarTypeIHeavyN-El_2L_MLM_MN20" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN30" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN40" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN50" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN60" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN70" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN75" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN85" ,1], ["TTbarTypeIHeavyN-El_2L_MLM_MN90" ,1],
#  ["TTbarTypeIHeavyN-Mu_2L_MLM_MN100",1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN20" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN30" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN40" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN50" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN60" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN70" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN75" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN85" ,1], ["TTbarTypeIHeavyN-Mu_2L_MLM_MN90" ,1]
]

List_IDOptimization_BkdMC_2016 = [
  ["TTLJ_powheg", 25],
]

List_IDOptimization_BkdMC_2017 = [
#  ["ZGToLLG", 5],
  ["TTLL_powheg", 13], ["TTLJ_powheg", 15],
#  ["TTLL_powheg_TrigInfo", 13], ["TTLJ_powheg_TrigInfo", 15],
#  ["DYJets", 25], ["WJets_MG", 7],
#  ["DYJets_TrigInfo", 10],
]

List_IDOptimization_BkdMC_2018 = [
  ["TTLJ_powheg", 25],
]


List_MeasTrigEff_BkdMC_2017 = [["TTLL_powheg_TrigInfo", 13], ["DYJets_TrigInfo", 10]]
#List_MeasTrigEff_BkdMC_2017 = [["TTLL_powheg", 13], ["DYJets",25]]
List_MeasTrigEff_Data_2017_DiMu = [
  ["DoubleMuon", 13, "B"], ["DoubleMuon", 15, "C"], ["DoubleMuon", 7, "D"], ["DoubleMuon", 15, "E"], ["DoubleMuon", 24, "F"],
]
List_MeasTrigEff_Data_2017_ElMu = [
  ["MuonEG", 13, "B"], ["MuonEG", 15, "C"], ["MuonEG", 7, "D"], ["MuonEG", 15, "E"], ["MuonEG", 24, "F"],
#  ["SingleMuonTrigInfo", 13, "B"], ["SingleMuonTrigInfo", 15, "C"], ["SingleMuonTrigInfo", 7, "D"], ["SingleMuonTrigInfo", 15, "E"], ["SingleMuonTrigInfo", 24, "F"],
#  ["SingleElectronTrigInfo", 13, "B"], ["SingleElectronTrigInfo", 15, "C"], ["SingleElectronTrigInfo", 7, "D"], ["SingleElectronTrigInfo", 15, "E"], ["SingleElectronTrigInfo", 24, "F"],
]


List_Debug_SigMC_2016 = [["TestFiltered_TTToHcToWA_AToMuMu_MHc160_MA75", 1]]
List_Debug_BkdMC_2016a = [["DYJets", 1]]
List_Debug_BkdMC_2016b = [["TTLJ_powheg", 1]]
List_Debug_Data_2016a = [["DoubleMuon", 1, "B_ver2"]]
List_Debug_SigMC_2017 = [
  #["TT_HeavyN-El_2L_MN20", 1],
  #["TT_HeavyN-Mu_2L_MN20", 1],
  ["TT_HeavyN-Mu_LepSMTop_3L_MN100", 1],
  ["TT_HeavyN-Mu_HadSMTop_3L_MN100", 1],
  ["TT_HeavyN-Mu_4L_MN100", 1],
]
#List_Debug_BkdMC_2017 = [["ttHToNonbb", 1]]
#List_Debug_BkdMC_2017 = [["ZGToLLG", 1]]
#List_Debug_BkdMC_2017 = [["WZTo3LNu_amcatnlo", 1]]
#List_Debug_BkdMC_2017 = [["DYJets", 1]]
List_Debug_BkdMC_2017 = [["TTLL_powheg", 1], ["DYJets", 1]]
#List_Debug_BkdMC_2017 = [["ZZTo4L_powheg", 1], ["GluGluHToZZTo4L", 1],]

#List_Debug_BkdMC_2017 = [["ttWToLNu", 1]]
#List_Debug_BkdMC_2017 = [["WGToLNuG", 1]]
List_Debug_Data_2017 = [["DoubleEG", 1, "B"]]
List_Debug_Flip_2017 = [["TTLL_powheg", 1], ["DYJets", 1]]
>>>>>>> Run2UltraLegacy
#List_Debug_Data_2017 = [["DoubleMuon", 1, "B"]]
List_Debug_SigMC_2018 = [["TestFiltered_TTToHcToWA_AToMuMu_MHc160_MA75", 1]]
List_Debug_BkdMC_2018 = [["DYJets", 10]]
List_Debug_Data_2018 = [["SingleMuon", 1, "B"]]



Dict_JobConfig = {
 "GetEffLumi_MC_2016a" : List_Lumi_2017,
 "GetEffLumi_MC_2016b" : List_Lumi_2017,
 "GetEffLumi_MC_2017"  : List_Lumi_2017,
 "GetEffLumi_MC_2018"  : List_Lumi_2017,
 "MeasureJetTaggingEfficiency_BkdMC_2016a" : List_MC_TT,
 "MeasureJetTaggingEfficiency_BkdMC_2016b" : List_MC_TT,
 "MeasureJetTaggingEfficiency_BkdMC_2017"  : List_MC_TT,
 "MeasureJetTaggingEfficiency_BkdMC_2018"  : List_MC_TT,
 "SkimTree_SS2lOR3l_BkdMC_2016a"        : List_SkimTree_SS2lOR3l_BkdMC,
 "SkimTree_SS2lOR3l_BkdMC_2016b"        : List_SkimTree_SS2lOR3l_BkdMC,
 "SkimTree_SS2lOR3l_BkdMC_2017"         : List_SkimTree_SS2lOR3l_BkdMC,
 "SkimTree_SS2lOR3l_BkdMC_2018"         : List_SkimTree_SS2lOR3l_BkdMC,
 "SkimTree_SS2lOR3l_Data_2016a_SS2lOR3l": List_Data_2LPD_2016a+List_Data_1LPD_2016a,
 "SkimTree_SS2lOR3l_Data_2016b_SS2lOR3l": List_Data_2LPD_2016b+List_Data_1LPD_2016b,
 "SkimTree_SS2lOR3l_Data_2017_SS2lOR3l" : List_Data_2LPD_2017+ List_Data_1LPD_2017,
 "SkimTree_SS2lOR3l_Data_2018_SS2lOR3l" : List_Data_2LPD_2018+ List_Data_1LPD_2018,
 "DiLepValid_Data_2016a_ElEl" : List_Data_DblEG_2016a,
 "DiLepValid_Data_2016a_MuMu" : List_Data_DblMu_2016a,
 "DiLepValid_Data_2016a_SF2L" : List_Data_DblMu_2016a+List_Data_DblEG_2016a,
 "DiLepValid_Data_2016a_ElMu" : List_Data_MuEG_2016a,
 "DiLepValid_Data_2016b_ElEl" : List_Data_DblEG_2016b,
 "DiLepValid_Data_2016b_MuMu" : List_Data_DblMu_2016b,
 "DiLepValid_Data_2016b_SF2L" : List_Data_DblMu_2016b+List_Data_DblEG_2016b,
 "DiLepValid_Data_2016b_ElMu" : List_Data_MuEG_2016b,
 "DiLepValid_Data_2017_ElEl"  : List_Data_DblEG_2017,
 "DiLepValid_Data_2017_MuMu"  : List_Data_DblMu_2017,
 "DiLepValid_Data_2017_SF2L"  : List_Data_DblMu_2017+List_Data_DblEG_2017,
 "DiLepValid_Data_2017_ElMu"  : List_Data_MuEG_2017,
 "DiLepValid_Data_2018_ElEl"  : List_Data_DblEG_2018,
 "DiLepValid_Data_2018_MuMu"  : List_Data_DblMu_2018,
 "DiLepValid_Data_2018_SF2L"  : List_Data_DblMu_2018+List_Data_DblEG_2018,
 "DiLepValid_Data_2018_ElMu"  : List_Data_MuEG_2018,
 "DiLepValid_BkdMC_2016a"     : List_MC_PrOS2l,
 "DiLepValid_BkdMC_2016b"     : List_MC_PrOS2l,
 "DiLepValid_BkdMC_2017"      : List_MC_PrOS2l, #List_MC_PrOS2l,
 "DiLepValid_BkdMC_2018"      : List_MC_PrOS2l,
 "IDOptimization_BkdMC_2016a": List_MC_TT,#TT
 "IDOptimization_BkdMC_2016b": List_MC_TT,#TT
 "IDOptimization_BkdMC_2017" : List_MC_TT,#TT
 "IDOptimization_BkdMC_2018" : List_MC_TT,#TT
 "IDOptimization_SigMC_2016a" : List_HNTop_Mu_Pivot,
 "IDOptimization_SigMC_2016b" : List_HNTop_Mu_Pivot,
 "IDOptimization_SigMC_2017"  : List_HNTop_Mu_Pivot,
 "IDOptimization_SigMC_2018"  : List_HNTop_Mu_Pivot,
 "MCFakeStudy_BkdMC_2016a": List_MC_TT,#List_MC_QCD_MuFilt,
 "MCFakeStudy_BkdMC_2016b": List_MC_TT,#List_MC_QCD_MuFilt,
 "MCFakeStudy_BkdMC_2017" : List_MC_TT,#List_MC_QCD_MuFilt, #Fk2l Cv2l QCD PrSS2l QCD
 "MCFakeStudy_BkdMC_2018" : List_MC_TT,#List_MC_QCD_MuFilt,
 "MCFakeStudy_SigMC_2016a" : List_HNTop_Mu_Pivot,
 "MCFakeStudy_SigMC_2016b" : List_HNTop_Mu_Pivot,
 "MCFakeStudy_SigMC_2017"  : List_HNTop_Mu_Pivot,
 "MCFakeStudy_SigMC_2018"  : List_HNTop_Mu_Pivot,
 "FakeRateMeas_BkdMC_2016a": List_MC_Pr1l,
 "FakeRateMeas_BkdMC_2016b": List_MC_Pr1l,
 "FakeRateMeas_BkdMC_2017" : List_MC_Pr1l,
 "FakeRateMeas_BkdMC_2018" : List_MC_Pr1l, #List_MC_Pr1l,
 "FakeRateMeas_Data_2016a_El": List_Data_DblEG_2016a,
 "FakeRateMeas_Data_2016a_Mu": List_Data_DblMu_2016a,
 "FakeRateMeas_Data_2016b_El": List_Data_DblEG_2016b,
 "FakeRateMeas_Data_2016b_Mu": List_Data_DblMu_2016b,
 "FakeRateMeas_Data_2017_El" : List_Data_SglEl_2017,
 "FakeRateMeas_Data_2017_Mu" : List_Data_DblMu_2017,#List_Data_SglMu_2017,
 "FakeRateMeas_Data_2018_El" : List_Data_DblEG_2018,
 "FakeRateMeas_Data_2018_Mu" : List_Data_DblMu_2018,#List_Data_SglMu_2018,
 "ControlPlots_Flip_2016a"         : List_MC_PrOS2l,
 "ControlPlots_Conv_2016a"         : List_MC_Cv2l,
 "ControlPlots_BkdMC_2016a"        : List_MC_PrSS2l, # PrSS2l TrigClos
 "ControlPlots_SigMC_2016a"        : List_HNTop_Pivot,
 "ControlPlots_Data_2016a_OS2l"    : List_Data_DblEG_2016a, #2LPD
 "ControlPlots_Data_2016a_SS2l"    : List_Data_SF2L_2016a, #SF2L
 "ControlPlots_Data_2016a_TriLep"  : List_Data_SF2L_2016a, #2LPD
 "ControlPlots_Data_2016a_TetraLep": List_Data_2LPD_2016a, #2LPD
 "ControlPlots_Flip_2016b"         : List_MC_PrOS2l,
 "ControlPlots_Conv_2016b"         : List_MC_Cv2l,
 "ControlPlots_BkdMC_2016b"        : List_MC_PrSS2l,# PrSS2l TrigClos
 "ControlPlots_SigMC_2016b"        : List_HNTop_Pivot,
 "ControlPlots_Data_2016b_OS2l"    : List_Data_DblEG_2016b, #2LPD
 "ControlPlots_Data_2016b_SS2l"    : List_Data_SF2L_2016b, #SF2L
 "ControlPlots_Data_2016b_TriLep"  : List_Data_SF2L_2016b, #2LPD
 "ControlPlots_Data_2016b_TetraLep": List_Data_2LPD_2016b, #2LPD
 "ControlPlots_Flip_2017"         : List_MC_PrOS2l,
 "ControlPlots_Conv_2017"         : List_MC_Cv2l,
 "ControlPlots_BkdMC_2017"        : List_MC_PrSS2l,# PrSS2l TrigClos
 "ControlPlots_SigMC_2017"        : List_HNTop_Pivot,
 "ControlPlots_Data_2017_OS2l"    : List_Data_DblEG_2017, #2LPD
 "ControlPlots_Data_2017_SS2l"    : List_Data_SF2L_2017, #SF2L
 "ControlPlots_Data_2017_TriLep"  : List_Data_SF2L_2017, #2LPD
 "ControlPlots_Data_2017_TetraLep": List_Data_2LPD_2017, #2LPD
 "ControlPlots_Flip_2018"         : List_MC_PrOS2l,
 "ControlPlots_Conv_2018"         : List_MC_Cv2l,
 "ControlPlots_BkdMC_2018"        : List_MC_PrSS2l,# PrSS2l TrigClos
 "ControlPlots_SigMC_2018"        : List_HNTop_Pivot,
 "ControlPlots_Data_2018_OS2l"    : List_Data_DblEG_2018, #2LPD
 "ControlPlots_Data_2018_SS2l"    : List_Data_SF2L_2018, #SF2L
 "ControlPlots_Data_2018_TriLep"  : List_Data_SF2L_2018, #2LPD
 "ControlPlots_Data_2018_TetraLep": List_Data_2LPD_2018, #2LPD
 "MeasTrigEff_Data_2016a_ElMuSE" : List_Data_SglEl_2016a,
 "MeasTrigEff_Data_2016a_ElMuSM" : List_Data_SglMu_2016a,
 "MeasTrigEff_Data_2016a_ElMuEM" : List_Data_MuEG_2016a,
 "MeasTrigEff_Data_2016a_MuMuMM" : List_Data_DblMu_2016a,
 "MeasTrigEff_Data_2016a_ElElEE" : List_Data_DblEG_2016a,
 "MeasTrigEff_Data_2016b_ElMuSE" : List_Data_SglEl_2016b,
 "MeasTrigEff_Data_2016b_ElMuSM" : List_Data_SglMu_2016b,
 "MeasTrigEff_Data_2016b_ElMuEM" : List_Data_MuEG_2016b,
 "MeasTrigEff_Data_2016b_MuMuMM" : List_Data_DblMu_2016b,
 "MeasTrigEff_Data_2016b_ElElEE" : List_Data_DblEG_2016b,
 "MeasTrigEff_Data_2017_ElMuSE" : List_Data_SglEl_2017,
 "MeasTrigEff_Data_2017_ElMuSM" : List_Data_SglMu_2017,
 "MeasTrigEff_Data_2017_ElMuEM" : List_Data_MuEG_2017,
 "MeasTrigEff_Data_2017_MuMuMM" : List_Data_DblMu_2017,
 "MeasTrigEff_Data_2017_ElElEE" : List_Data_DblEG_2017,
 "MeasTrigEff_Data_2018_ElMuSE" : List_Data_SglEl_2018,
 "MeasTrigEff_Data_2018_ElMuSM" : List_Data_SglMu_2018,
 "MeasTrigEff_Data_2018_ElMuEM" : List_Data_MuEG_2018,
 "MeasTrigEff_Data_2018_MuMuMM" : List_Data_DblMu_2018,
 "MeasTrigEff_Data_2018_ElElEE" : List_Data_DblEG_2018,
 "MeasTrigEff_BkdMC_2016a"      : List_MC_TrigEff,
 "MeasTrigEff_BkdMC_2016b"      : List_MC_TrigEff,
 "MeasTrigEff_BkdMC_2017"       : List_MC_TrigEff,
 "MeasTrigEff_BkdMC_2018"       : List_MC_TrigEff,
 "MeasCFlipRate_BkdMC_2016a"      : List_MC_CFMeas, #CF2l CFMeas
 "MeasCFlipRate_BkdMC_2016b"      : List_MC_CFMeas,
 "MeasCFlipRate_BkdMC_2017"       : List_MC_CFMeas,
 "MeasCFlipRate_BkdMC_2018"       : List_MC_CFMeas,
 "MeasCFlipRate_Data_2016a_All2l" : List_Data_DiEl_2016a,
 "MeasCFlipRate_Data_2016b_All2l" : List_Data_DiEl_2016b,
 "MeasCFlipRate_Data_2017_All2l"  : List_Data_DiEl_2017,
 "MeasCFlipRate_Data_2018_All2l"  : List_Data_DiEl_2018,
 "KinVarSearch_BkdMC_2016a"     : List_MC_TT+List_MC_ttVH,
 "KinVarSearch_SigMC_2016a"     : List_HNTop_Pivot,
 "KinVarSearch_BkdMC_2016b"     : List_MC_TT+List_MC_ttVH,
 "KinVarSearch_SigMC_2016b"     : List_HNTop_Pivot,
 "KinVarSearch_BkdMC_2017"      : List_MC_TT+List_MC_ttVH,
 "KinVarSearch_SigMC_2017"      : List_HNTop_Pivot,
 "KinVarSearch_BkdMC_2018"      : List_MC_TT+List_MC_ttVH,
 "KinVarSearch_SigMC_2018"      : List_HNTop_Pivot,
 "KinVarPlot_Flip_2016a"         : List_MC_PrOS2l,
 "KinVarPlot_Conv_2016a"         : List_MC_Cv2l,
 "KinVarPlot_BkdMC_2016a"        : List_MC_PrSS2l,#+List_MC_Cv2l, # PrSS2l TrigClos
 "KinVarPlot_SigMC_2016a"        : List_HNTop_Pivot,
 "KinVarPlot_Data_2016a_OS2l"    : List_Data_DblEG_2016a, #2LPD
 "KinVarPlot_Data_2016a_SS2l"    : List_Data_SF2L_2016a, #SF2L
 "KinVarPlot_Data_2016a_TriLep"  : List_Data_2LPD_2016a, #2LPD
 "KinVarPlot_Data_2016a_TetraLep": List_Data_2LPD_2016a, #2LPD
 "KinVarPlot_Flip_2016b"         : List_MC_PrOS2l,
 "KinVarPlot_Conv_2016b"         : List_MC_Cv2l,
 "KinVarPlot_BkdMC_2016b"        : List_MC_PrSS2l,#+List_MC_Cv2l,# PrSS2l TrigClos
 "KinVarPlot_SigMC_2016b"        : List_HNTop_Pivot,
 "KinVarPlot_Data_2016b_OS2l"    : List_Data_DblEG_2016b, #2LPD
 "KinVarPlot_Data_2016b_SS2l"    : List_Data_SF2L_2016b, #SF2L
 "KinVarPlot_Data_2016b_TriLep"  : List_Data_2LPD_2016b, #2LPD
 "KinVarPlot_Data_2016b_TetraLep": List_Data_2LPD_2016b, #2LPD
 "KinVarPlot_Flip_2017"         : List_MC_PrOS2l,
 "KinVarPlot_Conv_2017"         : List_MC_Cv2l,
 "KinVarPlot_BkdMC_2017"        : List_MC_PrSS2l,#+List_MC_Cv2l,# PrSS2l TrigClos
 "KinVarPlot_SigMC_2017"        : List_HNTop_Pivot,
 "KinVarPlot_Data_2017_OS2l"    : List_Data_DblEG_2017, #2LPD
 "KinVarPlot_Data_2017_SS2l"    : List_Data_SF2L_2017, #SF2L
 "KinVarPlot_Data_2017_TriLep"  : List_Data_2LPD_2017, #2LPD
 "KinVarPlot_Data_2017_TetraLep": List_Data_2LPD_2017, #2LPD
 "KinVarPlot_Flip_2018"         : List_MC_PrOS2l,
 "KinVarPlot_Conv_2018"         : List_MC_Cv2l,
 "KinVarPlot_BkdMC_2018"        : List_MC_PrSS2l,#+List_MC_Cv2l,# PrSS2l TrigClos
 "KinVarPlot_SigMC_2018"        : List_HNTop_Pivot,
 "KinVarPlot_Data_2018_OS2l"    : List_Data_DblEG_2018, #2LPD
 "KinVarPlot_Data_2018_SS2l"    : List_Data_SF2L_2018, #SF2L
 "KinVarPlot_Data_2018_TriLep"  : List_Data_2LPD_2018, #2LPD
 "KinVarPlot_Data_2018_TetraLep": List_Data_2LPD_2018, #2LPD
 "GenSigStudy_BkdMC_2016a" : List_MC_TT, 
 "GenSigStudy_BkdMC_2016b" : List_MC_TT,
 "GenSigStudy_BkdMC_2017"  : List_MC_TT,
 "GenSigStudy_BkdMC_2018"  : List_MC_TT,
 "GenSigStudy_SigMC_2016a" : List_HNTop_2L_Pivot, # HNTop_2L_Pivot HNTop_Pivot,
 "GenSigStudy_SigMC_2016b" : List_HNTop_2L_Pivot,
 "GenSigStudy_SigMC_2017"  : List_HNTop_2L_Pivot,
 "GenSigStudy_SigMC_2018"  : List_HNTop_2L_Pivot,
 "Debug_BkdMC_2016a" : List_Debug_BkdMC_2016a,
 "Debug_Data_2016a"  : List_Debug_Data_2016a,
 "Debug_BkdMC_2016b" : List_Debug_BkdMC_2016b,
 "Debug_SigMC_2017"  : List_Debug_SigMC_2017,
 "Debug_BkdMC_2017"  : List_Debug_BkdMC_2017,
 "Debug_Data_2017"   : List_Debug_Data_2017,
 "Debug_Flip_2017"   : List_Debug_Flip_2017,
 "Debug_SigMC_2018"  : List_Debug_SigMC_2018,
 "Debug_BkdMC_2018"  : List_Debug_BkdMC_2018,
 "Debug_Data_2018"   : List_Debug_Data_2018,

# ##Old Lists
# "MC_NonFk3l_2017": List_MC_Pr3l_2017,
# "GenMatchingValid_BkdMC_2016": List_GenMatchingValid_BkdMC_2016,
# "GenMatchingValid_BkdMC_2017": List_GenMatchingValid_BkdMC_2017,
# "GenMatchingValid_BkdMC_2018": List_GenMatchingValid_BkdMC_2018,
# "GenMatchingValid_SigMC_2017": List_GenMatchingValid_SigMC_2017,
# "SkimRateCheck_BkdMC_2016": List_SkimRateCheck_BkdMC_2016,
# "SkimRateCheck_Data_2016_SS2lOR3l": List_SkimTree_SS2lOR3l_Data_2016,
# "SkimRateCheck_Data_2017_TrigInfo": List_SkimTree_TrigInfo_Data_2017,
# #"ControlPlots_BkdMC_2017": List_MC_PrOS2l_2017,
# #"ControlPlots_FkMC_2017": List_MC_PrOS2l_2017,
# "ControlPlots_Conv_2017": List_MC_Cv2l_2017,
# "ControlPlots_BkdMC_2017": List_MC_PrSS2l_2017,
# "ControlPlots_FkMC_2017": List_MC_PrSS2l_2017+List_MC_Cv2l_2017,
# "ControlPlots_FkConv_2017": List_MC_Cv2l_2017,
## "ControlPlots_Conv_2017": List_MC_Cv3l_2017,
## "ControlPlots_BkdMC_2017": List_MC_Pr3l_2017,
## "ControlPlots_FkMC_2017": List_MC_Pr3l_2017,
## "ControlPlots_FkConv_2017": List_MC_Cv3l_2017,
# "ControlPlots_SigMC_2017": List_HNTopV2_SigMC_2017,
# "ControlPlots_Data_2017_OS2l": List_Data_2LPD_2017,
# "ControlPlots_Flip_2017_SS2l": List_Data_DiEl_2017,
# "ControlPlots_Data_2017_SS2l": List_Data_SF2L_2017,
# "ControlPlots_Data_2017_TriLep": List_Data_2LPD_2017,
# "GenSystStudy_BkdMC_2017": List_MC_TT_2017,
# "GenSystStudy_SigMC_2017": List_HNTopV3_SigMC_2017,
# "HNTopFeas_BkdMC_2016": List_HNTopFeas_BkdMC_2016,
# "HNTopFeas_BkdMC_2017": List_HNTopFeas_BkdMC_2017,
# "HNTopFeas_BkdMC_2018": List_HNTopFeas_BkdMC_2018,
# "HNTopFeas_SigMC_2017": List_HNTopV2_SigMC_2017,
}


List = Dict_JobConfig.get(sys.argv[1])
if not List is None:
  if len(sys.argv) < 3:
    print(len(List))
  else:
    if "MC_" in sys.argv[1] or "Conv_" in sys.argv[1] or "_Flip_" in sys.argv[1]:
      print(str(List[int(sys.argv[2])][0])+" "+str(List[int(sys.argv[2])][1]))
    elif "_Data_" in sys.argv[1]:
    #elif "Data" in sys.argv[1] or "Fake" in sys.argv[1] or "Flip" in sys.argv[1]:
      print(str(List[int(sys.argv[2])][0])+" "+str(List[int(sys.argv[2])][1])+" "+str(List[int(sys.argv[2])][2]))
    else:
      print("invalid runMode option")
else:
  print("Error : No such list")
