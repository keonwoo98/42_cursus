#include "push_swap.h"

int
	is_a_sorted(t_stack *stack, int cnt)
{
	int			i;
	int			sort;

	sort = 0;
	i = 0;
	if (cnt == 0 || cnt == 1)
		return (1);
	while (++i < cnt)
	{
		if (stack->top->num < stack->top->next->num)
			stack->top = stack->top->next;
		else
			break;
	}
	if (i == cnt)
		sort = 1;
	while (--i)
		stack->top = stack->top->prev;
	return (sort);
}

int
	under_five_a(t_stack *a, t_stack *b, int cnt)
{
	if (cnt == 2)
	{
		two_elements_a(a);
		return (1);
	}
	else if (cnt == 3)
	{
		three_elements_a(a);
		return (1);
	}
	else if (cnt == 4)
	{
		four_elements_a(a, b);
		return (1);
	}
	else if (cnt == 5)
	{
		five_elements_a(a, b);
		return (1);
	}
	return (0);
}

void
	sort_a(t_stack *a, t_stack *b, t_cmd *cmd, int cnt)
{
	int			i;
	int			s_pivot;
	int			b_pivot;

	i = -1;
	b_pivot = ((get_min_num(a->top, cnt) + get_max_num(a->top, cnt)) / 2);
	s_pivot = ((get_min_num(a->top, cnt) + b_pivot) / 2);
	while (++i < cnt)
	{
		if (a->top->num > b_pivot)
		{
			rotate(a, 6);
			cmd->ra++;
		}
		else
		{
			push_pop(a, b, 5);
			cmd->pb++;
			if (b->top->num > s_pivot)
			{
				rotate(b, 7);
				cmd->rb++;
			}
		}
	}
}

void
	rrr(t_stack *a, t_stack *b, t_cmd *cmd)
{
	int				i;

	i = -1;
	if (cmd->ra > cmd->rb)
	{
		while (++i < cmd->rb)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < cmd->ra)
			reverse_rotate(a, 9);
	}
	else
	{
		while (++i < cmd->ra)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < cmd->rb)
			reverse_rotate(b, 10);
	}
}

void
	a_to_b(t_stack *a, t_stack *b, int cnt)
{
	t_cmd		*cmd;

	cmd = init_cmd();
	if (is_a_sorted(a, cnt))
		return ;
	if (under_five_a(a, b, cnt))
		return ;
	sort_a(a, b, cmd, cnt);
	rrr(a, b, cmd);
	a_to_b(a, b, cmd->ra);
	b_to_a(a, b, cmd->rb);
	b_to_a(a, b, cmd->pb - cmd->rb);
	free(cmd);
}
