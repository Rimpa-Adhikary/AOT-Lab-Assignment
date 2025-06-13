#!/bin/bash
echo "Enter a number to check if it is a Krishnamurthy number:"
read num
n=$num
sum=0
while [ $n -gt 0 ]
do
    digit=$(( n%10 ))
    fact=1
    for (( i=1; i<=digit; i++ ));
    do
        fact=$(( fact * i ))
    done
        sum=$(( sum + fact ))
        n=$((n/10))
done
if [ $num -eq $sum ]; then
    echo "$num is Krishnamurthy number"
else
    echo "$num is not a Krishnamurthy number"
fi