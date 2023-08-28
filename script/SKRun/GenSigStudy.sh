#!/bin/bash

########################################################################
#"runBkdMC" "runConv" "runFlip" "runFakeRD" "runSigMC" "runData"
#declare -a List_runModes=("runSigMC" "runBkdMC")
#declare -a List_runModes=("runBkdMC")
declare -a List_runModes=("runSigMC")
#declare -a List_Year=("2017")
declare -a List_Year=("2017" "2018" "2016a" "2016b")

########################################################################
## RUN PARAMETERS

AnalysisCode="GenSigStudy"
FinalState="All" #"SS2l" #"SS2l" "OS2l" "TriLep"
Skim="" #"SkimTree_SS2lOR3l"
RunningMode="TrAccCheck"
# TrAccCheck TrRateCheck

NJobs=""
NJobFactor=2
Memory=""
NJobMax="200"
NEvtMax="50000"
NSkipEvt=""
ReductionFactor="" #"10"
SpecificList=""
SpecificDir="TrAccCheck"
runDebug="False"
ResubRun="False"


# Options:
# List_runModes   - run on RD, BkdMC, SigMC, 
#                 - Opt(Mult): runData/runFake/runBkdMC/runSigMC
# FinalState      - LabelDir & Code options (flag)
#                 - Opt(Sigl): DoubleMuon... 
# Skim            - run on Skimmed data set.
# Year            - Opt(Sigl): 2016/2017/2018
# RunningMode     - userflag
# NJobs           - num. of jobs for each sample
#                 - Opt(Sigl): int - uniform job allocation / 
#                              ""  - job allocation from GetJobConfig.py
# Memory          - max. memory allocation per job.
# NJobMax         - max. num. of jobs permitted for user.
# NEvtMax         - Max. num of evts to run - available only for debug
#                 - Opt(Sigl): ""/int
# NSkipEvt        - Skip first designated num. of evts.
#                 - Opt(Sigl): ""/int
# ReductionFactor - run only Total#/ReductionFactor events
#                 - Opt(Sigl): ""/int
# runDebug        - Make a code for pilot running on master node
#                 - Opt(Sigl): True/False


########################################################################

#if [[ ${Skim} == "" ]]; then NJobMax="100"; fi
if [[ ! -e CommandHist.txt ]]; then touch CommandHist.txt; echo "Command History">> CommandHist.txt; echo >> CommandHist.txt; fi;
date >> CommandHist.txt

