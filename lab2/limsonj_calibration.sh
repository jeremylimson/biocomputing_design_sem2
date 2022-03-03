#!/bin/bash
# jeremy limson
# 3/1/2022
# calibrate and cluster the microarray data from each time point  

# prompt the user for the number of microarray points to be read in and processed
echo "Please enter desired microarray points (0-6) to be read in and processed"

read data_points

for i in {0..6} ; do
    # calibrate the data from each of the seven time points
    ./vect_op_exe ./microarray/red_$i.dat ./microarray/red_background_$i.dat ./microarray/green_$i.dat ./microarray/green_background_$i.dat log_ratio_$i.dat $data_points
    # copy the log ratio output data to a new file
    cp ./log_ratio_$i.dat ./log_ratio_input.dat 
    # run clustering program with ith dataset
    ./cluster_op_exe $data_points suppressed_genes_$i.txt stationary_genes_$i.txt expressed_genes_$i.txt >> ./summary$i.txt
    # create a summary file that lists the final cluster means and the total number of expressed, suppressed, and stationary 
    echo >> ./summary$i.txt
    echo "suppressed genes" >> ./summary$i.txt
    wc -l < suppressed_genes_$i.txt >> ./summary$i.txt

    echo >> ./summary$i.txt
    echo "stationary genes" >> ./summary$i.txt
    wc -l < stationary_genes_$i.txt >> ./summary$i.txt

    echo >> ./summary$i.txt
    echo "expressed genes" >> ./summary$i.txt
    wc -l < expressed_genes_$i.txt >> ./summary$i.txt
done

echo

echo **Summary Files Generated**