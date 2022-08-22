#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

ARG=$1

if [ $# -eq 1 ]
then
	make fclean
	make && ./ft_containers $ARG > ft_test
	make std && ./ft_containers $ARG > std_test
	result=$(diff ft_test std_test)
	time=$(diff ft_time std_time)
	if [ "$result" != "" ]
	then
		echo -e "${RED}Test Failed${RESET}"
		echo "diff result =>"
		echo "$result"
	else
		echo -e "${GREEN}Test Passed${RESET}"
		echo "$time"
	fi
	rm -rf ft_test std_test ft_time std_time
else
	echo "Usage : ./test.sh [input]"
fi
