# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 20:34:37 by keokim            #+#    #+#              #
#    Updated: 2022/04/08 17:20:50 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS =	main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m
RED = \033[1;31m
GREY = \033[2;37m
MAGENTA = \033[0;35m
RESET = \033[m

all: $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(NAME): $(GREEN)object files created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) compiled$(RESET)"

clean:
		@rm -rf $(OBJS)
		@echo "$(NAME): $(RED)$(OBJS) deleted$(RESET)"
		@echo "$(NAME): $(RED)object files deleted$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME): $(RED)$(NAME) deleted$(RESET)"

re:
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: all clean fclean re

.SILENT: $(OBJS)
