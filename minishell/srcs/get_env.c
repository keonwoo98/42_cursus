/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:07 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:07 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int
	get_env(char *str)
{
	char	**temp;
	int		i;

	i = 0;
	while (g_state.env[i])
	{
		if (ft_strchr(g_state.env[i], '='))
		{
			temp = ft_split(g_state.env[i], '=');
			if (!ft_strcmp(temp[0], str))
			{
				free_str(temp);
				return (1);
			}
			free_str(temp);
		}
		else
		{
			if (!ft_strcmp(g_state.env[i], str))
				return (1);
		}
		i++;
	}
	return (0);
}

char
	*get_env_str(char *str)
{
	char	**temp;
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (g_state.env[i])
	{
		if (ft_strchr(g_state.env[i], '='))
		{
			temp = ft_split(g_state.env[i], '=');
			if (!ft_strcmp(temp[0], str))
			{
				if (temp[1])
					ret = ft_strdup(temp[1]);
				else
					ret = ft_strdup("");
				free_str(temp);
				return (ret);
			}
			free_str(temp);
		}
		i++;
	}
	return (NULL);
}
