#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

ARG=$1

if [ $# -eq 1 ]
then
	c++ -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address sources/tests.cpp && ./a.out $ARG > ft_test
	c++ -Wall -Werror -Wextra -std=c++98 -pedantic -fsanitize=address -D STD_MODE=1 sources/tests.cpp && ./a.out $ARG > std_test
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
	rm -rf ft_test std_test ft_time std_time a.out
else
	echo "Usage : ./simple_test.sh [input]"
fi
