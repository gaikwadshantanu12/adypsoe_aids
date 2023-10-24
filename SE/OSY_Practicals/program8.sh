#!/bin/sh

echo "\nEnter Data For Arithmetic Operations :-\n"
read -p "Enter First Integer : " num1
read -p "Enter Second Integer : " num2

add=`expr $num1 + $num2`
sub=`expr $num1 - $num2`
mul=`expr $num1 \* $num2`
div=`expr $num1 / $num2`
mod=`expr $num1 % $num2`

echo "\nAddition = $add"
echo "Subtraction = $sub"
echo "Multiplication = $mul"
echo "Division = $div"
echo "Modulous = $mod"