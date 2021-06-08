# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 20:42:26 by keokim            #+#    #+#              #
#    Updated: 2021/06/07 20:42:31 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_format.c ft_type.c ft_utils.c
INCS = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME) : $(OBJS)
		$(AR) $@ $^

clean :
		rm -f $(OBJS) $(B_OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
