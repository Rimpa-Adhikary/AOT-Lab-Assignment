#!/bin/bash
read -p "Enter Year:" yr
if [ $((yr%4)) -eq 0 ] && [ $((yr%100)) -ne 0 ] || [ $((yr%400)) -eq 0 ]; then
    echo "$yr is a leap year"
else
    echo "$yr is not a leap year"
fi