analyzer=SkimTree_DileptonBDT
rundir=runSkims
mcpath=${SKFlat_WD}/SkimScripts/${analyzer}/Bkg/
datapath=${SKFlat_WD}/SkimScripts/${analyzer}/data_lists_multilep/
sigpath=${SKFlat_WD}/SkimScripts/${analyzer}/Signals/
njobs=600
njobs_data=600
nmax=400
skim=' '
declare  -a era_list=("2018" "2017"  "2016preVFP" "2016postVFP")

if [[ $1 == "" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i DYJets10to50_MG  --nmax 350           -e ${i}  &
    done

fi

if [[ $1 == "IndData" ]]; then
    
    declare  -a era_list=("2018" "2017"  "2016preVFP")
    
     for i in "${era_list[@]}"
     do
	 SKFlat.py -a $analyzer  -l  $datapath/DATA_${i}_ind.txt  -n 500  --nmax 100    -e ${i} --skim SkimTree_Dilepton& 
	 SKFlat.py -a $analyzer  -l  $datapath/DATA_${i}EMu_ind.txt  -n 500  --nmax 100    -e ${i} 
     done

fi


if [[ $1 == "All" ]]; then

    for i in "${era_list[@]}"
    
    do
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt  -n ${njobs_data}  --nmax ${nmax}           -e ${i}  --skim SkimTree_Dilepton  &
	SKFlat.py -a $analyzer  -l $datapath/${i}_SingleLepton.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_Dilepton  &
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}EMu.txt  -n ${njobs_data}  --nmax ${nmax}        -e ${i}   &
	SKFlat.py -a $analyzer  -l $mcpath/MC.txt  -n 2000  --nmax ${nmax}   -e ${i}  --skim SkimTree_Dilepton &
    done
fi

