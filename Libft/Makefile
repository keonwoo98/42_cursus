# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:32:42 by keokim            #+#    #+#              #
#    Updated: 2021/05/05 11:28:05 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
SRCS = ft_atoi.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c main.c
OBJS = $(SRCS:.c=.o)
INCS = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(TARGET)

re : fclean all