for Year in ${List_Year[@]};
do
  for runMode in ${List_runModes[@]}; 
  do
  
    ## OUTPUT PATH CONFIG
    CategoryLabel=""
    StateLabel=${FinalState}
    
    if [[ -z ${SKFlatV} ]]; then echo "source setup.sh needed. exit"; exit 1; fi
    if [[ ! -e "${SKFlat_WD}/Analyzers/include/${AnalysisCode}.h" ]]; then
      echo "Inappropriate AnalysisCode setting."; exit 1;
    fi
    if   [[ ${runMode} == "runData"  ]]; then CategoryLabel="Data";
    elif [[ ${runMode} == "runFake"* ]]; then CategoryLabel="Fake";
    elif [[ ${runMode} == "runConv"  ]]; then CategoryLabel="Conv";
    elif [[ ${runMode} == "runFlip"  ]]; then CategoryLabel="Flip";
    elif [[ ${runMode} == "runBkdMC" ]]; then CategoryLabel="BkdMC";
    elif [[ ${runMode} == "runSigMC" ]]; then CategoryLabel="SigMC";
    else echo "Inappropriate runData/runBkdMC/runFake/runFakeMC/runSigMC settings."; exit 1; fi 
  
    OutputDir="${SKFlatOutputDir}/${SKFlatV}/${AnalysisCode}/${Year}/${StateLabel}/${SpecificDir}"
    if [[ ${runMode} == "runConv" || ${runMode} == "runFlip" ]];
    then OutputDir+="/BkdMC/${CategoryLabel}"
    elif [[ ${runMode} == "runFakeRD" ]]; then OutputDir+="/BkdMC/${CategoryLabel}/Data"
    elif [[ ${runMode} == "runFakeMC" ]]; then OutputDir+="/BkdMC/${CategoryLabel}/BkdMC"
    elif [[ ${runMode} == "runFakeCv" ]]; then OutputDir+="/BkdMC/${CategoryLabel}/BkdMC/Conv"
    elif [[ ${runMode} == "runFakeCF" ]]; then OutputDir+="/BkdMC/${CategoryLabel}/BkdMC/Flip"
    else OutputDir+="/${CategoryLabel}"; fi
    mkdir -pv ${OutputDir}
    
    
    #OPTION SETTING
    if [[ -z ${SpecificList} ]]; then
      List="${AnalysisCode}_${CategoryLabel}_${Year}";
      if [[ ${runDebug} == "True" ]]; then List="Debug_${CategoryLabel}_${Year}";
      elif [[ ${runMode} == "runData" || ${runMode} == "runFakeRD" ]]; then List="${AnalysisCode}_Data_${Year}_${StateLabel}"; 
      elif [[ ${runMode} == "runFakeMC" ]]; then List="${AnalysisCode}_BkdMC_${Year}"; 
      elif [[ ${runMode} == "runFakeCv" ]]; then List="${AnalysisCode}_Conv_${Year}"; 
      elif [[ ${runMode} == "runFakeCF" ]]; then List="${AnalysisCode}_Flip_${Year}"; 
      #elif [[ ${runMode} == "runFlip"   ]]; then List="${AnalysisCode}_Flip_${Year}_${StateLabel}"; 
      else :; fi
    fi
  
    NSample=$( python GetJobConfig.py ${List} )
    #echo "python GetJobConfig.py ${List}"
    if [[ ${NSample} == "Error"* ]]; then echo "Sample List wrong for ${runMode}, skip."; continue; fi
  
    for (( it_s=0; it_s<${NSample}; it_s++ ))
    do
      Option=" -a ${AnalysisCode}"
  
      SampleName=$( python GetJobConfig.py ${List} ${it_s} | cut -d ' ' -f1 )  
      NJobs=$( python GetJobConfig.py ${List} ${it_s} | cut -d ' ' -f2 )
      DataPeriod="ALL"
      #if [[ ${runMode} == "runData" || ${runMode} == "runFakeRD" || ${runMode} == "runFlip" ]];
      if [[ ${runMode} == "runData" || ${runMode} == "runFakeRD" ]];
      then DataPeriod=$( python GetJobConfig.py ${List} ${it_s} | cut -d ' ' -f3 ); fi
      if [[ ${ResubRun} == "True" && -e "${OutputDir}/${AnalysisCode}_${Skim}_${SampleName}.root" ]]; then continue; fi
  
      if [[ ${NJobs} -gt 0 ]]; then :; 
      elif [[ ${NJobs} == "-" ]]; then NJobs=20; 
      else echo "NJob Config invalid for ${SampleName} in ${CategoryLabel} mode"; continue; fi
      if [[ ( ${runDebug} == "False" ) ]]; then (( NJobs *= ${NJobFactor} )); fi
  
      TmpRunningMode=${RunningMode}; TmpSkim=${Skim};
      if [[ ${runMode} == "runFake"* ]]; then TmpRunningMode+=",FakeRun"; fi
      #if [[ ${runMode} == "runFlip" ]]; then TmpRunningMode+=",FlipRun"; fi
      if [[ ${runMode} == "runFlip" ]]; then TmpRunningMode+=",FlipRun"; TmpSkim=""; fi
      if [[ ${runMode} == "runFakeCF" ]]; then TmpRunningMode+=",FlipRun"; fi
      #if [[ ${runMode} == "runFakeCF" ]]; then TmpRunningMode+=",FlipRun"; TmpSkim=""; fi
      if [[ ${runMode} == "runConv" || ${runMode} == "runFakeCv" ]]; then TmpRunningMode+=",ConvRun"; fi
      if [[ ${runMode} == "runSigMC" ]]; then TmpSkim=""; fi
  
      Option+=" -i ${SampleName}" 
      Option+=" -n ${NJobs}" 
      Option+=" -e ${Year} -p ${DataPeriod}";
      if [[ ! -z ${TmpSkim} ]]; then Option+=" --skim ${TmpSkim}"; fi
      if [[ ! -z ${ReductionFactor} ]]; then Option+=" --reduction ${ReductionFactor}"; fi
      if [[ ! -z ${TmpRunningMode} ]]; then Option+=" --userflags ${TmpRunningMode}"; fi
      if [[ ! -z ${Memory} ]]; then Option+=" --memory ${Memory}"; fi
      if [[ ! -z ${NJobMax} ]]; then Option+=" --nmax ${NJobMax}"; fi
      if [[ ${runDebug} == "True" ]]; then Option+=" --no_exec"; fi
      Option+=" -o ${OutputDir}"
      SKFlat.py ${Option} &
      echo "SKFlat.py ${Option}" >> CommandHist.txt
  
      if [[ ${runDebug} == "True" ]]; then 
        sleep 4s
        DirName=$( ls -rt ${SKFlatRunlogDir} | tail -1 ) 
        if [[ ${DirName} == "www"* ]]; then DirName= $( ls -rt ${SKFlatRunlogDir} | tail -2 | head -1 ); fi
        PeriodLabel=""
        if [[ ${runMode} == "runData" || ${runMode} == "runFakeRD" ]]; then PeriodLabel="_period${DataPeriod}"; fi
        #if [[ ${runMode} == "runData" || ${runMode} == "runFakeRD" || ${runMode} == "runFlip" ]]; then PeriodLabel="_period${DataPeriod}"; fi
        OrigPath=${SKFlatRunlogDir}/${DirName}/${SampleName}${PeriodLabel}
        DebugPath=${SKFlat_WD}/Debug_${AnalysisCode}_${SampleName}${PeriodLabel}
        mkdir -p ${DebugPath}
        mv ${OrigPath}/run_0.C ${DebugPath}/run_0.C
        if [[ ${NEvtMax} -gt 0 ]]; then sed -i "/m.LogEvery/a \ \ m.MaxEvent\ =\ ${NEvtMax};" ${DebugPath}/run_0.C; fi
        if [[ ${NSkipEvt} -gt 0 ]]; then sed -i "/m.LogEvery/a \ \ m.NSkipEvent\ =\ ${NSkipEvt};" ${DebugPath}/run_0.C; fi
      fi
    done
  done
done

echo >> CommandHist.txt
