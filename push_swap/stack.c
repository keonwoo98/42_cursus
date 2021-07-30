#include "push_swap.h"

void
	push(t_stack *stack, int num)
{
	t_node		*new_node;

	new_node = init_node(num);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		stack->bottom->next = new_node;
		new_node->prev = stack->bottom;
		stack->bottom = stack->bottom->next;
	}
	stack->size++;
}

void
	pop(t_stack *stack)
{
	t_node		*cur_top;
	t_node		*new_top;

	cur_top = stack->top;
	if (!cur_top)
		return ;
	else
	{
		new_top = stack->top->prev;
		new_top->next = NULL;
		stack->top = new_top;
	}
	stack->size--;
	free(cur_top);
}

t_node
	*ret_top(t_stack *stack)
{
	return (stack->top);
}

void
	destroy(t_stack *stack)
{
	t_node		*del_node;

	del_node = stack->top;
	while (del_node != NULL)
	{
		stack->top = stack->top->prev;
		free(del_node);
		del_node = stack->top;
	}
	free(stack);
}

void
	swap(t_node *left, t_node *right, t_stack *stack)
{
	if (stack->size < 2)
		return ;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	if (left->next)
		left->next->prev = left;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	while (stack->bottom->next)
		stack->bottom = stack->bottom->next;
}

void
	size_one(t_stack *from, t_stack *to)
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
	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 1)
		size_one(from, to);
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
	rotate(t_stack *stack)
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
	reverse_rotate(t_stack *stack)
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
