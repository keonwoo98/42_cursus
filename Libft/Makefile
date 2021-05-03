# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 15:32:42 by keokim            #+#    #+#              #
#    Updated: 2021/05/03 17:52:29 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
SRCS = ft_atoi.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c main.c
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
