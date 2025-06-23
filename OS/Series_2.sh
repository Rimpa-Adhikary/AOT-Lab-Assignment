#QS-> f(x,n) = 1 + x²/2! + x⁴/4! + … + x²n/(2n)!

#!/bin/bash

factorial() {
    fact=1
    for (( i=1; i<=$1; i++ ))
    do
        fact=$((fact * i))
    done
    echo $fact
}

echo -n "Enter x: "
read x
echo -n "Enter n (number of terms): "
read n

sum=1

for (( i=1; i<=n; i++ ))
do
    power=$((2 * i))
    num=$(echo "$x^$power" | bc)
    denom=$(factorial $power)
    term=$(echo "scale=4; $num / $denom" | bc)
    sum=$(echo "scale=4; $sum + $term" | bc)
done

echo "Result of the series f(x, n) = $sum"
