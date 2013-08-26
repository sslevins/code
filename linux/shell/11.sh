#!/bin/bash

if [ "a" = "a" ] || echo "hello" || [ "b" = "x" ]
then
	echo "a = a"
	echo "b = b"
else
	echo "else"
fi

