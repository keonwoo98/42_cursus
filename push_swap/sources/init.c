/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:49:30 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:49:34 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack
	*init_stack(void)
{
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error();
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node
	*init_node(int num)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error();
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_cmd
	*init_cmd(int cnt)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		print_error();
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->pa = 0;
	cmd->pb = 0;
	cmd->s_pivot = 0;
	cmd->b_pivot = 0;
	cmd->cnt = cnt;
	return (cmd);
}
