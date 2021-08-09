/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:50:00 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:50:04 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int
	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*command;

	if (argc >= 2)
	{
		command = init_stack();
		a = init_stack();
		create_list(argv, a);
		is_duplicate(a);
		if (is_sorted(a))
		{
			free_stack(a);
			return (0);
		}
		b = init_stack();
		a_to_b(a, b, command, a->size);
		print(command);
		free_all(a, b, command);
	}
	else if (argc == 1)
		return (0);
	else
		print_error();
	return (0);
}
