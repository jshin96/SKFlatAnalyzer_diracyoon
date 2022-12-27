### SETUP RUN OPTIONS
analyzer=HNL_SignalLeptonOpt
rundir=HNLOpt/HNL_SignalLeptonOpt

# PATHS                                                                                                                                                    
runPATH=${SKFlat_WD}/runJobs/${rundir}/
sigpath=${SKFlat_WD}/runJobs/SampleLists/Signals/
mcpath=${SKFlat_WD}/runJobs/SampleLists/Bkg/
datapath=${SKFlat_WD}/runJobs/SampleLists/DATA/

#SKIM                                                                                                                                                     
skim=' '

# JOB CONFIG                                                                                                                                               
njobs=10
nLargejobs=40
njobs_sig=5
njobs_data=5

nmax=300


declare  -a era_list_Full=("2016postVFP" "2016preVFP" "2018")
declare  -a era_list_Partial=("2017")


if [[ $1 == "NP1_MUON_HighPt" ]]; then

    Flag='MuID_NP,HighPt,BB'
    source ${runPATH}/run_hnl.sh Muon ${Flag}
    
    Flag2='MuID_NP,HighPt,EC'
    source ${runPATH}/run_hnl.sh Muon ${Flag2}

fi

if [[ $1 == "NP1_MUON_FullPt" ]]; then

    Flag='MuID_NP,FullPt,BB'
    source ${runPATH}/run_hnl.sh Muon ${Flag}

    Flag2='MuID_NP,FullPt,EC'
    source ${runPATH}/run_hnl.sh Muon ${Flag2}

fi



#############################################################################
#############################################################################
#############################################################################




if [[ $1 == "Muon" ]]; then

    # If no inut then this is ran                                                                                                                        
    for i in "${era_list_Partial[@]}"
    do
	

	source ${runPATH}/run_hnl.sh MC  ${i} ${2} 
	
        source ${runPATH}/run_hnl.sh Signals ${i} ${2}
	
	ConvFlag=${2}',RunConv'

	source ${runPATH}/run_hnl.sh Conv ${i} ${ConvFlag}

    done

fi

if [[ $1 == "Electron" ]]; then

    # If no inut then this is ran                                                                                                                        
    for i in "${era_list_Partial[@]}"
    do
        source ${runPATH}/run_hnl.sh Signals ${i} ${2}
        source ${runPATH}/run_hnl.sh MC  ${i} ${2}

        CFFlag=${2}',RunCF'
        source ${runPATH}/run_hnl.sh CF ${i} ${CFFlag}
        ConvFlag=${2}',RunConv'
        source ${runPATH}/run_hnl.sh Conv ${i} ${ConvFlag}

    done

fi



if [[ $1 == "MC" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/MCOpt.txt  -n $njobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLep 
    SKFlat.py -a $analyzer  -l $mcpath/MCOptLarge.txt  -n $nLargejobs  --nmax ${nmax}   -e ${2}  --userflags ${3} --skim SkimTree_HNMultiLep &

fi

if [[ $1 == "Signals" ]]; then

    SKFlat.py -a $analyzer  -l $sigpath/SSWWOpt.txt  -n $njobs_sig  --nmax ${nmax}  -e ${2}  --userflags ${3}  &
    SKFlat.py -a $analyzer  -l $sigpath/DYOpt.txt    -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} &
    SKFlat.py -a $analyzer  -l $sigpath/VBFOpt.txt   -n $njobs_sig  --nmax ${nmax}   -e ${2}  --userflags ${3} &

fi


if [[ $1 == "CF" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/CF.txt  -n $njobs  --nmax ${nmax}   -e ${2} --skim SkimTree_HNMultiLep  --userflags ${3} &
    #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i} --userflags RunCF  &                                 

fi


if [[ $1 == "Conv" ]]; then

    SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n 5  --nmax ${nmax}   -e ${2} --skim SkimTree_HNMultiLep  --userflags ${3} &
fi



if [[ $1 == "TMP" ]]; then

    Flag='MuID_NP,AllPt,BB'

    SKFlat.py -a $analyzer  -i DYTypeI_DF_M2000_private  -n 2  --nmax ${nmax}  -e 2017  --userflags $Flag  &

fi
