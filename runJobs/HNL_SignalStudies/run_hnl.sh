analyzer=HNL_SignalStudies
rundir=HNL_SignalStudies
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
njobs=200
nmax=250
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

if [[ $1 == "DY" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/DY.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "VBF" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/VBF.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "SSWW" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/SSWW.txt  -n 2  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "" ]]; then

    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $mcpath/${i}/DY.txt  -n 5  --nmax ${nmax}   -e ${i} &
	SKFlat.py -a $analyzer  -l $mcpath/${i}/VBF.txt  -n 5  --nmax ${nmax}   -e ${i} &
	SKFlat.py -a $analyzer  -l $mcpath/${i}/SSWW.txt  -n 5  --nmax ${nmax}   -e ${i} 
    done

fi
