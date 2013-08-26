#!/bin/bash

total=""

for var in $*
do
	let total=$total+$var
done

echo $total


