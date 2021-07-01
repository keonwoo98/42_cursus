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
SRCS = pipex.c ft_split.c str_utils.c str_utils2.c
OBJS = $(SRCS:.c=.o)
INCS = pipex.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
