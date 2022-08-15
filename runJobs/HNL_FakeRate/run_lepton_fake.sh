analyzer=HNL_FakeRate
rundir=HNL_FakeRate
mcpath=${SKFlat_WD}/runJobs/${rundir}/mc_lists/
datapath=${SKFlat_WD}/runJobs/${rundir}/data_lists/
njobs=200
njobs_data=100
nmax=250
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

if [[ $1 == "MC" ]]; then
    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $mcpath/MC_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFake &
    done

fi

if [[ $1 == "DATA" ]]; then

    #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax} --skim SkimTree_HNFake  -e ${i} &

    declare  -a era_list=("2017")
    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i} &
    done
fi

if [[ $1 == "DATAPrompt" ]]; then
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_ll.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_Dilepton &

    done

fi


if [[ $1 == "" ]]; then
    for i in "${era_list[@]}"
    do
	
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_ll.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_Dilepton &
	
        SKFlat.py -a $analyzer  -l $mcpath/MC_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFake &

        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFake &

	if [[ $i == "2017" ]]; then

            SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} &
	else
	    SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i} --skim SkimTree_HNFake &
	fi
    done

fi



