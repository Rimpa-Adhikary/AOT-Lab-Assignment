#!/bin/bash

echo -n "Enter a number: "
read num

if [ $num -gt 0 ]; then
    echo "$num is Positive"
elif [ $num -lt 0 ]; then
    echo "$num is Negative"
else
    echo "The number is Zero"
fi
