#include "minishell.h"
#include "libft.h"

void
	print_errmsg(char *str, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void
	print_errmsg2(char *str, char *contents, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(contents, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void
	print_error_util(char *str, char *contents, char *msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(contents, 2);
	ft_putstr_fd("': ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
