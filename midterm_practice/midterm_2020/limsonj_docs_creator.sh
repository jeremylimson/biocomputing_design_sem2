#!/bin/bash
# jeremy limson
# 3/7/2022
# practice midterm 2020

# first instance is presumably the description
# replace /* with another symbol to identify comments
sed '0,/\/\*/{s//start_comment/}' ./test_data/$1 > ./modded_data.txt
sed -i 's/\*\//end_comment/g' ./modded_data.txt

# remove comment boundary strings
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' > output.txt

echo "====================================================================================================" >> output.txt

# remove boundaries surrounding description to avoid repeats
sed -i '0,/start_comment/{s///}' ./modded_data.txt
sed -i '0,/end_comment/{s///}' ./modded_data.txt

# all instances of /* */ after are subsequent comment blocks for function definitions
sed -i 's/\/\*/start_comment/g' ./modded_data.txt
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' | sed 's/\/\///' >> output.txt

# removes trailing white spaces
sed -i 's/^[ \t]*//;s/[ \t]*$//' output.txt