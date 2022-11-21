import os

NTreeOptions = [500 ]
NCuts = [300]
Channels = ["EE","MuMu"]
SignalModes =  [0,1,2]
MaxDepths = [4]
NEGWEIGHT = [" --IgnoreNE "]
NormModes = ["EqualNumEvents"]
AdaBoostBetaValues = ["0.5"]
Eras = ["2017","Run2"]

for NTREES in NTreeOptions:
    for NCut in NCuts:
        for SignalMode in SignalModes:
            for MaxDepth in MaxDepths:
                for NEG in NEGWEIGHT:
                    for NormMode in NormModes:
                        for AdaBoostBeta in AdaBoostBetaValues:
                            for Era in Eras:
                                for Channel in Channels:
                            
                                    nMAX = " --nmax 30"
                                    if SignalMode == 1:
                                        nMAX = " --nmax 25"
                                    if SignalMode == 0:
                                        nMAX = " --nmax 20"
                                    if Era == "Run2":
                                        nMAX =  " --nmax 2"

                                    os.system("RunIDBDT.py -a runIDBDT_HNtypeICF -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + NEG +  " -Nrom " +NormMode+ " -AdaBoostBeta " + AdaBoostBeta + " -e "+Era+" " + nMAX )    
                                
                    
