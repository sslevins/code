#!/bin/bash

let var1=$1%4
let var2=$1%100
let var3=$1%400

if [ $var3 -eq 0 ]
then
	echo "is"
elif [ $var1 -eq 0 ] && [ $var2 -ne 0 ] 
then
	echo "is"
else
	echo "is not"
fi
