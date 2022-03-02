#!/bin/bash
# jeremy limson
# 3/2/2022
# practice with downloading files from url, filtering, and trimming

# Download one of your cpp files from Lab 1 using bash from your Github
wget -N https://raw.githubusercontent.com/jeremylimson/biocomputing_design_sem2/main/lab1/limsonj_stats.cpp

# Using the filters we covered on Monday, extract all function headers, and output them to a file. 
grep ".*::.*(" ./limsonj_stats.cpp

echo 
echo "namespace:"
# Determine the namespace of all functions, and add a line to the bottom of the same file
grep -m1 ".*::" ./limsonj_stats.cpp | sed 's/::.*//g'

echo
echo "class name:"
# Determine the class of all functions, and add a line to the bottom of the same file
class_name=$(grep -m1 "::.*" ./limsonj_stats.cpp | sed 's/.*::.*:://g')
echo $class_name | sed 's/(.*//g'