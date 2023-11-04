analyzer=HNL_LeptonFakeRate
rundir=HNL_LeptonFakeRate
mcpath=${SKFlat_WD}/runJobs/HNL/${rundir}/mc_lists/
datapath=${SKFlat_WD}/runJobs/HNL/${rundir}/data_lists/
njobs=400
njobs_data=100
nmax=500
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

if [[ $1 == "MCFakes" ]]; then                                                                                                                                                                               

    for i in "${era_list[@]}"                                                                                                                                                                                     
    do
	SKFlat.py -a $analyzer  -l ${mcpath}/QCD_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags MCFakes&                                                     
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags MCFakes&                                            
    done                                                                                                                                                                                                    
    
fi  

                           


if [[ $1 == "CheckProfile" ]]; then
    for i in "${era_list[@]}"
    do

        #SKFlat.py -a $analyzer  -l ${mcpath}/QCD_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags CheckProfile&
        #SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags CheckProfile&
	#SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags CheckProfile&                                                   
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags CheckProfileEE&                                                   
    done
fi


if [[ $1 == "Rates" ]]; then

    for i in "${era_list[@]}"
    do

        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRates&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRates&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_MuMu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_DileptonBDT --userflags RunRates&
        #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFakeBDT --userflags RunRates&
    done
   
fi


if [[ $1 == "MakeRegionPlots" ]]; then
    for i in "${era_list[@]}"
    do

        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&                                              
        SKFlat.py -a $analyzer  -l ${mcpath}/QCD_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags MakeRegionPlots&                                                     
	
        #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFakeBDT --userflags RunRates&                                                         
    done

fi

if [[ $1 == "Test" ]]; then

    SKFlat.py -a $analyzer  -i DYJets  -n 2  --nmax ${nmax}  -e 2017 --skim SkimTree_HNFakeBDT&

fi

