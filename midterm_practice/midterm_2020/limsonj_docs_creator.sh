#!/bin/bash
# jeremy limson
# 3/7/2022
# practice midterm 2020

# first instance is presumably the description
# replace /* with another symbol to identify comments
# \ is used for escape characters e.g. if you wanted "/" you would do "\/" 
# or if you wanted "*" you would do "\*"
# the /g at the end treats * as a wild card --> not sure what that actually means
sed '0,/\/\*/{s//start_comment/}' ./test_data/$1 > ./modded_data.txt
sed -i 's/\*\//end_comment/g' ./modded_data.txt

# remove comment boundary strings
# this sed takes all the lines between the two strings i gave it
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' > output.txt

echo "====================================================================================================" >> output.txt

# the 0 says only look for the first instance of a match
# remove boundaries surrounding description to avoid repeats
sed -i '0,/start_comment/{s///}' ./modded_data.txt
sed -i '0,/end_comment/{s///}' ./modded_data.txt

# all instances of /* */ after are subsequent comment blocks for function definitions
sed -i 's/\/\*/start_comment/g' ./modded_data.txt
sed -n '/start_comment/, /end_comment/p' ./modded_data.txt | sed 's/\*//' | sed 's/start_comment//' | sed 's/end_comment//' | sed 's/\/\///' >> output.txt

# got this from github
# removes trailing white spaces
sed -i 's/^[ \t]*//;s/[ \t]*$//' output.txt


# this is my scratch work
# while IFS= read line
# do
#     #line=$(sed 's/\*//' <<< $line)
#     echo '${line}'
# done < ./test_data/example_hpp.hpp