#!/bin/sh

echo -n "#Architecture : " && uname -a
echo -n "#CPU physical : " && nproc
#echo -n "#CPU physical : " && cat/proc/cpuinfo | grep "cpu cores" | sed 's/cpu cores : //'
echo -n "#vCPU : " && cat /proc/cpuinfo | grep processor | wc -l
#echo -n "vCPU: " && cat /proc/cpuinfo | grep siblings | sed 's/siblings : //'

MEMORY_TOTAL=`free | grep Mem | awk '{print $2}'`
MEMORY_USED=`free | grep -/+ | awk '{print $3}'`
MEMORY_PERCENT=$((100*MEMORY_USED/MEMORY_TOTAL))

free -h | grep Mem | awk '{printf("#Memory Usage: %d"), $3}'
free -h | grep Mem | awk '{printf("/%dMB "), $2}'
free -t | grep Mem | awk '{printf("(%.2f%%)\n"), $3/$2*100}'