#include "push_swap.h"

void
	push(t_stack **stack, int num)
{
	t_node		*new_node;
	t_node		*old_top;

	new_node = init_node(num);
	if ((*stack)->top == NULL)
		(*stack)->top = new_node;
	else
	{
		// old_top = (*stack)->top;
		// old_top->prev = new_node;
		// new_node->next = old_top;
		// (*stack)->top = new_node;
		(*stack)->top->prev = new_node;
		new_node->next = (*stack)->top;
		(*stack)->top = (*stack)->top->prev;
	}
	(*stack)->size++;
}

void
	pop(t_stack **stack)
{
	t_node		*cur_top;
	t_node		*new_top;

	cur_top = (*stack)->top;
	if (!cur_top)
		return ;
	else
	{
		new_top = (*stack)->top->prev;
		new_top->next = NULL;
		(*stack)->top = new_top;
	}
	(*stack)->size--;
	// free(cur_top->num);
	free(cur_top);
}

t_node
	*ret_top(t_stack **stack)
{
	return ((*stack)->top);
}

void
	destroy(t_stack **stack)
{
	t_node		*del_node;

	del_node = (*stack)->top;
	while (del_node != NULL)
	{
		(*stack)->top = (*stack)->top->prev;
		// free(del_node->num);
		free(del_node);
		del_node = (*stack)->top;
	}
	free(*stack);
}
