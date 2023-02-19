#Script for
#arithmetic operations on integers
a=20 b=30
c=$(expr $a + $b)
echo $(expr $a - $b)
echo $(expr $a \* $b)
echo $(expr $a / $b)
echo $(expr $a % $b)
echo Sum = $c