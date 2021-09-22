/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:40:26 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:26 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static int
	home_not_exist(void)
{
	char	*user_home;
	char	*log_name;

	log_name = get_env_str("LOGNAME");
	user_home = ft_strjoin("/Users/", log_name);
	if (chdir(user_home) < 0)
	{
		print_errmsg("cd", strerror(errno));
		free(user_home);
		free(log_name);
		return (EXIT_FAILURE);
	}
	free(user_home);
	free(log_name);
	return (EXIT_SUCCESS);
}

static int
	ft_cd_tilde(char *home)
{
	int	ret;

	ret = 0;
	if (!is_home_exist(home))
	{
		ret = home_not_exist();
		if (ret > 0)
			return (EXIT_FAILURE);
	}
	else
	{
		if (*home && (chdir(home) < 0))
		{
			print_errmsg("cd", strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int
	ft_cd_old(void)
{
	char	*oldpwd;
	char	buf[1024];

	oldpwd = get_env_str("OLDPWD");
	if (oldpwd == NULL)
	{
		ft_putstr_fd("Minishell: cd: OLDPWD not set\n", 2);
		free(oldpwd);
		return (EXIT_FAILURE);
	}
	if (chdir(oldpwd) < 0)
	{
		print_errmsg("cd", strerror(errno));
		free(oldpwd);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(getcwd(buf, 1024), 1);
	free(oldpwd);
	return (EXIT_SUCCESS);
}

static int
	ft_cd_dir(t_node *node)
{
	char	**cd_path;

	if (get_env("CDPATH") && *(node->next->contents) != '/')
	{
		cd_path = put_slash();
		if (ft_cd_cdpath(cd_path, node) > 0)
			return (EXIT_FAILURE);
	}
	else
	{
		if (chdir(node->next->contents) < 0)
		{
			print_errmsg2("cd", node->next->contents, strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int
	ft_cd(t_node *node)
{
	char	buf[1024];
	int		ret;
	char	*temp;
	char	*home;

	home = get_env_str("HOME");
	temp = getcwd(buf, 1024);
	if (!node->next)
		ret = ft_cd_none(home);
	else if (!ft_strcmp(node->next->contents, "~"))
		ret = ft_cd_tilde(home);
	else if (!ft_strcmp(node->next->contents, "-"))
		ret = ft_cd_old();
	else
		ret = ft_cd_dir(node);
	free(home);
	if (ret > 0)
	{
		strerror(errno);
		return (EXIT_FAILURE);
	}
	add_oldpwd(temp);
	return (EXIT_SUCCESS);
}
