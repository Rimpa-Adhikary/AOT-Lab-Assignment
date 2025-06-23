#!/bin/bash

factorial() {
    f=1
    for (( i=1; i<=$1; i++ ))
    do
        f=$((f * i))
    done
    echo $f
}

echo -n "Enter n: "
read n
echo -n "Enter r: "
read r

n_fact=$(factorial $n)
r_fact=$(factorial $r)
nr_fact=$(factorial $((n - r)))

ncr=$((n_fact / (r_fact * nr_fact)))
echo "nCr value: $ncr"
