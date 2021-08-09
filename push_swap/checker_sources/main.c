/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:52:24 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:52:28 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void
	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

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

int
	is_sorted(t_stack *stack)
{
	int			sort;

	sort = 0;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	while (stack->top->next)
	{
		if (stack->top->num < stack->top->next->num)
			stack->top = stack->top->next;
		else
			break ;
	}
	if (stack->top->next == NULL)
		sort = 1;
	while (stack->top->prev)
		stack->top = stack->top->prev;
	return (sort);
}

void
	checker(t_stack *a, t_stack *b)
{
	char		*line;

	while (get_next_line(0, &line) > 0)
	{
		do_operation(line, a, b);
		free(line);
	}
	if (*line)
	{
		do_operation(line, a, b);
		free(line);
	}
	free(line);
	if (is_sorted(a) && b->size == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int
	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc >= 2)
	{
		a = init_stack();
		b = init_stack();
		create_list(argv, a);
		is_duplicate(a);
		while (a->top->prev)
			a->top = a->top->prev;
		checker(a, b);
		free_all(a, b);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();
	return (0);
}
