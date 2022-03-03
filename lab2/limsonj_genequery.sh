#!/bin/bash
# jeremy limson
# 3/1/2022
# probe the expression sequence for a specific gene

# take command line argument for gene name
echo "Please provide a gene name to probe for: "

read gene_name

echo

# output to the screen the status of the gene for each time point
# status is either expressed,
if grep -q $gene_name ./expressed_genes_*.txt; then
    echo "$gene_name found in expressed"
fi
# suppressed,
if grep -q $gene_name ./suppressed_genes_*.txt; then
    echo "$gene_name found in suppressed"
fi
# or stationary
if grep -q $gene_name ./stationary_genes_*.txt; then
    echo "$gene_name found in stationary"
fi

# there are repeats included in multiple clusters b/c they are repeated in the gene list