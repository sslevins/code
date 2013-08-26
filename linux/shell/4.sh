#!/bin/bash

for var in aa bb cc dd
do
	echo $var
done

echo $*
set xx yy zz
echo $*

#for var in xx yy zz
for var in $*
do
	echo $var
done

