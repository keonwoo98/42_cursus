#!/bin/sh

echo -n "#Architecture : " && uname -a
echo -n "#CPU physical : " && nproc
echo -n "#vCPU : " && cat /proc/cpuinfo | grep processor | wc -l

free -h | grep Mem | awk '{printf("#Memory Usage : %d"), $3}'
free -h | grep Mem | awk '{printf("/%dMB "), $2}'
free -t | grep Mem | awk '{printf("(%.2f%%)\n"), $3/$2*100}'

df --total | tail -n 1 | awk '{printf "#Disk Usage: %d/%dGb (%d%%)\n", ($3/1024), ($2/1048576), $5}'

top -b -n1 | grep "%Cpu(s)" | awk '{printf("#CPU load : %.1f%%\n"), $2 + $4}'

echo -n "#Last boot: " && who -b | awk '{print $3" "$4}'

echo -n "#LVM use : "
LV_DATA=`lsblk | grep "lvm" | wc -l`
if [ $LV_DATA = 0];
then
    echo "no"
else
    echo "yes"
fi

echo -n "#Connections TCP : "$(ss -t | grep -v "State" | wc -l) && echo " ESTABLISHED"

echo -n "#User log : " && who | wc -l

echo -n "#Network : IP "$(hostname -I) && ip a | grep link/ether | awk '{printf(" (%s)\n"), $2}'

echo -n "#Sudo : "$(ls -l /var/log/sudo/00/00 | grep -v "total" | wc -l) && echo " cmd"