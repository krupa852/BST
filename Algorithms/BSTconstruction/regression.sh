#!/bin/bash
FILES=Input_testcases/*
for f in $FILES
do
  echo "Processing $f file..." 
  new_tmp=${f//[!0-9_]/}
  filename="output${new_tmp}.txt"
  echo $filename
  ./a.out<$f>$filename
  mfile="Master_testcases/master${new_tmp}.txt"
  echo "$mfile"
  if ! diff -q $filename $mfile &>/dev/null; then
  >&2 echo "Testcase failed"
  fi
  if diff -q $filename $mfile &>/dev/null; then
  >&2 echo "Testcase passed"
  fi
  mv $filename /Users/krupa/Downloads/Algorithms/BSTconstruction/Output_testcases
done

