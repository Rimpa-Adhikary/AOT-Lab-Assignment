#!/bin/bash
read -p "Enter 1st number" n1
read -p "Enter 2nd number" n2
read -p "Enter operator (+,-,*,/)" op
case $op in
    +)
        ans=$((n1+n2))
        echo "Sum is $ans"
        ;;
    -)
        ans=$((n1-n2))
        echo "Difference is $ans"
        ;;
    *)
        ans=$((n1*n2))
        echo "Product is $ans"
        ;;
    /)
        if [ $n2 -ne 0 ]; then
            ans=$((n1/n2))
            echo "Quotient is $ans"
        else
            echo "Division by zero is not allowed"
        fi
        ;;
    *)
        echo "Invalid operator"
        ;;
esac