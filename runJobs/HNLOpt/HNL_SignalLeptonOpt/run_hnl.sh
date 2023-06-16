### SETUP RUN OPTIONS
analyzer=HNL_SignalLeptonOpt
rundir=HNLOpt/HNL_SignalLeptonOpt

# PATHS                                                                                                                                                    
runPATH=${SKFlat_WD}/runJobs/${rundir}/
sigpath=${SKFlat_WD}/runJobs/SampleLists/Signals/
mcpath=${SKFlat_WD}/runJobs/SampleLists/Bkg/
datapath=${SKFlat_WD}/runJobs/SampleLists/Data/

#SKIM                                                                                                                                                     
skim=' '

# JOB CONFIG                                                                                                                                               
njobs=25
nLargejobs=50
njobs_sig=30
njobs_data=10
nmax=350



if [[ $1 == "ELECTRON_CF" ]]; then

    declare  -a era_list=("2017" )

    for i in "${era_list[@]}"
    do

        Flag='RunEE,ELID_CF,BB,Bin1'
	source ${runPATH}/run_hnl.sh Electron ${Flag} ${i}

        Flag2='RunEE,ELID_CF,EC,Bin1'
	source ${runPATH}/run_hnl.sh Electron ${Flag2} ${i}

	Flag='RunEE,ELID_CF,FullEta,Bin1'
	source ${runPATH}/run_hnl.sh Electron ${Flag} ${i}

    done
fi



if [[ $1 == "ELID_NP" ]]; then

    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do

        Flag='RunEE,ELID_NP,Bin2,BB'                                                                                                           
	source ${runPATH}/run_hnl.sh Electron ${Flag} ${i}                   
	
	Flag='RunEE,ELID_NP,Bin2,EC'                                                                                               
        source ${runPATH}/run_hnl.sh Electron ${Flag} ${i}


    done
fi

if [[ $1 == "ELID_CONV" ]]; then

    declare  -a era_list=("2016postVFP" "2016preVFP"  "2018")

    for i in "${era_list[@]}"
    do

        Flag='RunEE,ELID_Conv'
        source ${runPATH}/run_hnl.sh Electron ${Flag} ${i}

    done
fi



#############################################################################                                                                                                                                                               
#############################################################################                                                                                                                                                               
#############################################################################     




if [[ $1 == "Electron" ]]; then

    # If no inut then this is ran                                                                                                                        
    source ${runPATH}/run_hnl.sh SignalsID ${3} ${2} &
    source ${runPATH}/run_hnl.sh MC  ${3} ${2}  &
    
    CFFlag=${2}',RunCF'
    source ${runPATH}/run_hnl.sh CF ${3} ${CFFlag}  &
    ConvFlag=${2}',RunConv'
    source ${runPATH}/run_hnl.sh Conv ${3} ${ConvFlag}  &
   
    FakeFlag=${2}',RunFake'
    source ${runPATH}/run_hnl_muon.sh FakeAll  ${3} ${FakeFlag}  &
    PromptFlag=${2}',RunPrompt'
    source ${runPATH}/run_hnl_muon.sh Prompt  ${3} ${PromptFlag}  &


fi




if [[ $1 == "CF" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/CF.txt  -n $njobs  --nmax ${nmax}   -e ${2} --skim SkimTree_HNMultiLepBDT  --userflags ${3} &
    #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i} --userflags RunCF  &                                 

fi


if [[ $1 == "Fake" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/FakeOpt.txt       -n $njobs       --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptXLarge.txt -n 100          --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &

fi


if [[ $1 == "FakeAll" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/FakeOptAll.txt     -n $njobs       --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptXLarge.txt -n 100          --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &

fi

if [[ $1 == "Prompt" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/MCOpt.txt  -n $njobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/MCOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &

fi



if [[ $1 == "SignalsID" ]]; then

    SKFlat.py -a $analyzer  -l $sigpath/DYIDOpt.txt    -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs_sig  --nmax ${nmax}  -e ${2}  --userflags ${3}  --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/VBFOpt.txt   -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&

fi


if [[ $1 == "Signals" ]]; then

    SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs_sig  --nmax ${nmax}  -e ${2}  --userflags ${3}  --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/DYOpt.txt    -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/VBFOpt.txt   -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&

fi


if [[ $1 == "Conv" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n 5  --nmax ${nmax}   -e ${2} --skim SkimTree_HNMultiLepBDT  --userflags ${3}
fi



