import os

Classifiers = ["BDTG"]
NTreeOptions = [1000]
NCuts = [200]
Channels = ["EE"]
SignalModes =  [1]
VarModes = [0,1,2]
MaxDepths = [4]
EtaBin = [-1]
NormModes = ["EqualNumEvents"]
Eras = ["2017", "2018"]
Seeds = ["100"]
MinNodeSizes = ["2.5", "5.0"]
BoostLearningValues = ["0.05","0.1","0.5"]
BaggedFracs = ["0.6","0.8"]
BDTVersion = "Version7"

for Classifier in Classifiers:
    
    for NTREES in NTreeOptions:
        for NCut in NCuts:
            for SignalMode in SignalModes:
                for VarMode in VarModes:
                    for MaxDepth in MaxDepths:
                        for Eta in EtaBin:
                            for NormMode in NormModes:
                                
                                for BoostLearningValue in BoostLearningValues:
                                    for BaggedFrac in BaggedFracs:
                                        for Channel in Channels:
                                            for Seed in Seeds:
                                                for MinNodeSize in MinNodeSizes:
                                                    for Era in Eras:

                                                        nMAX = " --nmax 200"

                                                        #os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFake -m " + str(Classifier) + " -b FakeBkgTop -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)    
                                                        
                                                        os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFake -m " + str(Classifier) + " -b FakeBkg -ns "+str(SignalMode)+  " -nv  "+str(VarMode)+  "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)    
                                                        
                                                        #os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFake -m " + str(Classifier) + " -b FakeBkg_LF -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)   
                                                        
                                                        #os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFakeHF -m " + str(Classifier) + " -b FakeBkg_HF -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)    
                                                        
                                                        #os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFakeHF -m " + str(Classifier) + " -b FakeBkg_HFB -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)    
                                                        
                                                        #os.system("RunIDBDT.py -a runIDBDT_HNtypeIElectronFakeHF -m " + str(Classifier) + " -b FakeBkg_HFC -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + " -eta "+ str(Eta) +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFrac +  " -s " + Seed + "  -e "+Era+" " + nMAX + " -MinNodeSize "+MinNodeSize + " -t " + BDTVersion)    
                                                    
