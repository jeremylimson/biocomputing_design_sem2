#!/bin/bash
# jeremy limson
# 3/6/2022
# practice midterm 2019

# If out_directory/ doesn’t exist, your script will create it.
# [ ! -d "/path/to/dir" ] && mkdir out_directory/

# For each student in the class list: 
while read students; do
    # Unpack the tar archive
    for f in ./test_data/*.tar.gz; do 
        tar xf "$f"; 
    done
done <./test_data/class_list.txt

# Copy each .c and .h file within the unpacked files into the out_directory
cp *.c *.h ./out_directory