/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:39 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:39:39 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

static void
	free_all(char **path, char *cmd_path, char **cmd)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	free(cmd_path);
}

static void
	no_such_error(char *contents)
{
	print_errmsg(contents, "No such file or directory");
	exit(127);
}

static void
	exec_file(t_node *node)
{
	char		*cmd[2];
	struct stat	sb;

	cmd[0] = node->contents;
	cmd[1] = NULL;
	if (!stat(node->contents, &sb))
	{
		if (S_ISREG(sb.st_mode))
		{
			if (!(sb.st_mode & S_IXUSR))
			{
				print_errmsg(node->contents, "Permission denied");
				exit(126);
			}
			if (execve(node->contents, cmd, g_state.env) == -1)
				exit(127);
		}
		else if (S_ISDIR(sb.st_mode))
		{
			print_errmsg(node->contents, "is a directory");
			exit(126);
		}
	}
	else
		no_such_error(node->contents);
}

int
	exec_cmd(t_node *node)
{
	char	**cmd;
	char	**path;
	char	*cmd_path;
	int		exec;

	path = split_path(g_state.env);
	if (path == NULL)
	{
		print_errmsg(node->contents, "No such file or directory");
		exit(127);
	}
	cmd = get_cmd(node);
	cmd_path = get_path(path, cmd[0]);
	exec = execve(cmd_path, cmd, g_state.env);
	if (ft_strchr(node->contents, '/'))
		exec_file(node);
	if (exec == -1)
	{
		free_all(path, cmd_path, cmd);
		print_errmsg(node->contents, "command not found");
		exit(127);
	}
	free_all(path, cmd_path, cmd);
	return (0);
}
