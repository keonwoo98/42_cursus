/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <minjkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:39:59 by minjkim2          #+#    #+#             */
/*   Updated: 2021/09/19 23:40:00 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

char
	**split_path(char **envp)
{
	char	**path;
	char	*tmp;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			path = ft_split(tmp, ':');
			free(tmp);
			return (path);
		}
	}
	return (NULL);
}

static void
	get_arg(int *flag, char **cmd_arg, t_node *node)
{
	if (*flag == 0)
	{
		*cmd_arg = ft_strjoin(node->next->contents, " ");
		*flag = 1;
	}
	else
	{
		*cmd_arg = ft_strjoin_free(*cmd_arg, node->next->contents);
		*cmd_arg = ft_strjoin_free(*cmd_arg, " ");
	}
}

char
	**get_cmd(t_node *node)
{
	char	**cmd_split;
	char	*cmd_arg;
	char	*cmd;
	int		flag;

	flag = 0;
	if (ft_strchr(node->contents, ' '))
		return (ft_split(node->contents, '\n'));
	cmd = ft_strjoin(node->contents, " ");
	while (node->next && (node->next->type == ARG || \
		node->next->type == DQUOTE || node->next->type == SQUOTE))
	{
		get_arg(&flag, &cmd_arg, node);
		node = node->next;
	}
	if (flag)
	{
		cmd = ft_strjoin(cmd, cmd_arg);
		free(cmd_arg);
	}
	cmd_split = ft_split(cmd, ' ');
	free(cmd);
	return (cmd_split);
}

char
	*get_path(char **path, char *cmd)
{
	char	*cmd_join;
	char	*cmd_path;
	int		fd;
	int		i;

	i = -1;
	if (!ft_strchr(cmd, '/'))
		cmd_join = ft_strjoin("/", cmd);
	else
		return (ft_strdup(cmd));
	while (path[++i])
	{
		cmd_path = ft_strjoin(path[i], cmd_join);
		fd = open(cmd_path, O_RDONLY);
		if (fd == -1)
			free(cmd_path);
		else
		{
			close(fd);
			free(cmd_join);
			return (cmd_path);
		}
	}
	free(cmd_join);
	return (NULL);
}
