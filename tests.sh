#!/usr/bin/env bash

echo "Test suite for nasteroids"
echo "#############################"
echo "Starting sequential version performance test"

################### SEQUENTIAL VERSION ##################
var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-seq 250 50 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-seq 250 50 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-seq 250 50 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-seq 500 50 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-seq 500 50 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-seq 500 50 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-seq 1000 50 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-seq 1000 50 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-seq 1000 50 1000 50.5 2000))

  ((counter++))
done
counter=1

echo "50 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))

var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-seq 250 100 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-seq 250 100 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-seq 250 100 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-seq 500 100 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-seq 500 100 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-seq 500 100 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-seq 1000 100 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-seq 1000 100 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-seq 1000 100 1000 50.5 2000))
  ((counter++))
done
counter=1

echo "100 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))

var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-seq 250 200 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-seq 250 200 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-seq 250 200 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-seq 500 200 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-seq 500 200 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-seq 500 200 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-seq 1000 200 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-seq 1000 200 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-seq 1000 200 1000 50.5 2000))
  ((counter++))
done
counter=1

echo "200 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))

var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0



################### PARALLEL VERSION ##################
echo "#############################"
echo "Starting parallel version performance test"
var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-par 250 50 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-par 250 50 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-par 250 50 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-par 500 50 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-par 500 50 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-par 500 50 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-par 1000 50 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-par 1000 50 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-par 1000 50 1000 50.5 2000))

  ((counter++))
done
counter=1

echo "50 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))

var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-par 250 100 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-par 250 100 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-par 250 100 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-par 500 100 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-par 500 100 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-par 500 100 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-par 1000 100 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-par 1000 100 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-par 1000 100 1000 50.5 2000))
  ((counter++))
done
counter=1

echo "100 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))

var1=0
var2=0
var3=0
var4=0
var5=0
var6=0
var7=0
var8=0
var9=0

counter=1
while [ $counter -le 10 ]
do
  var1=$(var1 + $(./nasteroids-par 250 200 250 50.5 2000))
  var2=$(var2 + $(./nasteroids-par 250 200 500 50.5 2000))
  var3=$(var3 + $(./nasteroids-par 250 200 1000 50.5 2000))

  var4=$(var4 + $(./nasteroids-par 500 200 250 50.5 2000))
  var5=$(var5 + $(./nasteroids-par 500 200 500 50.5 2000))
  var6=$(var6 + $(./nasteroids-par 500 200 1000 50.5 2000))

  var7=$(var7 + $(./nasteroids-par 1000 200 250 50.5 2000))
  var8=$(var8 + $(./nasteroids-par 1000 200 500 50.5 2000))
  var9=$(var9 + $(./nasteroids-par 1000 200 1000 50.5 2000))
  ((counter++))
done
counter=1

echo "200 iterations"
echo $((var1 / 10))
echo $((var2 / 10))
echo $((var3 / 10))
echo $((var4 / 10))
echo $((var5 / 10))
echo $((var6 / 10))
echo $((var7 / 10))
echo $((var8 / 10))
echo $((var9 / 10))
