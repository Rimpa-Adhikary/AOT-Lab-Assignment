#!/bin/bash

echo -n "Enter a number: "
read n

if [ $n -le 1 ]; then
    echo "$n is not a prime number"
    exit
fi

is_prime=1

for (( i=2; i<=n/2; i++ ))
do
    if [ $((n % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done

if [ $is_prime -eq 1 ]; then
    echo "$n is a prime number"
else
    echo "$n is not a prime number"
fi
