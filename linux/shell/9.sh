#!/bin/bash

file="./1.sh"

#if [ -e $file ] && [ -f $file ] && \
#	[ -r $file ] &&  [ -w $file ] && \
#	[ -x $file ]

if [ -e $file -a -f $file -a \
	 -r $file -a  -w $file  -a \
	 -x $file ]
then
	echo "$file is exists"
	echo "$file is a file"
	echo "$file have read permission"
	echo "$file have write permission"
	. $file
fi

