analyzer=HNL_LepIDKinVar
rundir=HNL_LepIDKinVar
sigpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Bkg/
njobs=300
nmax=300
skim=' --skim SkimTree_HNMultiLep'
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")


if [[ $1 == "" ]]; then
    
    nmax=300
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/DYsample.txt  -n 5  --nmax ${nmax}   -e ${i}  &
        SKFlat.py -a $analyzer  -l $sigpath/VBFsample.txt  -n 5  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l $sigpath/SSWWsample.txt  -n 5  --nmax ${nmax}   -e ${i} &

	SKFlat.py -a $analyzer  -l   $mcpath/Fake.txt  -n 400  --nmax ${nmax}   -e ${i}  --userflags SeperateFake  ${skim}&
	SKFlat.py -a $analyzer  -l   $mcpath/Conv.txt  -n 400  --nmax ${nmax}   -e ${i}  --userflags SeperateConv  &
	SKFlat.py -a $analyzer  -l   $mcpath/CF.txt  -n 400  --nmax ${nmax}   -e ${i}  --userflags SeperateCF  

    done

fi



if [[ $1 == "TMP" ]]; then

    declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $sigpath/DYsample.txt  -n 5  --nmax ${nmax}   -e ${i}  &
        SKFlat.py -a $analyzer  -l $sigpath/VBFsample.txt  -n 5  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l $sigpath/SSWWsample.txt  -n 5  --nmax ${nmax}   -e ${i} &
    done
    

fi


if [[ $1 == "MC" ]]; then


    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l   $mcpath/Fake.txt  -n 600  --nmax ${nmax}   -e ${i}  --userflags SeperateFake,GetRatio  &
	SKFlat.py -a $analyzer  -l   $mcpath/Conv.txt  -n 600  --nmax ${nmax}   -e ${i}  --userflags SeperateConv,GetRatio &

    done


fi


