#!/bin/bash

IFS=$'\n'

cppcheck --enable=all *.cpp 2> static-code-analysis.txt

if grep -q "(warning)" "./static-code-analysis.txt"; 
then 
echo "Static code analysis: Unsuccessful! Warning(s)!"
exit 1
fi 

if grep -q "(error)" "./static-code-analysis.txt"; 
then 
echo "Static code analysis: Unsuccessful! Error(s)!"
exit 1
fi

echo "Static code analysis: Successful!"
exit 0
