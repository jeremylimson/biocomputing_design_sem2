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
    # Copy each .c and .h file within the unpacked files into the out_directory
    cp *.c *.h ./out_directory

    # append the student’s last name to the start of the copied filename
    mv ./out_directory/*.c ./out_directory/${students}_code.c
    mv ./out_directory/*.h ./out_directory/${students}_code.h

done <./test_data/class_list.txt