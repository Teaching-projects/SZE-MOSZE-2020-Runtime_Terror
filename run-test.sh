#!/bin/bash

IFS=$'\n'

for i in `cat input.txt`; do
    echo ./a.out "$i"
done