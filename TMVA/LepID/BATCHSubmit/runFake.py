import os

Classifiers = ["BDTA","BDTG"]
NTreeOptions = [500,1000 ]
NCuts = [300]
Channels = ["EE","MuMu"]
SignalModes =  [1]
MaxDepths = [2,3,4]
NEGWEIGHT = [" --IgnoreNE "]
NormModes = ["EqualNumEvents"]
Eras = ["2017"]

BoostLearningValues = ["0.05","0.1","0.2","0.5","1."]
BaggedFracs =  ["0.3","0.5","0.7"]

for Classifier in Classifiers:
    
    
    for NTREES in NTreeOptions:
        for NCut in NCuts:
            for SignalMode in SignalModes:
                for MaxDepth in MaxDepths:
                    for NEG in NEGWEIGHT:
                        for NormMode in NormModes:
                            
                            for BoostLearningValue in BoostLearningValues:
                                for BaggedFracs in BaggedFracs:
                                    for Era in Eras:
                                        for Channel in Channels:

                                            nMAX = " --nmax 40"
                                            if SignalMode == 1:
                                                nMAX = " --nmax 35"
                                            if SignalMode == 0:
                                                nMAX = " --nmax 30"
                                            if Era == "Run2":
                                                nMAX =  " --nmax 4"

                                            os.system("RunIDBDT.py -a runIDBDT_HNtypeI -m " + str(Classifier) + " -b Fake -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + NEG +  " -Nrom " +NormMode+ " -BoostLearningRate  " + BoostLearningValue + " -BaggedFrac " + BaggedFracs +  " -e "+Era+" " + nMAX )    
                                
