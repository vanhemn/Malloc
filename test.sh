#!/bin/bash
make test
export LD_PRELOAD=`pwd`/libmy_malloc.so
./malloc
ls -R ../
unset LD_PRELOAD