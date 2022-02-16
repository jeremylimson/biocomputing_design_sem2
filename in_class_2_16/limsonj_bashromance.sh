#!/bin/bash
# jeremy limson
# 2/16/2022
# in class 2/16/22

lyric1="Oh-oh-oh-oh-oh, oh-oh-oh-oh, oh-oh-oh"
lyric2="Caught in a bad romance"
lyric3="Ra-ra-ah-ah-ah"
lyric4="Roma Roma-ma"
lyric5="Gaga, ooh la-la"
lyric6="Want your bad romance"

# print intro to song using for loop and if statements
for (( i=1;i<=6;i++ ));
do
    var="lyric$i"
    if [ "lyric$i" = "$lyric1" ];
    then
        echo lyric1
    elif [ "lyric$i" = "$lyric2" ];
    then
        echo lyric2
    else
        echo ${!var}
    fi
done