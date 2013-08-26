#!/bin/bash

aa()
{
	echo "in aa"
	bb
	echo "out aa"
}

bb()
{
	echo "in bb"
	#return 0
	exit 0
	cc
	echo "out bb"
}

cc()
{
	echo "in cc"
	echo "out cc"
}

aa


