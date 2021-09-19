# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjune <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/20 15:22:50 by minjune           #+#    #+#              #
#    Updated: 2021/09/20 00:33:12 by minjkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY) -lreadline -L$(READLINE_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(READLINE_HEADERS)

READLINE_DIRECTORY = /Users/keokim/.brew/opt/readline/lib/
READLINE_HEADERS = /Users/keokim/.brew/opt/readline/include/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = minishell.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = minishell.c\
				list_func.c\
				parsing.c\
				exec_cmd.c\
				exec_cmd_utils.c\
				expansion.c\
				execute.c\
				execute_utils.c\
				redirect.c\
				get_next_line.c\
				error.c\
				built_in.c\
				signal.c\
				check_assign.c\
				ft_cd.c\
				ft_export.c\
				print_export.c\
				env.c\
				ft_cd_utils.c\
				ft_unset.c\
				ft_exit.c\
				ft_echo.c\
				remove_blank.c\
				get_env.c\
				ft_export_util.c\
				assign_util.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(BLUE)$(NAME) : object files created$(RESET)"
	@echo "$(BLUE)$(NAME) : $(NAME) created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(OBJECTS_DIRECTORY) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(BLUE).$(RESET)\c"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(BLUE)$(NAME) : $(LIBFT) created$(RESET)"

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@echo "$(RED)$(NAME) : libft object files deleted$(RESET)"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED)$(NAME) : $(OBJECTS_DIRECTORY) deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)$(NAME) : $(LIBFT) deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) : $(NAME) deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
