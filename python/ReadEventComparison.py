#!/usr/bin/env python

import os 
from os import listdir
from os.path import isfile,isdir, join    





##---------------- SET ARG INPUT
import argparse
parser = argparse.ArgumentParser(description='option')
parser.add_argument('-i', dest='input', default="NULL")
parser.add_argument('-t', dest='tag', default="NULL")
parser.add_argument('-sr', dest='SR', default="NULL")
#parser.add_argument('--UserInput', action='store_true')
args = parser.parse_args()
input_dir=args.input
tag=args.tag
sr= args.SR


file_dir  = [f for f in listdir(input_dir) if isfile(join(input_dir,f))]

eras = ['2018']
for f in file_dir:

    if not tag in f: 
        continue
    if not sr in f:
        continue
    filenale = f.replace('.txt','')
    filenale = filenale.replace(tag,'')
    filenale = filenale.replace(sr,'')

    for era in eras:
        if era in f:
            filenale = filenale.replace('_'+era,'')
            
            print era+ '_'+ sr+ ' '+ tag  + ' '  + filenale
    
    
