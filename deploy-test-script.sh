#!/bin/bash
echo "Starting script..."
./nasteroid-base $1 $2 $3 $4 $5
./build/nasteroids $1 $2 $3 $4 $5
cat out.txt
cat build/out.txt
cat init_file.txt
cat build/init_file.txt
diff -q init_conf.txt build/init_conf.txt && diff -q out.txt build/out.txt
echo "Script ended"