analyzer=HNL_SignalRegionPlotter
rundir=HNL_SignalRegionPlotter
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
datapath=${SKFlat_WD}/runJobs/${analyzer}/DATA/
njobs=5
njobs_data=25
nmax=200
skim=' '
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")


if [[ $1 == "DY" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/DY.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "VBF" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/VBF.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
    done

fi

if [[ $1 == "VBF1500" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i VBFTypeI_SF_ll_M1500  -n 1  --nmax ${nmax}   -e ${i} &
    done

fi


if [[ $1 == "SSWW" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $mcpath/${i}/SSWW.txt  -n $njobs  --nmax ${nmax}   -e ${i} &
    done

fi



if [[ $1 == "DATA" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep & 
    done
    
fi

if [[ $1 == "" ]]; then

    njobs_data=50

    declare  -a era_list=("2018")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i  EGamma:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}   &
        SKFlat.py -a $analyzer  -i  EGamma:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}    --skim SkimTree_HNMultiLep &
        SKFlat.py -a $analyzer  -i  EGamma:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}    --skim SkimTree_SS2lOR3l &
        SKFlat.py -a $analyzer  -i  DoubleMuon:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}   &
        SKFlat.py -a $analyzer  -i  DoubleMuon:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep &
        SKFlat.py -a $analyzer  -i  DoubleMuon:C  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_SS2lOR3l &
    done

fi
