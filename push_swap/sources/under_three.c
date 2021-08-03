#include "push_swap.h"

void
	two_elements_a(t_stack *a)
{
	if (a->top->num > a->top->next->num)
		swap(a, 1);
}

void
	two_elements_b(t_stack *a, t_stack *b)
{
	if (b->top->num < b->top->next->num)
		swap(b, 2);
	push_pop(b, a, 4);
	push_pop(b, a, 4);
}

void
	three_elements(t_stack *a)
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
		three_elements(a);
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
	while (ra--)
		reverse_rotate(a, 9);
	three_elements_a(a);
	while (pb--)
		push_pop(b, a, 4);
	two_elements_a(a);
}

// void
// 	three_elements_bb(t_stack *a)
// {
// 	if (a->top->num > a->top->next->num)
// 	{
// 		if (a->top->next->num > a->top->next->next->num)
// 			return ;
// 		rotate(a, 7);
// 		swap(a, 2);
// 		reverse_rotate(a, 10);
// 	}
// 	else if (a->top->num < a->top->next->next->num)
// 	{
// 		swap(a, 2);
// 		rotate(a, 7);
// 		swap(a, 2);
// 		reverse_rotate(a, 10);
// 	}
// 	if (a->top->num < a->top->next->num)
// 		swap(a, 2);
// }

// void
// 	three_elements_b(t_stack *a, t_stack *b)
// {
// 	if (b->size == 3)
// 	{
// 		if (b->top->num > b->top->next->num)
// 		{
// 			if (b->top->next->num > b->top->next->next->num)
// 				return ;
// 			reverse_rotate(b, 10);
// 		}
// 		else if (b->top->num < b->top->next->next->num)
// 			rotate(b, 7);
// 		if (b->top->num < b->top->next->num)
// 			swap(b, 2);
// 	}
// 	else
// 		three_elements_bb(b);
// 	// push_pop(b, a, 4);
// 	// push_pop(b, a, 4);
// 	// push_pop(b, a, 4);
// }
