#include "push_swap.h"

// void
// 	print_command(int flag)
// {
// 	if (flag == 0)
// 		return ;
// 	else if (flag == 1)
// 		ft_putstr_fd("sa\n", 1);
// 	else if (flag == 2)
// 		ft_putstr_fd("sb\n", 1);
// 	else if (flag == 3)
// 		ft_putstr_fd("ss\n", 1);
// 	else if (flag == 4)
// 		ft_putstr_fd("pa\n", 1);
// 	else if (flag == 5)
// 		ft_putstr_fd("pb\n", 1);
// 	else if (flag == 6)
// 		ft_putstr_fd("ra\n", 1);
// 	else if (flag == 7)
// 		ft_putstr_fd("rb\n", 1);
// 	else if (flag == 8)
// 		ft_putstr_fd("rr\n", 1);
// 	else if (flag == 9)
// 		ft_putstr_fd("rra\n", 1);
// 	else if (flag == 10)
// 		ft_putstr_fd("rrb\n", 1);
// 	else if (flag == 11)
// 		ft_putstr_fd("rrr\n", 1);
// }

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
	swap(t_stack *stack, int flag)
{
	int			temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->num;
	stack->top->num = stack->top->next->num;
	stack->top->next->num = temp;
	print_command(flag);
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
	push_pop(t_stack *from, t_stack *to, int flag)
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
	print_command(flag);
}

void
	rotate(t_stack *stack, int flag)
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
	print_command(flag);
}

void
	reverse_rotate(t_stack *stack, int flag)
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
	print_command(flag);
}
