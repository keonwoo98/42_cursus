/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:50:24 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:50:28 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	two_elements_a(t_stack *a, t_stack *command)
{
	if (a->top->num > a->top->next->num)
		swap(a, command, 1);
}

void
	three_elements_a_else(t_stack *a, t_stack *command)
{
	if (a->top->num < a->top->next->num)
	{
		if (a->top->next->num < a->top->next->next->num)
			return ;
		rotate(a, command, 6);
		swap(a, command, 1);
		reverse_rotate(a, command, 9);
	}
	else if (a->top->num > a->top->next->next->num)
	{
		swap(a, command, 1);
		rotate(a, command, 6);
		swap(a, command, 1);
		reverse_rotate(a, command, 9);
	}
	if (a->top->num > a->top->next->num)
		swap(a, command, 1);
}

void
	three_elements_a(t_stack *a, t_stack *command)
{
	if (a->size == 3)
	{
		if (a->top->num < a->top->next->num)
		{
			if (a->top->next->num < a->top->next->next->num)
				return ;
			reverse_rotate(a, command, 9);
		}
		else if (a->top->num > a->top->next->next->num)
			rotate(a, command, 6);
		if (a->top->num > a->top->next->num)
			swap(a, command, 1);
	}
	else
		three_elements_a_else(a, command);
}

void
	five_elements_a(t_stack *a, t_stack *b, t_stack *command)
{
	int			pivot;
	t_cmd		*cmd;

	cmd = init_cmd(0);
	pivot = get_mid_num(a->top, 5);
	while (1)
	{
		if (a->top->num < pivot)
		{
			push_pop(a, b, command, 5);
			cmd->pb++;
		}
		else
		{
			rotate(a, command, 6);
			cmd->ra++;
		}
		if (cmd->pb == 2)
			break ;
	}
	while (cmd->ra-- && a->size != 3)
		reverse_rotate(a, command, 9);
	three_elements_a(a, command);
	two_elements_b(a, b, command);
	free(cmd);
}

void
	two_elements_b(t_stack *a, t_stack *b, t_stack *command)
{
	if (b->top->num < b->top->next->num)
		swap(b, command, 2);
	push_pop(b, a, command, 4);
	push_pop(b, a, command, 4);
}
