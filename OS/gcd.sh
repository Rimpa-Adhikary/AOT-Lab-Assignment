#!/bin/bash
read -p "Enter 1st number: " n1
read -p "Enter 2nd number: " n2
while [ $b -ne 0]
do
    n2=$(( n1%n2 ))
    n1=$n2
    n2=$n1
done
echo "GCD is $n1"