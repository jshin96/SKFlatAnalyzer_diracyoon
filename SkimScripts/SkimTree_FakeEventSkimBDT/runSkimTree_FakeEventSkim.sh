analyzer=SkimTree_FakeEventSkimBDT
rundir=runSkims
mcpath=${SKFlat_WD}/SkimScripts/${analyzer}/Bkg/
njobs=600
njobs_data=600
nmax=50
skim=' '
declare  -a era_list=("2018" "2017"  "2016preVFP" "2016postVFP")
declare  -a era_list=( "2016preVFP")
if [[ $1 == "" ]]; then
    for i in "${era_list[@]}"
    do
	SKFlat.py -a $analyzer  -i QCD_Pt-1000_MuEnriched  -n 1  --nmax 1   -e ${i}  --skim SkimTree_FakeEventSkim &
    done

fi

