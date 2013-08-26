#!/bin/bash


do_it() 
{
	local var="good"
	echo $var
}


echo "hello"
do_it
echo "world"
echo $var

read x
