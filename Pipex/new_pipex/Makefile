# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 10:04:23 by keokim            #+#    #+#              #
#    Updated: 2021/07/01 10:04:25 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = pipex.c ft_split.c ft_path.c str_utils.c str_utils2.c
SRCS_B = ./bonus/pipex_bonus.c ./bonus/ft_split_bonus.c ./bonus/ft_path_bonus.c ./bonus/str_utils_bonus.c ./bonus/str_utils2_bonus.c ./bonus/heredoc_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c
OBJS_M = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
INCS = ./includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
		OBJS = $(OBJS_B)
else
		OBJS = $(OBJS_M)
endif

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

bonus :
		make WITH_BONUS=1 all

clean :
		rm -f $(OBJS_M) $(OBJS_B)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
