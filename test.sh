#!/bin/bash

IFS=$'\n\r'

> output.txt

cat input.txt | ./a.out >> output.txt

different="$(diff output.txt expected-output.txt)"

if [ -z "$different" ]; 
then
    echo "Successful!"
    exit 0
else
    echo "ERORR: Unsuccessful test."
    exit 1
fi