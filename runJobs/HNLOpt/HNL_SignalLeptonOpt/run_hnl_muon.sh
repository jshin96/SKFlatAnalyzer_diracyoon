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


if [[ $1 == "" ]]; then

    declare  -a era_list=("2017" )

    for i in "${era_list[@]}"
    do
	
	SKFlat.py -a $analyzer  -i DYTypeI_DF_M100_private    -n 1   --nmax 1   -e ${i}  --skim SkimTree_HNMultiLepBDT  &
    done
fi




#############################################################################                                                                                                                                                               
#############################################################################                                                                                                                                                               
#############################################################################     

if [[ $1 == "NP_MUON" ]]; then

    declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")
    declare  -a era_list=("2017")
    for i in "${era_list[@]}"
    do

        Flag='MuID_NP,FullEta'
        source ${runPATH}/run_hnl_muon.sh Muon ${Flag} ${i}

    done

fi


#############################################################################
#############################################################################
#############################################################################




if [[ $1 == "Muon" ]]; then
    
   
    #source ${runPATH}/run_hnl_muon.sh Signals ${3} ${2} 
    
    #FakeFlag=${2}',RunFake'
    #source ${runPATH}/run_hnl_muon.sh Fake  ${3} ${FakeFlag}  
    PromptFlag=${2}',RunPrompt'
    source ${runPATH}/run_hnl_muon.sh Prompt  ${3} ${PromptFlag}  
    #ConvFlag=${2}',RunConv'
    #source ${runPATH}/run_hnl_muon.sh Conv ${3} ${ConvFlag} 
    
fi


if [[ $1 == "Fake" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/FakeOpt.txt  -n $njobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/FakeOptXLarge.txt  -n 100  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &

fi

if [[ $1 == "Prompt" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/MCOpt.txt  -n $njobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &
    SKFlat.py -a $analyzer  -l $mcpath/MCOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT &

fi


if [[ $1 == "Signals" ]]; then

    SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs_sig  --nmax ${nmax}  -e ${2}  --userflags ${3}  --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/DYOpt.txt    -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&
    SKFlat.py -a $analyzer  -l $sigpath/VBFOpt.txt   -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLepBDT&

fi


if [[ $1 == "Conv" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n 5  --nmax ${nmax}   -e ${2} --skim SkimTree_HNMultiLepBDT  --userflags ${3} &
fi



if [[ $1 == "TMP" ]]; then
    
    Flag='MuID_NP,FullPt,BB'
    
    SKFlat.py -a $analyzer  -i DYTypeI_DF_M100_private  -n 20  --nmax 1000   -e 2017  --userflags $Flag   --skim SkimTree_HNMultiLepBDT&
       

fi
