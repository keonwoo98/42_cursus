NAME = intern
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRCS =	main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp inter.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m
RED = \033[1;31m
GREY = \033[2;37m
MAGENTA = \033[0;35m
RESET = \033[m

all: $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(NAME): $(GREEN)object files created$(RESET)"
		@echo "$(NAME): $(GREEN)_shrubbery file created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) compiled$(RESET)"

clean:
		@rm -rf $(OBJS)
		@rm -f *_shrubbery
		@echo "$(NAME): $(RED)$(OBJS) deleted$(RESET)"
		@echo "$(NAME): $(RED)object files deleted$(RESET)"
		@echo "$(NAME): $(RED)_shrubbery file deleted$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME): $(RED)$(NAME) deleted$(RESET)"

re:
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: all clean fclean re

.SILENT: $(OBJS)
