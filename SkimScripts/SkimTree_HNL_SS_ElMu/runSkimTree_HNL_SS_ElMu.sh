analyzer=SkimTree_HNL_SS_ElMu
rundir=runSkims
mcpath=${SKFlat_WD}/SkimScripts/${analyzer}/Signals/
njobs=20
nmax=100
skim=' '
declare  -a era_list=("2016preVFP" "2016postVFP" "2017" "2018") 

for i in "${era_list[@]}"
do
    SKFlat.py -a $analyzer  -l $mcpath/${i}/SSWW.txt  -n ${njobs}  --nmax ${nmax}   -e ${i} -o /gv0/Users/jalmond/Run2UltraLegacy_v3/${i}/MC/ &
    SKFlat.py -a $analyzer  -l $mcpath/${i}/DY.txt  -n ${njobs}  --nmax ${nmax}   -e ${i} -o /gv0/Users/jalmond/Run2UltraLegacy_v3/${i}/MC/ &
    SKFlat.py -a $analyzer  -l $mcpath/${i}/VBF.txt  -n ${njobs}  --nmax ${nmax}   -e ${i} -o /gv0/Users/jalmond/Run2UltraLegacy_v3/${i}/MC/ &
done
