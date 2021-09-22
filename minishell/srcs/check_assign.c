/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:17 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:17 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <dirent.h>
#include <stdio.h>

int
	check_redir(t_cmd *cmd)
{
	t_node	*node;
	int		ret;

	node = cmd->first;
	if (node->type == PIPE)
	{
		ft_putstr_fd("Minishell: syntax error near unexpected token `|'\n", 2);
		g_state.exit_status = 258;
		return (258);
	}
	while (node)
	{
		if (check_type(node->type))
		{
			ret = check_syntax(node);
			if (ret > 0)
				return (ret);
		}
		node = node->next;
	}
	return (0);
}

static void
	assign_redir_util(t_node *node)
{
	if (node->type >= REDIROUT && node->type <= APPEND)
	{
		if (node->next)
		{
			if (node->type == REDIRIN && opendir(node->next->contents))
				node->next->type = DIRARG;
			else
				node->next->type = FILEARG;
		}
	}
	if (node->type == HEREDOC)
	{
		if (node->next)
			node->next->type = FILEARG;
	}
}

static void
	assign_redir_arg(t_node *node)
{
	while (node)
	{
		assign_redir_util(node);
		if (node->type == PIPE)
		{
			if (node->next && node->next->type == ARG)
			{
				if (is_builtin(node->next->contents))
					node->next->type = BUILTIN;
				else
					node->next->type = CMD;
			}
		}
		node = node->next;
	}
}

static void
	assign_command(t_node *node, int flag)
{
	while (node)
	{
		if (node->type <= PIPE || node->type > ARG)
		{
			if (node->type == PIPE)
				flag = 1;
			node = node->next;
			continue ;
		}
		if (node->type == CMD || node->type == BUILTIN)
			flag = 0;
		if (node->type != CMD && node->type != BUILTIN && flag == 1)
		{
			if (is_builtin(node->contents))
				node->type = BUILTIN;
			else
				node->type = CMD;
			flag = 0;
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
}

void
	assign_arg(t_cmd *cmd)
{
	t_node	*node;
	int		flag;

	flag = 1;
	node = cmd->first;
	if (!check_type(node->type))
	{
		if (is_builtin(node->contents))
			node->type = BUILTIN;
		else
			node->type = CMD;
	}
	assign_redir_arg(node);
	node = cmd->first;
	assign_command(node, flag);
}
