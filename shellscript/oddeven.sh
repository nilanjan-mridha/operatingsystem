# 1. Odd even
echo "Enter a number: "
read n
if [ $((number % 2)) -eq 0 ]; then
  echo "Number $n is even"
else
  echo "Number $n is odd"
fi
