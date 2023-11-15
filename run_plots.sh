#!/bin/bash


mkdir 2018_BREG_plot
mkdir 2017_BREG_plot
mkdir 2016preVFP_BREG_plot
mkdir 2016postVFP_BREG_plot


cd 2018_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2018 -B 0 >> fit_result.txt
cd ..
cd BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2018 -B 1 >> fit_result.txt
cd /data6/Users/shin/SKFlatAnalyzer

cd 2017_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2017 -B 0 >> fit_result.txt
cd ..
cd BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2017 -B 1 >> fit_result.txt
cd /data6/Users/shin/SKFlatAnalyzer

cd 2016preVFP_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2016preVFP -B 0 >> fit_result.txt
cd ..
cd BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2016preVFP -B 1 >> fit_result.txt
cd /data6/Users/shin/SKFlatAnalyzer

cd 2016postVFP_BREG_plot
mkdir BREG_Z_20
mkdir no_BREG_Z_20
cd no_BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2016postVFP -B 0 >> fit_result.txt
cd ..
cd BREG_Z_20
python3 /data6/Users/shin/SKFlatAnalyzer/plot.py -e 2016postVFP -B 1 >> fit_result.txt
cd /data6/Users/shin/SKFlatAnalyzer

