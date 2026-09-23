# 2. LEAP YEAR
read -p "Enter a year: " year
echo "$year"

if [ $((year % 400)) -eq 0 ] || { [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ]; }; then
  echo "Lear year"
else
  echo "Not leap year"
fi
