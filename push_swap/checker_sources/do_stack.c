#include "checker.h"

void
	do_swap(t_stack *stack)
{
	int			temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->num;
	stack->top->num = stack->top->next->num;
	stack->top->next->num = temp;
}

void
	do_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

void
	do_push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		do_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
			to->bottom = to->top;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	from->size--;
	to->size++;
}

void
	do_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->top->next->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top->next = NULL;
	stack->top->prev = stack->bottom;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	while (stack->bottom->next)
		stack->bottom = stack->bottom->next;
}

void
	do_reverse_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->bottom->prev->next = NULL;
	stack->top->prev = stack->bottom;
	stack->bottom->prev = NULL;
	stack->bottom->next = stack->top;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	while (stack->bottom->next)
		stack->bottom = stack->bottom->next;
}
