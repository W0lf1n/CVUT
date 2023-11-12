#!/bin/bash

for i in {0..4}
do

    testcase=$(printf "%04d" $i)
    ./main < "tests/${testcase}_in.txt" > "output.txt";
    diff -u "output.txt" "tests/${testcase}_out.txt";
    echo "                ";
done

