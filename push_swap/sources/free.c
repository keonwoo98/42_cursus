#include "push_swap.h"

void
	free_arr(char **str)
{
	int			i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void
	free_stack(t_stack *stack)
{
	while (stack->bottom)
	{
		free(stack->bottom);
		stack->bottom = stack->bottom->prev;
	}
	free(stack);
}
void
	free_all(t_stack *a, t_stack *b, t_stack *command)
{
	free_stack(a);
	free_stack(b);
	free_stack(command);
}