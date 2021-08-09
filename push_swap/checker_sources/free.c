/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 09:51:43 by keokim            #+#    #+#             */
/*   Updated: 2021/08/09 09:51:44 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
