/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:16 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:16 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_cmd
	*init_cmd_list(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->size = 0;
	cmd->first = NULL;
	cmd->last = NULL;
	return (cmd);
}

t_node
	*new_list(char *contents, int type)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->contents = contents;
	node->type = type;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void
	add_list(t_cmd *cmd, char *contents, int type)
{
	t_node	*new;
	t_node	*temp;

	new = new_list(contents, type);
	if (cmd->first == NULL)
	{
		cmd->first = new;
		cmd->last = new;
	}
	else
	{
		temp = cmd->last;
		temp->next = new;
		new->prev = temp;
		cmd->last = new;
	}
	cmd->size++;
}

void
	free_list(t_cmd *cmd)
{
	t_node	*temp;

	while (cmd->first)
	{
		temp = cmd->first->next;
		free(cmd->first->contents);
		free(cmd->first);
		cmd->first = temp;
	}
	free(cmd);
}
