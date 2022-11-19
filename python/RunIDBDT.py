#!/usr/bin/env python

import os,sys,time
import argparse
import datetime
from CheckJobStatus import *
from TimeTools import *
import random
import subprocess


## Arguments

parser = argparse.ArgumentParser(description='SKFlat Command')
parser.add_argument('-a', dest='Analyzer', default="")
parser.add_argument('-c', dest='Channel', default="EE")
parser.add_argument('-ns', dest='SignalMode', default=2, type=int)
parser.add_argument('-nt', dest='NTree', default=850, type=int)
parser.add_argument('-Nrom', dest='NormMode', default="NumEvents")
parser.add_argument('-MinNodeSize', dest='MinNodeSize', default="1.5")
parser.add_argument('-MaxDepth', dest='MaxDepth', default="3")
parser.add_argument('-ncut', dest='NCut', default="200")
parser.add_argument('--IgnoreNE', action='store_true')
parser.add_argument('-t', dest='Tag', default="Default")
parser.add_argument('-o', dest='Outputdir', default="")
parser.add_argument('-q', dest='Queue', default="fastq")
parser.add_argument('-e', dest='Era', default="Run2",help="2016preVFP(2016a), 2016postVFP(2016b), 2017, 2018, Run2")
parser.add_argument('--nmax', dest='NMax', default=100, type=int, help="maximum running jobs")
parser.add_argument('--reduction', dest='Reduction', default=1, type=float)
parser.add_argument('--memory', dest='Memory', default=0, type=float)
parser.add_argument('--batchname',dest='BatchName', default="")
args = parser.parse_args()

if ".C" in args.Analyzer:
  print("-a option must not contain subfix .C")
  exit()


if args.Analyzer == "":
  print("Input Macro not set...")
  exit()





NJobs=1

if args.Era=="2016a": args.Era="2016preVFP"
if args.Era=="2016b": args.Era="2016postVFP"

## Add Abosolute path for outputdir
if args.Outputdir!='':
  if args.Outputdir[0]!='/':
    args.Outputdir = os.getcwd()+'/'+args.Outputdir

## TimeStamp

# 1) dir/file name style
JobStartTime = datetime.datetime.now()
timestamp =  JobStartTime.strftime('%Y_%m_%d_%H%M%S')


# 2) log style
JobStartTime = datetime.datetime.now()
string_JobStartTime =  JobStartTime.strftime('%Y-%m-%d %H:%M:%S')
string_ThisTime = ""

## Environment Variables

USER = os.environ['USER']
if os.path.exists(os.environ['SKFlat_WD']+'/python/UserInfo_'+USER+'.py'):
  exec('from UserInfo_'+USER+' import *')
else:
  print("No UserInfo file")
  exit(1)

SKFlatLogWebDir = UserInfo['SKFlatLogWebDir']


SCRAM_ARCH = os.environ['SCRAM_ARCH']
cmsswrel = os.environ['cmsswrel']
SKFlat_WD = os.environ['SKFlat_WD']
SKFlatV = os.environ['SKFlatV']
SAMPLE_DATA_DIR = SKFlat_WD+'/data/'+SKFlatV+'/'+args.Era+'/Sample/'
BDTRunlogDir = os.environ['BDTRunlogDir']
BDTOutputDir = os.environ['BDTOutputDir']

os.system("mkdir -p " +BDTRunlogDir)
os.system("mkdir -p " +BDTOutputDir)

UID = str(os.getuid())
HOSTNAME = os.environ['HOSTNAME']
SampleHOSTNAME = HOSTNAME

## Check joblog email

SendLogToWeb = True
if SKFlatLogWebDir=='':
  SendLogToWeb = False

## Check hostname

IsTAMSA1 = ("tamsa1" in HOSTNAME)
IsTAMSA2 = ("tamsa2" in HOSTNAME)
IsTAMSA = IsTAMSA1 or IsTAMSA2
if IsTAMSA:
  if IsTAMSA1:
    HOSTNAME = "TAMSA1"
  elif IsTAMSA2:
    HOSTNAME = "TAMSA2"
  SampleHOSTNAME = "SNU"


