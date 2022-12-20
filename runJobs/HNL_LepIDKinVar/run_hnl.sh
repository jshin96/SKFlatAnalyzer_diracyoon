analyzer=HNL_LepIDKinVar
rundir=HNL_LepIDKinVar
sigpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Bkg/
njobs=300
nmax=300
skim=' --skim SkimTree_HNMultiLep'
declare  -a era_list=("2017")



if [[ $1 == "" ]]; then
    
    nmax=300
    
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/DYsample.txt  -n 5  --nmax ${nmax}   -e ${i}  &
        SKFlat.py -a $analyzer  -l $sigpath/VBFsample.txt  -n 5  --nmax ${nmax}   -e ${i} & 
	#SKFlat.py -a $analyzer  -l   $mcpath/Conv.txt  -n 400  --nmax ${nmax}   -e ${i}  --userflags SeperateConv &
    done

fi


