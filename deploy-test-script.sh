#!/bin/bash
echo -e "Starting script...\n"
echo -e "
TODO:
"
echo -e "\n***************** Executing nasteroids-base ***********"
./nasteroid-base $1 $2 $3 $4 $5
echo -e "\n***************** Executing nasteroids-seq ************"
cd build
./nasteroids-seq $1 $2 $3 $4 $5
cp init_conf.txt ../init_conf_seq.txt
cp out.txt ../out_seq.txt
./nasteroids-par $1 $2 $3 $4 $5
cp init_conf.txt ../init_conf_par.txt
cp out.txt ../out_par.txt
cd ..
echo -e "\n"
echo -e "***************** Correct init file *******************"
cat init_conf.txt
echo -e "***************** Tested init seq file ********************"
cat init_conf_seq.txt
echo -e "***************** Tested init par file ********************"
cat init_conf_par.txt
echo -e "\n***************** Correct output file *****************"
cat out.txt
echo -e "***************** Tested output seq file ******************"
cat out_seq.txt
echo -e "***************** Tested output par file ******************"
cat out_par.txt
echo -e "\n***************** Diff between correct and seq files **************"
diff -q init_conf.txt init_conf_seq.txt && diff -q out.txt out_seq.txt
e=$?
echo -e "\n***************** Diff between seq and par files **************"
diff -q init_conf_seq.txt init_conf_par.txt && diff -q out_seq.txt out_par.txt
e=$?
echo -e "\nRemoving generated files..."
rm -rf build/
rm -rf out.txt
rm -rf init_conf.txt
echo -e "\nScript ended"
exit ${e}
