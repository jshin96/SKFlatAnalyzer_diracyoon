#!/bin/bash

mkdir original_2jets
#mkdir modified_2jets
#mkdir free_2jets

cd original_2jets
mkdir 2016postVFP_BREG_plot
cd 2016postVFP_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2016postVFP -B 0 -s original  -r $1
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2016postVFP -B 1 -s original  -r $1


#cd ../../../
#cd modified_2jets
#mkdir 2016postVFP_BREG_plot
#cd 2016postVFP_BREG_plot
#mkdir BREG_Z_20
#mkdir no_BREG_Z_20
#cd no_BREG_Z_20
#python3 ../../../plot.py -e 2016postVFP -B 0 -s modified
#cd ..
#cd BREG_Z_20
#python3 ../../../plot.py -e 2016postVFP -B 1 -s modified

#cd ../../../
#cd free_2jets
#mkdir 2016postVFP_BREG_plot
#cd 2016postVFP_BREG_plot
#mkdir BREG_Z_20
#mkdir no_BREG_Z_20
#cd no_BREG_Z_20
#python3 ../../../plot.py -e 2016postVFP -B 0 -s free
#cd ..
#cd BREG_Z_20
#python3 ../../../plot.py -e 2016postVFP -B 1 -s free



