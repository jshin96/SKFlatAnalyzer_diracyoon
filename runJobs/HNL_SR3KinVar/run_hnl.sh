analyzer=HNL_SR3KinVar
rundir=HNL_SR3KinVar
sigpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Bkg/
njobs=250
nmax=250
skim=' --skim SkimTree_HNMultiLep'
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")


if [[ $1 == "DY" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/${i}/DY.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "VBF" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/${i}/VBF.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "SSWW" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/${i}/SSWW.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "WZ" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i WZTo3LNu_mllmin4p0_powheg   -n 10  --nmax ${nmax}   -e ${i} ${skim}&
    done

fi

if [[ $1 == "" ]]; then

    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $sigpath/${i}/DY.txt  -n 5  --nmax ${nmax}   -e ${i} --skim MC_SkimTree_HNL_SS_MuMu_BDT_TRAIN&
	SKFlat.py -a $analyzer  -l $sigpath/${i}/VBF.txt  -n 5  --nmax ${nmax}   -e ${i} --skim MC_SkimTree_HNL_SS_MuMu_BDT_TRAIN&
	SKFlat.py -a $analyzer  -l $sigpath/${i}/SSWW.txt  -n 5  --nmax ${nmax}   -e ${i} --skim MC_SkimTree_HNL_SS_MuMu_BDT_TRAIN & 
	SKFlat.py -a $analyzer  -l   $mcpath/${i}/MC.txt  -n 25  --nmax ${nmax}   -e ${i} ${skim} & 
    done

fi
