#!/bin/bash

echo -n "Enter a number: "
read num
sum=0

for (( i=1; i<num; i++ ))
do
    if (( num % i == 0 )); then
        sum=$((sum + i))
    fi
done

if (( sum == num )); then
    echo "$num is a Perfect Number"
else
    echo "$num is Not a Perfect Number"
fi
