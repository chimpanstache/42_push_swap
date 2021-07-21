#!/bin/bash

i=0
TAB=()
max=$1
while ((i<$max))
do
	tester=1
	RAND=$((1 + RANDOM % 150000))
	for j in "${TAB[@]}"; do
		if [[ $j == $RAND ]]
		then
			tester=0
		fi
	done
	if [[ $tester == 1 ]]
	then
		TAB[i]=$RAND
		((i+=1))
	fi
done
echo ${TAB[*]} > values
ARG=$(cat values);
./push_swap $ARG | ./checker_Mac $ARG