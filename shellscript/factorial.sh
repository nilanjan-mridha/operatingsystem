#!/bin/bash
read -p "Enter a number: " num
factorial=1

while [ $num -gt 1 ]; do
  ((factorial *= num))
  ((num--))
done

echo "Result is $factorial"
