import os

NTreeOptions = [50,100,400,800]
NCuts = [100,200]
Channels = ["EE","MuMu"]
SignalModes =  [0,1,2]
MaxDepths = [2,3,4]
NEGWEIGHT = ["" , " --IgnoreNE "]


for NTREES in NTreeOptions:
    for NCut in NCuts:
        for SignalMode in SignalModes:
            for MaxDepth in MaxDepths:
                for NEG in NEGWEIGHT:
                    for Channel in Channels:
                        os.system("RunIDBDT.py -a runIDBDT_HNtypeIFake -ns "+str(SignalMode)+ "  -nt "+ str(NTREES) + " -c " + Channel + " -MaxDepth  " + str(MaxDepth) + " -ncut " + str(NCut) + NEG)
                    
