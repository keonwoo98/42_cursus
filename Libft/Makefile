# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:32:42 by keokim            #+#    #+#              #
#    Updated: 2021/05/07 17:31:09 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c main.c
OBJS = $(SRCS:.c=.o)
INCS = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all : $(NAME)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME) : $(OBJS)
		$(AR) $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
