#include "push_swap.h"

void
	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
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

int
	is_sorted(t_stack *stack)
{
	int			sort;

	sort = 0;
	while (stack->top->next)
	{
		if (stack->top->num < stack->top->next->num)
			stack->top = stack->top->next;
		else
			break;
	}
	if (stack->top->next == NULL)
		sort = 1;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	return (sort);
}

int
	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc >= 2)
	{
		a = init_stack();
		create_list(argv, a);
		is_duplicate(a);
		if (is_sorted(a))
		{
			free_stack(a);
			return (0);
		}
		b = init_stack();
		a_to_b(a, b, a->size);
		free_stack(a);
		free_stack(b);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();
	// system("leaks push_swap");
	return (0);
}
