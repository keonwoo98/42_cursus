/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:38 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:39 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

static int
	ft_echo_no_newline(t_node *node)
{
	if (!node->next || node->next->type <= PIPE)
		return (EXIT_SUCCESS);
	else
	{
		node = node->next;
		while (node && node->type > PIPE)
		{
			ft_putstr_fd(node->contents, 1);
			if (node->next)
				ft_putstr_fd(" ", 1);
			node = node->next;
		}
	}
	return (EXIT_SUCCESS);
}

static int
	ft_echo_arg(t_node *node)
{
	while (node && node->type > PIPE)
	{
		printf("%s", node->contents);
		if (node->next)
			printf(" ");
		node = node->next;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}

int
	ft_echo(t_node *node)
{
	if (!node->next || node->next->type <= PIPE)
		write(1, "\n", 1);
	else if (!ft_strcmp("-n", node->next->contents))
	{
		node = node->next;
		ft_echo_no_newline(node);
	}
	else
	{
		node = node->next;
		ft_echo_arg(node);
	}
	return (EXIT_SUCCESS);
}
