#!/bin/bash
if ! diff -q init_conf.txt build/init_conf.txt || ! diff out.txt build/out.txt
then
	>&2 echo "different"
fi
