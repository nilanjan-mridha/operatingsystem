#!/bin/bash

read -p "Enter number 1: " a
read -p "Enter number 2: " b
read -p "Enter number 3: " c

if [[ $a -ge $b && $a -ge $c ]]; then
  echo "The greatest number is $a"
elif [[ $b -ge $a && $b -ge $c ]]; then
  echo "The greatest number is $b"
else
  echo "The greatest number is $c"
fi
