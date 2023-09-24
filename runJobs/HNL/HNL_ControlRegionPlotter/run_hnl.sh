analyzer=HNL_ControlRegionPlotter
rundir=HNL_ControlRegionPlotter
runPATH=${SKFlat_WD}/runJobs/HNL/${rundir}/
sigpath=${SKFlat_WD}/runJobs/SampleLists/Signals/
mcpath=${SKFlat_WD}/runJobs/SampleLists/Bkg/
datapath=${SKFlat_WD}/runJobs/SampleLists/Data/

njobs=30
njobs_sig=2
njobs_data=100
nmax=400
skim=' '

declare  -a era_list=("2017")

if [[ $1 == "TEST" ]]; then

    SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e 2017  --skim SkimTree_HNMultiLepBDT --userflags RunFake  &
fi


if [[ $1 == "VBF" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/${i}/VBF.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "VBF1500" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i VBFTypeI_SF_ll_M1500  -n 1  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT  &
    done

fi


if [[ $1 == "SSWW" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/${i}/SSWW.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
    done

fi



if [[ $1 == "DATA" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  &
    done
    
fi

if [[ $1 == "FAKE" ]]; then

    
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunFake  &
    done

fi


if [[ $1 == "XG" ]]; then
    
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i WGToLNuG   -n  50  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT --userflags RunConv &
	#SKFlat.py -a $analyzer  -i ZGToLLG   -n  10  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags RunConv &
	#SKFlat.py -a $analyzer  -i WGToLNuG   -n  10  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep  &
        #SKFlat.py -a $analyzer  -i ZGToLLG   -n  10  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep &
	#SKFlat.py -a $analyzer  -i DYJets   -n  10  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags RunConv &
        #SKFlat.py -a $analyzer  -i DYJets   -n  10  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep &

    done

fi


if [[ $1 == "WZ" ]]; then

    declare  -a era_list=("2017")
 
    for i in "${era_list[@]}"
    do
	#SKFlat.py -a $analyzer  -i  WZ_pythia  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,Standard &
        SKFlat.py -a $analyzer  -i  WZ_pythia  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoTrigSF &
	#SKFlat.py -a $analyzer  -i  WZ_pythia  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoIDSF &
        #SKFlat.py -a $analyzer  -i  WZTo3LNu_amcatnlo  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,Standard &
	SKFlat.py -a $analyzer  -i  WZTo3LNu_amcatnlo  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoTrigSF &
	#SKFlat.py -a $analyzer  -i  WZTo3LNu_amcatnlo  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoIDSF &
	#SKFlat.py -a $analyzer  -i  WZTo3LNu_mllmin4p0_powheg  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,Standard &                                                                         
        SKFlat.py -a $analyzer  -i  WZTo3LNu_mllmin4p0_powheg  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoTrigSF &                                                                           
        #SKFlat.py -a $analyzer  -i  WZTo3LNu_mllmin4p0_powheg  -n 50             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt,NoIDSF &                                                                         

    done

fi



if [[ $1 == "Full" ]]; then

    declare  -a era_list=("2017")

    
    for i in "${era_list[@]}"
    do
        
	#### Data
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT  &
	#SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n 40             --nmax 400       -e ${i}  --skim SkimTree_DileptonBDT    &
	##### Prompt
	SKFlat.py -a $analyzer  -l $mcpath/PromptSS.txt  -n 20             --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunPrompt &
	#SKFlat.py -a $analyzer  -l $mcpath/PromptOS.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_DileptonBDT   --userflags RunPrompt &
	### SIGNALS
	#SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --skim SkimTree_HNMultiLepBDT &
        #SKFlat.py -a $analyzer  -l $sigpath/DY.txt    -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT &
        #SKFlat.py -a $analyzer  -l $sigpath/VBF.txt   -n $njobs_sig  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT &
	### Conv
        SKFlat.py -a $analyzer  -l $mcpath/Conv.txt   -n 10      --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT  --userflags RunConv &
	### CF
        SKFlat.py -a $analyzer  -l $mcpath/CF.txt     -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLepBDT  --userflags RunCF &
        #####   FAKES
	SKFlat.py -a $analyzer  -l $datapath/${i}_DiLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunFake  &
        #SKFlat.py -a $analyzer  -l $mcpath/VVOS.txt             -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLepBDT --userflags RunFake  &



    done

fi
