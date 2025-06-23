#!/bin/bash

echo -n "Enter the number: "
read num
echo -n "Enter lower range: "
read lower
echo -n "Enter upper range: "
read upper

if [ $num -ge $lower ] && [ $num -le $upper ]; then
    echo "$num is within the range [$lower, $upper]"
else
    echo "$num is outside the range [$lower, $upper]"
fi
