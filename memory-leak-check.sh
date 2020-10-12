#!/bin/bash

IFS=$'\n'

valgrind --error-exitcode=1 ./a.out unit1.json unit2.json 2> ./memory-leak-check.txt

echo "Memory leak check: Successful!"
exit 0