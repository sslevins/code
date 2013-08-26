#!/bin/bash

file=a.txt

echo -n "Please input a string for search: "
read key
echo 


#IFS_BAK=$IFS
#IFS=","

set $(grep "$key" $file)

#IFS=$IFS_BAK

echo "result: -"
echo "------------------"
echo "catlog: $1"
echo "  name: $2"
echo "  text: $3"








