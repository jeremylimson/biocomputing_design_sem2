#!/bin/bash
# jeremy limson
# 2/16/2022
# in class 2/16/22

lyric1="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
lyric2="Caught in a bad romance"
lyric5="Ra-ra-ah-ah-ah"
lyric6="Roma Roma-ma"
lyric7="Gaga, ooh la-la"
lyric8="Want your bad romance"

for (( i=1;i<=12;i++ ));
do
    if [ $i -eq 1 ] || [ $i -eq 3 ];
    then
        echo $lyric1
    elif [ $i -eq 2 ] || [ $i -eq 4 ];
    then
        echo $lyric2
    elif [ $i -eq 5 ] || [ $i -eq 9 ];
    then
        echo $lyric5
    elif [ $i -eq 6 ] || [ $i -eq 10 ];
    then
        echo $lyric6
    elif [ $i -eq 7 ] || [ $i -eq 11 ];
    then
        echo $lyric7
    elif [ $i -eq 8 ] || [ $i -eq 12 ];
    then
        echo $lyric8
    fi
done

file_name=./good_movies.txt

echo $file_name

good_movies=cat $file_name

# print favorite movie from the good_movies.txt list
for movie in $good_movies;
do
    if [ "$movie" = "Nick is a bad coder" ];
    then
        echo ${movie}
    fi
done