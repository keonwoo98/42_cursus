/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:48:52 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:48:56 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