StringForHash = ""

## When using txt file for input (i.e., -l option)


random.seed(hash(StringForHash+timestamp+args.Era))
RandomNumber = int(random.random()*1000000)
str_RandomNumber = str(RandomNumber)

webdirname = timestamp+"_"+str_RandomNumber

## Define MasterJobDir

MasterJobDir = BDTRunlogDir+'/'+timestamp+'__'+str_RandomNumber+"__"+args.Analyzer+'__'+'Era'+args.Era+"__"+args.Channel + '__'+str(args.SignalMode) +'__'+ str(args.NTree)+'__'+ str(args.NormMode)+'__'+ str(args.MinNodeSize) +'__'+ str(args.MaxDepth)  +'__'+ str(args.NCut) 
if args.IgnoreNE:
  MasterJobDir += '__IgnoreNegEvents'
MasterJobDir += '__'+HOSTNAME+'/'
os.mkdir(MasterJobDir)

FinalOutputPath = args.Outputdir
if args.Outputdir=="":
  FinalOutputPath = BDTOutputDir+'/'+SKFlatV+'/'+args.Analyzer+'/'+args.Era+'/'
  os.system('mkdir -p '+ BDTOutputDir+'/'+SKFlatV)
  os.system('mkdir -p '+ BDTOutputDir+'/'+SKFlatV +'/'+args.Analyzer+'/')

if args.Tag != "":
  FinalOutputPath = BDTOutputDir+'/'+SKFlatV+'/'+args.Analyzer+'/' +args.Tag + '/'+args.Era+'/'
  os.system('mkdir -p '+ BDTOutputDir+'/'+SKFlatV)
  os.system('mkdir -p '+ BDTOutputDir+'/'+SKFlatV +'/'+args.Analyzer+'/')
  os.system('mkdir -p '+ BDTOutputDir+'/'+SKFlatV +'/'+args.Analyzer+'/'+args.Tag)

os.system('mkdir -p '+FinalOutputPath)
os.system('mkdir -p '+FinalOutputPath+'/Logs/')
os.system('mkdir -p '+FinalOutputPath+'/dataset/')
os.system('mkdir -p '+FinalOutputPath+'/dataset/weights/')




TMVADirs = [os.environ['SKFlat_WD'] + '/TMVA/LepID/']

