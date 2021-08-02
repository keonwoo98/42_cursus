#include "push_swap.h"

void
	two_elements_a(t_stack *a)
{
	if (a->top->num > a->top->next->num)
		swap(a, 1);
}

void
	two_elements_b(t_stack *b)
{
	if (b->top->num > b->top->next->num)
		swap(b, 2);
}

void
	three_elements_a(t_stack *a)
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

void
	three_elements_b(t_stack *b)
{
	if (b->top->num < b->top->next->num)
	{
		if (b->top->next->num < b->top->next->next->num)
			return ;
		reverse_rotate(b, 10);
	}
	else if (b->top->num > b->top->next->next->num)
		rotate(b, 7);
	if (b->top->num > b->top->next->num)
		swap(b, 1);
}
