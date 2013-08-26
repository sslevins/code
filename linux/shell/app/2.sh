#!/bin/bash

file=a.txt
temp=temp.txt

echo -n "Please input a string for search: "
read key

grep -v "$key" $file > $temp
mv $temp $file

