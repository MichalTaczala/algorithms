#!/bin/bash

echo "compiling"
g++ prog.cpp
echo "compiling done"
echo "creating output files"
./a.out <in.txt > myOut.txt
./a.out <in1.txt > myOut1.txt
./a.out <in2.txt > myOut2.txt
./a.out <in3.txt > myOut3.txt
echo "output files created"


echo "check dif"

diff -w myOut.txt out.txt
echo "_________________________"

echo "check dif1"
diff -w myOut1.txt out1.txt
echo "_________________________"

echo "check dif2"
diff -w myOut2.txt out2.txt
echo "_________________________"

echo "check dif3"

diff -w myOut3.txt out3.txt

