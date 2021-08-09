NAME = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./sources/Libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

CHECKER_HEADERS_LIST = checker.h
CHECKER_HEADERS_DIRECTORY = ./includes/
CHECKER_HEADERS = $(addprefix $(CHECKER_HEADERS_DIRECTORY), $(CHECKER_HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = push_swap.c init.c parsing.c stack.c get_pivot.c under_five.c a_to_b.c b_to_a.c print_command.c free.c ft_atoi_long.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

CHECKER_DIRECTORY = ./checker_sources/
CHECKER_SOURCES_LIST = main.c parsing.c do_operation.c do_stack.c free.c get_next_line.c init.c ft_atoi_long.c
CHECKER_SOURCES = $(addprefix $(CHECKER_DIRECTORY), $(CHECKER_SOURCES_LIST))

CHECKER_OBJECTS_DIRECTORY = ./checker_objects/
CHECKER_OBJECTS_LIST = $(patsubst %.c, %.o, $(CHECKER_SOURCES_LIST))
CHECKER_OBJECTS = $(addprefix $(CHECKER_OBJECTS_DIRECTORY), $(CHECKER_OBJECTS_LIST))

GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[m

.PHONY: all clean fclean re

all: $(NAME) $(CHECKER)

$(NAME): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files are created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) created$(RESET)"

$(CHECKER): $(CHECKER_OBJECTS_DIRECTORY) $(CHECKER_OBJECTS)
	@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(CHECKER_OBJECTS) -o $(CHECKER)
	@echo "\n$(CHECKER): $(GREEN)$(CHECKER) created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(CHECKER_OBJECTS_DIRECTORY):
	@mkdir -p $(CHECKER_OBJECTS_DIRECTORY)
	@echo "$(CHECKER): $(GREEN)$(CHECKER_OBJECTS_DIRECTORY) created$(RESET)"

$(CHECKER_OBJECTS_DIRECTORY)%.o : $(CHECKER_DIRECTORY)%.c $(CHECKER_HEADERS)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) deleted$(RESET)"
	@echo "$(NAME): $(RED)object files are deleted$(RESET)"
	@rm -rf $(CHECKER_OBJECTS_DIRECTORY)
	@echo "$(CHECKER): $(RED)$(CHECKER_OBJECTS_DIRECTORY) deleted$(RESET)"
	@echo "$(CHECKER): $(RED)checker object files are deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) deleted$(RESET)"
	@rm -f $(CHECKER)
	@echo "$(CHECKER): $(RED)$(CHECKER) deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
