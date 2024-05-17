analyzer=SkimTree_HNMultiLepBDT
qrundir=runSkims
mcpath=${SKFlat_WD}/SkimScripts/SampleLists/Bkg/
datapath=${SKFlat_WD}/SkimScripts/SampleLists/Data/
sigpath=${SKFlat_WD}/SkimScripts/SampleLists/Signals/
njobs=600
njobs_data=100
nmax=500
declare  -a era_list=("2016postVFP" "2016preVFP"  "2017" "2018")



if [[ $1 == "DY" ]]; then
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i DYJetsToTauTau_MiNNLO     -n ${njobs_data}  --nmax ${nmax}   -e ${i}   --skim SkimTree_Dilepton &
    done
fi


if [[ $1 == "VBF" ]]; then

    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -i VBFTypeI_DF_M300_private -n 20  --nmax ${nmax}   -e ${i} &
	SKFlat.py -a $analyzer  -i VBFTypeI_DF_M400_private -n 20  --nmax ${nmax}   -e ${i} &
    done
fi

if [[ $1 == "Signal" ]]; then

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l ${sigpath}/DYAdditionalBDT.txt  -n 20  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l ${sigpath}/DYOfficial.txt    -n 20  --nmax ${nmax}   -e ${i} &
	SKFlat.py -a $analyzer  -l ${sigpath}/VBFOfficial.txt   -n 20  --nmax ${nmax}   -e ${i} &
	SKFlat.py -a $analyzer  -l ${sigpath}/SSWWOfficial.txt  -n 20  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l ${sigpath}/DY.txt            -n 20  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l ${sigpath}/VBF.txt           -n 20  --nmax ${nmax}   -e ${i} &
        SKFlat.py -a $analyzer  -l ${sigpath}/SSWW.txt          -n 20  --nmax ${nmax}   -e ${i} &
    done
fi



if [[ $1 == "All" ]]; then

    declare  -a era_list=("2016preVFP" "2016postVFP")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}.txt     -n ${njobs_data}  --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l $datapath/DATA_l_${i}.txt   -n ${njobs_data}  --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/MCXSmall.txt      -n 2              --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/MCSmall.txt       -n 5              --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/MCMedium.txt      -n 20             --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/MCLarge.txt       -n 50             --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/MCXLarge.txt      -n 200            --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${mcpath}/${i}/QCD.txt      -n 2              --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
        SKFlat.py -a $analyzer  -l ${sigpath}/Signal.txt       -n 10             --nmax ${nmax}   -e ${i} --skim  SkimTree_HNMultiLep&
    done
fi

