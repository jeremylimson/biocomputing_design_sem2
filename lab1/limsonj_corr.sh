#!/bin/bash
# jeremy limson
# 2/15/2022
# correlation of consecutive data sets of ERP data

# prompt user for concentration to analyze
echo Please enter desired concentration levels

read lvl_analyzed

# for FILE in *; do 
#     echo $FILE;   # this does all the files but not in consecutive order
# done

# iterate through all files in ERPXX directory
if [ "$lvl_analyzed"=="ERP00" ];
then
    echo Reading $lvl_analyzed
    # iterate through all files in ERPXX directory
    for i in {1..59} ; do
        let next_file=$i+1
        # send to .csv
        # add label describing correlation e.g. ERP001 vs. ERP002, coefficient
        ./
        # FIXME this works but running it multiple times will only append to existing file
        # what is the format of a csv and how do we add commas
        ./limsonj_corr_exec ./ERP00/ERP00$i.txt ./ERP00/ERP00$next_file.txt >> ./EEG_DATA/conc_corr_$lvl_analyzed.csv
    done
elif [ "$lvl_analyzed"=="ERP05" ];
then
    echo Reading $lvl_analyzed
    for i in {1..59} ; do
        let next_file=$i+1
        # send to .csv
        # FIXME this works but running it multiple times will only append to existing file
        ./limsonj_corr_exec ./ERP05/ERP05.$i.txt ./ERP05/ERP05.$next_file.txt >> ./EEG_DATA/conc_corr_$lvl_analyzed.csv
    done
fi

FILE=./EEG_DATA/conc_corr_$lvl_analyzed.csv

# check if file exists
if test -f "$FILE"; then
    echo "$FILE exists. Take a looksie ;')"
fi