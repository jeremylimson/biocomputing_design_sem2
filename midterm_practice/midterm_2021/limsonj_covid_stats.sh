#!/bin/bash
# jeremy limson
# 3/6/2022
# practice midterm 2021

# check if file exist
FILE=owid-covid-data.csv

# make sure it is only done once
if test -f "$FILE"; then
    rm owid-covid-data.csv
fi

# download the csv file
wget -A csv https://raw.githubusercontent.com/owid/covid-19-data/master/public/data/owid-covid-data.csv

# This will take a CSV file as input, 
# pull out the header row, 
# split that onto new lines 
# and then prepend a zero indexed line number to each line
# head ./owid-covid-data.csv -n 1 | sed "s/,/\n/g" | awk '{printf("%d %s\n", NR-1, $0)}'
headers=( $( head ./owid-covid-data.csv -n 1 | sed "s/,/\n/g" ) ) 

if [[ ! " ${headers[*]} " =~ " ${1} " ]]; then
    # whatever you want to do when array doesn't contain value
    echo "The item you chose does not exist"
fi

# use grep or sed to
# pipe cut into ifs to read line by line

if [[ " ${headers[*]} " =~ " ${1} " ]]; then
    # whatever you want to do when array contains value
    for i in "${!headers[@]}"; do
    if [[ "${headers[$i]}" = "${1}" ]]; then
        let column=$i+1
        new_cases=( $( cut -d ',' -f$column owid-covid-data.csv ) )
    fi
done
fi

country=( $( cut -d ',' -f3 owid-covid-data.csv ) )

if [[ " ${country[*]} " =~ " ${2} " ]]; then

fi

# display to the screen the monthly average of the new covid cases per million for at least one country
# TODO : how do you get monthly average

# print out two arrays on same line
# paste <(printf "%s\n" "${country[@]}") <(printf "%s\n" "${new_cases[@]}") > 

# FIXME : arrays are different sizes 
# how do you remove blank data
echo "${#country[@]}"
echo "${#new_cases[@]}"