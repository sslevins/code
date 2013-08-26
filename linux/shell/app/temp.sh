#!/bin/bash

menu_choice=""
current_cd=""
title_file="title.cdb"
tracks_file="tracks.cdb"
temp_file=/tmp/cdb.$$

get_return() 
{
	echo -n "Press return"
	read x
	return 0
}

get_confirm()
{
	echo -n "Are you sure?"
	while true
	do
		read x
		case "$x" in 
			y | yes | Y | Yes | YES )
				return 0
				;;
			n | no | N | No | NO )
				echo
				echo "Cancelled"
				return 1
				;;
			*)
				echo "Please enter yes or no"
				;;
		esac
	done
}

set_menu_choice()
{
	clear
	echo "Options :-"
	echo 
	echo "	a) Add new CD"
	echo "	f) Find CD"
	echo "	c) Count the CDs and tracks in the catalog"
	if [ "$cdcatnum" != "" ]
	then
		echo "	l) List tracks on $cdtitle"
		echo "	r) Remove $cdtitle"
		echo "	u) Update track information for $cdtitle"
	fi
	echo "	q) Quit"
	echo
	echo -n "Please enter choice then press return "

	read menu_choice

	return
}

insert_title() 
{
}

insert_track() 
{
}

add_record_tracks() 
{
}

add_records()
{
}

find_cd()
{
}

update_cd()
{
}

count_cds()
{
}

remove_records()
{
}

list_tracks()
{
}

rm -f $temp_file

if [ ! -f $title_file ]
then
	touch $title_file
fi

if [ ! -f $tracks_file]
then
	touch $tracks_file
fi

clear
echo
echo
echo "Mini CD manager"
sleep 1

quit=n
while [ "$quit" != "y" ]
do
	set_menu_choice
	case "$menu_choice" in
		a) 
			add_records 
			;;
		r) 
			remove_records 
			;;
		f) 
			find_cd 
			;;
		u) 
			update_cd 
			;;
		c) 
			count_cds 
			;;
		l) 
			list_tracks 
			;;
		b)
			echo
			cat $title_file
			echo
			get_return
			;;
		q | Q )
			quit=y
			;;
		*)
			echo "Sorry, choice not recognized"
			;;
	esac
done

rm -f $temp_file
echo "Finished"
exit 0
