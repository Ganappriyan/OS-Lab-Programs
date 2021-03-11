read -p "Enter the number: " n
a=-1
b=1
c=0
echo "Fibonacci Series is,"
while [ $n -gt $c ]
do
  c=$(($a+$b))
  echo $c
  a=$b
  b=$c
done
