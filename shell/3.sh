#!/bin/bash
read -p "Enter something: " str
echo "User input is: $str"
strUppercase=$(printf '%s\n' "$str" | awk '{ print toupper($0) }')
strLowercase=$(printf '%s\n' "$str" | awk '{ print tolower($0) }')
if [ -z "${str//[0-9]/}" ]; then
	echo "Digit"
elif [ $str == $strLowercase ]; then
	echo "Lowercase"
elif [ $str == $strUppercase ]; then
	echo "Uppercase"
else
	echo "Something else"
fi
