#!/bin/bash

aa()
{
	echo 1
	echo 2
	echo 3
	echo 4
	echo 5

	return 4
	return 6
	return 7
	return 8
	return 9
}

echo "hello world"
aa
echo $?
