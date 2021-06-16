NAME = libftprintf.a
SRCS = ft_printf.c ft_type.c ft_utils.c ft_check_flag.c
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