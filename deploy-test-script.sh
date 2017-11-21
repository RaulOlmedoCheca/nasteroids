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
./build/nasteroids $1 $2 $3 $4 $5
echo -e "\n\n"
echo -e "***************** Correct output file *****************"
cat out.txt
echo -e "***************** Tested output file ******************"
cat build/out.txt
echo -e "\n***************** Correct init file *******************"
cat init_conf.txt
echo -e "***************** Tested init file ********************"
cat build/init_conf.txt
echo -e "\n***************** Diff between all files **************"
diff -q init_conf.txt build/init_conf.txt && diff -q out.txt build/out.txt
echo "Script ended"