echo "Enter the number"
read n
i=1
a=-1
fib=0
b=1
echo "Fibonacci series is"
while [ $i -lt $n ]; do
    fib=$(expr $a + $b)
    a=$b
    b=$fib
    echo $fib
    i=$(expr $i + 1)
done
