#include "checker.h"

void
	do_ss(t_stack *a, t_stack *b)
{
	do_swap(a);
	do_swap(b);
}

void
	do_rr(t_stack *a, t_stack *b)
{
	do_rotate(a);
	do_rotate(b);
}

void
	do_rrr(t_stack *a, t_stack *b)
{
	do_reverse_rotate(a);
	do_reverse_rotate(b);
}

void
	do_operation(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa", ft_strlen(line)))
		do_swap(a);
	else if (!ft_strncmp(line, "sb", ft_strlen(line)))
		do_swap(b);
	else if (!ft_strncmp(line, "ss", ft_strlen(line)))
		do_ss(a, b);
	else if (!ft_strncmp(line, "pa", ft_strlen(line)))
		do_push_pop(b, a);
	else if (!ft_strncmp(line, "pb", ft_strlen(line)))
		do_push_pop(a, b);
	else if (!ft_strncmp(line, "ra", ft_strlen(line)))
		do_rotate(a);
	else if (!ft_strncmp(line, "rb", ft_strlen(line)))
		do_rotate(b);
	else if (!ft_strncmp(line, "rr", ft_strlen(line)))
		do_rr(a, b);
	else if (!ft_strncmp(line, "rra", ft_strlen(line)))
		do_reverse_rotate(a);
	else if (!ft_strncmp(line, "rrb", ft_strlen(line)))
		do_reverse_rotate(b);
	else if (!ft_strncmp(line, "rrr", ft_strlen(line)))
		do_rrr(a, b);
	else
		print_error();
}
