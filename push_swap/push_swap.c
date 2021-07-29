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

int
	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc >= 2)
	{
		a = init_stack();
		create_list(argv, &a);
		is_duplicate(a);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();

	printf("size : %d\n", a->size);
	while (a->top)
	{
		printf("%d\n", a->top->num);
		if (a->top->next == NULL)
			break ;
		a->top = a->top->next;
	}
	while (a->top)
	{
		free(a->top);
		a->top = a->top->prev;
	}
	free(a);
}
