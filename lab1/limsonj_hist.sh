#!/bin/bash
# jeremy limson
# 2/28/2022
# histogram analysis

# prompt user for concentration to analyze
echo Please enter desired concentration levels

read lvl_analyzed

if [ "$lvl_analyzed"=="ERP00" ];
then
    echo Reading $lvl_analyzed  
    cat ERP00/* > EEG_DATA/catted_input.dat
elif [ "$lvl_analyzed"=="ERP05" ];
then
    echo Reading $lvl_analyzed
    cat ERP05/* > EEG_DATA/catted_input.dat  
fi

# FIXME
~/bin/./limsonj_stats_exec EEG_DATA/catted_input.dat > EEG_DATA/hist_results_$lvl_analyzed.dat

# check if file exist
FILE=EEG_DATA/hist_results_$lvl_analyzed.dat

if test -f "$FILE"; then
    echo "$FILE exists."
fi

# let user know histogram was generated
echo Histogram is hot n ready. Please check EEG_DATA/hist_results_$lvl_analyzed.dat