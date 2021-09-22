/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:44 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:44 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

static int
	is_num(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void
	exit_error(char *str)
{
	if (g_state.ac == 1)
		printf("exit\n");
	if (str[0] == '|')
		return ;
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	if (g_state.ac == 1)
		exit(255);
}

static void
	ft_exit_arg(t_node *node)
{
	int	ret;

	if (!is_num(node->next->contents))
		exit_error(node->next->contents);
	else
	{
		if (g_state.ac == 1)
			printf("exit\n");
		if (!node->next->next)
		{
			ret = ft_atoi(node->next->contents);
			g_state.exit_status = (ret & 255);
			exit(ret & 255);
		}
		else if (g_state.ac == 1)
		{
			g_state.exit_status = 1;
			g_state.fork = 0;
			ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		}
	}
}

void
	ft_exit(t_node *node)
{
	if (node->prev)
		return ;
	if (node->next && node->next->contents[0] == 0)
		node = node->next;
	if (!node->next)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	else
		ft_exit_arg(node);
}
