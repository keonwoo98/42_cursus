#include "push_swap.h"

void
	print_error(void)
{
	ft_putendl_fd("Error", 2);
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
		validate(argv, &a);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();

	printf("size : %d\n", a->size);
	while (a->top != NULL)
	{
		printf("%d\n", a->top->num);
		a->top = a->top->next;
	}
	printf("%d\n", a->top->prev->num);
}
