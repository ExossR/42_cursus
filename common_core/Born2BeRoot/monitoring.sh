#!/bin/bash
arc=$(uname -a)
cpu=$(lscpu | grep 'par socket' | awk '{ print $4 }')
vcpu=$(lscpu | grep 'Thread' | awk '{ print $4 }')
memu1=$(sed -zE 's_.*MemTotal: *([0-9]*).*\nMemFree: *([0-9]*).*_echo "\2/\1"kB_e' /proc/meminfo)
memu2=$(sed -zE 's_.*MemTotal: *([0-9]*).*\nMemFree: *([0-9]*).*_echo $((100*\2/\1))%_e' /proc/meminfo)
diu1=$(df -h / | grep "/dev/mapper" | awk '{print$3}' | sed 's/G//g')
diu2=$(df -h / | grep "/dev/mapper" | awk '{print$2}' | sed 's/G//g')
diu3=$(df -h / | grep "/dev/mapper" | awk '{print$5}')
loadcpu=$(top -bn1 | grep 'load average' | awk '{ print $11 }' | sed 's/0,//' | sed 's/,/%/g')
lboot=$(who -b | grep -o "[0-9]*\-[0-9]*\-[0-9]* [0-9]*\:[0-9]*")
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
tcp=$(ss -t state established | wc -l)
user=$(who | wc -l)
ip4=$(hostname -I)
mac=$(ip link | grep 'ether' | awk '{ print $2 }')
sud=$(sudo cat /var/log/auth.log | grep -a 'sudo' | grep 'COMMAND' | wc -l)

wall "	#Architecture:	$arc
		#CPU physical:	$cpu
		#vCPU:	$vcpu
		#Memory Usage:	$memu1 ($memu2)
		#Disk Usage:	$diu1/${diu2}Gb ($diu3)
		#CPU load:	$loadcpu
		#Last boot:	$lboot
		#LVM use:	$lvmu
		#Connexions TCP:	$tcp ESTABLISHED
		#User log:	$user
		#Network:	IP $ip4 ($mac)
		#Sudo:	$sud cmd"