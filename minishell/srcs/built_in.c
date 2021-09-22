/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:08 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:08 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int
	is_builtin(char *str)
{
	if (!ft_strcmp(str, "pwd") || !ft_strcmp(str, "echo")
		|| !ft_strcmp(str, "cd") || !ft_strcmp(str, "env")
		|| !ft_strcmp(str, "export") || !ft_strcmp(str, "unset")
		|| !ft_strcmp(str, "exit"))
		return (1);
	else
		return (0);
}

static int
	ft_pwd(t_node *node)
{
	char	buf[1024];

	if (node->next && node->next->type == ARG)
	{
		print_errmsg("pwd", "too many arguments");
		return (EXIT_FAILURE);
	}
	else if (!getcwd(buf, 1024))
	{
		print_errmsg("pwd", "getcwd fail");
		return (EXIT_FAILURE);
	}
	else
		ft_putendl_fd(buf, 1);
	return (EXIT_SUCCESS);
}

static int
	ft_env(t_node *node)
{
	int	i;

	i = -1;
	if (node->next && node->next->type == ARG)
	{
		print_errmsg("env", "too many arguments");
		return (EXIT_FAILURE);
	}
	while (g_state.env[++i])
	{
		if (ft_strchr(g_state.env[i], '='))
			printf("%s\n", g_state.env[i]);
	}
	return (EXIT_SUCCESS);
}

void
	exec_builtin(t_node *node)
{
	if (!ft_strcmp(node->contents, "pwd"))
		g_state.exit_status = ft_pwd(node);
	else if (!ft_strcmp(node->contents, "env"))
		g_state.exit_status = ft_env(node);
	else if (!ft_strcmp(node->contents, "cd"))
		g_state.exit_status = ft_cd(node);
	else if (!ft_strcmp(node->contents, "export"))
		g_state.exit_status = ft_export(node);
	else if (!ft_strcmp(node->contents, "unset"))
		g_state.exit_status = ft_unset(node);
	else if (!ft_strcmp(node->contents, "exit"))
		ft_exit(node);
	else if (!ft_strcmp(node->contents, "echo"))
		g_state.exit_status = ft_echo(node);
}
