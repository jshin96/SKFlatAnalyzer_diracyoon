import os

eras = ["2016preVFP", "2016postVFP","2017","2018"]

for era in eras:
    
    SampleList= []
    with open(os.getenv('SKFlat_WD')+'/data/Run2UltraLegacy_v3/'+era+'/Sample/SampleSummary_Signal_Type1.txt','r') as f:
            for line in f:
                if len(line.split())>0:
                    SampleList.append(line.split()[0])
    os.system("mkdir -p " + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era)
    ssww_signal_file= open(os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/SSWW.txt','w')
    dy_signal_file= open(os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/DY.txt','w')
    vbf_signal_file= open(os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/VBF.txt','w')
    n_ssww=0
    n_dy=0
    n_vbf=0

    for signal in SampleList:
        if 'SSWW' in signal :
            ssww_signal_file.write(signal+'\n')
            n_ssww=n_ssww+1
        if 'DY' in signal :
            dy_signal_file.write(signal+'\n')
            n_dy=n_dy+1
        if 'VBF' in signal :
            vbf_signal_file.write(signal+'\n')
            n_vbf=n_vbf+1
            
    ssww_signal_file.close()
    dy_signal_file.close()
    vbf_signal_file.close()
    print ("Make file " + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/SSWW.txt : ')
    os.system('cat  ' + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/SSWW.txt')
    print ("Make file "+ os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/DY.txt : ')
    os.system('cat  ' +os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/DY.txt')
    print ("Make file "+ os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/VBF.txt : ')
    os.system('cat  ' +os.getenv('SKFlat_WD')+ '/runJobs/HNL_SignalStudies/Signals/'+era + '/VBF.txt')
    print str(n_ssww) + ' : ' +  str(n_dy) +' : '+str(n_vbf) +' : '
