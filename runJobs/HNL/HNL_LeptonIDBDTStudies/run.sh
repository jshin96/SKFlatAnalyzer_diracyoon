analyzer=HNL_LeptonIDBDTStudies
rundir=HNL_LeptonIDBDTStudies
datapath=${SKFlat_WD}/runJobs/HNL/${analyzer}/Data/
mcpath=${SKFlat_WD}/runJobs/HNL/${analyzer}/Bkg/
njobs=250
nmax=800
skim=' SkimTree_Dilepton'
declare  -a era_list=("2018" "2016postVFP" "2016preVFP" "2017")

if [[ $1 == "" ]]; then
    
    declare  -a era_list=("2018")
    for i in "${era_list[@]}"
    do

	SKFlat.py -a $analyzer  -i DYJets_MG_HT-800to1200 -n 1  --nmax 1 -e ${i}  --skim SkimTree_DileptonBDT&
        #SKFlat.py -a $analyzer  -i DYJets          -n 400   --nmax 400  -e ${i}  --skim SkimTree_DileptonBDT&
        #SKFlat.py -a $analyzer  -i TTLJ_powheg     -n 1000  --nmax 400  -e ${i}  --skim SkimTree_DileptonBDT&
    done
fi



if [[ $1 == "All" ]]; then

    declare  -a era_list=("2018" "2016postVFP" "2016preVFP" "2017")
    for i in "${era_list[@]}"
    do
	
	SKFlat.py -a $analyzer  -l ${mcpath}/Fake.txt    -n 250  --nmax 100  -e ${i}  --skim SkimTree_FakeEventSkimBDT
	SKFlat.py -a $analyzer  -l ${mcpath}/CF.txt      -n 100  --nmax 100  -e ${i}  --skim SkimTree_CFEventSkim
	SKFlat.py -a $analyzer  -l ${mcpath}/Conv.txt    -n 100  --nmax 100  -e ${i}  --skim SkimTree_ConvEventSkim
	#SKFlat.py -a $analyzer  -l ${mcpath}/Sig.txt     -n 100  --nmax 400  -e ${i}  --skim SkimTree_HNMultiLepBDT
	
    done
fi


