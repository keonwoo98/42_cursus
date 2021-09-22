/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:02 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:02 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

static void
	delete_env(char *key)
{
	int			i;
	char		*temp;

	i = is_exist(key);
	if (i > -1)
	{
		temp = g_state.env[i];
		g_state.env[i] = ft_strdup("");
		free(temp);
	}
}

int
	ft_unset(t_node *node)
{
	if (node->next)
		node = node->next;
	while (node && node->type > PIPE)
	{
		if (!is_key_valid(node->contents))
		{
			print_error_util("unset", node->contents, "not a valid identifier");
			return (EXIT_FAILURE);
		}
		else
			delete_env(node->contents);
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
