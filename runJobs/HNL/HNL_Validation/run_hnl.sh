analyzer=HNL_Validation
rundir=HNL_Validation
sigpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Bkg/
datapath=${SKFlat_WD}/runJobs/${analyzer}/DATA/
njobs=100
njobs_data=100
nmax=300
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

if [[ $1 == "" ]]; then

    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i} --skim SkimTree_Dilepton  &
        SKFlat.py -a $analyzer  -l $mcpath/${i}/MC2.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_Dilepton  &

    done

fi
