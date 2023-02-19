#!/bin/bash
read source; read dest;
if cp $source $dest
then
echo File copied successfully
else
echo Unsuccessful
fi