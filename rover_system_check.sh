#!/bin/bash
battery=$((RANDOM%100))

check1=0
check2=0

if [[ $battery -le 20 ]];
then
       echo "Battery low. Return to base"
       check1=0
       	exit

else
	echo "battery charged"
	check1=1
fi

ping -c 1 &> /dev/null google.com 
if [[ $? -eq 0 ]];
then 
	echo "NETWORK CONNECTION SUCCESSFUL"
	check2=1
else
	echo "communication failure"
	check2=0
	exit
fi

if [[(($check1==1)) && (($check2==1))]];
then 
	echo "All systems operational"
fi





