/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:28 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:28 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int
	environ_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int
	env_len(void)
{
	int	i;

	i = 0;
	while (g_state.env[i])
		i++;
	return (i);
}

int
	get_env_last(void)
{
	int	i;

	i = 0;
	while (g_state.env[i])
		i++;
	return (i);
}

static void
	find_key(char *key, char **split, int *i)
{
	while (g_state.env[*i])
	{
		if (ft_strchr(g_state.env[*i], '='))
		{
			split = ft_split(g_state.env[*i], '=');
			if (!ft_strcmp(key, split[0]))
			{
				free_str(split);
				break ;
			}
			free_str(split);
		}
		else
		{
			if (!ft_strcmp(g_state.env[*i], key))
				break ;
		}
		(*i)++;
	}
}

int
	is_exist(char *key)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	if (get_env(key))
	{
		find_key(key, split, &i);
		return (i);
	}
	return (-1);
}
