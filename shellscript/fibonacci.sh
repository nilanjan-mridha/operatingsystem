#!/bin/bash

read -p "Enter number of terms: " t
[[ $t -le 0 ]] && echo "Enter a number greater than 0" && exit

a=0
b=1

for i in $(seq 1 $t); do
  echo -n "$a "
  next=$((a + b))
  a=$b
  b=$next

done
echo ""
