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
	while (stack->top->prev)
		stack->top = stack->top->prev;
	while (stack->top)
	{
		free(stack->top);
		stack->top = stack->top->next;
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
		// b = init_stack();
	}
	else if (argc == 1)
		return (0);
	else
		print_error();

	// push_pop(a, b);
	// push_pop(a, b);
	// push_pop(a, b);
	// reverse_rotate(a);
	// reverse_rotate(b);
	// swap(a->top, a->top->next, a);
	// swap(b->top, b->top->next, b);
	// rotate(a);
	// rotate(b);

	// printf("a size : %d\n", a->size);
	// while (a->top)
	// {
	// 	printf("%d\n", a->top->num);
	// 	if (a->top->next == NULL)
	// 		break ;
	// 	a->top = a->top->next;
	// }
	// printf("\n");
	// while (a->bottom)
	// {
	// 	printf("%d\n", a->bottom->num);
	// 	if (a->bottom->prev == NULL)
	// 		break ;
	// 	a->bottom = a->bottom->prev;
	// }
	// printf("\n");

	// printf("b size : %d\n", b->size);
	// while (b->top)
	// {
	// 	printf("%d\n", b->top->num);
	// 	if (b->top->next == NULL)
	// 		break ;
	// 	b->top = b->top->next;
	// }
	// printf("\n");
	// while (b->bottom)
	// {
	// 	printf("%d\n", b->bottom->num);
	// 	if (b->bottom->prev == NULL)
	// 		break ;
	// 	b->bottom = b->bottom->prev;
	// }

	quick_sort(a->top);
	print_list(a->top);

	free_stack(a);
	// free_stack(b);
	// system("leaks a.out");
}
