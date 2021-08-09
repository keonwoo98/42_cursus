#include "checker.h"

t_stack
	*init_stack(void)
{
	t_stack		*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		print_error();
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node
	*init_node(int num)
{
	t_node		*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		print_error();
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
