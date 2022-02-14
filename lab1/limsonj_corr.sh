#!/bin/bash
# jeremy limson
# 2/28/2022
# correlation of consecutive data sets of ERP data

# prompt user for concentration to analyze
echo Please enter desired concentration levels

read lvl_analyzed

# iterate through all files in ERPXX directory
if [ "$lvl_analyzed"=="ERP00" ];
then
    echo Reading $lvl_analyzed
    # iterate through all files in ERPXX directory
    for i in {1..59} ; do
        let next_file=$i+1
        ./limsonj_corr_exec ./ERP00/ERP00$i.txt ./ERP00/ERP00$next_file.txt
        # send to .csv
    done
elif [ "$lvl_analyzed"=="ERP05" ];
then
    echo Reading $lvl_analyzed
    for i in {1..59} ; do
        let next_file=$i+1
        ./limsonj_corr_exec ./ERP05/ERP05$i.txt ./ERP05/ERP05$next_file.txt
        # send to .csv
    done
fi