<< 'Deactive'





SKFlat.py -a ControlPlots -i EGamma                              -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR   &
SKFlat.py -a ControlPlots -i EGamma                              -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR,FakeRun   &
SKFlat.py -a ControlPlots -i DoubleEG                            -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR   &
SKFlat.py -a ControlPlots -i DoubleEG                            -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR,FakeRun   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR,FakeRun   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR,ConvRun   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR,FakeRun,ConvRun   &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 10 -e 2018                               --userflags TriLep,SystRun,ConvCR,FakeRun,FlipRun   &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 10 -e 2018                               --userflags TriLep,SystRun,ConvCR,FlipRun  &
SKFlat.py -a ControlPlots -l prompt_background.txt               -n  5 -e 2018      --skim SkimTree_SS2lOR3l --userflags TriLep,SystRun,ConvCR   &


SKFlat.py -a ControlPlots -i EGamma                              -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr,FakeRun  &
SKFlat.py -a ControlPlots -i EGamma                              -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr   &
SKFlat.py -a ControlPlots -i DoubleEG                            -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr,FakeRun  &
SKFlat.py -a ControlPlots -i DoubleEG                            -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr,FakeRun  &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr,FakeRun,ConvRun  &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 10 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr,ConvRun  &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 10 -e 2018                               --userflags SS2l,SystRun,CFlip,CFCorr,FlipRun  &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 10 -e 2018                               --userflags SS2l,SystRun,CFlip,CFCorr,FakeRun,FlipRun   &
SKFlat.py -a ControlPlots -l prompt_background.txt               -n 5  -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,CFlip,CFCorr   &








SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2016b                           --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2016a                           --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2017                            --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2018                            --userflags SS2l,SystRun,VarPlots,SingleTrigger   &


SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &
SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016b  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016b  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &
SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2017   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2017   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &




SKFlat.py -a KinVarPlot   -i TT_HeavyN-Mu_2L_MN50         -n  5  -e 2018                            --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2018                            --userflags SS2l,SystRun,SystRun,VarPlots,SingleTrigger   &



SKFlat.py -a DiLepValid   -i DYJets                 -n 30  -e 2016a --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets10to50_MG        -n 30  -e 2016a --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets                 -n 30  -e 2016b --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets10to50_MG        -n 30  -e 2016b --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets                 -n 30  -e 2017  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets10to50_MG        -n 30  -e 2017  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets                 -n 30  -e 2018  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DYJets10to50_MG        -n 30  -e 2018  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -l DiLepValid_MC.txt      -n 15  -e 2018  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -l DiLepValid_MC.txt      -n 15  -e 2017  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -l DiLepValid_MC.txt      -n 15  -e 2016b --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -l DiLepValid_MC.txt      -n 15  -e 2016a --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DoubleMuon             -n 20  -e 2018  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DoubleMuon             -n 20  -e 2017  --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DoubleMuon             -n 20  -e 2016b --userflags MuMu,DiLTrig,DiLIncl,SystRun &
SKFlat.py -a DiLepValid   -i DoubleMuon             -n 20  -e 2016a --userflags MuMu,DiLTrig,DiLIncl,SystRun &




Deactive



#SKFlat.py -a KinVarPlot   -i SingleMuon            -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
#SKFlat.py -a KinVarPlot   -i SingleMuon            -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &
#SKFlat.py -a KinVarPlot   -i EGamma                -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
#SKFlat.py -a KinVarPlot   -i EGamma                -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &

#SKFlat.py -a KinVarPlot   -i DoubleMuon            -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
#SKFlat.py -a KinVarPlot   -i DoubleMuon            -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &
#SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
#SKFlat.py -a KinVarPlot   -i DoubleEG              -n  15 -e 2016a  --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun   &


#SKFlat.py -a KinVarPlot   -l TT_HeavyN.txt         -n  5  -e 2018                            --userflags SS2l,SystRun,VarPlots,SingleTrigger   &
#SKFlat.py -a KinVarPlot   -l Conv_background.txt   -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,ConvRun   &
#SKFlat.py -a KinVarPlot   -l Conv_background.txt   -n  15 -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun,ConvRun   &
#SKFlat.py -a KinVarPlot   -l CF_background.txt     -n  15 -e 2018                            --userflags SS2l,SystRun,VarPlots,SingleTrigger,FlipRun   &
#SKFlat.py -a KinVarPlot   -l CF_background.txt     -n  15 -e 2018                            --userflags SS2l,SystRun,VarPlots,SingleTrigger,FakeRun,FlipRun   &
#SKFlat.py -a KinVarPlot   -l prompt_background.txt -n  5  -e 2018   --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,SingleTrigger   &



#SKFlat.py -a KinVarPlot    -l TT_HeavyN.txt          -n  5  -e 2016b                           --userflags SS2l,EffFlow,SingleTrigger  &
#SKFlat.py -a KinVarPlot    -l TT_HeavyN.txt          -n  5  -e 2016b                           --userflags SS2l,EffFlow  &

#SKFlat.py -a KinVarPlot    -i SingleMuon             -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,SingleTrigger,FakeRun  & 
#SKFlat.py -a KinVarPlot    -i DoubleMuon             -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,FakeRun  & 

#SKFlat.py -a KinVarPlot    -i SingleElectron         -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,SingleTrigger,FakeRun  &
#SKFlat.py -a KinVarPlot    -i DoubleEG               -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,FakeRun  &

#SKFlat.py -a KinVarPlot    -l CF_background.txt      -n  15 -e 2016b                           --userflags SS2l,EffFlow,SingleTrigger,FakeRun,FlipRun &
#SKFlat.py -a KinVarPlot    -l CF_background.txt      -n  15 -e 2016b                           --userflags SS2l,EffFlow,FakeRun,FlipRun &

#SKFlat.py -a KinVarPlot    -l Conv_background.txt    -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,SingleTrigger,FakeRun,ConvRun &
#SKFlat.py -a KinVarPlot    -l Conv_background.txt    -n  15 -e 2016b --skim SkimTree_SS2lOR3l  --userflags SS2l,EffFlow,FakeRun,ConvRun &


SKFlat.py -a FakeRateMeas  -l FakeRateMeas.txt       -n  15 -e 2017                            --userflags ElFR,MeasFR,SystRun,ConePtCut,HEMRun &
SKFlat.py -a FakeRateMeas  -l FakeRateMeas.txt       -n  15 -e 2017                            --userflags MuFR,MeasFR,SystRun,ConePtCut,HEMRun &
SKFlat.py -a FakeRateMeas  -i DoubleEG               -n  15 -e 2017                            --userflags ElFR,MeasFR,SystRun,ConePtCut,HEMRun &
SKFlat.py -a FakeRateMeas  -i DoubleMuon             -n  15 -e 2017                            --userflags MuFR,MeasFR,SystRun,ConePtCut,HEMRun &



#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2018                            --userflags MuFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2018                            --userflags ElFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2017                            --userflags MuFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2017                            --userflags ElFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2016b                           --userflags MuFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2016b                           --userflags ElFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2016a                           --userflags MuFR,MeasFR,SystRun &
#SKFlat.py -a FakeRateMeas  -i WGToLNuG_MG            -n  15 -e 2016a                           --userflags ElFR,MeasFR,SystRun &

