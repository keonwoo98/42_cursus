#include "push_swap.h"

int
	is_a_sorted(t_stack *stack, int cnt)
{
	int			sort;

	sort = 0;
	if (cnt == 1)
		return (1);
	while (--cnt)
	{
		if (stack->top->num < stack->top->next->num)
			stack->top = stack->top->next;
		else
			break;
	}
	if (cnt == 0)
		sort = 1;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	return (sort);
}

int
	is_b_sorted(t_stack *a, t_stack *b, int cnt)
{
	int			i;
	int			sort;

	i = cnt;
	sort = 0;
	if (cnt == 1)
	{
		push_pop(b, a, 4);
		return (1);
	}
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

void
	a_to_b(t_stack *a, t_stack *b, int cnt)
{
	int			i;
	int			ra;
	int			pb;
	int			pivot;

	i = -1;
	ra = 0;
	pb = 0;
	if (is_a_sorted(a, cnt))
		return ;
	if (cnt == 1)
		return ;
	else if (cnt == 2)
	{
		two_elements_a(a);
		return ;
	}
	else if (cnt == 3)
	{
		three_elements_a(a);
		return ;
	}
	else if (cnt == 5)
	{
		five_elements_a(a, b);
		return ;
	}
	pivot = get_mid_num(a->top, cnt);
	while (++i < cnt)
	{
		if (a->top->num > pivot)
		{
			rotate(a, 6);
			ra++;
		}
		else
		{
			push_pop(a, b, 5);
			pb++;
		}
	}
	i = -1;
	while (++i < ra)
		reverse_rotate(a, 9);
	a_to_b(a, b, ra);
	b_to_a(a, b, pb);
}

void
	b_to_a(t_stack *a, t_stack *b, int cnt)
{
	int			i;
	int			rb;
	int			pa;
	int			pivot;

	i = -1;
	rb = 0;
	pa = 0;
	if (is_b_sorted(a, b, cnt))
		return ;
	if (cnt == 1)
	{
		push_pop(b, a, 4);
		return ;
	}
	else if (cnt == 2)
	{
		two_elements_b(a, b);
		return ;
	}
	// else if (cnt == 3)
	// {
	// 	three_elements_b(a, b);
	// 	return ;
	// }
	// else if (cnt == 5)
	// {
	// 	five_elements_b(a, b);
	// 	return ;
	// }
	pivot = get_mid_num(b->top, cnt);
	while (++i < cnt)
	{
		if (b->top->num < pivot)
		{
			rotate(b, 7);
			rb++;
		}
		else
		{
			push_pop(b, a, 4);
			pa++;
		}
	}
	i = -1;
	while (++i < rb)
		reverse_rotate(b, 10);
	a_to_b(a, b, pa);
	b_to_a(a, b, rb);
}
