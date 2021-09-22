/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:50 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:50 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

int
	is_key_valid(char *key)
{
	int	i;

	i = 1;
	if (!ft_isalpha(key[0]) && key[0] != '_')
		return (0);
	while (key[i] && key[i] != '=')
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void
	add_key(char *key)
{
	int	i;

	i = 0;
	while (g_state.env[i])
		i++;
	g_state.env[i] = ft_strdup(key);
	g_state.env[++i] = NULL;
}

static void
	add_env(char *key, t_node *node)
{
	int		i;

	i = is_exist(key);
	if (node->next == NULL || node->next->type == ARG)
		add_env_arg(node, i);
	else if (node->next->type == DQUOTE)
		add_env_quote(node, i);
}

static void
	update_env(t_node *temp)
{
	char	**split;

	if (!ft_strchr(temp->contents, '='))
	{
		if (!get_env(temp->contents))
			add_key(temp->contents);
	}
	else
	{
		split = ft_split(temp->contents, '=');
		add_env(split[0], temp);
		free_str(split);
	}
}

int
	ft_export(t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!temp->next || temp->next->type <= PIPE)
		print_export();
	else
	{
		temp = temp->next;
		while (temp && temp->type > PIPE)
		{
			if (temp->type != DQUOTE)
			{
				if (!is_key_valid(temp->contents))
				{
					print_error_util("export", \
					temp->contents, "not a valid identifier");
					return (EXIT_FAILURE);
				}
				else
					update_env(temp);
			}
			temp = temp->next;
		}
	}
	return (EXIT_SUCCESS);
}
