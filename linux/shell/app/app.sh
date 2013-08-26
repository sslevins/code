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
	echo $* >> $title_file
	return
}

insert_track() 
{
	echo $* >> $tracks_file
	return
}

add_record_tracks() 
{
	echo add_record_tracks
}

add_records()
{
	echo -n "Enter catalog: "
	read catalog

	echo -n "  Enter title: "
	read title

	echo -n "   Enter style: "
	read style

	echo -n "  Enter artist: "
	read artist

	echo "Are you sure to add CD as: "
	echo "$catalog,$title,$style,$artist"

	if get_confirm
	then
		insert_title $catalog $title $style $artist
	else
		return 1
	fi

	echo "please add tracks for this CD"
	echo "enter a blank line to quit"

	name="x"

	while true
	do

		echo -n "tracks name: "
		read name 

		if [ -z $name ]
		then
			return 1
		fi

		if get_confirm
		then
			insert_track $catalog $name
		fi
		
	done
}

find_cd()
{
	echo -n "Enter a string for search: "
	read key

	grep $key $title_file > $temp_file

	set $(wc -l $temp_file)
	num=$1

	case $num in
		0)
			echo "Didn't find CD by $key"
			;;
		1)
			set $(cat $temp_file)
			cdcatnum=$1
			cat $temp_file
			;;
		*)
			echo "The result is not unique, please input a new string and try again"
			cat $temp_file
			;;
	esac

	get_return
}

update_cd()
{
	echo update_cd
}

count_cds()
{
	set $(wc -l $title_file)
	cds=$1

	set $(wc -l $tracks_file)
	tracks=$1

	echo "We have $cds CDs, they contain $tracks tracks"
	get_return
}

remove_records()
{
	grep -v $cdcatnum $title_file > $temp_file
	mv $temp_file $title_file

	grep -v $cdcatnum $tracks_file > $temp_file
	mv $temp_file $tracks_file

	cdcatnum=""

	get_return
}

list_tracks()
{
	echo list_tracks
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
