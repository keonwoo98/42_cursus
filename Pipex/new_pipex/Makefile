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
SRCS = pipex.c ft_split.c ft_path.c str_utils.c str_utils2.c ft_redirect.c
OBJS = $(SRCS:.c=.o)
INCS = pipex.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
