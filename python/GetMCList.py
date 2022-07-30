import os

eras = ["2016preVFP", "2016postVFP","2017","2018"]

for era in eras:
    
    SampleList= []
    with open(os.getenv('SKFlat_WD')+'/data/Run2UltraLegacy_v3/'+era+'/Sample/SampleSummary_MC.txt','r') as f:
            for line in f:
                if len(line.split())>0:
                    SampleList.append(line.split()[0])
    os.system("mkdir -p " + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SR3KinVar/Bkg/'+era)
    mc_file= open(os.getenv('SKFlat_WD')+ '/runJobs/HNL_SR3KinVar/Bkg/'+era + '/MC.txt','w')

    for sample in SampleList:
        mc_file.write(sample+'\n')
            
    mc_file.close()

    print ("Make file " + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SR3KinVar/Bkg/'+era + '/MC.txt : ')
    os.system('cat  ' + os.getenv('SKFlat_WD')+ '/runJobs/HNL_SR3KinVar/Bkg/'+era + '/MC.txt')
