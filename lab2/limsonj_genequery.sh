#!/bin/bash
# jeremy limson
# 3/1/2022
# probe the expression sequence of a specific gene

# take command line argument for gene name
echo "Please provide a gene name to probe for: "

read gene_name

grep $gene_name

# output to the screen the status of the gene for each time point
# status is either expressed, suppressed, stationary