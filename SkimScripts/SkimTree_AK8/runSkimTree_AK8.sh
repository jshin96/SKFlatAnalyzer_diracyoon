analyzer=SkimTree_AK8
rundir=runSkims
mcpath=${SKFlat_WD}/SkimScripts/${analyzer}/mc_list/
datapath=${SKFlat_WD}/SkimScripts/${analyzer}/data_list/
njobs=50
njobs_data=100
nmax=150
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")


if [[ $1 == "DATA" ]]; then
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l $datapath/DATA_l_${i}.txt   -n ${njobs_data}  --nmax ${nmax}    -e ${i} &
    done

fi
