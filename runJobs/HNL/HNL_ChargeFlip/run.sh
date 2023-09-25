analyzer=HNL_ChargeFlip
rundir=HNL_ChargeFlip
datapath=${SKFlat_WD}/runJobs/HNL/${analyzer}/Data/
mcpath=${SKFlat_WD}/runJobs/HNL/${analyzer}/Bkg/
njobs=250
nmax=200
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")


if [[ $1 == "" ]]; then

    declare  -a era_list=("2017")
    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -i DYJets        -n 600  --nmax 400   -e ${i}  --skim SkimTree_DileptonBDT --userflags CFratePtInverse&
	SKFlat.py -a $analyzer  -i TTLL_powheg   -n 600  --nmax 400   -e ${i}  --skim SkimTree_DileptonBDT --userflags CFratePtInverse&
    done
fi


