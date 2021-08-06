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
			break ;
	}
	if (i == cnt)
		sort = 1;
	while (--i)
		stack->top = stack->top->prev;
	return (sort);
}

int
	under_five_a(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	if (cnt == 2)
	{
		two_elements_a(a, command);
		return (1);
	}
	else if (cnt == 3)
	{
		three_elements_a(a, command);
		return (1);
	}
	else if (cnt == 5)
	{
		five_elements_a(a, b, command);
		return (1);
	}
	return (0);
}

t_cmd
	*sort_a(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	t_cmd		*cmd;

	cmd = init_cmd(cnt);
	cmd->b_pivot = ((get_min_num(a->top, cnt) + get_max_num(a->top, cnt)) / 2);
	cmd->s_pivot = ((get_min_num(a->top, cnt) + cmd->b_pivot) / 2);
	while (cnt--)
	{
		if (a->top->num > cmd->b_pivot)
		{
			rotate(a, command, 6);
			cmd->ra++;
		}
		else
		{
			push_pop(a, b, command, 5);
			cmd->pb++;
			if (b->top->num > cmd->s_pivot)
			{
				rotate(b, command, 7);
				cmd->rb++;
			}
		}
	}
	return (cmd);
}

void
	rrr(t_stack *a, t_stack *b, t_stack *command, t_cmd *cmd)
{
	int				i;

	i = -1;
	if (cmd->ra > cmd->rb)
	{
		while (++i < cmd->rb)
		{
			reverse_rotate(a, command, 11);
			reverse_rotate(b, command, 0);
		}
		while (i++ < cmd->ra && cmd->cnt < a->size)
			reverse_rotate(a, command, 9);
	}
	else
	{
		while (++i < cmd->ra)
		{
			reverse_rotate(a, command, 11);
			reverse_rotate(b, command, 0);
		}
		while (i++ < cmd->rb && cmd->cnt < b->size)
			reverse_rotate(b, command, 10);
	}
}

void
	a_to_b(t_stack *a, t_stack *b, t_stack *command, int cnt)
{
	t_cmd		*cmd;

	if (is_a_sorted(a, cnt))
		return ;
	if (under_five_a(a, b, command, cnt))
		return ;
	cmd = sort_a(a, b, command, cnt);
	rrr(a, b, command, cmd);
	a_to_b(a, b, command, cmd->ra);
	b_to_a(a, b, command, cmd->rb);
	b_to_a(a, b, command, cmd->pb - cmd->rb);
	free(cmd);
}
