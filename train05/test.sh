#!/bin/bash

for i in {0..6}
do

    testcase=$(printf "%04d" $i)
    ./main < "tests/${testcase}_in.txt" > "output.txt";
    diff -u "output.txt" "tests/${testcase}_out.txt";
    echo "                ";
done

