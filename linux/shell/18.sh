#!/bin/bash

do_it()
{
	echo -n "Please input a char: "
	read x

	case $x in
		n | N)
			return 1
			;;
		y | Y)
			return 0
			;;
		*)
			return 1
			;;
	esac
}

if do_it
then
	echo "you just input y"
else
	echo "you just input n"
fi

echo 

do_it && {
	echo "you just input y" 
	echo 1
	echo 2
	echo 3
	echo 4
} || {
	echo "you just input n"
	echo a
	echo b
	echo c
	echo d
}







