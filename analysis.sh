<< 'Deactive'
#






SKFlat.py -a ControlPlots -l prompt_background.txt               -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun   &
SKFlat.py -a ControlPlots -i EGamma                              -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun,ConvRun   &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 15 -e 2018                               --userflags SS2l,CFlip,SystRun,FlipRun  &
SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 10 -e 2018                                              --userflags SS2l,SystRun,VarPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2018                                              --userflags SS2l,SystRun,VarPlots,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2018                                              --userflags SS2l,SystRun,VarPlots,FakeRun,FlipRun  &
SKFlat.py -a KinVarPlot -i EGamma                   -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i EGamma                   -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun  &



SKFlat.py -a KinVarPlot -i EGamma                   -n 20 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 20 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 20 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,VarPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2018                                              --userflags SS2l,SystRun,VarPlots,FakeRun,FlipRun  &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun,FakeRun   &
SKFlat.py -a ControlPlots -i EGamma                              -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun,FakeRun   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 15 -e 2018      --skim SkimTree_SS2lOR3l --userflags SS2l,CFlip,SystRun,FakeRun,ConvRun   &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 15 -e 2018                               --userflags SS2l,CFlip,SystRun,FakeRun,FlipRun    &



SKFlat.py -a KinVarPlot -l TT_HeavyN.txt                   -n 20 -e 2018                     --userflags SS2l,SystRun,VarPlots  &


SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2018                               --userflags ElFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2017                               --userflags ElFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2016a                               --userflags ElFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2016b                               --userflags ElFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2018                               --userflags MuFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2017                               --userflags MuFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2016a                               --userflags MuFR,MCClosure    &
SKFlat.py -a MCFakeStudy -l FR_MC_Closure.txt          --skim SkimTree_SS2lOR3l         -n 15 -e 2016b                               --userflags MuFR,MCClosure    &





SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 5 -e 2017                                              --userflags OS2l,SystRun,VarPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,ConvRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,FlipRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,FakeRun,FlipRun  &

SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 5 -e 2016a                                             --userflags OS2l,SystRun,VarPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,ConvRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,FlipRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,FakeRun,FlipRun  &

SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 5 -e 2016b                                             --userflags OS2l,SystRun,VarPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,ConvRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,FlipRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,FakeRun,FlipRun  &



SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2017                                              --userflags OS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2016a                                             --userflags OS2l,SystRun,VarPlots,FakeRun  &
SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots  &
SKFlat.py -a KinVarPlot -i DoubleEG                   -n 10 -e 2016b                                             --userflags OS2l,SystRun,VarPlots,FakeRun  &


SKFlat.py -a DiLepValid -i DYJets                            -n 10 -e 2018                                   --userflags SF2L,PUVETO,DiLTrig,DiLBJet  &
SKFlat.py -a DiLepValid -i DYJets10to50_MG                   -n 10 -e 2018                                   --userflags SF2L,PUVETO,DiLTrig,DiLBJet  &
SKFlat.py -a DiLepValid -i DYJets                            -n 10 -e 2018                                   --userflags SF2L,DiLTrig,DiLBJet  &
SKFlat.py -a DiLepValid -i DYJets10to50_MG                   -n 10 -e 2018                                   --userflags SF2L,DiLTrig,DiLBJet  &

SKFlat.py -a ControlPlots -i EGamma                              -n 15 -e 2018                               --userflags TetraLep,SystRun   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 15 -e 2018                               --userflags TetraLep,SystRun,FakeRun   &
SKFlat.py -a ControlPlots -i EGamma                              -n 15 -e 2018                               --userflags TetraLep,SystRun,FakeRun   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 15 -e 2018                               --userflags TetraLep,SystRun,ConvRun   &
SKFlat.py -a ControlPlots -l Conv_background.txt                 -n 15 -e 2018                               --userflags TetraLep,SystRun,FakeRun,ConvRun   &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 15 -e 2018                               --userflags TetraLep,SystRun,FakeRun,FlipRun    &
SKFlat.py -a ControlPlots -l CF_background.txt                   -n 15 -e 2018                               --userflags TetraLep,SystRun,FlipRun  &
SKFlat.py -a ControlPlots -l prompt_background.txt               -n 15 -e 2018                               --userflags TetraLep,SystRun   &
SKFlat.py -a ControlPlots -i DoubleMuon                          -n 15 -e 2018                               --userflags TetraLep,SystRun   &

SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 3  -e 2016b                                             --userflags SS2l,SystRun,DiscPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 5  -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 20 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2016b                                             --userflags SS2l,SystRun,DiscPlots,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 20 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2016b                                             --userflags SS2l,SystRun,DiscPlots,FakeRun,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,FakeRun  &

SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 3  -e 2016a                                             --userflags SS2l,SystRun,DiscPlots &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 5  -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 20 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2016a                                             --userflags SS2l,SystRun,DiscPlots,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 20 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 20 -e 2016a                                             --userflags SS2l,SystRun,DiscPlots,FakeRun,FlipRun  &

SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 3  -e 2018                                              --userflags SS2l,SystRun,DiscPlots,DiscCutOpt &
SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 5  -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2018                                              --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2018                                              --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,FlipRun  &
SKFlat.py -a KinVarPlot -i EGamma                   -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i EGamma                   -n 10 -e 2018                     --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &


SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 3  -e 2016b                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt &
SKFlat.py -a KinVarPlot -l TT_HeavyN.txt            -n 3  -e 2016a                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt &

Deactive





SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 5  -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016b                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016b                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016b                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &

SKFlat.py -a KinVarPlot -l prompt_background.txt    -n 5  -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016a                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i DoubleMuon               -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &
SKFlat.py -a KinVarPlot -l Conv_background.txt      -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,ConvRun  &
SKFlat.py -a KinVarPlot -l CF_background.txt        -n 10 -e 2016a                                             --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun,FlipRun  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt  &
SKFlat.py -a KinVarPlot -i DoubleEG                 -n 10 -e 2016a                    --skim SkimTree_SS2lOR3l --userflags SS2l,SystRun,DiscPlots,DiscCutOpt,FakeRun  &
