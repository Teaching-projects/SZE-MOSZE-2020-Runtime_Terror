#!/bin/bash

IFS=$'\n\r'

> output.txt

for i in `cat input.txt`; do
    echo "east" | ./a.out $i >> output.txt
done

different="$(diff output.txt expected-output.txt)"

if [ -z "$different" ]; 
then
    echo "Successful!"
    exit 0
else
    echo "ERORR: Unsuccessful test."
    exit 1
fi