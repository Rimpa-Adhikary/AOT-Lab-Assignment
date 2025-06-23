# QS-> 1 + x^1 + x^2 + x^3 + ... + x^n
#!/bin/bash

echo -n "Enter value of x: "
read x
echo -n "Enter value of n: "
read n

sum=1
power=1

for (( i=1; i<=n; i++ ))
do
    power=$((power * x))
    sum=$((sum + power))
done

echo "Sum of series: $sum"
