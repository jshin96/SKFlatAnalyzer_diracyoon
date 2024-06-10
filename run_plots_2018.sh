#!/bin/bash

mkdir original_2jets
#mkdir modified_2jets
#mkdir free_2jets

cd original_2jets
mkdir 2018_BREG_plot
cd 2018_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2018 -B 0 -s original  -r $1
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2018 -B 1 -s original  -r $1


#cd ../../../
#cd modified_2jets
#mkdir 2018_BREG_plot
#cd 2018_BREG_plot
#mkdir BREG_Z_20
#mkdir no_BREG_Z_20
#cd no_BREG_Z_20
#python3 ../../../plot.py -e 2018 -B 0 -s modified
#cd ..
#cd BREG_Z_20
#python3 ../../../plot.py -e 2018 -B 1 -s modified

#cd ../../../
#cd free_2jets
#mkdir 2018_BREG_plot
#cd 2018_BREG_plot
#mkdir BREG_Z_20
#mkdir no_BREG_Z_20
#cd no_BREG_Z_20
#python3 ../../../plot.py -e 2018 -B 0 -s free
#cd ..
#cd BREG_Z_20
#python3 ../../../plot.py -e 2018 -B 1 -s free



