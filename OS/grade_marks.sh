#!/bin/bash

echo -n "Enter your marks (0-100): "
read marks

if [ $marks -ge 90 ] && [ $marks -le 100 ]; then
    echo "Grade: A"
elif [ $marks -ge 80 ]; then
    echo "Grade: B"
elif [ $marks -ge 70 ]; then
    echo "Grade: C"
elif [ $marks -ge 60 ]; then
    echo "Grade: D"
elif [ $marks -ge 50 ]; then
    echo "Grade: E"
elif [ $marks -ge 0 ]; then
    echo "Grade: F (Fail)"
else
    echo "Invalid input"
fi
