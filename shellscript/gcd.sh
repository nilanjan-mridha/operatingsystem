#!/bin/bash

read -p "Enter number 1: " a
read -p "Enter number 2: " b

while [ $b -ne 0 ]; do
  remainer=$((a % b))
  a=$b
  b=$remainer
done

echo "GCD is $a"
