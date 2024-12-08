#!/bin/bash
echo enter the age 
read num
if [ $num -ge 18 ]
then
      echo allowed
else
      echo not allowed
fi