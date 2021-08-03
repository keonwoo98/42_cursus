#include "push_swap.h"

void
	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void
	print_error_msg(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

void
	free_stack(t_stack *stack)
{
	// while (stack->top->prev)
	// 	stack->top = stack->top->prev;
	// while (stack->top)
	// {
	// 	free(stack->top);
	// 	stack->top = stack->top->next;
	// }
	// free(stack);
	while (stack->bottom)
	{
		free(stack->bottom);
		stack->bottom = stack->bottom->prev;
	}
	free(stack);
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
		b = init_stack();
		a_to_b(a, b, a->size);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();

	// for (int i = 0; i < a->size; i++)
	// {
	// 	printf("%d\n", a->top->num);
	// 	a->top = a->top->next;
	// }
	free_stack(a);
	free_stack(b);
	// system("leaks push_swap");
}
