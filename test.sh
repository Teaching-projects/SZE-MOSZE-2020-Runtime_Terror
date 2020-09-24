#!/bin/bash

IFS=$'\n\r'

for i in `cat input.txt`; do
    echo $i | xargs ./a.out
done