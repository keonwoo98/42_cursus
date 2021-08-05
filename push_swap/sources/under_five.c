#include "push_swap.h"

void
	two_elements_a(t_stack *a)
{
	if (a->top->num > a->top->next->num)
		swap(a, 1);
}

void
	three_elements_a_else(t_stack *a)
{
	if (a->top->num < a->top->next->num)
	{
		if (a->top->next->num < a->top->next->next->num)
			return ;
		rotate(a, 6);
		swap(a, 1);
		reverse_rotate(a, 9);
	}
	else if (a->top->num > a->top->next->next->num)
	{
		swap(a, 1);
		rotate(a, 6);
		swap(a, 1);
		reverse_rotate(a, 9);
	}
	if (a->top->num > a->top->next->num)
		swap(a, 1);
}

void
	three_elements_a(t_stack *a)
{
	if (a->size == 3)
	{
		if (a->top->num < a->top->next->num)
		{
			if (a->top->next->num < a->top->next->next->num)
				return ;
			reverse_rotate(a, 9);
		}
		else if (a->top->num > a->top->next->next->num)
			rotate(a, 6);
		if (a->top->num > a->top->next->num)
			swap(a, 1);
	}
	else
		three_elements_a_else(a);
}

void
	four_elements_a(t_stack *a, t_stack *b)
{
	int			pivot;
	int			ra;

	ra = 0;
	pivot = get_min_num(a->top, 4);
	while (1)
	{
		if (a->top->num == pivot)
		{
			push_pop(a, b, 5);
			break;
		}
		else
		{
			rotate(a, 6);
			ra++;
		}
	}
	while (ra-- && a->size != 4)
		reverse_rotate(a, 9);
	three_elements_a(a);
	push_pop(b, a, 4);
}

void
	five_elements_a(t_stack *a, t_stack *b)
{
	int			pivot;
	int			pb;
	int			ra;

	pivot = get_mid_num(a->top, 5);
	pb = 0;
	ra = 0;
	while (1)
	{
		if (a->top->num < pivot)
		{
			push_pop(a, b, 5);
			pb++;
		}
		else
		{
			rotate(a, 6);
			ra++;
		}
		if (pb == 2)
			break;
	}
	while (ra-- && a->size != 3)
		reverse_rotate(a, 9);
	three_elements_a(a);
	two_elements_b(a, b);
}

void
	two_elements_b(t_stack *a, t_stack *b)
{
	if (b->top->num < b->top->next->num)
		swap(b, 2);
	push_pop(b, a, 4);
	push_pop(b, a, 4);
}
