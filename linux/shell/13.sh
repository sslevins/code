#!/bin/bash

#var=$1
echo -n "Please input a num: "
read var

while [ $var -ne 0 ]
do
	echo "hello"
	let var=$var-1
done

echo "world"
