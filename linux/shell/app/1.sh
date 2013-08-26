#!/bin/bash

file=$$.db

echo -n "Enter your name: "
read name
echo

echo -n "Enter your sex: "
read sex
echo 

echo -n "Enter your age: "
read age
echo 

echo "Are you sure to insert info as : "
echo -n "$name,$sex,$age "
read x

case $x in
	y | Y | yes | Yes | YES )
		echo "$name,$sex,$age" >> $file
		;;
	*)
		echo "You Canceld"
		;;
esac

echo -n "Enter Return to end"
read temp


