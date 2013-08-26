#!/bin/bash

var=""

if [ -n $var ]
then
	echo "is null"
else
	echo "is not null"
fi

if [ -z $var ]
then
	echo "length is zero"
else
	echo "length is not zero"
fi

var1="hello"
var2="hello"
if [ $var1 = $var2 ]
then
	echo "is equal"
else
	echo "is not equal"
fi

var1=123
var2=45
#if [ $var1 -eq $var2 ]
#if [ $var1 -ge $var2 ]
if [ $var1 -lt $var2 ]
then
	echo "yes"
else
	echo "no"
fi

