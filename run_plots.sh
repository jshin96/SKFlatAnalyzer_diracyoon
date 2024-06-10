#!/bin/bash
mkdir original_2jets
#mkdir modified_2jets
#mkdir free_2jets

cd original_2jets
mkdir 2016preVFP_BREG_plot
cd 2016preVFP_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2016preVFP -B 0 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2016preVFP -B 0 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2016preVFP -B 0 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2016preVFP -B 1 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2016preVFP -B 1 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2016preVFP -B 1 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd ..
mkdir 2016postVFP_BREG_plot
cd 2016postVFP_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2016postVFP -B 0 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2016postVFP -B 0 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2016postVFP -B 0 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2016postVFP -B 1 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2016postVFP -B 1 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2016postVFP -B 1 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd ..
mkdir 2017_BREG_plot
cd 2017_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2017 -B 0 -s original -r $(($1/10)).$(($1%10)) 
#python3 ../../../plot.py -e 2017 -B 0 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2017 -B 0 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2017 -B 1 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2017 -B 1 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2017 -B 1 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd ..
mkdir 2018_BREG_plot
cd 2018_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 ../../../plot.py -e 2018 -B 0 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2018 -B 0 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2018 -B 0 -s original -r $(($1/10)).$(($1%10)) -M uu
cd ..
cd BREG_Z_20
python3 ../../../plot.py -e 2018 -B 1 -s original -r $(($1/10)).$(($1%10))
#python3 ../../../plot.py -e 2018 -B 1 -s original -r $(($1/10)).$(($1%10)) -M dd
#python3 ../../../plot.py -e 2018 -B 1 -s original -r $(($1/10)).$(($1%10)) -M uu

cd ../../..

tar -vcf original_2jets_$(($1/10))p$(($1%10)).tar.gz original_2jets

mv original_2jets_$(($1/10))p$(($1%10)).tar.gz original_2jets
