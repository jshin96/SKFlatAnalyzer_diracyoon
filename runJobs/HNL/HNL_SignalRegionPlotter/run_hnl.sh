analyzer=HNL_SignalRegion_Plotter
#analyzer=GetEffLumi
rundir=HNL_SignalRegion_Plotter
runPATH=${SKFlat_WD}/runJobs/HNL/${rundir}/
sigpath=${SKFlat_WD}/runJobs/SampleLists/Signals/
mcpath=${SKFlat_WD}/runJobs/SampleLists/Bkg/
datapath=${SKFlat_WD}/runJobs/SampleLists/Data/

njobs=30
njobs_sig=10
njobs_data=100
nmax=400
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

if [[ $1 == "TEST" ]]; then

    declare  -a era_list=( "2017")
    for i in "${era_list[@]}"
    do
	
	SKFlat.py -a $analyzer  -i tZq    -n 1  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT --userflags RunFullSyst &
    done
fi



if [[ $1 == "DY" ]]; then

    SKFlat.py -a $analyzer  -i DYTypeI_DF_M1000_private  -n 20  --nmax ${nmax}   -e 2017 --skim SkimTree_HNMultiLepBDT --userflags RunFullSyst &
    SKFlat.py -a $analyzer  -i DYTypeI_DF_M400_private  -n 20  --nmax ${nmax}   -e 2017 --skim SkimTree_HNMultiLepBDT   --userflags RunFullSyst &

fi



if [[ $1 == "SSWW" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT &
    done

fi



if [[ $1 == "CF" ]]; then

    SKFlat.py -a $analyzer  -l $datapath/2017_DiLepton_EE.txt      -n 400    --nmax ${nmax}   -e 2017 --skim SkimTree_DileptonBDT  --userflags RunCF,RunEE &
    
fi

if [[ $1 == "FAKE" ]]; then

    declare  -a era_list=("2016postVFP")
    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_MuMu.txt      -n 100  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake   &
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake   &
    done

fi


if [[ $1 == "SIG" ]]; then

#    declare  -a era_list=("2016postVFP")
    declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")
    for i in "${era_list[@]}"
    do

	SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --skim SkimTree_HNMultiLepBDT   &
	SKFlat.py -a $analyzer  -l $sigpath/DY.txt    -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
	SKFlat.py -a $analyzer  -l $sigpath/VBF.txt   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
#	SKFlat.py -a $analyzer  -i DYTypeI_DF_M90_private   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
#	SKFlat.py -a $analyzer  -i DYTypeI_DF_M85_private   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
#	SKFlat.py -a $analyzer  -i VBFTypeI_DF_M300_private   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
#	SKFlat.py -a $analyzer  -i VBFTypeI_DF_M400_private   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
    done
    
fi

if [[ $1 == "DATA" ]]; then

    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_MuMu.txt      -n 100  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT    &
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT    &
  done
fi

if [[ $1 == "SYST" ]]; then

    for i in "${era_list[@]}"
    do
        #SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax 200   -e ${i} --skim SkimTree_DileptonBDT  --userflags RunCF,RunSyst
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_MuMu.txt      -n 600  --nmax 600   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake,RunSyst   
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 600    --nmax 600   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake,RunSyst   
    done
fi

if [[ $1 == "" ]]; then

#    declare  -a era_list=("2017" "2018" "2016preVFP" "2016postVFP")
    declare  -a era_list=("")

    for i in "${era_list[@]}"
    do
	
        #SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --skim SkimTree_HNMultiLepBDT &
	#SKFlat.py -a $analyzer  -l $sigpath/DY.txt    -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT &
        #SKFlat.py -a $analyzer  -l $sigpath/VBF.txt   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT &
	
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_MuMu.txt      -n 100  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT    &
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT    &
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EMu.txt      -n 100    --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT   &
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_MuMu.txt      -n 100  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake   &
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake   &
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EMu.txt      -n 100    --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  --userflags RunFake   &

	SKFlat.py -a $analyzer  -l $mcpath/PromptSS.txt             -n 20        --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt &
        SKFlat.py -a $analyzer  -l $mcpath/PromptSS2.txt            -n 200       --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt &
        SKFlat.py -a $analyzer  -l $mcpath/Conv.txt                 -n 10        --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT  --userflags RunConv & 
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton_EE.txt      -n 100    --nmax ${nmax}   -e ${i} --skim SkimTree_DileptonBDT  --userflags RunCF 

	
    done

fi

