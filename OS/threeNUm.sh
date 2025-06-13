#!/bin/bash
#Find the largest of three numbers
echo "Enter 1st number:"
read n1
echo "Enter 2nd number:"
read n2
echo "Enter 3rd number:"
read n3
if [ $n1 -gt $n2] && [ $n1 -gt $n3 ]; then
    echo "$n1 is largest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]; then
    echo "$n2 is largest"
else
    echo "$n3 is largest"
fi