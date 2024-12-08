#!/bin/bash
echo Sarthak A2 58
ch=0
while [ $ch -ne 4 ]
do
	echo 1 current path
	echo 2 list dir
	echo 3 Date
	echo 4 exit
	echo enter the choice
	read ch
	case $ch in
		1) pwd;;
		2) ls -ltr;;
		3) date;;
		4) ch=4;;
		*) echo invalid;;
	esac
done