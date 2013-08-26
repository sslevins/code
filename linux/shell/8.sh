#!/bin/bash

file="./1.sh"

if [ -e $file -a -f $file -a -r $file -a -w $file -a -x $file ]
then
	echo "$file is exists"
	echo "$file is a file"
	echo "$file have read permission"
	echo "$file have write permission"
	. $file
fi

