#include "push_swap.h"

int
	is_b_sorted(t_stack *a, t_stack *b, int cnt)
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
			break;
	}
	while (b->top->prev)
		b->top = b->top->prev;
	if (cnt == 0)
	{
		sort = 1;
		while (i--)
			push_pop(b, a, 4);
	}
	return (sort);
}

int
	under_five_b(t_stack *a, t_stack *b, int cnt)
{
	if (cnt == 0)
		return (1);
	else if (cnt == 1)
	{
		push_pop(b, a, 4);
		return (1);
	}
	else if (cnt == 2)
	{
		two_elements_b(a, b);
		return (1);
	}
	if (is_b_sorted(a, b, cnt))
		return (1);
	return (0);
}

void
	sort_b(t_stack *a, t_stack *b, t_cmd *cmd, int cnt)
{
	int			i;
	int			s_pivot;
	int			b_pivot;

	i = -1;
	b_pivot = ((get_min_num(b->top, cnt) + get_max_num(b->top, cnt)) / 2);
	s_pivot = ((get_min_num(b->top, cnt) + b_pivot) / 2);
	while (++i < cnt)
	{
		if (b->top->num <= s_pivot)
		{
			rotate(b, 7);
			cmd->rb++;
		}
		else
		{
			push_pop(b, a, 4);
			cmd->pa++;
			if (a->top->num <= b_pivot)
			{
				rotate(a, 6);
				cmd->ra++;
			}
		}
	}
}

void
	b_to_a(t_stack *a, t_stack *b, int cnt)
{
	t_cmd		*cmd;

	cmd = init_cmd();
	if (under_five_b(a, b, cnt))
		return ;
	sort_b(a, b, cmd, cnt);
	a_to_b(a, b, cmd->pa - cmd->ra);
	rrr(a, b, cmd);
	a_to_b(a, b, cmd->ra);
	b_to_a(a, b, cmd->rb);
}
