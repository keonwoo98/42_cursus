/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:16:07 by keokim            #+#    #+#             */
/*   Updated: 2021/07/01 16:16:08 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char			**split_path(char **envp)
{
	int			i;
	char		**path;
	char		*tmp;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			path = ft_split(tmp, ':');
			free(tmp);
		}
	}
	return (path);
}

char			*get_path(char **path, char *cmd)
{
	int			i;
	int			fd;
	char		*cmd_join;
	char		*cmd_path;

	i = 0;
	cmd_join = ft_strjoin("/", cmd);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd_join);
		if ((fd = open(cmd_path, O_RDONLY)) == -1)
			free(cmd_path);
		else
		{
			close(fd);
			free(cmd_join);
			return (cmd_path);
		}
		i++;
	}
	free(cmd_join);
	return (NULL);
}
