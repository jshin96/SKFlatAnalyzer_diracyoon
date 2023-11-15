SKFlat.py -l DYB_HT_list.txt -a Vcb_BJetRegression_Single_Mu -n 20 -e 2018 --userflags RunSyst &
SKFlat.py -l DYB_HT_list.txt -a Vcb_BJetRegression_Single_El -n 20 -e 2018 --userflags RunSyst &
SKFlat.py -i EGamma -a Vcb_BJetRegression_Single_El -n 20 -e 2018 --userflags RunSyst &
SKFlat.py -i DoubleMuon -a Vcb_BJetRegression_Single_Mu -n 20 -e 2018 --userflags RunSyst &
