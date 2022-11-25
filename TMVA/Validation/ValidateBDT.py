import os,ROOT
from os import listdir
from os.path import isfile,isdir, join

def AUCCalc(filepath):


    RootFile = ROOT.TFile(filepath)
    if not RootFile:
        return -1

    ClassifierTag="BDT"

    if "BDTG" in filepath:
        ClassifierTag="BDTG"

    BkgRej="dataset/Method_BDT/"+ClassifierTag+"/MVA_"+ClassifierTag+"_rejBvsS"
    
    HistBkgReg = RootFile.Get(BkgRej)
    if not HistBkgReg:
        return -1

    print( "AUC = " +  str(HistBkgReg.Integral()/100.))
    return float(HistBkgReg.Integral()/100.)
    
def PerformKolmogorovSmirnov(filepath):
    
    RootFile = ROOT.TFile(filepath)
    if not RootFile:
        return
        
    ClassifierTag="BDT"
    
    if "BDTG" in filepath:
        ClassifierTag="BDTG"

    Train_S="dataset/Method_BDT/"+ClassifierTag+"/MVA_"+ClassifierTag+"_Train_S"
    Test_S="dataset/Method_BDT/"+ClassifierTag+"/MVA_"+ClassifierTag+"_S"
    Train_B="dataset/Method_BDT/"+ClassifierTag+"/MVA_"+ClassifierTag+"_Train_B"
    Test_B="dataset/Method_BDT/"+ClassifierTag+"/MVA_"+ClassifierTag+"_B"
    HistTrain_S = RootFile.Get(Train_S)
    HistTrain_B = RootFile.Get(Train_B)

    HistTest_S = RootFile.Get(Test_S)
    HistTest_B = RootFile.Get(Test_B)

    if not HistTrain_S:
        return 
    
    kolS = HistTest_S.KolmogorovTest( HistTrain_S, "X" );
    kolB = HistTest_B.KolmogorovTest( HistTrain_B, "X" );
    print(filepath+":")
    print("--- Goodness of signal (background) consistency: " + str(kolS)+ " (" + str(kolB) + ")" )

    RootFile.Close()


BDTFile_Dir = "/data6/Users/jalmond/BDTOutput/Run2UltraLegacy_v3/runIDBDT_HNtypeI/Default/2017/"
BDTFileList  = [f for f in listdir(BDTFile_Dir) if isfile(join(BDTFile_Dir,f))]



import argparse
parser = argparse.ArgumentParser(description='option')
parser.add_argument('-b', dest='Bkg', default="NULL")
parser.add_argument('-f', dest='Channel', default="NULL")
parser.add_argument('-c', dest='Classifier', default="BDT")

args = parser.parse_args()

MaxAUC=0.
MaxJob=""
for File in BDTFileList:

    if not args.Bkg in File:
        continue

    
    if not args.Channel in File:
        continue
        
    if not args.Classifier in File:
        continue

    print ("="*50)
    PerformKolmogorovSmirnov(BDTFile_Dir+"/"+File)
    print ("-"*50)
    AUC= AUCCalc(BDTFile_Dir+"/"+File)
    if AUC  > MaxAUC:
        MaxAUC = AUC
        MaxJob=File
    print ("="*50)


print ("%"*50)
print ("%"*50)
print "Max perfomance from " + MaxJob + " with AUC " + str(MaxAUC)
PerformKolmogorovSmirnov(BDTFile_Dir+"/"+MaxJob)

