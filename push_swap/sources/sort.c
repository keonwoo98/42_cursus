#include "push_swap.h"

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
	if (cnt == 1)
	{
		push_pop(b, a, 4);
		return ;
	}
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
