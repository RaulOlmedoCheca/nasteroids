#!/bin/bash
echo -e "Starting script...\n"
echo -e "                  +-----------------------+
                  |          ++           |
                  |                       |
                  |                       |
                  +-----------------------+
                  +-----------------------+
                  |                       |
                  |     Gabo subbnormal   |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
                  |                       |
+-----------------+                       +----------------+
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
|                 |                       |                |
+-----------------+-----------------------+----------------+

"
echo -e "\n***************** Executing nasteroids-base ***********"
./nasteroid-base $1 $2 $3 $4 $5
echo -e "\n***************** Executing nasteroids-seq ************"
cd build
./nasteroids $1 $2 $3 $4 $5
cd ..
echo -e "\n"
echo -e "***************** Correct init file *******************"
cat init_conf.txt
echo -e "***************** Tested init file ********************"
cat build/init_conf.txt
echo -e "\n***************** Correct output file *****************"
cat out.txt
echo -e "***************** Tested output file ******************"
cat build/out.txt
echo -e "\n***************** Diff between all files **************"
diff -q init_conf.txt build/init_conf.txt && diff -q out.txt build/out.txt
echo -e "\n Removing generated files..."
rm -rf build/out.txt
rm -rf out.txt
rm -rf init_conf.txt
rm -rf build/init_conf.txt
echo -e "\nScript ended"