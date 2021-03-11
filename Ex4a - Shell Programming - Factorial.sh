read -p "Enter a Positive Number to find Factorial: " n
f=1
while [ $n -gt 0 ]
do
	let "f *= n"
	let "n -= 1"
done
echo "Factorial is $f"
