# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 12:37:54 by keokim            #+#    #+#              #
#    Updated: 2021/12/04 12:38:02 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = philo.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST =	main.c\
				init.c\
				utils.c\
				dining.c\
				routine.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(BLUE)$(NAME) : object files created$(RESET)"
	@echo "$(BLUE)$(NAME) : $(NAME) created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(OBJECTS_DIRECTORY) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(BLUE).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)$(NAME) : $(OBJECTS_DIRECTORY) deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) : $(NAME) deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
