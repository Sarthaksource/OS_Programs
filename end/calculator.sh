#!/bin/bash
echo Sarthak A2 58
ch=0
while [ $ch -ne 5 ]
do
    echo 1=Add
    echo 2=Subtract
    echo 3=Multiply
    echo 4=divide
    echo 5=exit
    echo enter the choice
    read ch
    case $ch in
        1) read a
        read b
        let c=$a+$b
        echo $c
        ;;
        2) read a
        read b
        let c=$a-$b
        echo $c
        ;;
        3) read a
        read b
        let c=$a*$b
        echo $c
        ;;
        4) read a
        read b
        let c=$a/$b
        echo $c
        ;;
        5) ch=5;;
        *) echo invalid;;
    esac
done