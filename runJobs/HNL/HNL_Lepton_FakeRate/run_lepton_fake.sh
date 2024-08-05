analyzer=HNL_Lepton_FakeRate
rundir=HNL_Lepton_FakeRate
mcpath=${SKFlat_WD}/runJobs/HNL/${rundir}/mc_lists/
datapath=${SKFlat_WD}/runJobs/HNL/${rundir}/data_lists/
njobs=400
njobs_data=100
nmax=350
declare  -a era_list=("2016postVFP" "2016preVFP" "2017" "2018")

declare  -a joblist=("CheckProfile"  "RatesMuon" "RatesMuon2" "RatesEl" "RatesEl2" "RatesWR")

for i in "${era_list[@]}"

do
    
    
    if [[ $1 == "RatesWR" ]]; then
        #SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesTauAnalysisEE&
        #SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesTauAnalysisEE&
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesTauAnalysis&
	SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesTauAnalysis&

    fi

    if [[ $1 == "CheckProfile" ]]; then
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags CheckProfile&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n  ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags CheckProfileEE&
    fi

    if [[ $1 == "CheckProfileEE" ]]; then
	
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n  ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags CheckProfileEE&
    fi
    
    if [[ $1 == "Rates" ]]; then
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRates&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRates&
	SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesEE&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesEE&
    fi
    
    if [[ $1 == "RatesFull" ]]; then
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesFullID&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesFullID&
        
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesFullEEID&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags RunRatesFullEEID&
    fi

    if [[ $1 == "MakeRegionPlots" ]]; then
        SKFlat.py -a $analyzer  -l $mcpath/MC.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&                                              
        SKFlat.py -a $analyzer  -l ${mcpath}/QCD_${i}.txt  -n ${njobs}  --nmax ${nmax}  -e ${i}   --skim SkimTree_FakeEventSkimBDT --userflags MakeRegionPlots&                                                     
    fi

    if [[ $1 == "GetNvtxSF" ]]; then
        SKFlat.py -a $analyzer  -l $mc/DY.txt              -n ${njobs}       --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_mu.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&
        SKFlat.py -a $analyzer  -l $datapath/DATA_${i}_el.txt  -n ${njobs_data}  --nmax ${nmax}  -e ${i}   --skim SkimTree_HNFakeBDT --userflags MakeRegionPlots&
    fi


done
echo "List of Job Options are:"
for i in "${joblist[@]}"

do
    echo $i
done

