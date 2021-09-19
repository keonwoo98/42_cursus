/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:02 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:03 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int
	check_type(int type)
{
	if (type == REDIRIN || type == REDIROUT \
	|| type == APPEND || type == HEREDOC || type == PIPE)
		return (1);
	else
		return (0);
}

int
	check_meta(t_node *node)
{
	if (node->type >= REDIROUT && node->type <= HEREDOC)
	{
		if (node->next->type >= REDIROUT && node->next->type <= HEREDOC)
		{
			printf("Minishell: syntax error near unexpected token ");
			printf("`%s`\n", node->next->contents);
			g_state.exit_status = 258;
			return (258);
		}
	}
	return (0);
}

int
	check_syntax(t_node *node)
{
	if (!node->next)
	{
		printf("Minishell: syntax error near unexpected token `newline'\n");
		g_state.exit_status = 258;
		return (258);
	}
	else if (opendir(node->next->contents) && node->type != REDIRIN)
	{
		printf("Minishell: %s: Is a Directory\n", node->next->contents);
		g_state.exit_status = 1;
		return (1);
	}
	else
	{
		if (check_meta(node) > 0)
			return (258);
	}
	return (EXIT_SUCCESS);
}
