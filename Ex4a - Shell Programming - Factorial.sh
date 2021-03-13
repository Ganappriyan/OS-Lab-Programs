echo " Enter the number for which factorial is to be found "
read n
f=1
a=0
i=1
if [ $n -eq $a ]; then
    echo $f
else
    while [ $i -le $n ]; do
        f=$(expr $f \* $i)
        i=$(expr $i + 1)
    done
fi
echo " The factorial of the number is "
echo $f