macroname=""
for TMVADir in TMVADirs:

  base_rundir = MasterJobDir+"/"+args.Tag
  os.mkdir(base_rundir)
  macroname = args.Analyzer+".C"
  submitMacro = args.Analyzer+".C(\""+str(args.Channel)+"\", "+str(args.SignalMode)+", \""+str(args.NTree)+"\" , \""+str(args.NormMode)+"\",  \""+str(args.MinNodeSize)+"\",  \""+str(args.MaxDepth)+"\", \""+str(args.NCut)+"\",false)"
  if args.IgnoreNE:
    submitMacro = args.Analyzer+".C(\""+str(args.Channel)+"\", "+str(args.SignalMode)+", \""+str(args.NTree)+"\" , \""+str(args.NormMode)+"\",  \""+str(args.MinNodeSize)+"\",  \""+str(args.MaxDepth)+"\", \""+str(args.NCut)+"\",true)"
  
  os.system('cp ' + TMVADir + '/'+ macroname+' ' + base_rundir)

  commandsfilename = args.Analyzer+'-'+args.Tag
  run_commands = open(base_rundir+'/'+commandsfilename+'.sh','w')

  signalName = "SignalMode_"+str(args.SignalMode)

  outName = 'output_'+signalName+'_'+args.Channel+'__NTrees_'+ str(args.NTree)+'__NormMode_'+ str(args.NormMode)+'__MinNodeSize_'+ str(args.MinNodeSize) +'__MaxDepth_'+ str(args.MaxDepth) +'__NCut_'+ str(args.NCut) +'__BDT'
  if args.IgnoreNE:
    outName = 'output_'+signalName+'_'+args.Channel+'__NTrees_'+ str(args.NTree)+'__NormMode_'+ str(args.NormMode)+'__MinNodeSize_'+ str(args.MinNodeSize) +'__MaxDepth_'+ str(args.MaxDepth) +'__NCut_'+ str(args.NCut) +'__IgnoreNegWeights__BDT'

  print>>run_commands,'''#!/bin/bash
SECTION=`printf $1`
WORKDIR=`pwd`

Trial=0

#### make sure use C locale
export LC_ALL=C

#### Don't make root history
export ROOT_HIST=0

#### use cvmfs for root ####
export CMS_PATH=/cvmfs/cms.cern.ch
source $CMS_PATH/cmsset_default.sh
export SCRAM_ARCH={3}
export cmsswrel={4}
cd /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/$cmsswrel/src
echo "@@@@ SCRAM_ARCH = "$SCRAM_ARCH
echo "@@@@ cmsswrel = "$cmsswrel
echo "@@@@ scram..."
eval `scramv1 runtime -sh`
cd -
source /cvmfs/cms.cern.ch/$SCRAM_ARCH/cms/$cmsswrel/external/$SCRAM_ARCH/bin/thisroot.sh

while [ "$Trial" -lt 3 ]; do
  echo "#### running ####"
  echo "root -l -b -q '{1}/{2}'"
  root -l -b -q '{1}/{2}' 2> err.log 
  EXITCODE=$?
  if [ "$EXITCODE" -eq 5 ]; then
    echo "IO error occured.. running again in 300 seconds.."
    Trial=$((Trial+=1))
    sleep 300
  else
    break
  fi
done

mv dataset/weights/*     {5}/dataset/weights/
mv _condor_stdout {5}/Logs/Job_out_{6}.log
mv _condor_stderr {5}/Logs/Job_err_{6}.log                                                                                                                                                                                                 

mv *.root   {5}  


if [ "$EXITCODE" -ne 0 ]; then
  echo "ERROR errno=$EXITCODE" >> err.log
fi

cat err.log >&2
exit $EXITCODE
'''.format(MasterJobDir, base_rundir, submitMacro, SCRAM_ARCH, cmsswrel,FinalOutputPath , outName)
  run_commands.close()

  submit_command = open(base_rundir+'/submit.jds','w')
  concurrency_limits=''
  if args.NMax:
    concurrency_limits='concurrency_limits = n'+str(args.NMax)+'.'+os.getenv("USER")
    request_memory=''
    if args.Memory:
      request_memory='request_memory = '+str(args.Memory)
    print>>submit_command,'''executable = {1}.sh
jobbatchname = {1}
universe   = vanilla
arguments  = $(Process)
log = condor.log
getenv     = True
should_transfer_files = YES
when_to_transfer_output = ON_EXIT
output = job_$(Process).log
error = job_$(Process).err
{2}
{3}
queue {0}
'''.format(str(NJobs), commandsfilename,concurrency_limits,request_memory)
    submit_command.close()


    cwd = os.getcwd()
    os.chdir(base_rundir)
    condorOptions = ''
    if args.BatchName!="":
      condorOptions = ' -batch-name '+args.BatchName
    os.system('condor_submit submit.jds '+condorOptions)
    os.chdir(cwd)



print '##################################################'
print("RunDir: " + base_rundir)
print 'Submission Finished'
print '- JobID = '+str_RandomNumber
print '- Analyzer = '+args.Analyzer+'.C'
print '- Channel = '+args.Channel
print '- Signal = '+str(args.SignalMode)

print '-'*40
print '- NJobs = '+str(NJobs)
print '-'*40
print '- NTrees = '+str(args.NTree)
print '- NormMode = '+str(args.NormMode)
print '- MinNodeSize = '+str(args.MinNodeSize)
print '- MaxDepth = '+str(args.MaxDepth)
print '- NCut = '+str(args.NCut)
if args.IgnoreNE:
  print '-IgnoreNegWeights  = True'
else:
  print '-IgnoreNegWeights  = False'


print '- output will be send to : '+FinalOutputPath

print '##################################################'

