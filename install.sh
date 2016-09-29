#!/bin/bash
echo '\v'
echo '---rmmod----------------------------------------------'
sudo rmmod mblock
sudo dmesg -C
echo '---clean----------------------------------------------'
make clean
echo '---make-----------------------------------------------'
make
echo '---insmod---------------------------------------------'
sudo insmod mblock.ko
echo '---dmseg----------------------------------------------\n'
dmesg
echo '\n---modinfo--------------------------------------------'
modinfo mblock.ko

