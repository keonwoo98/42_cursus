/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:32 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:41:32 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

void
	free_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static char
	**copy_env(void)
{
	int		i;
	int		j;
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * (env_len() + 1));
	i = 0;
	j = 0;
	while (g_state.env[i])
	{
		if (*g_state.env[i])
		{
			temp[j] = ft_strdup(g_state.env[i]);
			j++;
		}
		i++;
	}
	temp[j] = NULL;
	return (temp);
}

static void
	sort_env(char ***temp)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	while ((*temp)[i])
	{
		j = i + 1;
		while ((*temp)[j])
		{
			if (ft_strcmp((*temp)[i], (*temp)[j]) > 0)
			{
				swap = (*temp)[i];
				(*temp)[i] = (*temp)[j];
				(*temp)[j] = swap;
			}
			j++;
		}
		i++;
	}
}

void
	print_export(void)
{
	int		i;
	char	**temp;
	char	**split;

	temp = copy_env();
	sort_env(&temp);
	i = 0;
	while (temp[i])
	{
		printf("declare -x ");
		split = ft_split(temp[i], '=');
		if (!ft_strchr(temp[i], '='))
			printf("%s\n", split[0]);
		else
		{
			if (split[1])
				printf("%s=\"%s\"\n", split[0], split[1]);
			else
				printf("%s=\"\"\n", split[0]);
		}
		free_str(split);
		i++;
	}
	free_str(temp);
}
