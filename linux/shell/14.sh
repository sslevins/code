#!/bin/bash

echo -n "Please input a char: "
read x

case $x in
	"a")
		echo "hello"
		;;
	"b")
		echo "world"
		;;
	"c")
		echo "good"
		;;
	"d")
		echo "bye"
		;;
	*)
		echo "other"
		;;
esac

echo -n "Please input a char: "
read x

if [ $x = "a" ]
then
	echo "hello"
elif [ $x = "b" ]
then
	echo "world"
elif [ $x = "c" ]
then
	echo "good"
elif [ $x = "d" ]
then
	echo "bye"
else
	echo "other"
fi
