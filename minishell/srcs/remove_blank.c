/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_blank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:45 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:46 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static void
	free_node(t_node *node)
{
	free(node->contents);
	free(node);
}

static void
	delete_node(t_cmd **cmd, t_node *node)
{
	t_node	*temp;

	if ((*cmd)->size == 1)
		return ;
	if (node->prev == NULL)
	{
		(*cmd)->first = node->next;
		(*cmd)->first->prev = NULL;
		if ((*cmd)->size == 2)
			(*cmd)->last = node->next;
		free_node(node);
	}
	else if (node->next == NULL)
	{
		(*cmd)->last = node->prev;
		(*cmd)->last->next = NULL;
		free_node(node);
	}
	else
	{
		temp = node->prev;
		temp->next = node->next;
		node->next->prev = temp;
		free_node(node);
	}
}

void
	remove_blank(t_cmd **cmd)
{
	t_node	*temp;

	temp = (*cmd)->first;
	while (temp)
	{
		if (!*temp->contents)
		{
			delete_node(cmd, temp);
			(*cmd)->size--;
		}
		temp = temp->next;
	}
}
