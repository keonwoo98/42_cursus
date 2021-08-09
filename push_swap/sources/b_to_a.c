/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:48:41 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:48:44 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	is_b_sorted(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	int			i;
	int			sort;

	i = cnt;
	sort = 0;
	while (--cnt)
	{
		if (b->top->num > b->top->next->num)
			b->top = b->top->next;
		else
			break ;
	}
	while (b->top->prev)
		b->top = b->top->prev;
	if (cnt == 0)
	{
		sort = 1;
		while (i--)
			push_pop(b, a, command, 4);
	}
	return (sort);
}

int
	under_five_b(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	if (cnt == 0)
		return (1);
	else if (cnt == 1)
	{
		push_pop(b, a, command, 4);
		return (1);
	}
	else if (cnt == 2)
	{
		two_elements_b(a, b, command);
		return (1);
	}
	if (is_b_sorted(a, b, command, cnt))
		return (1);
	return (0);
}

t_cmd
	*sort_b(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	t_cmd		*cmd;

	cmd = init_cmd(cnt);
	cmd->b_pivot = ((get_min_num(b->top, cnt) + get_max_num(b->top, cnt)) / 2);
	cmd->s_pivot = ((get_min_num(b->top, cnt) + cmd->b_pivot) / 2);
	while (cnt--)
	{
		if (b->top->num <= cmd->s_pivot)
		{
			rotate(b, command, 7);
			cmd->rb++;
		}
		else
		{
			push_pop(b, a, command, 4);
			cmd->pa++;
			if (a->top->num <= cmd->b_pivot)
			{
				rotate(a, command, 6);
				cmd->ra++;
			}
		}
	}
	return (cmd);
}

void
	b_to_a(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	t_cmd		*cmd;
	int			first_cnt;

	first_cnt = cnt;
	if (under_five_b(a, b, command, cnt))
		return ;
	cmd = sort_b(a, b, command, cnt);
	a_to_b(a, b, command, cmd->pa - cmd->ra);
	rrr(a, b, command, cmd);
	a_to_b(a, b, command, cmd->ra);
	b_to_a(a, b, command, cmd->rb);
	free(cmd);
}
