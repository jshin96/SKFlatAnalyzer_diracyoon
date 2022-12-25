analyzer=HNL_SignalLeptonOpt
rundir=HNL_SignalLeptonOpt
sigpath=${SKFlat_WD}/runJobs/${analyzer}/Signals/
mcpath=${SKFlat_WD}/runJobs/${analyzer}/Bkg/
datapath=${SKFlat_WD}/runJobs/${analyzer}/DATA/
njobs=10
njobs_sig=10
njobs_data=5
nmax=300
skim=' '

declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")


if [[ $1 == "TMP1" ]]; then

    declare  -a era_list=("2017")
    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -i DYTypeI_DF_M250_private -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -i DYTypeI_DF_M250_private  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,EC&

    done

fi


if [[ $1 == "DATA_NP1_MUON_PT3" ]]; then

    declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATAMu_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -l $sigpath/DY.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -l $sigpath/VBF.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,BB&

    done

fi

if [[ $1 == "MC_NP_MUON_PT3" ]]; then

    declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -l $sigpath/DY.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,BB&
        SKFlat.py -a $analyzer  -l $sigpath/VBF.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP,PtBin3,BB&

        #SKFlat.py -a $analyzer  -l $datapath/DATAMu_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep  --userflags MuID_NP,PtBin3,BB&
        #SKFlat.py -a $analyzer  -l $mcpath/MC.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags MuID_NP,PtBin3,BB &
        #SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags MuID_NP,PtBin3,BB,RunConv &
        #SKFlat.py -a $analyzer  -l $datapath/DATAMu_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep  --userflags MuID_NP,PtBin3,EC&
        #SKFlat.py -a $analyzer  -l $mcpath/MC.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags MuID_NP,PtBin3,EC &
        #SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags MuID_NP,PtBin3,EC,RunConv &


    done

fi



if [[ $1 == "DATA_NP1_MUON_PT2" ]]; then

    declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATAMu_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep  --userflags MuID_NP1,PtBin2&
        SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --userflags MuID_NP1,PtBin2&
        SKFlat.py -a $analyzer  -l $sigpath/DY.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP1,PtBin2&
        SKFlat.py -a $analyzer  -l $sigpath/VBF.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP1,PtBin2&

    done

fi

if [[ $1 == "DATA_NP1_MUON_PT1" ]]; then

    declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018")
    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
        SKFlat.py -a $analyzer  -l $datapath/DATAMu_${i}.txt  -n ${njobs_data}  --nmax ${nmax}   -e ${i}  --skim SkimTree_HNMultiLep  --userflags MuID_NP1,PtBin1&
        SKFlat.py -a $analyzer  -l $sigpath/SSWW.txt  -n $njobs_sig  --nmax ${nmax}  -e ${i}  --userflags MuID_NP1,PtBin2&
        SKFlat.py -a $analyzer  -l $sigpath/DY.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP1,PtBin2&
        SKFlat.py -a $analyzer  -l $sigpath/VBF.txt  -n $njobs_sig  --nmax ${nmax}   -e ${i}  --userflags MuID_NP1,PtBin2&

    done

fi






if [[ $1 == "SSWW" ]]; then

    SKFlat.py -a $analyzer  -i SSWWTypeI_SF_M2000_private  -n 10  --nmax ${nmax}   -e 2017  --userflags RunEE,RunHighPt &

fi


if [[ $1 == "SIG" ]]; then
 

    SKFlat.py -a $analyzer  -l $sigpath/2017/SSWW.txt  -n $njobs_sig  --nmax ${nmax}   -e 2017 &
    SKFlat.py -a $analyzer  -l $sigpath/2017/DY.txt  -n $njobs_sig  --nmax ${nmax}   -e 2017 &
    SKFlat.py -a $analyzer  -l $sigpath/2017/VBF.txt  -n $njobs_sig  --nmax ${nmax}   -e 2017 &
   

fi

if [[ $1 == "DY" ]]; then


    SKFlat.py -a $analyzer  -i DYTypeI_DF_M100_private  -n 1  --nmax ${nmax}   -e 2017   &


fi



if [[ $1 == "" ]]; then

    declare  -a era_list=("2017")

    for i in "${era_list[@]}"
    do
	
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep &
        SKFlat.py -a $analyzer  -l $mcpath/CF.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags RunCF &
        SKFlat.py -a $analyzer  -l $mcpath/Conv.txt  -n $njobs  --nmax ${nmax}   -e ${i} --skim SkimTree_HNMultiLep --userflags RunConv & 

    done

fi

