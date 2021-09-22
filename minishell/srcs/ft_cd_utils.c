/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:32 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:33 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int
	is_home_exist(char *home)
{
	if (home == NULL)
		return (0);
	else
		return (1);
}

void
	add_oldpwd(char *path)
{
	char	*temp;
	int		i;

	i = is_exist("OLDPWD");
	if (i > -1)
	{
		temp = g_state.env[i];
		g_state.env[i] = ft_strjoin("OLDPWD=", path);
		free(temp);
	}
	else
	{
		i = get_env_last();
		g_state.env[i] = ft_strjoin("OLDPWD=", path);
		g_state.env[++i] = NULL;
	}
}

char
	**put_slash(void)
{
	char	**cd_path;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = get_env_str("CDPATH");
	cd_path = ft_split(temp, ':');
	while (cd_path[i])
	{
		while (cd_path[i][j])
			j++;
		j--;
		if (cd_path[i][j] != '/')
			cd_path[i] = ft_strjoin_free(cd_path[i], "/");
		i++;
	}
	free(temp);
	return (cd_path);
}

int
	ft_cd_cdpath(char **cd_path, t_node *node)
{
	char	*temp;
	char	buf[1024];
	int		i;

	i = 0;
	while (cd_path[i])
	{
		temp = ft_strjoin(cd_path[i], node->next->contents);
		if (!chdir(temp))
		{
			ft_putendl_fd(getcwd(buf, 1024), 1);
			free_str(cd_path);
			free(temp);
			return (EXIT_SUCCESS);
		}
		free(temp);
		i++;
	}
	print_errmsg("cd", strerror(errno));
	free_str(cd_path);
	return (EXIT_FAILURE);
}

int
	ft_cd_none(char *home)
{
	if (!is_home_exist(home))
	{
		print_errmsg("cd", "HOME not set");
		return (EXIT_FAILURE);
	}
	if (!*home)
		return (EXIT_FAILURE);
	if (chdir(home) < 0)
	{
		print_errmsg("cd", strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
