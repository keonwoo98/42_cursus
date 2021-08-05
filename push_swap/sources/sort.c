#include "push_swap.h"

int
	is_a_sorted(t_stack *stack, int cnt)
{
	int			sort;
	int			i;

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
	// while (stack->top->prev)
	// 	stack->top = stack->top->prev;
	while (--i)
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
	if (cnt == 0)
		return (1);
	else if (cnt == 1)
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

// void
// 	a_to_b(t_stack *a, t_stack *b, int cnt)
// {
// 	int			i;
// 	int			ra;
// 	int			pb;
// 	int			pivot;

// 	i = -1;
// 	ra = 0;
// 	pb = 0;
// 	if (is_a_sorted(a, cnt))
// 		return ;
// 	if (cnt == 1)
// 		return ;
// 	else if (cnt == 2)
// 	{
// 		two_elements_a(a);
// 		return ;
// 	}
// 	else if (cnt == 3)
// 	{
// 		three_elements_a(a);
// 		return ;
// 	}
// 	else if (cnt == 4)
// 	{
// 		four_elements_a(a, b);
// 		return ;
// 	}
// 	else if (cnt == 5)
// 	{
// 		five_elements_a(a, b);
// 		return ;
// 	}
// 	pivot = get_mid_num(a->top, cnt);
// 	while (++i < cnt)
// 	{
// 		if (a->top->num > pivot)
// 		{
// 			rotate(a, 6);
// 			ra++;
// 		}
// 		else
// 		{
// 			push_pop(a, b, 5);
// 			pb++;
// 		}
// 		if (pb > (cnt / 2))
// 			break ;
// 	}
// 	i = -1;
// 	while (++i < ra && cnt < a->size)
// 		reverse_rotate(a, 9);
// 	a_to_b(a, b, (cnt - pb));
// 	b_to_a(a, b, pb);
// }

// void
// 	b_to_a(t_stack *a, t_stack *b, int cnt)
// {
// 	int			i;
// 	int			rb;
// 	int			pa;
// 	int			pivot;

// 	i = -1;
// 	rb = 0;
// 	pa = 0;
// 	if (is_b_sorted(a, b, cnt))
// 		return ;
// 	if (cnt == 1)
// 	{
// 		push_pop(b, a, 4);
// 		return ;
// 	}
// 	else if (cnt == 2)
// 	{
// 		two_elements_b(a, b);
// 		return ;
// 	}
// 	pivot = get_mid_num(b->top, cnt);
// 	while (++i < cnt)
// 	{
// 		if (b->top->num < pivot)
// 		{
// 			rotate(b, 7);
// 			rb++;
// 		}
// 		else
// 		{
// 			push_pop(b, a, 4);
// 			pa++;
// 		}
// 		if (pa > (cnt / 2))
// 			break ;
// 	}
// 	i = -1;
// 	while (++i < rb && cnt < b->size)
// 		reverse_rotate(b, 10);
// 	a_to_b(a, b, pa);
// 	b_to_a(a, b, (cnt - pa));
// }

void
	a_to_b(t_stack *a, t_stack *b, int cnt)
{
	int			i;
	int			ra;
	int			rb;
	int			pb;
	int			s_pivot;
	int			b_pivot;

	i = -1;
	ra = 0;
	rb = 0;
	pb = 0;
	if (is_a_sorted(a, cnt))
		return ;
	if (cnt == 2)
	{
		two_elements_a(a);
		return ;
	}
	else if (cnt == 3)
	{
		three_elements_a(a);
		return ;
	}
	else if (cnt == 4)
	{
		four_elements_a(a, b);
		return ;
	}
	else if (cnt == 5)
	{
		five_elements_a(a, b);
		return ;
	}
	// s_pivot = get_small_pivot(a->top, cnt);
	// b_pivot = get_big_pivot(a->top, cnt);
	b_pivot = ((get_min_num(a->top, cnt) + get_max_num(a->top, cnt)) / 2);
	s_pivot = ((get_min_num(a->top, cnt) + b_pivot) / 2);
	while (++i < cnt)
	{
		if (a->top->num > b_pivot)
		{
			rotate(a, 6);
			ra++;
		}
		else
		{
			push_pop(a, b, 5);
			pb++;
			if (b->top->num > s_pivot)
			{
				rotate(b, 7);
				rb++;
			}
		}
	}
	i = -1;
	if (ra > rb)
	{
		while (++i < rb)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < ra)
			reverse_rotate(a, 9);
	}
	else
	{
		while (++i < ra)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < rb)
			reverse_rotate(b, 10);
	}
	a_to_b(a, b, ra);
	b_to_a(a, b, rb);
	b_to_a(a, b, (pb - rb));
}

void
	b_to_a(t_stack *a, t_stack *b, int cnt)
{
	int			i;
	int			ra;
	int			rb;
	int			pa;
	int			s_pivot;
	int			b_pivot;

	i = -1;
	ra = 0;
	rb = 0;
	pa = 0;
	if (is_b_sorted(a, b, cnt))
		return ;
	else if (cnt == 2)
	{
		two_elements_b(a, b);
		return ;
	}
	// s_pivot = get_small_pivot(b->top, cnt);
	// b_pivot = get_big_pivot(b->top, cnt);
	b_pivot = ((get_min_num(b->top, cnt) + get_max_num(b->top, cnt)) / 2);
	s_pivot = ((get_min_num(b->top, cnt) + b_pivot) / 2);
	while (++i < cnt)
	{
		if (b->top->num <= s_pivot)
		{
			rotate(b, 7);
			rb++;
		}
		else
		{
			push_pop(b, a, 4);
			pa++;
			if (a->top->num <= b_pivot)
			{
				rotate(a, 6);
				ra++;
			}
		}
	}
	a_to_b(a, b, (pa - ra));
	i = -1;
	if (ra > rb)
	{
		while (++i < rb)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < ra)
			reverse_rotate(a, 9);
	}
	else
	{
		while (++i < ra)
		{
			reverse_rotate(a, 11);
			reverse_rotate(b, 0);
		}
		while (i++ < rb)
			reverse_rotate(b, 10);
	}
	a_to_b(a, b, ra);
	b_to_a(a, b, rb);
}

