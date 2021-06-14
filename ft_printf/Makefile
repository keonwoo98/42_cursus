# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 20:42:26 by keokim            #+#    #+#              #
#    Updated: 2021/06/14 16:53:21 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_type.c ft_type2.c ft_utils.c ft_utils2.c ft_utils3.c ft_utils4.c ft_check_flag.c ft_check_flag2.c
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

bonus : all

clean :
		rm -f $(OBJS) $(B_OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
