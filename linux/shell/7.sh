#!/bin/bash

file="./1.sh"

if [ -e $file ]
then
	echo "$file is exists"

	if [ -f $file ]
	then
		echo "$file is a file"

		if [ -r $file ]
		then
			echo "$file have read permission"
			if [ -w $file ]
			then
				echo "$file have write permission"

				if [ -x $file ]
				then
					echo "$file have excute permission"
					. $file
				fi
			fi
		fi

	else
		echo "$file is not a file"
	fi
else
	echo "$file is not exists"
fi

