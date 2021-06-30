/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:40:21 by keokim            #+#    #+#             */
/*   Updated: 2021/06/28 19:40:26 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		free_all(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

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
	}
	free(cmd_join);
	return (NULL);
}

static void		child_process(int *fd, char **argv, char **envp)
{
	int			infile;
	char		**path;
	char		**cmd;
	char		*cmd_path;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	if ((infile = open(argv[1], O_RDONLY)) == -1)
		return (ft_putendl_fd("open fail", 2));
	dup2(infile, 0);
	path = split_path(envp);
	cmd = ft_split(argv[2], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
		return (ft_putendl_fd("command not found", 2));
	if ((execve(cmd_path, cmd, envp)) == -1)
		return (ft_putendl_fd("exevc fail", 2));
	free_all(path);
	free_all(cmd);
	free(cmd_path);
}

static void		parent_process(int *fd, char **argv, char **envp)
{
	int			outfile;
	char		**path;
	char		**cmd;
	char		*cmd_path;

	if ((outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
		return (ft_putendl_fd("open fail", 2));
	wait(0);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(outfile, 1);
	path = split_path(envp);
	cmd = ft_split(argv[3], ' ');
	if ((cmd_path = get_path(path, cmd[0])) == NULL)
		return (ft_putendl_fd("command not found", 2));
	if ((execve(cmd_path, cmd, envp)) == -1)
		return (ft_putendl_fd("exevc fail", 2));
	free_all(path);
	free_all(cmd);
	free(cmd_path);
}

int				main(int argc, char **argv, char **envp)
{
	pid_t		pid;
	int			fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Usage : ./pipex infile cmd1 cmd2 outfile\n", 2);
		return (0);
	}
	if (pipe(fd) == -1)
	{
		ft_putendl_fd("pipe fail", 2);
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("fork fail", 2);
		return (0);
	}
	if (pid == 0)
		child_process(fd, argv, envp);
	else
		parent_process(fd, argv, envp);
	return (0);
}
