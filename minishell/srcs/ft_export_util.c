/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:55 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:56 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void
	add_env_arg(t_node *node, int i)
{
	char	*temp;

	if (i > -1)
	{
		temp = g_state.env[i];
		g_state.env[i] = ft_strjoin(node->contents, "");
		free(temp);
	}
	else
	{
		i = get_env_last();
		g_state.env[i] = ft_strjoin(node->contents, "");
		g_state.env[++i] = NULL;
	}
}

void
	add_env_quote(t_node *node, int i)
{
	char	*temp;

	if (i > -1)
	{
		temp = g_state.env[i];
		g_state.env[i] = ft_strjoin(node->contents, node->next->contents);
		free(temp);
	}
	else
	{
		i = get_env_last();
		g_state.env[i] = ft_strjoin(node->contents, node->next->contents);
		g_state.env[++i] = NULL;
	}
}
